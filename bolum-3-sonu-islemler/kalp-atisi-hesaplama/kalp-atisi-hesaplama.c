#include <stdio.h>

int main( void )
{
    int yas = 0;
    unsigned int enKalpAtis = 200, hedefKalpAtisALT, hedefKalpAtisUST;

    while(yas <= 0)
    {
        printf("Kalp atisinizi ogrenmek icin yasinizi giriniz: ");
        scanf("%d", &yas);
    }

    if(yas > 0)
    {
        enKalpAtis -= yas;
        hedefKalpAtisALT = (int)(enKalpAtis / 2);
        hedefKalpAtisUST = (int)((enKalpAtis / 10) * 8.5);

        printf("======================================\n");
        printf("Yasiniz: %d\n", yas);
        printf("En fazla kalp atis hizi: %d\n", enKalpAtis);
        printf("Hedef kalp atis hizi (%50-85): %d-%d\n", hedefKalpAtisALT, hedefKalpAtisUST);
        printf("======================================\n");
    }
    else if(yas <= 0)
    {
        printf("Yas 0'a esit veya kucuk oldugu icin program sonlandiriliyor...\n");
        return 0;
    }
    else
    {
        printf("Yas kontrolunde bilinmeyen bir hata olustu! (HATA)\n");
        return 0;
    }
}