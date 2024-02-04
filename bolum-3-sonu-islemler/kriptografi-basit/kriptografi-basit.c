#include <stdio.h>

void kriptoCoz(int kriptoSayi)
{
    unsigned int cozKrip1, cozKrip2, cozKrip3, cozKrip4, cozBKrip;

    cozKrip1 = ((((kriptoSayi / 10) % 10) + 10) -7) % 10;
    cozKrip2 = ((((kriptoSayi / 1000) % 10) + 10) -7) % 10; 
    cozKrip3 = (((kriptoSayi % 10) + 10) -7) % 10;
    cozKrip4 = ((((kriptoSayi / 100) % 10) + 10) -7) % 10;

    cozBKrip = ((cozKrip4 * 1000) + (cozKrip2 * 100) + (cozKrip3 * 10) + (cozKrip1 * 1));

    printf("=============================\n");
    printf("Cozulmus kripto tekli: %d-%d-%d-%d\n", cozKrip4, cozKrip2, cozKrip3, cozKrip1);
    printf("Cozulmus kripto birlikte: %d\n", cozBKrip);
    printf("=============================\n");
}

int main( void )
{
    int dortBasamakliSayi = 0;
    unsigned int dortBas1, dortBas2, dortBas3, dortBas4, dortKripto;

    while(dortBasamakliSayi < 1000 || dortBasamakliSayi > 9999)
    {
        printf("Dort basamakli sayi giriniz: ");
        scanf("%d", &dortBasamakliSayi);
    }

    if(dortBasamakliSayi > 999 && dortBasamakliSayi < 10000)
    {
        dortBas1 = ((dortBasamakliSayi % 10) + 7) % 10;
        dortBas2 = (((dortBasamakliSayi / 10) % 10) + 7) % 10;
        dortBas3 = (((dortBasamakliSayi / 100) % 10) + 7) % 10;
        dortBas4 = ((dortBasamakliSayi / 1000) + 7) % 10;

        dortKripto = (dortBas3 * 1000) + (dortBas4 * 100) + (dortBas1 * 10) + (dortBas2 * 1);

        printf("=============================\n");
        printf("Kripto tekli: %d-%d-%d-%d\n", dortBas3, dortBas4, dortBas1, dortBas2);
        printf("Kripto birlikte: %d\n", dortKripto);
        printf("=============================\n");

        kriptoCoz(dortKripto);
    }
    else if(dortBasamakliSayi < 1000 || dortBasamakliSayi > 9999)
    {
        printf("Girdiginiz sayi dort basamakli olmadigindan program sonlandiriliyor...\n");
        return 0;
    }
    else
    {
        printf("Sayi kontrol edilirken bilinmeyen bir hata olustu! (HATA)\n");
        return 0;
    }
}