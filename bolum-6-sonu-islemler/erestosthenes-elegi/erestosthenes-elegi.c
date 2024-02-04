// C Erestosthenes Elegi
// Konu: Asal olmayan sayilarin dizideki konumu 0, asal olanlar 1
#include <stdio.h>
#define DIZI_SINIR 1000

// ++_Submain
void _Submain(void);

// ++_SsalKontrol
unsigned short _AsalKontrol(unsigned short);

// +main
int main(void)
{
    _Submain();
}
// -main

// +_Submain
void _Submain(void)
{
    unsigned short __submain_dizi_asal[DIZI_SINIR] = {0};
    unsigned short __submain_sayac_dizi;

    for(__submain_sayac_dizi = 0; __submain_sayac_dizi < DIZI_SINIR; __submain_sayac_dizi++)
    {
        if(_AsalKontrol(__submain_sayac_dizi) != 1)
        {
            // asal degildir, 0 yap
            __submain_dizi_asal[__submain_sayac_dizi] = 0;
        }
        else
        {
            // asaldir, 1 yap
            __submain_dizi_asal[__submain_sayac_dizi] = 1;
        }
    }

    // Erestosthenes Elegi
    puts("Erestosthenes Elegi");
    puts("-------------------");

    for(__submain_sayac_dizi = 0; __submain_sayac_dizi < DIZI_SINIR; __submain_sayac_dizi++)
    {
        // sadece asallari yazdir
        if(__submain_dizi_asal[__submain_sayac_dizi] == 1)
        {
            printf("%hd asaldir\n", __submain_sayac_dizi);
        }
    }
}
// -_Submain

// +_AsalKontrol
unsigned short _AsalKontrol(unsigned short ___asal_sayi)
{
    if(___asal_sayi != 2 && ___asal_sayi % 2 == 0)
    {
        // cift asal bir tek 2'dir
        return 0;
    }
    else if(___asal_sayi > 6)
    {
        if(___asal_sayi % 6 == 1 || ___asal_sayi % 6 == 5)
        {
            unsigned short __asalkontrol_sayac;

            for(__asalkontrol_sayac = 3; __asalkontrol_sayac <= (___asal_sayi / 2); __asalkontrol_sayac += 2)
            {
                if(___asal_sayi % __asalkontrol_sayac == 0)
                {
                    // tam bolundugunden asal degildir
                    return 0;
                }
            }

            // tam bolunmediginden asaldir
            return 1;
        }

        // 6'ya bolundugunde 1 veya 5 kalmayanlar asal degil
        return 0;
    }

    // 2,3 veya 5 ise 1 dondur, asaldir
    return (___asal_sayi == 2 || ___asal_sayi == 3 || ___asal_sayi == 5);
}
// -_AsalKontrol