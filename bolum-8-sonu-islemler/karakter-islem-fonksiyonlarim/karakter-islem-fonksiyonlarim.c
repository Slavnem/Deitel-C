// Slavnem
// Kendi Karakter İşlem Fonksiyonlarım
// ===================================
// Kütüphaneler
#include <stdio.h>

#define ASCII_CNTRL_START 0 // ASCII standartına göre kontrol karakterleri başlangıcı
#define ASCII_CNTRL_END 31 // ASCII standartına göre kontrol karakterleri sonu
#define ASCII_CNTRL_LAST 127 // ASCII standartına göre son kontrol karakteri
#define ASCII_DIFF 32 // ASCII standartına göre küçük, büyük harf arasındaki sayı farkı
#define ASCII_A 65 // ASCII büyük harf başlangıcı
#define ASCII_END_A (ASCII_A + 25) // ASCII büyük harf sonu
#define ASCII_a 97 // ASCII küçük harf başlangıcı
#define ASCII_END_a (ASCII_a + 25) // ASCII Küçük harf sonu
#define ASCII_HEX_START (ASCII_a) // ASCII standartına göre a, 16'lık sistem başlangıcı
#define ASCII_HEX_END (102) // ASCII standartına göre f, 16'lık sistem sonu

#define ASCII_ETC_UNLEM 1
#define ASCII_ETC_ALINTI 2
#define ASCII_ETC_HASHTAG 3
#define ASCII_ETC_DOLAR 4
#define ASCII_ETC_MOD 5
#define ASCII_ETC_VE 6
#define ASCII_ETC_KESME 7
#define ASCII_ETC_PARANTEZAC 8
#define ASCII_ETC_PARANTEZKAPA 9
#define ASCII_ETC_CARP 10
#define ASCII_ETC_TOPLA 11
#define ASCII_ETC_VIRGUL 12
#define ASCII_ETC_TRE 13
#define ASCII_ETC_NOKTA 14
#define ASCII_ETC_SLAS 15
#define ASCII_ETC_IKINOKTAUSTUSTE 26
#define ASCII_ETC_NOKTALIVIRGUL 27
#define ASCII_ETC_KUCUKTUR 28
#define ASCII_ETC_ESITTIR 29
#define ASCII_ETC_BUYUKTUR 30
#define ASCII_ETC_SORU 31
#define ASCII_ETC_ETISARETI 64
#define ASCII_ETC_KESME2 96
#define ASCII_ETC_SUSLUAC 123
#define ASCII_ETC_DIKCIZGI 124
#define ASCII_ETC_SUSLUKAPA 125

// Fonksiyon tanımları
int boslukMu(int);
int rakamMi(int);
int harfMi(int);
int harfrakamMi(int);
int onaltilikMi(int);
int kucukMu(int);
int buyukMu(int);
int kucukYap(int);
int buyukYap(int);
int ozelMi(int);
int kontrolMu(int);
int noktalamaMi(int);
int gorulebilenMi(int);
int yazdirilabilenMi(int);

// main
int main(void)
{
    char k = 'a';

    printf("%c%s%d\n", k, " bosluk mu: ", boslukMu(k));
    printf("%c%s%d\n", k, " rakam mi: ", rakamMi(k));
    printf("%c%s%d\n", k, " harf mi: ", harfMi(k));
    printf("%c%s%d\n", k, " harf rakam mi: ", harfrakamMi(k));
    printf("%c%s%d\n", k, " onaltilik mi: ", onaltilikMi(k));
    printf("%c%s%d\n", k, " kucuk mu: ", kucukMu(k));
    printf("%c%s%d\n", k, " buyuk mu: ", buyukMu(k));
    printf("%c%s%c\n", k, " kucuk yap: ", kucukYap(k));
    printf("%c%s%c\n", k, " buyuk yap: ", buyukYap(k));
    printf("%c%s%d\n", k, " ozel mi: ", ozelMi(k));
    printf("%c%s%d\n", k, " kontrol mu: ", kontrolMu(k));
    printf("%c%s%d\n", k, " noktalama mi: ", noktalamaMi(k));
    printf("%c%s%d\n", k, " gorulebilen mi: ", gorulebilenMi(k));
    printf("%c%s%d\n", k, " yazdirilabilen mi: ", yazdirilabilenMi(k));
}

// boslukMu
int boslukMu(int k)
{
    // boşluk karakteri ise 1 değilse 0
    return (k == ASCII_CNTRL_START); // boşluk
}

// rakamMi
int rakamMi(int k)
{
    // 0 (dahil) ile 9 dahil arasında ise rakam
    return (k >= 0 && k <= 9);
}

// harfMi
int harfMi(int k)
{
    // ASCII standartına göre karakter numarasına sahipse doğru değilse yanlış
    return ((k >= ASCII_A && k <= ASCII_END_A) || (k >= ASCII_a && k <= ASCII_END_a));
}

// harfrakamMi
int harfrakamMi(int k)
{
    // ASCII standartına göre karakter numarasına sahipse doğru ya da rakamsa doğru
    return ((k >= ASCII_A && k <= ASCII_END_A) || (k >= ASCII_a && k <= ASCII_END_a) || (k >= 0 && k <= 9));
}

// onaltilikMi
int onaltilikMi(int k)
{
    // 0,9 (dahil) arasında ya da a,b,c,d,e,f ise 16'lık
    return ((k >= 0 && k <= 9) || (k >= ASCII_HEX_START && k <= ASCII_HEX_END));
}

// kucukMu
int kucukMu(int k)
{
    // ASCII strandartına göre küçük harf başlangıç ve sonu arasında (dahil) ise küçüktür
    return (k >= ASCII_a && k <= ASCII_END_a);
}

// buyukMu
int buyukMu(int k)
{
    // ASCII strandartına göre büyük harf başlangıç ve sonu arasında (dahil) ise büyüktür
    return (k >= ASCII_A && k <= ASCII_END_A);
}

// kucukYap
int kucukYap(int k)
{
    // ASCII standartına göre büyük harf ise küçük halini döndür
    // yoksa kendisini döndür
    return ((k >= ASCII_A && k<= ASCII_END_A) ? (k + ASCII_DIFF) : (k));
}

// buyukYap
int buyukYap(int k)
{
    // ASCII standartına göre küçük harf ise büyük halini döndür
    // yoksa kendisini döndür
    return ((k >= ASCII_a && k<= ASCII_END_a) ? (k - ASCII_DIFF) : (k));
}

// ozelMi
int ozelMi(int k)
{
    // özel karakter ise doğru
    switch(k)
    {
        case '\n':
        case '\f':
        case '\t':
        case '\v':
        case '\r':
        case ASCII_CNTRL_START: // boşluk
            return 1;
    }
    
    // özel değil
    return 0;
}

// kontrolMu
int kontrolMu(int k)
{
    // ASCII standartına göre olan kontrol karakterlerinden biri ise doğru
    return ((k >= ASCII_CNTRL_START && k <= ASCII_CNTRL_END) || (k == ASCII_CNTRL_LAST));
}

// noktalamaMi
int noktalamaMi(int k)
{
    // ASCII standartına göre noktalama işareti
    switch(k)
    {
        case ASCII_ETC_NOKTA:
        case ASCII_ETC_VIRGUL:
        case ASCII_ETC_KESME:
        case ASCII_ETC_KESME2:
        case ASCII_ETC_SORU:
        case ASCII_ETC_UNLEM:
        case ASCII_ETC_IKINOKTAUSTUSTE:
        case ASCII_ETC_NOKTALIVIRGUL:
        case ASCII_ETC_ALINTI:
        case ASCII_ETC_TRE:
            return 1;
    }

    // noktalama işareti değil
    return 0;
}

// gorulebilenMi
int gorulebilenMi(int k)
{
    // ASCII standartına göre ekranda görülemeyen
    switch(k)
    {
        case '\n':
        case '\f':
        case '\t':
        case '\v':
        case '\r':
            return 0;
    }

    // ekranda görülebilen
    return 1;
}

// yazdirilabilenMi
int yazdirilabilenMi(int k)
{
    // yazdırılamayan
    switch(k)
    {
        case ASCII_CNTRL_LAST: // silme
        case ASCII_CNTRL_START: // boşluk
            return 0;
    }

    // yazdırılabilen
    return 1;
}