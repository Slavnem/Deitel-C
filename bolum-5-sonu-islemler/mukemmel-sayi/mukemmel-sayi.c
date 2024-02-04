// 1-1000 ARASI MÜKEMMEL SAYILARI BULMA
#include <stdio.h>

unsigned int mukemmel(unsigned int);

int main(void)
{
    unsigned int dongu;

    for(dongu = 1; dongu <= 1000; dongu++)
    {
        mukemmel(dongu) == 1 ? (printf("%d mukemmel sayidir\n", dongu)) : (printf("%d mukemmel sayi degildir\n", dongu));
    }
}

unsigned int mukemmel(unsigned int sayi)
{
    unsigned int tur;
    unsigned int toplam = 0;

    for(tur = 1; tur < sayi; tur++)
    {
        sayi % tur == 0 ? (toplam += tur) : (toplam == toplam);
    }

    if(toplam == sayi)
        {return 1;}
    else
        {return 0;}
}