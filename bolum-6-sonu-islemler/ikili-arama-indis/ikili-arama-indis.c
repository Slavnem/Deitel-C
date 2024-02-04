// C Ikili Arama Indis
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIZI_SINIR 30

// ++_Submain
void _Submain(void);

// ++_DiziSirala
void _DiziSirala(
    short _ds_sayac_baslangic,
    const short _ds_sayac_son,
    short _ds_dizi[]
);

// ++_IkiliArama
short _IkiliArama(
    const short _ia_anahtar,
    short _ia_kucuk,
    short _ia_buyuk,
    const short _ia_dizi[]
);

// ++_DiziYazdir
void _DiziYazdir(
    short _dy_sayac_baslangic,
    const short _dy_sayac_son,
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
    short __s_dizi_rastgele[DIZI_SINIR];

    short __s_rastgele_sayac;
    short __s_kullanici_sayi;
    short __s_anahtar_aralik_baslangic = 0;
    short __s_anahtar_aralik_son = DIZI_SINIR;
    short __s_anahtar_arama_sonuc;

    // rastgele sayilar uretip diziye vermek
    for(__s_rastgele_sayac = 0; __s_rastgele_sayac < DIZI_SINIR; __s_rastgele_sayac++)
    {
        __s_dizi_rastgele[__s_rastgele_sayac] = 1 + (rand() % DIZI_SINIR);
    }

    // diziyi sirala
    _DiziSirala(
        __s_anahtar_aralik_baslangic,
        __s_anahtar_aralik_son,
        __s_dizi_rastgele
    );

    // kullanicidan sayi isteme
    do
    {
        printf("Bir sayi giriniz[%hd-%hd]: ", __s_anahtar_aralik_baslangic, __s_anahtar_aralik_son);
        scanf("%hd", &__s_kullanici_sayi);
    } while(__s_kullanici_sayi < __s_anahtar_aralik_baslangic || __s_kullanici_sayi > __s_anahtar_aralik_son);

    // diziyi yazdir
    _DiziYazdir(
        __s_anahtar_aralik_baslangic,
        __s_anahtar_aralik_son,
        __s_dizi_rastgele
        );

    // sayi bulunduysa indisi dondur, bulunmadiysa -1
    __s_anahtar_arama_sonuc = _IkiliArama(
        __s_kullanici_sayi,
        __s_anahtar_aralik_baslangic,
        __s_anahtar_aralik_son,
        __s_dizi_rastgele
    );

    if(__s_dizi_rastgele[__s_anahtar_arama_sonuc] == __s_kullanici_sayi)
    {
        printf("Girdiginiz sayi(%hd) dizinin icinde var\n", __s_kullanici_sayi);
    }
    else
    {
        printf("Girdiginiz sayi(%hd) dizinin icinde yok\n", __s_kullanici_sayi);
    }
}
// -_Submain

// +_DiziSirala
void _DiziSirala(
    short _ds_sayac_baslangic,
    const short _ds_sayac_son,
    short _ds_dizi[]
)
{
    short __ds_gecici = _ds_dizi[_ds_sayac_son];
    short __ds_sayac;
    short __ds_ic_sayac;

    // kucukten buyuge siralama
    for(__ds_sayac = _ds_sayac_son; __ds_sayac > _ds_sayac_baslangic; --__ds_sayac)
    {
        for(__ds_ic_sayac = 0; __ds_ic_sayac < __ds_sayac -1; __ds_ic_sayac++)
        {
            if(_ds_dizi[__ds_sayac] > _ds_dizi[__ds_sayac +1])
            {
                __ds_gecici = _ds_dizi[__ds_sayac];
                _ds_dizi[__ds_sayac] = _ds_dizi[__ds_sayac +1];
                _ds_dizi[__ds_sayac +1] = __ds_gecici;
            }
        }
    }
}
// -_DiziSirala

// +_IkiliArama
short _IkiliArama(
    const short _ia_anahtar,
    short _ia_kucuk,
    short _ia_buyuk,
    const short _ia_dizi[]
)
{
    short __ia_orta;

    while(_ia_kucuk <= _ia_buyuk)
    {
        __ia_orta = (_ia_kucuk + _ia_buyuk) / 2;

        if(_ia_anahtar == _ia_dizi[__ia_orta])
        {
            // indis numarasi
            printf("[%hd: indis numarasi]\n", __ia_orta);
            return __ia_orta;
        }
        else if(_ia_dizi[__ia_orta] > _ia_anahtar)
        {
            _ia_buyuk = __ia_orta -1;
        }
        else
        {
            _ia_kucuk = __ia_orta +1;
        }
    }

    // anahtar bulunamadi
    return -1;
}
// -_IkiliArama

// +_DiziYazdir
void _DiziYazdir(
    short _dy_sayac_baslangic,
    const short _dy_sayac_son,
    const short _dy_dizi[]
)
{
    // ekrana sayialri cikti vermek
    for(;_dy_sayac_baslangic < _dy_sayac_son; _dy_sayac_baslangic++)
    {
        printf("%hd) %hd\n", _dy_sayac_baslangic, _dy_dizi[_dy_sayac_baslangic]);
    }
}
// -_DiziYazdir