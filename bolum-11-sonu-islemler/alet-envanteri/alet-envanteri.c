// Slavnem @2024-05-16
// Alet Envanteri

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// Ön Tanımlamalar
#define MIN_LIST 1
#define MAX_LIST 100

// Doğru/Yanlış yapısı
typedef enum bool
{
    false = 0,
    true
} bool;

// Veri işlem numaralandırma yapısı
typedef enum TaskType
{
    TASK_FAIL = -1, // işlem başarısızlığı
    TASK_FREE = 0, // boş işlem
    TASK_RESET, // veriyi baştan oluştur
    TASK_NEW, // yeni veri
    TASK_UPDATE, // veri güncelle
    TASK_DELETE, // veriyi sil
    TASK_LIST, // veriyi listele
    TASK_END // veri işlem sonu
} TaskType;

// Alet Envanteri Yapısı
typedef struct ToolInventory
{
    int id; // alet kayıt numarası
    char toolname[15]; // alet adı
    int quality; // kalite
    double cost; // maliyet
} ToolInventory;

// Sabit metin
typedef const char* const string;

// Dosya İşlem Yapısı
typedef struct FileTask
{
    FILE* filePtr; // dosya işaretçisi
    string fileName; // dosya adı
    const unsigned int minSize: 1; // dosya en düşük boyutu
    const unsigned int maxSize: 7; // dosya en yüksek boyutu
    TaskType taskCode; // dosya işlem numarası
    TaskType(*process)(struct FileTask*); // dosya işlemi
} FileTask;

// Dosya açma türleri
static string __FileOpen_WriteBin = "wb";
static string __FileOpen_ReadBin = "rb";
static string __FileOpen_ReadWriteBin = "rb+";

// Oluşturulmuş sabit bir yapı örneği
static const ToolInventory const __AutoTool[8] =
{
    {3, "Electric sander", 7, 57.98},
    {17, "Hammer", 76, 11.99},
    {24, "Jig saw", 21, 11.00},
    {39, "Lawn mower", 3, 79.50},
    {56, "Power saw", 18, 99.99},
    {68, "Screwdriver", 106, 6.99},
    {77, "Sledge hammer", 11, 21.50},
    {83, "Wrench", 34, 7.50}
};

// Sabit isimlendirmeler
static string __FileNameFor_Hardware = "hardware.dat";
static string __ErrFileNotFound = "Dosya Bulunamadi";
static string __ErrFileNotOpened = "Dosya Acilamadi";
static string __ErrProcessFail = "Islem Basarisiz Oldu";
static string __ErrInvalidID = "Gecersiz Id Numarasi";
static string __OutProcessCode = "Islem Kodu:";
static string __SuccessProcessEnd = "Dosya Islemi Sonlandiriliyor...";
static string __WarnTaskNotFound = "Boyle Bir Islem Bulunamadi!";
static string __DataRemoved = "* Veri/Veriler Silindi *";
static string __DataReseted = "* Veri/Veriler Sifirlandi *";
static string __DataAdded = "* Veri/Veriler Eklendi *";
static string __DataUpdated = "* Veri/Veriler Guncellendi *";
static string __DataListed = "* Veri/Veriler Listelendi *";

// Fonksiyon tanımlamaları
TaskType taskChooser(FileTask*);

// main
int main(void)
{
    // Dosya işlemleri için yapı oluşturma
    FileTask fileTask =
    {
        NULL, // dosya
        __FileNameFor_Hardware, // dosya adı
        MIN_LIST, // dosya en az satır boyutu
        MAX_LIST, // dosya en fazla satır boyutu
        TASK_FREE, // boş işlem kodu
        taskChooser // işlem yapacak olan fonksiyon
    };

    // Başlangıçta eski verinin üstüne yazıp
    // yazmaması için işlem yaptıracağız bu yüzden
    // dosya durumunu ayarlıyoruz
    fileTask.taskCode = TASK_RESET;

    // belirlenen görev kodu ile işlem yapsın
    fileTask.process(&fileTask);

    // işlem başarısız ise dönüş yapılsın
    if(fileTask.taskCode == TASK_FAIL)
    {
        // işlemin başarısız olduğuna dair çıktı
        printf("%s %d | %s\n",
            (__OutProcessCode),
            (fileTask.taskCode),
            (__ErrProcessFail));

        return (bool)false;
    }

    // işlem durumu boşa alınıyor çünkü
    // kullanıcı işlem yapmaya devam edebilir
    fileTask.taskCode = TASK_FREE;

    // işlem devam ediyor
    fileTask.process(&fileTask);

    // dosya açıksa kapat
    if(fileTask.filePtr != NULL)
    {
        fclose(fileTask.filePtr);
        fileTask.filePtr = NULL;
    }

    // işlem kodunu döndürsün
    return fileTask.taskCode;
}

// taskChooser
TaskType taskChooser(FileTask* argFTaskPtr)
{
    // fonksiyon tanımlamaları
    TaskType taskReset(FileTask*, const ToolInventory* const); // veri sıfırla
    TaskType taskNew(FileTask*); // yeni veri
    TaskType taskUpdate(FileTask*); // veri güncelle
    TaskType taskDelete(FileTask*); // veri sil
    TaskType taskList(FileTask*); // veri lisele

    // bazı işlemleri listelemek
    TaskType(*taskMulti[])(FileTask*) = {
        taskNew,
        taskUpdate,
        taskDelete
    };

    // işlem durumu için
    int controller = false;

    // işlem durumlarını almak için buffer
    char buffer[2];

    // işlem koduna göre işlem yapılacak
    switch(argFTaskPtr->taskCode)
    {
        // veriyi sıfırla
        case TASK_RESET:
            // kullanıcıya soru sorsun ve değeri alsın
            printf("%s",
                "Dosyadaki tum veriyi silmek icin kontrol\n"
                "Veriyi silmek istiyorsaniz 1\n"
                "Istemiyorsaniz rastgele bir numaraya tiklayiniz\n?: ");
            
            // satırı oku
            scanf("%2s", buffer);

            // okunan satırı sayıya döndür
            controller = strtoul(buffer, NULL, 10);

            // eğer veri sıfırlama istenmiyorsa işlem durumu kodunu
            // boş yapsın ve kodu döndürsün
            if(controller != true)
            {
                argFTaskPtr->taskCode = TASK_FREE;
                return argFTaskPtr->taskCode;
            }

            // veriyi sıfırla ve kodu döndür
            return taskReset(argFTaskPtr, __AutoTool);
    }

    // hata olmayana kadar ya daişlem sonlanana kadar işlem yapsın
    while(argFTaskPtr->taskCode != TASK_FAIL && argFTaskPtr->taskCode != TASK_END)
    {
        // kullanıcıdan işlem numarası istemek
        printf("%s\n%d%s\n%d%s\n%d%s\n%d%s\n%d%s\n%s",
            "Bir islem seciniz",
            TASK_NEW, " - Yeni Kayit",
            TASK_UPDATE, " - Kayit Guncelle",
            TASK_DELETE, " - Kayit Sil",
            TASK_LIST, " - Kayitlari Listele",
            TASK_END, " - Sonlandir",
            "?: ");

        // satırı oku
        scanf("%2s", buffer);

        // okunan satırı sayıya döndür
        controller = strtoul(buffer, NULL, 10);

        // işlem koduna göre işlem
        switch(controller)
        {
            // sonlandır
            case TASK_END:
                // işlem kodunu sonlandırmaya ayarlasın
                argFTaskPtr->taskCode = TASK_END;

                // dosya açıksa kapat
                if(argFTaskPtr->filePtr != NULL)
                {
                    fclose(argFTaskPtr->filePtr);
                    argFTaskPtr->filePtr = NULL;
                }

                printf("\n%s\n\n", (__SuccessProcessEnd)); // işlem sonu mesajı
                return argFTaskPtr->taskCode;
            // yeni veri
            // veri güncelle
            // veri sil
            case TASK_NEW:
            case TASK_UPDATE:
            case TASK_DELETE:
                argFTaskPtr->taskCode = controller;
                (*taskMulti[(argFTaskPtr->taskCode - TASK_NEW)])(argFTaskPtr);
                break;
            // veri listeleme
            case TASK_LIST:
                argFTaskPtr->taskCode = TASK_LIST;
                taskList(argFTaskPtr);                
                break;
            // işlem hala boş
            default:
                puts(__WarnTaskNotFound); // geçersiz işlem bilgilendirmesi
                argFTaskPtr->taskCode = TASK_FREE;
        }
    }
}

// taskReset
TaskType taskReset(FileTask* argFTaskPtr, const ToolInventory* const argToolInv)
{
    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    // dosyayı yazma modunda aç
    if((argFTaskPtr->filePtr = fopen(argFTaskPtr->fileName, __FileOpen_WriteBin)) == NULL)
    {
        // dosya açma başarısız oldu
        printf("%s: %s\n", (argFTaskPtr->fileName), (__ErrFileNotOpened));
        return TASK_FAIL;
    }

    // işlem için geçici sayaç
    int tempCounter;

    // boş araç kiti yapısı
    ToolInventory tempToolInventory = {0, "", 0, 0.0};

    // dosya konumunu başa al, almazsa da hata döndür
    if(fseek(argFTaskPtr->filePtr, 0, SEEK_SET) == TASK_FAIL)
    {
        // işlem durumunu başarısız yap ve döndür
        argFTaskPtr->taskCode = TASK_FAIL;
        return TASK_FAIL;
    }

    // dosyaya desteklenen boyut kadar veri yaz
    for(tempCounter = argFTaskPtr->minSize; tempCounter < argFTaskPtr->maxSize; tempCounter++)
    {
        // dosyaya yazsın
        fwrite(&tempToolInventory, sizeof(argFTaskPtr), 1, argFTaskPtr->filePtr);
    }

    // dizi boyutunu sakla
    const unsigned int sizeTools = sizeof(argToolInv);

    // belirli elemanları belirli konuma yaz
    for(tempCounter = 0; tempCounter < sizeTools; tempCounter++)
    {
        if(argToolInv[tempCounter].id < argFTaskPtr->minSize || argToolInv[tempCounter].id >  argFTaskPtr->maxSize)
        {
            continue; // işlem numarası geçersiz, sonraki tura geçsin
        }

        // dosya konumuna ayarla
        fseek(argFTaskPtr->filePtr, (((argToolInv[tempCounter].id) - 1) * sizeof(ToolInventory)), SEEK_SET);

        // veriyi yaz
        fwrite(&argToolInv[tempCounter], sizeof(ToolInventory), 1, argFTaskPtr->filePtr);
    }

    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    argFTaskPtr->taskCode = TASK_RESET; // işlem kodunu ayarlasın
    printf("\n%s\n\n", (__DataReseted)); // bilgilendirme çıktısı versin
    return argFTaskPtr->taskCode; // işlem kodunu döndür
} // veri sıfırla

// taskNew
TaskType taskNew(FileTask* argFTaskPtr)
{
    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    // dosyayı okuma/yazma modunda aç
    if((argFTaskPtr->filePtr = fopen(argFTaskPtr->fileName, __FileOpen_ReadWriteBin)) == NULL)
    {
        // dosya açma başarısız oldu
        printf("%s: %s\n", (argFTaskPtr->fileName), (__ErrFileNotOpened));
        argFTaskPtr->taskCode = TASK_FAIL;
        return argFTaskPtr->taskCode;
    }

    // araç yapıları
    ToolInventory tempTool;
    ToolInventory controlTool;

    // veri girişi istenmeli
    printf("Id, Isim, kalite ve fiyat giriniz\n?: ");
    scanf("%d%14s%d%lf",
        &tempTool.id,
        tempTool.toolname,
        &tempTool.quality,
        &tempTool.cost
    );

    // dosya konumu verilen kayıt numarasına göre ayarlanmalı
    // eğer geçersiz numara ise ya da zaten veri varsa
    // başka bir kayıt numarası girmesi için uyarı verilmeli
    if(tempTool.id < argFTaskPtr->minSize || tempTool.id > argFTaskPtr->maxSize)
    {
        printf("%s: %d\n", (__ErrInvalidID), (tempTool.id)); // bilgilendirici metin
        argFTaskPtr->taskCode = TASK_FREE; // işlem durumunu boş yap
        return argFTaskPtr->taskCode; // durumu döndür
    }

    // dosya konumuna ayarla
    fseek(argFTaskPtr->filePtr, ((tempTool.id - 1) * sizeof(ToolInventory)), SEEK_SET);

    // veriyi oku
    fread(&controlTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

    // eğer id zaten kullanılıyorsa
    if(controlTool.id == tempTool.id)
    {
        printf("%d%s\n", tempTool.id, " - Id numarasi aktif olarak kullaniliyor zaten!");
        argFTaskPtr->taskCode = TASK_FREE;
        return argFTaskPtr->taskCode;
    }

    // dosya konumuna ayarla
    fseek(argFTaskPtr->filePtr, ((tempTool.id - 1) * sizeof(ToolInventory)), SEEK_SET);

    // veriyi dosyaya yaz
    fwrite(&tempTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    argFTaskPtr->taskCode = TASK_NEW; // işlem durumunu yeni veri yap
    printf("\n%s\n\n", (__DataAdded)); // bildiri mesajı
    return argFTaskPtr->taskCode; // işlem durumunu döndür
}

// taskUpdate
TaskType taskUpdate(FileTask* argFTaskPtr)
{
    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    // dosyayı okuma/yazma modunda aç
    if((argFTaskPtr->filePtr = fopen(argFTaskPtr->fileName, __FileOpen_ReadWriteBin)) == NULL)
    {
        // dosya açma başarısız oldu
        printf("%s: %s\n", (argFTaskPtr->fileName), (__ErrFileNotOpened));
        argFTaskPtr->taskCode = TASK_FAIL;
        return argFTaskPtr->taskCode;
    }

    // araç yapıları
    ToolInventory oldTool;
    ToolInventory newTool;

    // veri girişi istenmeli
    printf("Id, Isim, kalite ve fiyat giriniz\n?: ");
    scanf("%d%14s%d%lf",
        &newTool.id,
        newTool.toolname,
        &newTool.quality,
        &newTool.cost
    );

    // dosya konumu verilen kayıt numarasına göre ayarlanmalı
    // eğer geçersiz numara ise ya da zaten veri varsa
    // başka bir kayıt numarası girmesi için uyarı verilmeli
    if(newTool.id < argFTaskPtr->minSize || newTool.id > argFTaskPtr->maxSize)
    {
        printf("%s: %d\n", (__ErrInvalidID), (newTool.id)); // bilgilendirici metin
        argFTaskPtr->taskCode = TASK_FREE; // işlem durumunu boş yap
        return argFTaskPtr->taskCode; // durumu döndür
    }

    // dosya konumuna ayarla
    fseek(argFTaskPtr->filePtr, ((newTool.id - 1) * sizeof(ToolInventory)), SEEK_SET);

    // veriyi oku
    fread(&oldTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

    // eğer geçerli id numarası yoksa
    if(oldTool.id < argFTaskPtr->minSize || oldTool.id > argFTaskPtr->maxSize)
    {
        printf("%s: %d\n", (__ErrInvalidID), (newTool.id)); // bilgilendirici metin
        argFTaskPtr->taskCode = TASK_FREE; // işlem durumunu boş yap
        return argFTaskPtr->taskCode; // durumu döndür
    }

    // dosya konumuna ayarla
    fseek(argFTaskPtr->filePtr, ((newTool.id - 1) * sizeof(ToolInventory)), SEEK_SET);

    // veriyi dosyaya yaz
    fwrite(&newTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    argFTaskPtr->taskCode = TASK_UPDATE; // işlem durumunu yeni veri yap
    printf("\n%s\n\n", (__DataUpdated)); // bildiri mesajı
    return argFTaskPtr->taskCode; // işlem durumunu döndür
}

// taskDelete
TaskType taskDelete(FileTask* argFTaskPtr)
{
    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    // dosyayı okuma/yazma modunda aç
    if((argFTaskPtr->filePtr = fopen(argFTaskPtr->fileName, __FileOpen_ReadWriteBin)) == NULL)
    {
        // dosya açma başarısız oldu
        printf("%s: %s\n", (argFTaskPtr->fileName), (__ErrFileNotOpened));
        argFTaskPtr->taskCode = TASK_FAIL;
        return argFTaskPtr->taskCode;
    }

    // araç yapıları
    ToolInventory tempTool; // geçici depolanacak veri
    ToolInventory storedTool; // depolanmış veri
    ToolInventory freeTool = {0,"",0,0.0}; // boş veri

    // veri girişi istenmeli
    printf("Id giriniz\n?: ");
    scanf("%d", &tempTool.id);

    // dosya konumu verilen kayıt numarasına göre ayarlanmalı
    // eğer geçersiz numara ise ya da zaten veri varsa
    // başka bir kayıt numarası girmesi için uyarı verilmeli
    if(tempTool.id < argFTaskPtr->minSize || tempTool.id > argFTaskPtr->maxSize)
    {
        printf("%s: %d\n", (__ErrInvalidID), (tempTool.id)); // bilgilendirici metin
        argFTaskPtr->taskCode = TASK_FREE; // işlem durumunu boş yap
        return argFTaskPtr->taskCode; // durumu döndür
    }

    // dosya konumuna ayarla
    fseek(argFTaskPtr->filePtr, ((tempTool.id - 1) * sizeof(ToolInventory)), SEEK_SET);

    // veriyi oku
    fread(&storedTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

    // eğer geçerli id numarası yoksa
    if(storedTool.id < argFTaskPtr->minSize || storedTool.id > argFTaskPtr->maxSize)
    {
        printf("%s: %d\n", (__ErrInvalidID), (tempTool.id)); // bilgilendirici metin
        argFTaskPtr->taskCode = TASK_FREE; // işlem durumunu boş yap
        return argFTaskPtr->taskCode; // durumu döndür
    }

    // dosya konumuna ayarla
    fseek(argFTaskPtr->filePtr, ((tempTool.id - 1) * sizeof(ToolInventory)), SEEK_SET);

    // veriyi dosyaya yaz
    fwrite(&freeTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    argFTaskPtr->taskCode = TASK_DELETE; // işlem durumunu yeni veri yap
    printf("\n%s\n\n", (__DataRemoved)); // bildiri mesajı
    return argFTaskPtr->taskCode; // işlem durumunu döndür
}

// taskList
TaskType taskList(FileTask* argFTaskPtr)
{
    // dosya açıksa kapat
    if(argFTaskPtr->filePtr != NULL)
    {
        fclose(argFTaskPtr->filePtr);
        argFTaskPtr->filePtr = NULL;
    }

    // dosyayı okuma modunda aç
    if((argFTaskPtr->filePtr = fopen(argFTaskPtr->fileName, __FileOpen_ReadBin)) == NULL)
    {
        // dosya açma başarısız oldu
        printf("%s: %s\n", (argFTaskPtr->fileName), (__ErrFileNotOpened));
        argFTaskPtr->taskCode = TASK_FAIL;
        return argFTaskPtr->taskCode;
    }

    // Geçici bir depolama yapısı oluştur
    ToolInventory tempTool;

    // döngü için sayaç
    int counter;

    // döngü ile dosya bitene kadar dönsün ve listelesin
    for(counter = argFTaskPtr->minSize; counter < argFTaskPtr->maxSize; counter++)
    {
        // dosya konumuna gitmek
        fseek(argFTaskPtr->filePtr, ((counter - 1) * (sizeof(ToolInventory))), SEEK_SET);

        // dosyadan veriyi okumak
        fread(&tempTool, sizeof(ToolInventory), 1, argFTaskPtr->filePtr);

        // veri boşsa eğer sonraki tura geçsin
        if(tempTool.id < argFTaskPtr->minSize || tempTool.id > argFTaskPtr->maxSize || tempTool.id < counter)
            continue;

        // veriyi çıktı vermek
        printf("%-8d%-16s%-8d%-8.2f\n",
            tempTool.id, tempTool.toolname,
            tempTool.quality, tempTool.cost);
    }

    // işlem kodunu ayarla ve döndür
    argFTaskPtr->taskCode = TASK_LIST;
    printf("\n%s\n\n", (__DataListed)); // bildiri mesajı
    return argFTaskPtr->taskCode;
}