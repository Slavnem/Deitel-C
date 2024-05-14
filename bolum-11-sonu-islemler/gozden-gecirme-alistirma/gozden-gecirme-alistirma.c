// Slavnem @2024-05-14
// Gözden Geçirme Alıştırma

// Kütüphaneler
#include <stdio.h>

// Yapı tanımlaması
typedef struct
{
    unsigned int hesapNum;
    char* isim;
    double suankiBakiye;
} Kayıt;

typedef struct
{
    unsigned int hesapNum;
    double dolar;
} Kayıtv2;

// main
int main(void)
{
    // Yapı değişkenleri
    FILE *oPtr;
    FILE *nPtr;

    // oldmast.dat dosyasını okuma için aç ve oPtr'ye ata
    oPtr = fopen("oldmast.dat", "r");

    // trans.dat dosyasını okuma için açan ve dönen değeri oPtr'ye kaydetmek
    oPtr = fopen("trans.dat", "r");

    // newmast.dat dosyasını yazma işlemi için açan ve dönen değeri nPtr'ye kaydetmek
    nPtr = fopen("newmast.dat", "w");

    // oldmast.dat dosyasından kayıt okuyan bir ifade
    if((oPtr = fopen("oldmast.dat", "r")) != NULL)
    {
        // kayıt yapısını kullanan değişken oluşturma
        Kayıt yeniKayıt;

        fscanf(oPtr, "%d%s%lf",
            &yeniKayıt.hesapNum, yeniKayıt.isim, yeniKayıt.suankiBakiye);
    }
    
    // oPtr daha kullanmayacağım için eğer açıksa kapatıyorum
    if(oPtr != NULL)
        fclose(oPtr);

    // trans.dat dosyasından kayıt okuyan bir ifade
    if((nPtr = fopen("trans.dat", "r")) != NULL)
    {
        // kayıtv2 yapısını kullanan değişken oluşturma
        Kayıtv2 yeniKayıtv2;

        fscanf(nPtr, "%d%lf",
            &yeniKayıtv2.hesapNum, &yeniKayıtv2.dolar);
    }

    // newmast.dat dosyasına bir kayıt yazan ifade
    if((nPtr = fopen("newmast.dat", "w")) != NULL)
    {
        // kayıt yapısını kullanan değişken oluşturma
        Kayıt yeniKayıt2;

        yeniKayıt2.hesapNum = 9;
        yeniKayıt2.isim = "denemeblabnfqnaw";
        yeniKayıt2.suankiBakiye = 87.65;

        // normal yazma
        fprintf(nPtr, "%05d %-s %-.2f\n",
            yeniKayıt2.hesapNum, yeniKayıt2.isim, yeniKayıt2.suankiBakiye);

        // test çıktısı
        printf("nu: %d | ad: %s | bakiye: %lf\n",
            yeniKayıt2.hesapNum, yeniKayıt2.isim, yeniKayıt2.suankiBakiye);
    }

    // dosya açıksa kapatma
    if(nPtr != NULL)
        fclose(nPtr);
}