// C Dizi Yazdir
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SINIR 10

// ++_Submain
void _Submain(void);

// ++_RastgeleDizi
void _RastgeleDizi(
    short _rd_alt_sinir,
    short _rd_ust_sinir,
    short _rd_dizi[]
);

// ++_DiziYazdir
void _DiziYazdir(
    short _dy_alt_sinir,
    const short _dy_ust_sinir,
    const short _dy_dizi[]
);

// +main
int main(void)
{
    // yardimci main
    _Submain();
}
// -main

// +_Submain
void _Submain(void)
{
    srand(time(NULL));

    short __s_rastgele_dizi_boyut = rand() % SINIR;
    short __s_dizi_rastgele[__s_rastgele_dizi_boyut];

    // olusan dizinin boyutu 0'dan buyukse icine rastgele degerler versin
    if(__s_rastgele_dizi_boyut > 0)
    {
        _RastgeleDizi(
            0,
            __s_rastgele_dizi_boyut,
            __s_dizi_rastgele
        );
    }

    // erkana dizinin adini cikti vermek
    puts("[Rastlege Dizi]");

    // diziyi cikti vermek
    _DiziYazdir(
        0,
        __s_rastgele_dizi_boyut,
        __s_dizi_rastgele
    );
}
// -_Submain

// +_RastgeleDizi
void _RastgeleDizi(
    short _rd_alt_sinir,
    short _rd_ust_sinir,
    short _rd_dizi[]
)
{
    // dizi icine rastgele deger vermek
    for(;_rd_alt_sinir < _rd_ust_sinir; _rd_alt_sinir++)
    {
        _rd_dizi[_rd_alt_sinir] = rand() % SINIR;
    }
}
// -_RastgeleDizi

// +_DiziYazdir
void _DiziYazdir(
    short _dy_alt_sinir,
    const short _dy_ust_sinir,
    const short _dy_dizi[]
)
{
    // sayilari cikti vermek
    for(;_dy_alt_sinir < _dy_ust_sinir; _dy_alt_sinir++)
    {
        printf("%hd) %hd\n", _dy_alt_sinir+1, _dy_dizi[_dy_alt_sinir]);
    }
}
// -_DiziYazdir