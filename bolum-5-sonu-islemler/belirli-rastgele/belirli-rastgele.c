// BELİRLİ RASTGELE SAYI ÜRETMEK
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int belirliRastgele(int, int);

int main(void)
{
    int aralikILK, aralikSON;

    do
    {
        printf("Baslangic araligini giriniz: ");
        scanf("%d", &aralikILK);
    } while(aralikILK < 0);

    do
    {
        printf("Bitis araligini giriniz: ");
        scanf("%d", &aralikSON);
    } while(aralikSON <= aralikILK);

    srand(time(NULL));

    printf("%d-%d arasi rastgele sayi: %d\n", aralikILK, aralikSON, belirliRastgele(aralikILK, aralikSON));
}

int belirliRastgele(int sayiBaslangic, int sayiBitis)
{
    int rastgeleSayi;

    rastgeleSayi = (rand() % (sayiBitis +1));
    rastgeleSayi == 0 ? (rastgeleSayi = sayiBaslangic) : (rastgeleSayi);

    return rastgeleSayi;
}