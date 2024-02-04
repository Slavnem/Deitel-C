// C Palindrom Kelime
// Konu: kelime palindrommu degilmi kontrol etsin
#include <stdio.h>

// ++_Submain
void _Submain(void);

// ++_PalindromKelime
short _PalindromKelime(const char[]);

// +main
int main(void)
{
    _Submain();
}
// -main

// +_Submain
void _Submain(void)
{
    char __s_dizi_kelime[] = {'i','y','i'};

    if(_PalindromKelime(__s_dizi_kelime) == 1)
    {
        printf("Kelime (%s) palindromdur\n", __s_dizi_kelime);
    }
    else
    {
        printf("Kelime (%s) palindrom degildir\n", __s_dizi_kelime);
    }
}
// -_Submain

// +_PalindromKelime
short _PalindromKelime(const char ___pk_dizi_kelime[])
{
    int __pk_sayac;
    int __pk_son_sayac;
    int __pk_durum = 1;

    for(__pk_sayac = 0; ___pk_dizi_kelime[__pk_sayac] != ' ' && ___pk_dizi_kelime[__pk_sayac] != '\0'; __pk_sayac++);

    __pk_son_sayac = __pk_sayac -1;

    for(__pk_sayac = 0; __pk_sayac <= __pk_son_sayac; (__pk_sayac += 1) && (__pk_son_sayac -= 1))
    {
        if(___pk_dizi_kelime[__pk_sayac] != ___pk_dizi_kelime[__pk_son_sayac])
        {
            __pk_durum = 0;
            break;
        }
    }

    return __pk_durum;
}
// -_PalindromKelime