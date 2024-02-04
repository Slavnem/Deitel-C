#include <stdio.h>

int main( void )
{
    int faktoriyel;
    unsigned int faktoplam = 1;

    printf("Faktoriyelini hesaplamak istediginiz sayiyi giriniz: ");
    scanf("%d", &faktoriyel);

    while(faktoriyel < 0)
    {
        printf("Negatif sayilarin faktoriyeli hesaplanamaz! (HATA)\n");
        printf("Faktoriyelini hesaplamak istediginiz sayiyi giriniz: ");
        scanf("%d", &faktoriyel);
    }

    for(int i = 1; i <= faktoriyel; i++)
    {
        faktoplam *= i;
    }

    printf("=========================================\n");
    printf("Girilen sayi: %d\n", faktoriyel);
    printf("Girilen sayinin faktoriyeli: %d\n", faktoplam);
    printf("=========================================\n");
}