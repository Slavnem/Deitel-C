// C Ozyineleme Dizideki En Kucuk Degeri Bulmak
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIZI_SINIR 20

// ++submain
void submain(void);

// ++_DiziKucukSayi
short _DiziKucukSayi(
    short _dks_sayac,
    const short _dks_sayac_bitis,
    short _dks_kucuk_sayi,
    const short _dks_dizi[]
);

// ++_DiziYazdir
void _DiziYazdir(
    short _dy_sayac,
    const short _dy_sayac_bitis,
    const short _dy_dizi[]
);

// +main
int main(void)
{
    submain();
}
// -main

// +submain
void submain(void)
{
    srand(time(NULL));

    short __dizi_rastgele[DIZI_SINIR];
    short __sayac;
    short __kucuk_sayi;

    // diziye rastgele degerler vermek
    for(__sayac = 0; __sayac < DIZI_SINIR; __sayac++)
    {
        __dizi_rastgele[__sayac] = (rand() % DIZI_SINIR);
    }

    // kucuk sayiyi hesaplatmak
    __kucuk_sayi = _DiziKucukSayi(
        0,
        DIZI_SINIR,
        __dizi_rastgele[0],
        __dizi_rastgele
    );

    // diziyi cikti vermek
    _DiziYazdir(
        0,
        DIZI_SINIR,
        __dizi_rastgele
    );

    // ekrana cikti vermek
    printf("Dizideki en kucuk sayi: %hd\n", __kucuk_sayi);
}
// -submain

// +_Dizi
short _DiziKucukSayi(
    short _dks_sayac,
    const short _dks_sayac_bitis,
    short _dks_kucuk_sayi,
    const short _dks_dizi[]
)
{
    // dongu daha bitmemisse...
    if(_dks_sayac < _dks_sayac_bitis)
    {
        // eger suanki sayi kucuk sayidan kucukse yeni kucuk sayi suanki sayidir
        if(_dks_dizi[_dks_sayac] < _dks_kucuk_sayi)
        {
            _dks_kucuk_sayi = _dks_dizi[_dks_sayac];
        }

        // fonksiyon kendisini yeni degerlerle dondurur
        return _DiziKucukSayi(
            ++_dks_sayac,
            _dks_sayac_bitis,
            _dks_kucuk_sayi,
            _dks_dizi
        );
    }

    // kucuk sayiyi dondur
    return _dks_kucuk_sayi;
}
// -_DiziKucukSayi

// +_DiziYazdir
void _DiziYazdir(
    short _dy_sayac,
    const short _dy_sayac_bitis,
    const short _dy_dizi[]
)
{
    for(;_dy_sayac < _dy_sayac_bitis; _dy_sayac++)
    {
        printf("%hd) %hd\n", _dy_sayac+1, _dy_dizi[_dy_sayac]);
    }

    puts(""); // yeni satir
}
// -_DiziYazdir