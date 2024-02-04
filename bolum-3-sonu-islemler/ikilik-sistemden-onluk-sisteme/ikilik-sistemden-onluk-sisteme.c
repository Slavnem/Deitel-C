#include <stdio.h>

int main( void )
{
    int ikiliksistem;
    unsigned int bBirler, bOnlar, bYuzler, bBinler, bOnbinler, oBirler, oOnlar, oYuzler, oBinler, oOnbinler, onluksistem;

    printf("En fazla 5 basamakli olucak sekilde 2li sistemde sayi giriniz (ornek: 10101): ");
    scanf("%d", &ikiliksistem);


    if(ikiliksistem < 0)
    {
        printf("2lik sistem icin negatif degerler kabul edilmez! (HATA)\n");
        return 0;
    }
    else if(ikiliksistem > 99999)
    {
        printf("En fazla 5 en az 1 basamakli disinda 2lik sistem icin sayiyi bu program icin kabul etmiyoruz! (HATA)\n");
        return 0;
    }

    bBirler = (int)(ikiliksistem % 10);
    bOnlar = (int)((ikiliksistem / 10) % 10);
    bYuzler = (int)((ikiliksistem / 100) % 10);
    bBinler = (int)((ikiliksistem / 1000) % 10);
    bOnbinler = (int)((ikiliksistem) / 10000);

    if(
    (bBirler < 0 || bBirler > 1) ||
    (bOnlar < 0 || bOnlar > 1) ||
    (bYuzler < 0 || bYuzler > 1) ||
    (bBinler < 0 || bBinler > 1) ||
    (bOnbinler < 0 || bOnbinler > 1))
    {
        printf("1 veya 0 disinda sayi 2lik sistem icin kabul edilemez! (HATA)\n");
        return 0;
    }

    oBirler = (bBirler * 1);
    oOnlar = (bOnlar * 2);
    oYuzler = (bYuzler * 4);
    oBinler = (bBinler * 8);
    oOnbinler = (bOnbinler * 16);

    onluksistem = oBirler + oOnlar + oYuzler + oBinler + oOnbinler;

    printf("====================================\n");
    printf("Girdiginiz 2lik sistemdeki sayi = %d\n", ikiliksistem);
    printf("Girdiginiz 2lik sistemdeki sayi basamaklarina ayrilmis hali = %d-%d-%d-%d-%d\n", bOnbinler, bBinler, bYuzler, bOnlar, bBirler);
    printf("Girdiginiz 2lik sistemdeki sayi 10luk sisteme cevrilmis hali = %d\n", onluksistem);
    printf("====================================\n");

}
