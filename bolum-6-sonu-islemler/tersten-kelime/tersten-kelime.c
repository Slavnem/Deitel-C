// C Ozyineleme Tersten Kelime
#include <stdio.h>

// ++_Submain
void submain(void);

// ++_TersDizgi
void _TersDizgi(
    short _td_sayac_baslangic,
    const short _td_uzunluk_dizi,
    const char _td_dizi_kelime[]
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
    const char __dizi_kelime[] = {'k','a','d','i','r'};
    short __sayac_dizi_uzunluk;

    // dizinin sonuna gelene kadar donsun
    for(__sayac_dizi_uzunluk = 0;
    __dizi_kelime[__sayac_dizi_uzunluk] != '\0';
    __sayac_dizi_uzunluk++);

    puts("[Tersten Yazilisi]");

    _TersDizgi(
        __sayac_dizi_uzunluk,
        0,
        __dizi_kelime
    );

    puts(""); // bos satir
}
// -submain

// +_TersDizgi
void _TersDizgi(
    short _td_sayac_baslangic,
    const short _td_uzunluk_dizi,
    const char _td_dizi_kelime[]
)
{
    if(_td_sayac_baslangic >= _td_uzunluk_dizi)
    {
        // karakteri yazsin
        printf("%c ", _td_dizi_kelime[_td_sayac_baslangic]);

        // kendini bi daha dondursun
        return _TersDizgi(
            _td_sayac_baslangic -= 1,
            _td_uzunluk_dizi,
            _td_dizi_kelime
        );
    }
}
// -_TersDizgi