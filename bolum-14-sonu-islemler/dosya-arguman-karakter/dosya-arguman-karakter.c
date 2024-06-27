// Slavnem @2024-06-27
// Konsoldan Argüman Olarak Giriş/Çıkış Dosyayı Alıp
// Giriş Dosyasındaki Karakterleri Çıkış Dosyasına Ters Yazdırmak

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// NULL kontrolcü
#ifndef NULLER
#define NULLER(x) (x == NULL)
#endif

// NULL kontrolcü olmak zorunda
#ifndef NULLER
#error "NULL Kontrolcusu Yok!"
#endif

// Değişken isimlendirmeleri
typedef unsigned int uint;
typedef const char* const string;
typedef FILE* fileptr;

// Fonksiyon prototipleri
static void end_save(void);
static void reader_saver(fileptr *infile, fileptr *outfile);

// Giriş/Çıkış dosyaları işaretçileri
static fileptr inputFile = NULL;
static fileptr outputFile = NULL;

// main
int main(uint argc, string argv[])
{
    // program kapandığında son kayıtları tutacak
    atexit(end_save);
    
    // argüanları kontrol edip dosya olup olmadığını kontrol etmek
    if(argc != 3)
    { // 1: program çalıştırma kodu, 2: giriş dosyası, 3: çıkış dosyası
        puts("\n* Dosya islemleri icin konsol argumani olarak <giris dosyasi> <cikis dosyasi> argumanlarini unutmayiniz! *");
        return 0;
    }

    // okunacak dosyayı açsın
    inputFile = fopen(argv[1], "r");

    if(NULLER(inputFile))
    {
        printf("\n\'%s\' Dosyasi Okuma Modunda Acilamadi *\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // çıkış dosyasını açsın
    outputFile = fopen(argv[2], "w");
    
    if(NULLER(outputFile))
    {
        printf("\n\'%s\' Dosyasi Yazma Modunda Acilamadi *\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // dosyaların başına alsın
    fseek(inputFile, 0, SEEK_SET);
    fseek(outputFile, 0, SEEK_SET);

    // dosya okyucu ve kaydedici
    reader_saver(&inputFile, &outputFile);

    return 0; // program sonu
}

// end_save -> son kayıt
static void end_save(void)
{
    // dosyalar açıksa kapatsın
    !NULLER(inputFile) ? fclose(inputFile) : 0;
    !NULLER(outputFile) ? fclose(outputFile) : 0;

    // dosyaların kapatıldığına ve bellek adreslerinin temizlendiğine dair çıktı
    puts("\n* Acik Dosyalar Basariyla Kapatildi *");

    exit(EXIT_SUCCESS); // başaryıla sonlandırsın
}

// reader_saver -> okuyucu ve kaydedici
static void reader_saver(fileptr *infile, fileptr *outfile)
{
    // karakteri geçici olarak depolasın
    char tempc = fgetc(*infile);

    // dosya sonu gelmedikçe özyineli olarak devam etsin
    if(tempc != EOF)
    {
        // karakter bitene kadar kendisini döndürsün
        reader_saver(&(*infile), &(*outfile));
        
        // EOF haric karakteri dosyaya kaydetsin
        fputc(tempc, (*outfile));
    }
}