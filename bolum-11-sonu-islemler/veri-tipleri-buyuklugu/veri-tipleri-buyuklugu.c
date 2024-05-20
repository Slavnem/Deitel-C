// Slavnem @2024-05-19
// Veri Tipleri Büyüklüğü

// Kütüphaneler
#include <stdio.h>

// Veri tipelri tanımlamaları
typedef unsigned char uchar;
typedef short int s2int;
typedef unsigned short int us2int;
typedef unsigned int u4int;
typedef long int l4int;
typedef unsigned long int ul4int;
typedef long double l16double;
typedef const char* const string; // sabit metin
typedef char* vstring; // değiştirilebilir metin
typedef const unsigned int const cu4int; // değiştirilemeyen tamsayı

// isimlerini dizi de tutmak
string __VariableNames[] =
{
    "char",
    "unsigned char",
    "short int",
    "unsigned short int",
    "int",
    "unsigned int",
    "long int",
    "unsigned long int",
    "float",
    "double",
    "long double"
};

// boyularını dizide tutmak
u4int __VariableSizes[sizeof(__VariableNames) / sizeof(__VariableNames[0])] =
{
    sizeof(char),
    sizeof(uchar),
    sizeof(s2int),
    sizeof(us2int),
    sizeof(int),
    sizeof(u4int),
    sizeof(l4int),
    sizeof(ul4int),
    sizeof(float),
    sizeof(double),
    sizeof(l16double)
};

// dizilerin boyutları
cu4int __sizeNamesPtr = (unsigned int)(sizeof(__VariableNames) / sizeof(__VariableNames[0]));
cu4int __sizeVariablesPtr = (unsigned int)(sizeof(__VariableSizes) / sizeof(__VariableSizes[0]));

typedef char abool; // gelişmiş bool türü (advanced bool)

// Gelişmiş doğrulama
#define afail -1
#define afalse 0
#define atrue 1

typedef enum Job
{
    WRITE_VARTYPES_TO_FILE = 1, // değişken türlerini dosyaya yaz
    READ_VARTYPES_FROM_FILE // değişken türlerini dosyadan oku
} Job;

typedef struct FileStore
{
    FILE* fileAddr;
    string fileName;
    vstring fileOpen;
    Job fileJob;
    abool fileStatus;
    abool(*open)(struct FileStore** argFileStore);
    abool(*close)(FILE** argFileAddr);
    abool(*status)(const FILE** const argFileAddr);
    abool(*process)(struct FileStore* argFileStore);
} FileStore;

// Fonksiyon tanımlamaları
abool open(struct FileStore** argFileStore);
abool close(FILE** argFileAddr);
abool status(const FILE** const argFileAddr);
abool process(FileStore* argFileStore);

// main
int main(void)
{
    // Dosya türü tanımlama
    FileStore fileStorage =
    {
        NULL, // boş dosya
        "datasize.dat",
        NULL, // başlangıçta dosya açma türü boş
        WRITE_VARTYPES_TO_FILE, // dosyaya yapılacak işlem türü
        afalse, // dosya yok bu yüzden kapalı
        open, // dosya açma fonksiyonu
        close, // dosya kapama fonksiyonu
        status, // dosya durumu fonksiyonu
        process // dosya işlemi
    };

    // dosyayı veri yazma işlemine sokuyoruz
    fileStorage.process(&fileStorage);

    // dosya işlemi yaptırıyoruz ve dönüş kontrolü yapıyoruz
    switch((abool)fileStorage.fileStatus)
    {
        case afail: // işlem hatalı
            puts("\n* Dosyaya Veri Yazma Islemi Hata Verdi *\n");
            return (int)afail;
        case afalse: // işlem başarısız
            puts("\n* Dosyaya Veri Yazma Islemi Basarisiz Oldu *\n");
            return (int)afalse;
        case atrue:
            puts("\n* Dosyaya Veri Yazma Basarili *\n");
            break;
    }

    // dosyadan değişken türleri okunacak
    fileStorage.fileJob = READ_VARTYPES_FROM_FILE;

    // veri okuma işlemini çalıştırıyoruz
    fileStorage.process(&fileStorage);

    switch((abool)fileStorage.fileStatus)
    {
        case afail: // işlem hatalı
            puts("\n* Dosyadan Veri Okuma Islemi Hata Verdi *\n");
            return (int)afail;
        case afalse: // işlem başarısız
            puts("\n* Dosyadan Veri Okuma Islemi Basarisiz Oldu *\n");
            return (int)afalse;
        case atrue:
            puts("\n* Dosyadan Veri Okuma Basarili *\n");
            break;
    }

    // programı başarıyla sonlandırıyoruz
    return (int)atrue;
}

// open file
abool open(FileStore** argFileStorage)
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

// close file
abool close(FILE** argFileAddr)
{
    // dosya boş değilse kapatsın
    if((*argFileAddr) != NULL)
    {
        fclose((*argFileAddr)); // dosyayı kapat
        (*argFileAddr) = NULL; // hiçbir dosyaya ulaşmadığını belirt
    }

    return ((*argFileAddr) == NULL ? atrue : afalse); // dosya zaten boş
}

// status file
abool status(const FILE** const argFileAddr)
{
    // dosya boş değilse aktif, değilse pasif
    return ((*argFileAddr) != NULL ? atrue : afalse);
}

// process file
abool process(FileStore* argFileStore)
{
    // açık dosya varsa kapatma
    if((argFileStore->fileStatus = argFileStore->close(&argFileStore->fileAddr)) != atrue)
    {
        // dosya durumunu hataya ayarla, çıktı ver ve durumunu döndür
        argFileStore->fileStatus = afail;
        printf("\n* \"%s\" Dosya Basari Ile Kapatilamadi *\n\n", (argFileStore->fileName));
        return argFileStore->fileStatus;
    }

    // dosya işlem türüne göre dosya açma şeklini belirlesin
    switch(argFileStore->fileJob)
    {
        // dosyaya veri yazma
        case WRITE_VARTYPES_TO_FILE:
            argFileStore->fileOpen = "w";
            break;
        // dosyadan veri okuma
        case READ_VARTYPES_FROM_FILE:
            argFileStore->fileOpen = "r";
            break;
    }

    // dosyayı açıyoruz
    if((argFileStore->fileStatus = argFileStore->open(&argFileStore)) != atrue)
    {
        // dosya durumunu hataya ayarla, çıktı ver ve durumunu döndür
        argFileStore->fileStatus = afail;
        printf("\n* \"%s\" Dosya Basari Ile Acilamadi *\n\n", (argFileStore->fileName));
        return argFileStore->fileStatus;
    }

    // dosya işlem türüne göre işlem
    switch(argFileStore->fileJob)
    {
        // dosyaya değişken türlerini yazdırma
        case WRITE_VARTYPES_TO_FILE:
            // konumu dosyanın başına alma
            fseek(argFileStore->fileAddr, 0, SEEK_SET);

            // başlık ekleme
            fprintf(argFileStore->fileAddr, "%-35s %5s\n", "Veritipleri", "Boyut");

            // döngü ile değişken isimlerini ve boyutlarını yazdırma
            for(int counter = 0; counter < __sizeNamesPtr && counter < __sizeVariablesPtr; counter++)
            {
                // dosyaya veriyi yaz
                fprintf(argFileStore->fileAddr, "%-35s %5d\n",
                    __VariableNames[counter],
                    __VariableSizes[counter]
                );
            }

            // yazma bitti, dosyayı kapat
            argFileStore->fileStatus = argFileStore->close(&argFileStore->fileAddr);
            return argFileStore->fileStatus;
        // dosyadan veri türlerini okuyup çıktı verme
        case READ_VARTYPES_FROM_FILE:
            // başlık verisi için
            char buffer[50];

            // dosya konumunu dosya başına alma
            fseek(argFileStore->fileAddr, 0, SEEK_SET);

            // başlık verisini okuyoruz
            fgets(buffer, 50, argFileStore->fileAddr);

            // döngü ile dosyanın kalanını çıktı verme
            while(!feof(argFileStore->fileAddr))
            {
                printf("%s", buffer); // okunan bilgiyi çıktı vermek
                fgets(buffer, 50, argFileStore->fileAddr); // bilgiyi dosyadan okumak
            }

            // okuma bitti, dosyayı kapat
            argFileStore->fileStatus = argFileStore->close(&argFileStore->fileAddr);
            return argFileStore->fileStatus;
    }

    // dosya durumunu belirleme ve döndürme
    argFileStore->fileStatus = afalse;
    return argFileStore->fileStatus;
}