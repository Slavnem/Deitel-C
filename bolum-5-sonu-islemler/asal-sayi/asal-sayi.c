// 1-10000 ARASINDAKİ ASAL SAYILARI BULMA
#include <stdio.h>

unsigned long long int asal(unsigned long long int);

int main(void)
{
    unsigned long long int dongu;

    for(dongu = 2; dongu <= 10000; dongu++)
    {
        asal(dongu) == 1 ? (printf("%llu asal sayidir\n", dongu)) : (printf("%llu asal sayi degildir\n", dongu));
    }
}

unsigned long long int asal(unsigned long long int sayi)
{
    unsigned int durum = 1;
    unsigned long long int tur;

    if(sayi == 2)
        {return 1;}
    else if(sayi % 2 == 0)
        {return 0;}
    else
    {
        for(tur = 3; tur <= ((sayi -1) / 2); tur++)
        {
            sayi % tur == 0 ? (durum = 0) : (durum == durum);
        }

        if(durum == 1)
            {return 1;}
        else
            {return 0;}
    }
}