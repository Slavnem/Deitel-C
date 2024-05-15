// Slavnem @2024-05-15
// Kayıt Liste

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Ön tanımlamalar
#define MIN_LIST 1
#define MAX_LIST 100

// Kayıt Yapısı
typedef struct
{
    char soyisim[15];
    char isim[15];
    char yas[2];
} Kayit;

// Dosya İşlemi Yapısı
typedef struct
{
    const char* const fileNamePtr;
    int fileJob: 4;
    int: 4; // bellek hizalamasi
    const unsigned int fileMin: 1; // min 1
    const unsigned int fileMax: 7; // max 100
} FileTask;

// Fonksiyon isimlendirmeleri
typedef enum
{
    ERECFAIL = -1, // kayıt işlemi başarısızlığı
    ERECFREE = 0, // boş işlem
    ERECAUTO = 1, // otomatik kayıt
    ERECNEW, // yeni kayıt ekleme
    ERECUPDATE, // kayıt güncelleme
    ERECDELETE, // kayıt silme
    ERECEND // kayıt son
} FileRecord;

// Doğrulama isimlendirmeleri
typedef enum
{
    false = 0,
    true
} bool;

// Dosya yapısını kullanan fonksiyon tanımı
int taskChooser(FileTask*);

// Sabit isimler
static const char* const __FileNameFor_Record = "nameage.dat";
static const char* const __ErrFileNotFound = "Dosya Bulunamadi";
static const char* const __ErrFileCellUnableCreate = "Dosya Hucreleri Olusturulamiyor";

// main
int main(void)
{
    srand(time(NULL)); // rastgele zamanlama

    // Dosya yapısı ve başalngıç tanımlaması
    FileTask fileTaskPtr = {
        __FileNameFor_Record, -1,
        MIN_LIST, MAX_LIST
    };

    // İşlem doğrulayıcı
    bool returner = false;

    // eski verinin üstüne yazılıp yazılmayacağını tutacak
    int removeOld = false;

    // başlangıç için soru soracağız, ona göre eski kayıtın üstüne yazılacak
    printf("%s",
        "Eski verinin ustune yazilmasini onaliyorsaniz 1'e, degilse rastgele sayiya tiklayiniz\n?: ");
    scanf("%d", &removeOld);

    // eski verinin üstüne yazma aktif
    if(removeOld == true)
    {
        fileTaskPtr.fileJob = ERECAUTO;
        returner = (taskChooser(&fileTaskPtr) > ERECFAIL) ? true : false;

        // işlem başarısız ise sonlandır
        if(!returner)
        {
            printf("%s\n", (__ErrFileCellUnableCreate));
            return ERECFAIL;
        }
    }

    // otomatik oluşturmayı sonlandır
    fileTaskPtr.fileJob = ERECFREE;

    // işlemi döndür
    returner = taskChooser(&fileTaskPtr);
    
    // işlem sonucuna göre döndür
    return (returner) ? true : false;
}

// Dosya işlem seçimi
int taskChooser(FileTask* argFileTask)
{
    // Fonksiyon tanımları
    int RecordAuto(FILE*, FileTask*);
    int RecordNew(FILE*);
    int RecordUpdate(FILE*);
    int RecordDelete(FILE*);

    FILE *filePtr; // dosya
    
    int choice; // kullanıcı seçimi için
    int procResult; // işlem sonucunu tutacak

    // Eğer otomatik oluşturma varsa direk otomatik oluşturma yapsın
    if(argFileTask->fileJob == ERECAUTO)
    {
        if((filePtr = fopen(argFileTask->fileNamePtr, "wb")) == NULL)
        {
            printf("%s: %s\n", (__ErrFileNotFound), (argFileTask->fileNamePtr));
            return ERECFAIL;
        }

        RecordAuto(filePtr, argFileTask); // otomatik hücre oluşturmasını sağlıyoruz
        return ERECAUTO;
    }

    // dosyayı açmak
    if((filePtr = fopen(argFileTask->fileNamePtr, "rb+")) == NULL)
    {
        printf("%s: %s\n", (__ErrFileNotFound), (argFileTask->fileNamePtr));
        return ERECFAIL;
    }

    // işlem bitmediği sürece
    do
    {
        puts("Secim Yapiniz");
        printf("%d%s\n%d%s\n%d%s\n%d%s\n%s",
            ERECNEW , " - Yeni Kayit",
            ERECUPDATE, " - Kayit Guncelle",
            ERECDELETE, " - Kayit Sil",
            ERECEND, " - Sonlandir",
            "?: "
        );

        scanf("%d", &choice);

        // İşlem numarasını ata
        argFileTask->fileJob = choice;

        // seçime göre işlem
        switch(argFileTask->fileJob)
        {
            case ERECAUTO:
                procResult = RecordAuto(filePtr, argFileTask);
                break;
            case ERECNEW:
                procResult = RecordNew(filePtr);
                break;
            case ERECUPDATE:
                procResult = RecordUpdate(filePtr);
                break;
            case ERECDELETE:
                procResult = RecordDelete(filePtr);
                break;
            case ERECEND:
                /// dosya açıksa kapatıyoruz
                (filePtr != NULL) ? fclose(filePtr) : false;
                break;
            default:
                procResult = ERECFAIL;
                printf("%d - Boyle Bir Secim Yok\n", argFileTask->fileJob);
        }
    } while(choice != ERECEND);
}

// Otomatik Kayıt
int RecordAuto(FILE* argFile, FileTask* argFileTask)
{
    // Boş kayıt
    Kayit blankKayit = {"unassigned", "", "0"};

    // boş kayıt için sayaç
    unsigned int blankCounter;

    // dosya başına almak
    fseek(argFile, 0, SEEK_SET);

    // döngü ile dosya başından sonuna kadar yazmak
    for(blankCounter = 0; blankCounter < (*argFileTask).fileMax; blankCounter++)
    {
        // dosyaya yaz
        fwrite(&blankKayit, sizeof(Kayit), 1, argFile);
    }

    // dosya yazma bitti, dosyayı kapatıyoruz
    fclose(argFile);
}

// Yeni Kayıt
int RecordNew(FILE* argFile)
{
    Kayit kayitListeler[10]; // kayıt dizisi oluşturmak

    unsigned int sayacKayitlar; // kayıtlar için sayaç
    const unsigned int const sizeKayitlar = (sizeof(kayitListeler) / sizeof(kayitListeler[0]));
    unsigned int kayitKonum = 0;

    // kayıt için başlangıç numarası istemek
    printf("Kayit icin bir konum baslangici giriniz (%d-%d): ", (MIN_LIST), (MAX_LIST - sizeKayitlar));
    scanf("%d", &kayitKonum);

    // geçersiz konum girilmise eğer rastgele versin
    if(kayitKonum < MIN_LIST || kayitKonum > (MAX_LIST - sizeKayitlar))
    {
        kayitKonum = (rand() % (MAX_LIST - sizeKayitlar));
    }

    // kullanıcıdan verileri almak
    for(sayacKayitlar = 0; sayacKayitlar < sizeKayitlar; sayacKayitlar++)
    {
        printf("[%02u] Soyad, ad, yas giriniz: ", (sayacKayitlar + 1));
        scanf("%14s%14s%s",
            &kayitListeler[sayacKayitlar].soyisim,
            &kayitListeler[sayacKayitlar].isim,
            &kayitListeler[sayacKayitlar].yas);
    }

    // döngü ile rastgele olarak dosyaya ekleme
    for(sayacKayitlar = 0; sayacKayitlar < sizeKayitlar; sayacKayitlar++)
    {
        // konuma gitmek
        fseek(argFile, ((kayitKonum + sayacKayitlar) * sizeof(Kayit)), SEEK_SET);

        // kayıtı yazdırmak
        fwrite(&kayitListeler[sayacKayitlar], sizeof(Kayit), 1, argFile);
    }

    // başarılı dön
    return true;
}

// Kayıt Güncelle
int RecordUpdate(FILE* argFile)
{
    // geçici Kayıt için yapı oluştur
    Kayit tempKayit;
    Kayit kontrolKayit;

    // kullanıcı id'sini geçici olarak tutmak için
    int tempId;

    // verileri iste
    printf("Id, Soyad, ad ve yas giriniz: ");
    scanf("%03d%14s%14s%s",
        &tempId,
        &tempKayit.soyisim,
        &tempKayit.isim,
        &tempKayit.yas);

    // eğer geçersiz id girilmişse ona göre id değerini düzenle
    if(tempId < MIN_LIST || tempId > MAX_LIST)
    {
        // rastgele numara ver
        tempId = (rand() % MAX_LIST) + MIN_LIST;
    }

    // dosya konumuna ayarlamak
    fseek(argFile, ((tempId - 1) * sizeof(Kayit)), SEEK_SET);

    // adreste bilgi yoksa çıktı ver ve dön
    fread(&kontrolKayit, sizeof(Kayit), 1, argFile);

    // veri kontrolü
    if(strcmp(kontrolKayit.soyisim, "unassigned") == 0 ||
        strcmp(kontrolKayit.yas, "0") == 0 ||
        strcmp(kontrolKayit.isim, "") == 0)
    {
        puts("\nKayit Bilgisi Yok\n");
        return ERECFAIL;
    }

    // dosya konumuna ayarlamak
    fseek(argFile, ((tempId - 1) * sizeof(Kayit)), SEEK_SET);

    // Kayıtın üstüne yaz, bu sayede güncellenmiş olacak
    fwrite(&tempKayit, sizeof(Kayit), 1, argFile);
    
    // işlem numarasını döndür
    return ERECUPDATE;
}

// Kayıt Sil
int RecordDelete(FILE* argFile)
{
    // bos kayit
    Kayit freeKayit = {"unassigned", "", "0"};

    // kayit numarasi
    int kayitNum;

    // silinmek istenen kayit numarasini istemek
    printf("Bir kayit numarasi giriniz (%d-%d): ", (MIN_LIST), (MAX_LIST));
    scanf("%d", &kayitNum);

    // istenen aralıkta değilse eğer
    if(kayitNum < MIN_LIST || kayitNum > MAX_LIST)
    {
        printf("%d - Boyle bir kayit numarasi yok!\n", kayitNum);
        return ERECFAIL;
    }

    // kayit konumuna ayarla
    fseek(argFile, ((kayitNum - 1) * sizeof(Kayit)), SEEK_SET);

    // kayıtın üstüne boş veri yaz
    fwrite(&freeKayit, sizeof(Kayit), 1, argFile);

    // işlem numarasını döndür
    return ERECDELETE;
}