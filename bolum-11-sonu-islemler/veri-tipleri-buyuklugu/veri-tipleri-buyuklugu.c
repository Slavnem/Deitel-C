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
    char* fileOpen;
    Job fileJob;
    abool fileStatus;
    abool(*open)(struct FileStore* argFileStore);
    abool(*close)(FILE* argFileAddr);
    abool(*status)(const FILE* const argFileAddr);
    abool(*process)(struct FileStore* argFileStore);
} FileStore;

// Fonksiyon tanımlamaları
abool open(struct FileStore* argFileStore);
abool close(FILE* argFileAddr);
abool status(const FILE* const argFileAddr);
abool process(FileStore* argFileStore);

// main
int main(void)
{
    // Dosya türü tanımlama
    FileStore fileStorage =
    {
        NULL, // boş dosya
        "datasize.dat",
        "w", // başlangıçta dosyayı açacak
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

    // dosyaya veri yazma başarılı oldu
    // şimdi veri okuyacağız
    fileStorage.fileOpen = "r";

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
abool open(FileStore* argFileStorage)
{
    // dosyayı açmaya çalışsın ve boş değilse doğru, değilse hata
    return ((argFileStorage->fileAddr = fopen(argFileStorage->fileName, argFileStorage->fileOpen)) != NULL) ?
        atrue : afalse;
}

// close file
abool close(FILE* argFileAddr)
{
    // dosya kapanmışsa doğru, değilse hata
    return (fclose(argFileAddr) == 0 ? atrue : afalse);
}

// status file
abool status(const FILE* const argFileAddr)
{
    // dosya boş değilse aktif, değilse pasif
    return (argFileAddr != NULL ? atrue : afalse);
}

// process file
abool process(FileStore* argFileStore)
{
    // dosyaya veri yazmak için açıyoruz
    if(argFileStore->open(argFileStore) != atrue)
    {
        // dosya açılamadı
        printf("\n* \"%s\" Dosya Acilamadi *\n", (argFileStore->fileName));
        return afail;
    }

    // dosya işlem türüne göre işlem
    switch(argFileStore->fileJob)
    {
        // dosyaya değişken türlerini yazdırma
        case WRITE_VARTYPES_TO_FILE:
            // konumu dosyanın başına alma
            fseek(argFileStore->fileAddr, 0, SEEK_SET);

            // başlık ekleme
            fprintf(argFileStore->fileAddr, "%-35s %+5s\n", "Veritipleri", "Boyut");

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
            argFileStore->fileStatus = argFileStore->close(argFileStore->fileAddr);
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
                printf(buffer); // okunan bilgiyi çıktı vermek
                fgets(buffer, 50, argFileStore->fileAddr); // bilgiyi dosyadan okumak
            }

            // okuma bitti, dosyayı kapat
            argFileStore->fileStatus = argFileStore->close(argFileStore->fileAddr);
            return argFileStore->fileStatus;
    }

    // dosya durumunu belirleme ve döndürme
    argFileStore->fileStatus = afalse;
    return argFileStore->fileStatus;
}