// Slavnem @2024-05-12
// Sıralı Rastgele Erişimli Dosya Oluşturma

// Kütüphaneler
#include <stdio.h>

// clientData'niın tanımı yapılıyor
typedef struct
{
    unsigned int acctNum; // hesap numarası
    char lastName[15]; // hesap sahibinin soyadı
    char firstName[15]; // hesap sahibinin adı
    double balance; // hesap bakiyesi
} clientData;

// main
int main(void)
{
    // 1-100 arasında saymak için kullanılacak sayaç
    unsigned int i;

    // clientData default değeri oluşturma
    clientData blankClient = { 0, "", "", 0.0 };

    FILE* cfPtr; // credit.data dosya işaretçisi

    // fopen dosyayı açar, dosya açılmaz ise null değeri döner
    if((cfPtr = fopen("credit.dat", "wb")) == NULL)
    {
        puts("Dosya Acilamadi");
        return 0;
    }

    // dosya da boş 100 kayıt çıktısı
    for(i = 1; i <= 100; i++)
    {
        fwrite(&blankClient, sizeof(clientData), 1, cfPtr);
    }

    // fclose dosya kapatma
    fclose(cfPtr);
}