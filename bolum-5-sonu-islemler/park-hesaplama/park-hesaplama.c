// PARK ÜCRETİ VE SÜRESİ HESAPLAMA
#include <stdio.h>

float calculateChargers(float ucret);
static float toplamSure = 0, toplamUcret = 0;

int main(void)
{
    float araba1 = 25.0, araba2 = 25.0, araba3 = 25.0;

    while(araba1 > 24.0 || araba1 < 0.0)
    {
        printf("%d)Araba toplam park saati giriniz [0.0]:", 1);
        scanf("%f", &araba1);
    }

    while(araba2 > 24.0 || araba2 < 0.0)
    {
        printf("%d)Araba toplam park saati giriniz [0.0]:", 2);
        scanf("%f", &araba2);
    }

    while(araba3 > 24.0 || araba3 < 0.0)
    {
        printf("%d)Araba toplam park saati giriniz [0.0]:", 3);
        scanf("%f", &araba3);
    }

    printf("Araba\tSaat\tUcret\n");
    printf("%d\t%.1f\t%.2f\n", 1, araba1, calculateChargers(araba1));
    printf("%d\t%.1f\t%.2f\n", 2, araba2, calculateChargers(araba2));
    printf("%d\t%.1f\t%.2f\n", 3, araba3, calculateChargers(araba3));
    printf("TOPLAM\t%.2f\t%.2f\n", toplamSure, toplamUcret);
}

float calculateChargers(float saat)
{
    float ucret;

    toplamSure += saat;
    
    if(saat <= 3.00)
    {
        ucret = (saat * 2);
        toplamUcret += ucret;
    }
    else
    {
        ucret = (3.00 * 2) + ((saat - 3.00) * (0.5));
        toplamUcret += ucret;
    }

    return ucret;
}