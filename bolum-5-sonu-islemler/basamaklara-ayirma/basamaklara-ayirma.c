// RASTGELE VERİLEN SAYIYI BASAMAKLARA AYIRMA
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rastgeleBasamak(unsigned long long int);

int main(void)
{
    srand(time(NULL));
    // ben en fazla 5 basamaklı olsun diye 99999 yazdım
    // sınır olmasın istiyorsanız, % 99999 u silin, sadece rand() kalsın
    unsigned long long int rastgele = rand() % 99999;

    printf("Rastgele sayi: %llu\n", rastgele);
    rastgeleBasamak(rastgele);
}

void rastgeleBasamak(unsigned long long int rastgeleSayi)
{
    int dongu;

    for(dongu = 10; rastgeleSayi % dongu != rastgeleSayi && dongu <= rastgeleSayi; dongu *= 10);

    while (dongu / 10 >= 1)
    {
        dongu /= 10;
        printf("%d ", ((rastgeleSayi / dongu) % 10));
    }
    printf("\n");
}
