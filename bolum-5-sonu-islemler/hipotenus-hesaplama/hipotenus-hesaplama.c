// HİPOTENÜS HESAPLAMA
#include <stdio.h>
#include <math.h>

double hipotenusHesap(double, double);

int main(void)
{
    float kenarHipo1 = 0.0, kenarHipo2 = 0.0;

    while(kenarHipo1 <= 0.0)
    {
        printf("%d. kenari giriniz: ", 1);
        scanf("%f", &kenarHipo1);
    }

    while(kenarHipo2 <= 0.0)
    {
        printf("%d. kenari giriniz: ", 2);
        scanf("%f", &kenarHipo2);
    }

    printf("Hipotenus: %.1f\n", hipotenusHesap(kenarHipo1, kenarHipo2));
}

double hipotenusHesap(double hipo1, double hipo2)
{
    double hipotenus = sqrt(pow(hipo1, 2) + pow(hipo2, 2));
    return hipotenus;
}