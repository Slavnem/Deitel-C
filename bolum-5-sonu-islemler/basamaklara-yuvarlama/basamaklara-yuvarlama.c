// GİRİLEN SAYIYI EN YAKIN BİRLER, ONLAR, YÜZLER VE BİNLER BASAMAĞINA YUVARLAMAK
#include <stdio.h>

unsigned long long int yuvarlaDongu(int);

/*int yuvarlaBirlik(int);
int yuvarlaOnluk(int);
int yuvarlaYuzluk(int);
int yuvarlaBinlik(int);*/

int main(void)
{
    int sayiBirler, sayiOnlar, sayiYuzler, sayiBinler;

    do
    {
        printf("Birler basamagina yuvarlamak icin sayi giriniz: ");
        scanf("%d", &sayiBirler);
    } while (sayiBirler <= 0 || sayiBirler >= 10);

    do
    {
        printf("Onlar basamagina yuvarlamak icin sayi giriniz: ");
        scanf("%d", &sayiOnlar);
    } while (sayiOnlar <= 10 || sayiOnlar >= 100);

    do
    {
        printf("Yuzler basamagina yuvarlamak icin sayi giriniz: ");
        scanf("%d", &sayiYuzler);
    } while (sayiYuzler <= 100 || sayiYuzler >= 1000);

    do
    {
        printf("Binler basamagina yuvarlamak icin sayi giriniz: ");
        scanf("%d", &sayiBinler);
    } while (sayiBinler <= 1000 || sayiBinler >= 10000);

    printf("%d yuvarlandi: %d\n", sayiBirler, yuvarlaDongu(sayiBirler));
    printf("%d yuvarlandi: %d\n", sayiOnlar, yuvarlaDongu(sayiOnlar));
    printf("%d yuvarlandi: %d\n", sayiYuzler, yuvarlaDongu(sayiYuzler));
    printf("%d yuvarlandi: %d\n", sayiBinler, yuvarlaDongu(sayiBinler));
}

/* PRATİK VE ÇOK KULLANIŞLI HESAPLAYICI FORMÜL */
unsigned long long int yuvarlaDongu(int sadeDongu)
{
    int don;
    int yedekdon = 0;
    unsigned int sinir;
    unsigned int sonuc;

    for(don = 1; sadeDongu % don != sadeDongu; don *= 10)
    {
        don < 10 ? (yedekdon = 0) : (yedekdon += (don / 10));
    }

    sinir = ((4 * (don / 10)) + yedekdon * 9);

    sadeDongu > sinir ? (sonuc = don) : (sonuc = don / 10);
    sonuc < 10 ? (sonuc = 0) : (sonuc);

    // test
    //printf("2Bas-%d\tsinir-%d\tsonuc-%d\tdon-%d\n", sadeIkinciDonguBasamak, sinir, sonuc, don);

    return sonuc;
}

/* ALTERNATİF VE SÜREKLİ DEĞER İSTEYEN HESAPALYICI FORMÜL */
/*int yuvarlaBirlik(int sadeBirlik)
{
    sadeBirlik > 4 ? (sadeBirlik = 10) : (sadeBirlik = 0);
    return sadeBirlik;
}

int yuvarlaOnluk(int sadeOnluk)
{
    int onlukSadeBasamak = sadeOnluk / 10;
    int birlikSadeBasamak = sadeOnluk % 10;

    birlikSadeBasamak > 4 ? (birlikSadeBasamak = 10) : (birlikSadeBasamak = 0);

    return ((onlukSadeBasamak * 10) + birlikSadeBasamak);
}

int yuvarlaYuzluk(int sadeYuzluk)
{
    int yuzlukSadeBasamak = sadeYuzluk / 100;
    int onlukSadeBasamak = sadeYuzluk % 100;

    onlukSadeBasamak > 49 ? (onlukSadeBasamak = 100) : (onlukSadeBasamak = 0);

    return ((yuzlukSadeBasamak * 100) + onlukSadeBasamak);
}

int yuvarlaBinlik(int sadeBinlik)
{
    int binlikSadeBasamak = sadeBinlik / 1000;
    int yuzlukSadeBasamak = sadeBinlik % 1000;

    yuzlukSadeBasamak > 499 ? (yuzlukSadeBasamak = 1000) : (yuzlukSadeBasamak = 0);

    return ((binlikSadeBasamak * 1000) + yuzlukSadeBasamak);
}*/