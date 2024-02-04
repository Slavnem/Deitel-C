// DEĞERLER İLE ÜS ALMA
#include <stdio.h>

unsigned long long int integerPower(int, int);

int main(void)
{
    int ass, uss;

    do
    {
        printf("Us hesaplama icin taban degeri giriniz: ");
        scanf("%d", &ass);
    } while(ass <= 0);

    do
    {
        printf("Us hesaplama icin ust degeri giriniz: ");
        scanf("%d", &uss);
    } while(uss < 0);

    printf("Taban[%d]-Ust[%d] Us: %llu\n", ass, uss, integerPower(ass, uss));
}

unsigned long long int integerPower(int alt, int ust)
{
    int dongu, usDeger = 1;

    for(dongu = 1; dongu <= ust; dongu++)
    {
        usDeger *= alt;
    }

    return usDeger;
}