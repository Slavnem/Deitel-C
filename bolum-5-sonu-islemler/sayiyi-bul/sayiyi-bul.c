// KULLANICIDAN RASTGELE VERİLEN SAYIYI BULMASINI İSTEMEK
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int bulmaca(unsigned int, unsigned int);

int main(void)
{
    unsigned int bul;
    int tahmin, altsayi, ustsayi, tekrar;

    srand(time(NULL));

    do
    {
        do
        {
            puts("{Negatif Sayi Kabul Edilmiyor}");
            puts("{Alt Sinir Ust Sinirdan Buyuk Olamaz ve Aralarindaki Fark En Az 2 Olmalidir!}");
            printf("Alt sinir sayisini giriniz: ");
            scanf("%d", &altsayi);

            printf("Ust sinir sayisini giriniz: ");
            scanf("%d", &ustsayi);
        } while (altsayi < 0 || ustsayi < 0 || altsayi >= ustsayi || (altsayi += 1) >= ustsayi);


        bul = bulmaca(altsayi, ustsayi);

        do
        {
            printf("Tahmin giriniz: ");
            scanf("%d", &tahmin);

            while(tahmin < 0)
            {
                printf("Sayi negatif olamaz! Tahmin giriniz: ");
                scanf("%d", &tahmin);
            }

            if(tahmin < bul)
            {
                printf("Girdiginiz sayiyi daha buyuk yaziniz :)\n");
            }
            else
            {
                printf("Girdiginiz sayiyi daha kucuk yaziniz :)\n");
            }
        } while (tahmin != bul);

        if(tahmin == bul)
        {
            printf("Tebrikler! Dogru sayiyi [%u] buldunuz!\n", bul);
        }

        tekrar = -1;
        while (tekrar < 0 || tekrar > 1)
        {
            printf("Tekrar denemek ister misiniz (evet: 1, hayir: 0): ");
            scanf("%d", &tekrar);
        }
    } while(tekrar != 0 && tekrar == 1);
}

unsigned int bulmaca(unsigned int altsinir, unsigned int ustsinir)
{
    unsigned int istenilen;

    do
    {
        istenilen = rand() % ustsinir;
    }
    while (istenilen < altsinir);

    return istenilen;
}