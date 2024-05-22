// Slavnem @2024-05-20
// Gelişmiş Simpletron Dosya İşlemleri İle Birlikte

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Değişken Tanımlamaları
typedef const char* const string; // sabit metin
typedef char* vstring; // değiştirilebilir metin
typedef unsigned int uint; // nötr, pozitif tam sayı
typedef char abool; // gelişmiş bool (advanced bool)

// Simpletron Sınırlandırma Tanımlamaları
#define SIMPLETRON_MIN 0
#define SIMPLETRON_MAX 1000
#define SIMPLETRON_KILL -1

// Geişmiş Doğrulama
#define afail -1
#define afalse 0
#define atrue 1

// Çıktı İçin Satır ve Sütun Sayısı
#define OUTPUT_COLUMN 10
#define OUTPUT_ROW (SIMPLETRON_MAX / OUTPUT_COLUMN)

// Dosya İşlem Komutları
typedef enum FileJob
{
    WRITE_OUTPUT_TO_FILE = 1, // simpletron komut çıktısını dosyaya yaz
    READ_COMMAND_FROM_FILE // simpletron komutlarını dosyadan oku
} FileJob;

// Simpletron durumları
typedef enum SimpletronStatus
{
    SSTAT_FAIL = -1, // hata verdi
    SSTAT_OFF = 0, // kapalı durumda
    SSTAT_ON, // aktif durumda
    SSTAT_ONPROCESS, // işlemde
    SSTAT_END, // sonlandı
    SSTAT_LEAK, // güvenlik açığı
    SSTAT_NOCOMMAND // geçerli komut yok
} SimpletronStatus;

// Simpletron Komutları
typedef enum SimpletronCommand
{
    SCOMM_READ = 0X0A, // okuma
    SCOMM_WRITE = 0X0B, // yazma
    SCOMM_LOAD = 0X14, // yükleme
    SCOMM_STORE = 0x15, // depolama
    SCOMM_ADD = 0X1E, // toplama
    SCOMM_SUBSTRACT = 0X1F, // çıkarma
    SCOMM_DIVIDE = 0X20, // bölme
    SCOMM_MULTIPLY = 0X21, // çarpma
    SCOMM_MOD = 0X22, // mod
    SCOMM_POW = 0X23, // üssü
    SCOMM_BRANCH = 0X28, // kısım/şube
    SCOMM_BRANCHNEG = 0X29, // negatif
    SCOMM_BRANCHZERO = 0X2A, // sıfır
    SCOMM_HALT = 0X2B, // sonlandır
    SCOMM_END = -1 // program veri okumayı sonlandır
} SimpletronCommand;

// Dosya İşlemleri
typedef struct FileStorage
{
    FILE* fileAddr; // dosya adresi
    vstring fileName; // dosya adı
    vstring fileOpen; // dosya açma
    FileJob fileJob; // dosya işlemi
    abool fileStatus; // dosya durumu
    abool(*open)(struct FileStorage**); // dosya açma
    abool(*close)(struct FileStorage**); // dosya kapatma
    abool(*status)(const FILE** const); // dosya durumu
    abool(*process)(struct FileStorage*); // dosya işlemi
} FileStorage;

// Simpletron Belleği
typedef struct SimpletronMemory
{
    int code; // komut değeri
    int operand; // bellek konumu
} SimpletronMemory;

// Simpletron Bellek Hücresi
typedef struct SimpletronMemCell
{
    float cell; // bellek hücresi
} SimpletronMemCell;

// Simpletron Fonksiyonları
typedef struct SimpletronFunction
{
    // Simpletron Function Yapısına Ait Fonksiyon tanımları
    void(*read)(float* argMemoryCell);
    void(*write)(const float* argValue);
    void(*load)(float* argAccumulator, const float* argMemValue);
    void(*store)(float* argMemory, const float* argAccumulator);
    void(*add)(float* argAccumulator, const float* argMemValue);
    void(*sub)(float* argAccumulator, const float* argMemValue);
    void(*div)(float* argAccumulator, const float* argMemValue);
    void(*mul)(float* argAccumulator, const float* argMemValue);
    void(*mod)(float* argAccumulator, const float* argMemValue);
    void(*pow)(float* argAccumulator, const float* argMemValue);
    void(*branch)(int* argInscounter, const SimpletronMemory* argSimpletronMem);
    void(*branchneg)(int* argInscounter, const SimpletronMemory* argSimpletronMem, const float* argAccumulator);
    void(*branchzero)(int* argInscounter, const SimpletronMemory* argSimpletronMem, const float* argAccumulator);
} SimpletronFunction;

// Simpletron İşlemleri
typedef struct Simpletron
{
    FileStorage* fileStoragePtr; // dosya işlemleri için
    SimpletronStatus(*simpletron)(struct Simpletron*); // simpletron işlemleri için
    SimpletronFunction simpletronFunction; // simpletron fonksiyonları
    void(*halt)(struct Simpletron* argSimpletron, const uint argSizeSimpletron, const SimpletronMemory* argSimpletronMem, const uint argSizeSimpletronMem, const float* argAccumulator);
    SimpletronStatus simpletronStatus; // simpletron durumu
    SimpletronMemory simpletronMemory; // simpletron belleği yönetimi için
    SimpletronMemCell simpletronMemCell[SIMPLETRON_MAX]; // simpletron bellek hücresi
    const uint const sizeSimpletronMemCell; // simpletron bellek uzunluğu
} Simpletron;

// FileStorage Yapısına Ait Fonksiyon Tanımlamaları
abool procFileOpen(FileStorage** argFileStorage); // dosya açma
abool procFileClose(FileStorage** argFileStorage); // dosya kapatma
abool procFileStatus(const FILE** const argFile); // dosya durumu
abool procFile(FileStorage* argFileStorage); // dosya işlemi

// Simpletron Yapısına Ait Fonksiyon Tanımlamaları
SimpletronStatus processSimpletron(Simpletron* argSimpletron); // simpletron işlemi

// Simpletron Function Yapısına Ait Fonksiyon tanımları
void memRead( // bellek girdi okuyucu
    float* argMemory
);

void memWrite( // bellek değer çıktısı verici
    const float* argValue
);

void memLoad( // bellek yükleyici
    float* argAccumulator,
    const float* argMemValue
);

void memStore( // bellek depolayıcı
    float* argMemory,
    const float* argAccumulator
);

void calcAdd( // toplama
    float* argAccumulator,
    const float* argMemValue
);

void calcSub( // çıkartma
    float* argAccumulator,
    const float* argMemValue
);

void calcDiv( // bölme
    float* argAccumulator,
    const float* argMemValue
);

void calcMul( // çarpma
    float* argAccumulator,
    const float* argMemValue
);

void calcMod( // mod
    float* argAccumulator,
    const float* argMemValue
);

void calcPow( // üs
    float* argAccumulator,
    const float* argMemValue
);

void branch( // dallanma
    int* argInscounter,
    const SimpletronMemory* argSimpletronMem
);

void branchNeg( // negatif dallanma
    int* argInscounter,
    const SimpletronMemory* argSimpletronMem,
    const float* argAccumulator
);

void branhZero( // nötr dallanma
    int* argInscounter,
    const SimpletronMemory* argSimpletronMem,
    const float* argAccumulator
);

void halt( // çıktı
    Simpletron* argSimpletron,
    const uint argSizeSimpletron,
    const SimpletronMemory* argSimpletronMem,
    const uint argSizeSimpletronMem,
    const float* argAccumulator
);

// main
int main(void)
{
    // Dosya türü tanımlama
    FileStorage fileSimpletron =
    {
        .fileAddr = NULL, // dosya boş
        .fileName = "simpletroncommand.dat", // dosya adı
        .fileOpen = "", // dosya açma türü boş
        .fileJob = -1, // dosyaya veri yazma başlangıçta boş
        .fileStatus = afalse, // dosya durum kapalı çünkü dosya yok
        .open = procFileOpen, // dosya açma fonksiyonu
        .close = procFileClose, // dosya kapama fonksiyonu
        .status = procFileStatus, // dosya durum fonksionu
        .process = procFile // dosya işlem fonksiyonu
    };

    // Simpletron tanımlama
    Simpletron advancedSimpletron =
    {
        .fileStoragePtr = &fileSimpletron, // dosya için
        .simpletron = processSimpletron, // simpletron işlemleri için
        .simpletronStatus = SSTAT_ON, // simpletron aktifleştir
        .simpletronFunction = { // fonksiyon tanımlamaları
            .read = memRead, // oku
            .write = memWrite, // çıktı
            .load = memLoad, // yükle
            .store = memStore, // depola
            .add = calcAdd, // topla
            .sub = calcSub, // çıkar
            .div = calcDiv, // böl
            .mul = calcMul, // çarp
            .mod = calcMod, // mod
            .pow = calcPow, // üssü
            .branch = branch, // dallanma
            .branchneg = branchNeg, // negatif dallanma
            .branchzero = branhZero, // nötr dallanma
        }, // simpletron fonksiyonlar
        .halt = halt, // sonlandırma
        .simpletronMemCell = 0.0, // bellek boş
        .sizeSimpletronMemCell = ( // bellek uzunluğu
            sizeof(advancedSimpletron.simpletronMemCell) /
            sizeof(advancedSimpletron.simpletronMemCell[0])
        )
    };

    // belleğin tamamını temizlemek
    for(int memcounter = 0; memcounter < advancedSimpletron.sizeSimpletronMemCell; memcounter++)
    {
        advancedSimpletron.simpletronMemCell[memcounter].cell = 0.0;
    }

    // Simpletron işlemleri
    advancedSimpletron.simpletronStatus = advancedSimpletron.simpletron(&advancedSimpletron);

    // Simpletron durumuna göre programı sonlandırma
    switch(advancedSimpletron.simpletronStatus)
    {
        // komut yok
        case SSTAT_NOCOMMAND:
            puts("\n* Simpletron Calistirilacak Komut Olmadigi Icin Sonlandiriliyor... *\n");
            return SSTAT_NOCOMMAND;
        // hata
        case SSTAT_FAIL:
            puts("\n\n* Simpletron Hata Sonucu Sonlandi *\n");
            return SSTAT_FAIL;
        // kapalı
        case SSTAT_OFF:
            puts("\n\n* Simpletron Calismiyor, Kapali *\n");
            return SSTAT_OFF;
        // hala açık
        case SSTAT_ON:
            puts("\n\n* Simpletron Sonladirilmadi, Hala Calisiyor... *\n");
            return SSTAT_ON;
        // işlem durumunda
        case SSTAT_ONPROCESS:
            puts("\n\n* Simpletron Hala Islem Durumunda... *\n");
            return SSTAT_ONPROCESS;
        // sonlandı
        case SSTAT_END:
            puts("\n\n* Simpletron Basari Ile Sonlandiriliyor... *\n");
            return SSTAT_END;
        // bilinmeyen durum
        default:
            puts("\n\n* Simpletron Sonlanmasinda Bilinmeyen Durum Olustu *");
            printf("* Simpletron Durum Kodu: %d\n\n", (advancedSimpletron.simpletronStatus));
            return advancedSimpletron.simpletronStatus;
    }
}

// Dosya Açma -> open
abool procFileOpen(FileStorage** argFileStorage)
{
    // dosya boş değilse, hata versin
    if((*argFileStorage)->fileAddr != NULL)
    {
        (*argFileStorage)->fileStatus = afail;
        return (*argFileStorage)->fileStatus;
    }

    // dosyayı açmaya çalışsın
    (*argFileStorage)->fileAddr = fopen((*argFileStorage)->fileName, (*argFileStorage)->fileOpen);

    // dosya boş değilse kontrol
    (*argFileStorage)->fileStatus = ((*argFileStorage)->fileAddr != NULL) ? atrue : afalse;

    // dosya boş değilse doğru, değilse hata
    return ((*argFileStorage)->fileStatus);
}

// Dosya Kapatma -> close
abool procFileClose(FileStorage** argFileStorage)
{
    // dosya boş değilse kapatsın
    if((*argFileStorage)->fileAddr != NULL)
    {
        fclose((*argFileStorage)->fileAddr); // dosyayı kapat
        (*argFileStorage)->fileAddr = NULL; // hiçbir dosyaya ulaşmadığını belirt
    }

    return ((*argFileStorage)->fileAddr == NULL ? atrue : afalse); // dosya zaten boş
}

// Dosya Durumu -> status
abool procFileStatus(const FILE** const argFile)
{
    // dosya boş değilse var, yoksa yok
    return (*argFile != NULL ? atrue : afalse);
}

// Dosya İşlem -> process
abool procFile(FileStorage* argFileStorage)
{
    // açık dosya varsa kapatma
    if(((argFileStorage)->fileStatus = (argFileStorage)->close(&argFileStorage)) != atrue)
    {
        // dosya durumunu hataya ayarla, çıktı ver ve durumunu döndür
        (argFileStorage)->fileStatus = afail;
        printf("\n* \"%s\" Dosya Basari Ile Kapatilamadi *\n\n", ((argFileStorage)->fileName));
        return (argFileStorage)->fileStatus;
    }

    // dosya işlem türüne göre dosya açma şeklini belirlesin
    switch((argFileStorage)->fileJob)
    {
        // dosyaya veri yazma
        case WRITE_OUTPUT_TO_FILE:
            (argFileStorage)->fileOpen = "w";
            break;
        // dosyadan veri okuma
        case READ_COMMAND_FROM_FILE:
            (argFileStorage)->fileOpen = "r";
            break;
    }

    // dosyayı açıyoruz
    if(((argFileStorage)->fileStatus = (argFileStorage)->open(&argFileStorage)) != atrue)
    {
        // dosya durumunu hataya ayarla, çıktı ver ve durumunu döndür
        (argFileStorage)->fileStatus = afail;
        printf("\n* \"%s\" Dosya Basari Ile Acilamadi *\n\n", ((argFileStorage)->fileName));
        return (argFileStorage)->fileStatus;
    }
}

// Simpletron İşlemleri -> simpletron
SimpletronStatus processSimpletron(Simpletron* argSimpletron)
{
    // bellek için değişkenler
    int commandCounter; // komut sayacı
    int memCounter; // bellek sayacı
    float accumulator = 0.0; // akümülatör

    // Dosya işlem türünü komut okumaya alıyoruz
    argSimpletron->fileStoragePtr->fileJob = READ_COMMAND_FROM_FILE;

    // dosya açma türünü ikili modda yazma/okuma moduna alıyoruz
    argSimpletron->fileStoragePtr->fileOpen = "r";

    // Ilk dosya açma işlemlerini yapıyoruz
    argSimpletron->fileStoragePtr->process(argSimpletron->fileStoragePtr);

    // geçici simpletron bellek depolayıcı yapısı
    SimpletronMemory tempSimpletronMem;

    // komut okuyan sayaç için kontrolcü
    abool tempReadEnd = afalse;

    // dosyanın başına alıyoruz
    fseek(argSimpletron->fileStoragePtr->fileAddr, 0, SEEK_SET);

    // satır miktarını saymak için sayaçla kontrol ediyoruz
    for(commandCounter = 0; !feof(argSimpletron->fileStoragePtr->fileAddr) && tempReadEnd != atrue; commandCounter++)
    {
        // komut ve işlemi al, bellekte depola
        fscanf(argSimpletron->fileStoragePtr->fileAddr, "%2d%4d",
            &tempSimpletronMem.code,
            &tempSimpletronMem.operand
        );

        // kod işlem türü kontrolü
        switch(tempSimpletronMem.code)
        {
            // Simpletron Komutları
            case SCOMM_READ:
            case SCOMM_WRITE:
            case SCOMM_LOAD:
            case SCOMM_STORE:
            case SCOMM_ADD:
            case SCOMM_SUBSTRACT:
            case SCOMM_DIVIDE:
            case SCOMM_MULTIPLY:
            case SCOMM_MOD:
            case SCOMM_POW:
            case SCOMM_BRANCH:
            case SCOMM_BRANCHNEG:
            case SCOMM_BRANCHZERO:
            case SCOMM_HALT:                
                break;
            case SCOMM_END: // komut girişi sonlandırma
                tempReadEnd = atrue;
                commandCounter--;
                break;
            default:
                // geçersiz komut ya da sonlandırma
                commandCounter--;
        }
    }

    // eğer hiç komut yoksa sonlansın
    if(commandCounter < 1)
        return SSTAT_NOCOMMAND;

    // Simpletron işlemlerini tutacak depolayıcı
    SimpletronMemory arrSimpletronMem[commandCounter];
    const uint sizeArrSimpletronMem = (sizeof(arrSimpletronMem) / sizeof(arrSimpletronMem[0]));

    // komut girişi sıfırlama
    tempReadEnd = afalse;

    // dosyanın başına alıyoruz
    fseek(argSimpletron->fileStoragePtr->fileAddr, 0, SEEK_SET);

    // dosyanın sonuna kadar satıra veri okusun
    for(commandCounter = 0; !feof(argSimpletron->fileStoragePtr->fileAddr) && tempReadEnd != atrue; commandCounter++)
    {
        // komut ve işlemi al, bellekte depola
        fscanf(argSimpletron->fileStoragePtr->fileAddr, "%2d%4d",
            &tempSimpletronMem.code,
            &tempSimpletronMem.operand
        );

        // geçerli kod varsa eğer, geçici komut belleğine kaydetsin
        switch(tempSimpletronMem.code)
        {
            case SCOMM_READ:
            case SCOMM_WRITE:
            case SCOMM_LOAD:
            case SCOMM_STORE:
            case SCOMM_ADD:
            case SCOMM_SUBSTRACT:
            case SCOMM_DIVIDE:
            case SCOMM_MULTIPLY:
            case SCOMM_MOD:
            case SCOMM_POW:
            case SCOMM_BRANCH:
            case SCOMM_BRANCHNEG:
            case SCOMM_BRANCHZERO:
            case SCOMM_HALT:
                // komutu kaydetsin
                arrSimpletronMem[commandCounter].code = tempSimpletronMem.code;
                arrSimpletronMem[commandCounter].operand = tempSimpletronMem.operand;
                break;
            case SCOMM_END: // komut girişi sonlandırma
                tempReadEnd = atrue;
                commandCounter--;
                break;
            default:
                // geçersiz komut ya da sonlandırma
                commandCounter--;
        }
    }

    // komutları çalıştırsın
    for(commandCounter = 0; commandCounter < sizeArrSimpletronMem; commandCounter++)
    {
        // kod işlem türü kontrolü
        switch(arrSimpletronMem[commandCounter].code)
        {
            // Simpletron Komutları
            case SCOMM_READ:
                argSimpletron->simpletronFunction.read(
                    &argSimpletron->simpletronMemCell[
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_WRITE:
                argSimpletron->simpletronFunction.write(
                    &argSimpletron->simpletronMemCell[
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_LOAD:
                argSimpletron->simpletronFunction.load(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_STORE:
                argSimpletron->simpletronFunction.store(
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell,
                    &accumulator // akümülatör
                );
                break;
            case SCOMM_ADD:
                argSimpletron->simpletronFunction.add(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_SUBSTRACT:
                argSimpletron->simpletronFunction.sub(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_DIVIDE:
                argSimpletron->simpletronFunction.div(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_MULTIPLY:
                argSimpletron->simpletronFunction.mul(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_MOD:
                argSimpletron->simpletronFunction.mod(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_POW:
                argSimpletron->simpletronFunction.pow(
                    &accumulator, // akümülator adresi
                    &argSimpletron->simpletronMemCell[ // bellek hücresi adresi
                        (arrSimpletronMem[commandCounter].operand - 1)
                    ].cell
                );
                break;
            case SCOMM_BRANCH:
                argSimpletron->simpletronFunction.branch(
                    &commandCounter, // komut okuma sayacı
                    &arrSimpletronMem[commandCounter] // bellek komut adresi
                );
                break;
            case SCOMM_BRANCHNEG:
                argSimpletron->simpletronFunction.branchneg(
                    &commandCounter, // komut okuma sayacı
                    &arrSimpletronMem[commandCounter], // bellek komut adresi
                    &accumulator // akümülatör
                );
                break;
            case SCOMM_BRANCHZERO:
                argSimpletron->simpletronFunction.branchzero(
                    &commandCounter, // komut okuma sayacı
                    &arrSimpletronMem[commandCounter], // bellek komut adresi
                    &accumulator // akümülatör
                );
                break;
            case SCOMM_HALT:
                argSimpletron->halt(
                    argSimpletron, // bellek hücresi
                    (argSimpletron->sizeSimpletronMemCell), // bellek hücresi boyutu
                    &arrSimpletronMem[0], // bellek komutları
                    (sizeof(arrSimpletronMem) / sizeof(arrSimpletronMem[0])), // bellek komutları miktarı
                    &accumulator // akümülatör
                );
                break;
            case SCOMM_END:
                tempReadEnd = atrue;
                return SSTAT_END;
            default:
                puts("\n* Komut Islemlerinde Guvenlik Acigi*");
                printf("* Bilinmeyen Islem Kodu: \"%d\" *\n\n", (tempSimpletronMem.code));
                return SSTAT_LEAK;
        }
    }

    // başarılı sonlandırma
    return SSTAT_END;
}

// memRead
void memRead(float* argMemory)
{
    printf("? Deger giriniz: ");
    scanf("%f", argMemory);
}

// memWrite
void memWrite(const float* argValue)
{
    printf("* Deger: %.2f\n", *argValue);
}

// memLoad
void memLoad(float* argAccumulator, const float* argMemValue)
{
    *argAccumulator = *argMemValue;
}

// memStore
void memStore(float* argMemory, const float* argAccumulator)
{
    *argMemory = *argAccumulator;
}

// calcAdd
void calcAdd(float* argAccumulator, const float* argMemValue)
{
    *argAccumulator += *argMemValue;
}

// calcSub
void calcSub(float* argAccumulator, const float* argMemValue)
{
    *argAccumulator -= *argMemValue;
}

// calcDiv
void calcDiv(float* argAccumulator, const float* argMemValue)
{
    if(*argAccumulator == 0 || *argMemValue == 0)
    {
        // hata mesajı ve son
        puts("\n* Bolme Islemci Icin 0 Degeri Kabul Edilemez! *\n");
        return;
    }

    *argAccumulator /= *argMemValue;
}

// calcMul
void calcMul(float* argAccumulator, const float* argMemValue)
{
    *argAccumulator *= *argMemValue;
}

// calcMod
void calcMod(float* argAccumulator, const float* argMemValue)
{
    *argAccumulator = (int)*argAccumulator % (int)*argMemValue;
}

// calcPow
void calcPow(float* argAccumulator, const float* argMemValue)
{
    // üs 0 ise ve taban 0'dan büyük ise 1 olur
    if(*argAccumulator > 0 && *argMemValue == 0)
    {
        *argAccumulator = 1;
        return;
    }
    // eğer ikisi de 0 ise
    else if(*argAccumulator == 0 && *argMemValue == 0)
    {
        puts("\n* Ussu Hesaplamak Icın Taban Ve Us 0 Olamaz! *\n");
        return;
    }
    // eğer üs 0'dan büyük ise fakat taban 0 ise sonuç 0 olur
    else if(*argAccumulator > 0 && *argMemValue == 0)
    {
        *argAccumulator = 0;
        return;
    }

    // üs hesaplama
    float tempValue = *argAccumulator;
    uint counter; // üs için sayaç

    for(counter = 2; counter < *argMemValue; counter++)
    {
        *argAccumulator *= (tempValue);
    }
}

// branch
void branch(int* argInscounter, const SimpletronMemory* argSimpletronMem)
{
    *argInscounter = (*argSimpletronMem).operand;
}

// branchNeg
void branchNeg(int* argInscounter, const SimpletronMemory* argSimpletronMem, const float* argAccumulator)
{
    if(*argAccumulator < 0.0)
        *argInscounter = ((*argSimpletronMem).operand - 1);
}

// branchZero
void branhZero(int* argInscounter, const SimpletronMemory* argSimpletronMem, const float* argAccumulator)
{
    if(*argAccumulator == 0.0)
        *argInscounter = ((*argSimpletronMem).operand - 1);
}

// halt
void halt(Simpletron* argSimpletron, const uint argSizeSimpletron, const SimpletronMemory* argSimpletronMem, const uint argSizeSimpletronMem, const float* argAccumulator)
{
    // açık dosya varsa kapatıyoruz ve yeni dosya açıyoruz
    argSimpletron->fileStoragePtr->close(
        &argSimpletron->fileStoragePtr
    );

    // dosyayı varolan verinin sonrasından devam edicek şekilde ayarlıyoruz
    argSimpletron->fileStoragePtr->fileJob = WRITE_OUTPUT_TO_FILE;
    argSimpletron->fileStoragePtr->fileName = "simpletronoutput.dat";
    argSimpletron->fileStoragePtr->fileOpen = "a+";
    argSimpletron->fileStoragePtr->fileStatus = afalse;

    // yeni dosya açıp kaydedeceğiz
    argSimpletron->fileStoragePtr->open(
        &argSimpletron->fileStoragePtr
    );

    ///////////////////////////
    // Bilgileri dosyaya yazmak
    ///////////////////////////
    fputs("\nREGISTERS\n", argSimpletron->fileStoragePtr->fileAddr);
    fprintf(argSimpletron->fileStoragePtr->fileAddr, "Accumulator: %05.2f\n", *argAccumulator);
    fprintf(argSimpletron->fileStoragePtr->fileAddr,
        "Instruction Counter: %2d%04d\n",
        (argSimpletronMem + (argSizeSimpletronMem - 1))->code,
        (argSimpletronMem + (argSizeSimpletronMem - 1))->operand
    );

    fprintf(argSimpletron->fileStoragePtr->fileAddr, "Instruction Register: %d\n", (argSizeSimpletronMem));
    fprintf(argSimpletron->fileStoragePtr->fileAddr, "Code: %02d\n", (argSimpletronMem + (argSizeSimpletronMem - 1))->code);
    fprintf(argSimpletron->fileStoragePtr->fileAddr, "Operand: %04d\n", (argSimpletronMem + (argSizeSimpletronMem - 1))->operand);
    fputs("\nMEMORY\n", argSimpletron->fileStoragePtr->fileAddr);

    ///////////////////////////
    // Kullanıcı için çıktı
    ///////////////////////////
    puts("\nREGISTERS");
    printf("\nAccumulator: %05.2f\n", *argAccumulator);
    printf("Instruction Counter: %2d%04d\n",
        (argSimpletronMem + (argSizeSimpletronMem - 1))->code,
        (argSimpletronMem + (argSizeSimpletronMem - 1))->operand
    );
    printf("Instruction Register: %d\n", (argSizeSimpletronMem));
    printf("Code: %02d\n", (argSimpletronMem + (argSizeSimpletronMem - 1))->code);
    printf("Operand: %04d\n", (argSimpletronMem + (argSizeSimpletronMem - 1))->operand);

    // Bellek sütunlarını belli etmek
    puts("\nMEMORY");

    // sayaçlar ile çıktı vermek
    uint rowCounter; // satır sayacı
    uint colCounter; // sütun sayacı

    // satır uzunluğunu hesaplamak
    const uint sizeRow = (argSizeSimpletron / OUTPUT_COLUMN);
    
    // satır numarası geleceği için başına boşluk koymak
    fprintf(argSimpletron->fileStoragePtr->fileAddr, "%6s", " ");

    // kullanıcı okuyabilmesi için satır başına boşluk koymak
    printf("%6s", " ");

    // sütun numaralarını yazdırmak
    for(colCounter = 0; colCounter < OUTPUT_COLUMN; colCounter++)
    {
        // sütun numaralarını dosyaya kaydetsin
        fprintf(
            argSimpletron->fileStoragePtr->fileAddr,
            "%3d%6s", (colCounter + 1),
            " "
        );

        // kullanıcı için sütun numaralarını çıktı versin
        printf("%3d%6s", (colCounter + 1)," ");
    }

    // satır satır veriyi yazdırmak
    for(rowCounter = 0; rowCounter < sizeRow; rowCounter++)
    {
        fprintf(argSimpletron->fileStoragePtr->fileAddr, "\n%3d| ", (rowCounter + 1)); // dosyaya kaydetsin
        printf("\n%3d| ", (rowCounter + 1)); // kullanıcı için ekrana çıktı versin

        // sütun miktarı kadar dönsün
        for(colCounter = 0; colCounter < OUTPUT_COLUMN; colCounter++)
        {
            // dosyaya kaydetsin
            fprintf(argSimpletron->fileStoragePtr->fileAddr,
                "%08.2f ",
                (argSimpletron->simpletronMemCell[(rowCounter * OUTPUT_COLUMN) + colCounter].cell)
            );

            // kullanıcı için ekrana çıktı versin
            printf("%08.2f ",
                (argSimpletron->simpletronMemCell[(rowCounter * OUTPUT_COLUMN) + colCounter].cell)
            );
        }
    }

    // yazma işlemi bitti, boşluk koysun
    fputs("\n", argSimpletron->fileStoragePtr->fileAddr);

    // dosyayı kapat
    argSimpletron->fileStoragePtr->close(
        &argSimpletron->fileStoragePtr
    );

    // başarıyla bitti
    return;
}