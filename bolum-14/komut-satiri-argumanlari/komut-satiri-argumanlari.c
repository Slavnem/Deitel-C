// Slavnem @2024-06-26
// Komut Satırı Argümanları Kullanmak

// Kütüphaneler
#include <stdio.h>

// main
int main(int argc, char* argv[])
{
    FILE *inFilePtr; // input dosya işaretçisi
    FILE *outFilePtr; // output dosya işaretçisi
    int c; // kaynak dosyadan okunan karakterleri tutmak için c değişkenini tanımla

    // komut satır argümanlarının sayısını kontrol et
    if(argc != 3)
    {
        puts("Kullanim: <program adi> <giris dosyasi> <cikis dosyasi>");
        return 0;
    }

    // giriş dosyası açılamıyor ise hatayla sonlandırsın
    if((inFilePtr = fopen(argv[1], "r")) == NULL)
    {
        printf("Okumak icin \"%s\" dosyasi acilamiyor!\n", argv[1]);
        return 0;
    }

    // çıkış dosyası açılamıyor ise hatayla sonlandırsın
    if((outFilePtr = fopen(argv[2], "w")) == NULL)
    {
        printf("\"Yazmak icin \"%s\" dosyasi acilamiyor!\n", argv[2]);
        return 0;
    }

    // karakterleri oku ve ekranda yazdır
    while((c = fgetc(inFilePtr)) != EOF)
    {
        // karakteri dosyaya yaz
        fputc(c, outFilePtr);
    }

    // veri yazılan dosyayı kapat
    fclose(outFilePtr);

    // veri okunan dosyayı kapat
    fclose(inFilePtr);
}