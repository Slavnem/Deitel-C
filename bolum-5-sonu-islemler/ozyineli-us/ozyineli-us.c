// FONKSİYONU ÖZYİNELEME İLE ÜS BULMA
#include <stdio.h>

unsigned long long int ozus(int, int, unsigned long long int);

int main(void)
{
    int oztaban, ozust;

    do
    {
        printf("Taban icin sayi giriniz [+]: ");
        scanf("%d", &oztaban);
    } while (oztaban <= 0);

    do
    {
        printf("Ust icin sayi giriniz [0, +]: ");
        scanf("%d", &ozust);
    } while (ozust < 0);
    
    printf("%d ussu %d: %llu\n", oztaban, ozust, ozus(oztaban, ozust, 1));
}

unsigned long long int ozus(int taban, int ust, unsigned long long int sonuc)
{
    if(ust > 0)
    {
        sonuc *= taban;
        ozus(taban, ust-1, sonuc);
    }
    else
    {
        return sonuc;
    }
}