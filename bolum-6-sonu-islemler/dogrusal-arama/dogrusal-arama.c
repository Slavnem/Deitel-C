// C Dogrusal Arama
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIZI_SINIR 30

// ++_Submain
void _Submain(void);

// ++_ArananSayi
short _ArananSayi(
    short _as_anahtar,
    short _as_sayac_bas,
    short _as_sayac_son,
    const short _as_dizi_anahtar[]
);

// ++_DiziYazdir
void _DiziYazdir(
    short _dy_sayac_bas,
    short _dy_sayac_son,
    const short _dy_dizi[]
);

// +main
int main(void)
{
    _Submain();
}
// -main

// +_Submain
void _Submain(void)
{
    srand(time(NULL));

    short __s_dizi_rastgele[DIZI_SINIR];
    short __s_sayac;
    short __s_kullanici;

    for(__s_sayac = 0; __s_sayac < DIZI_SINIR; __s_sayac++)
    {
        __s_dizi_rastgele[__s_sayac] = rand() % DIZI_SINIR;
    }

    do
    {
        printf("Anahtar icin sayi giriniz[%hd-%hd]: ", 0, DIZI_SINIR);
        scanf("%hd", &__s_kullanici);
    } while(__s_kullanici < 0 || __s_kullanici > DIZI_SINIR);

    // sayıları cikti vermek
    _DiziYazdir(0, DIZI_SINIR, __s_dizi_rastgele);

    if(_ArananSayi(__s_kullanici, 0, DIZI_SINIR,__s_dizi_rastgele) != -1)
    {
        printf("Girdiginiz anahtar (%hd) liste icinde var\n", __s_kullanici);
    }
    else
    {
        printf("Girdiginiz anahtar (%hd) liste icinde yok\n", __s_kullanici);
    }
}
// -_Submain

// +_ArananSayi
short _ArananSayi(
    short _as_anahtar,
    short _as_sayac_bas,
    short _as_sayac_son,
    const short _as_dizi_anahtar[]
)
{
    for(;_as_sayac_bas < _as_sayac_son;_as_sayac_bas++)
    {
        if(_as_anahtar == _as_dizi_anahtar[_as_sayac_bas])
        {
            // anahtar bulundu
            return _as_sayac_bas;
        }
    }

    // anahtar bulunmamissa
    return -1;
}
// -_ArananSayi

// +_DiziYazdir
void _DiziYazdir(
    short _dy_sayac_bas,
    short _dy_sayac_son,
    const short _dy_dizi[]
)
{
    for(;_dy_sayac_bas < _dy_sayac_son; _dy_sayac_bas++)
    {
        printf("%hd) %hd\n", _dy_sayac_bas+1, _dy_dizi[_dy_sayac_bas]);
    }
}
// -_DiziYazdir