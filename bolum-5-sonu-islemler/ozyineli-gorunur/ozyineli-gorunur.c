// ÖZYİNELEMEDEKİ ADIMLARI GÖRÜNÜR YAPMAK
#include <stdio.h>

int sayac(int, int, int);

int main(void)
{
    int baslangic, son, enbuyuk, enkucuk;

    do
    {
        printf("Ilk degeri giriniz: ");
        scanf("%d", &baslangic);

        printf("IKinci degeri giriniz: ");
        scanf("%d", &son);

        baslangic > son ? (enbuyuk = baslangic, enkucuk = son) : (enbuyuk = son, enkucuk = baslangic);
    } while (baslangic == son);

    sayac(enkucuk, enbuyuk, 1);
}

int sayac(int kucuk, int buyuk, int tur)
{
    printf("%d (tur %d)\n", kucuk, tur);

    if(kucuk < buyuk)
    {
        return sayac(kucuk+1, buyuk, tur+1);
    }
    else
    {
        return kucuk;
    }
}