// Slavnem @2024-02-26
// Alıştırmalar

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    // unsigned int türündeki 40000 sayısını 15 basamak
    // genişliğindeki bir alana sola dayalı şekilde yazınır
    unsigned int num = 40000;
    printf("%-15d\n", num);

    // Onaltılık sistemde olan bir değeri hex değişkenine yazınız
    int hex;
    scanf("%x", &hex);

    // 200 değerini işaretli ve işaretsiz biçimde yazınız
    printf("%+d | %-d\n", 200, -200);

    // 100 değerini onaltılık sistemde başına 0x koyarak yazınız
    printf("%#x\n", 100);

    // p harfi ile karşılaşıncaya kadar s dizisi içine
    // karakter okuyunuz
    char s[9];
    scanf("%8[^p]", s);

    // Başına 0 yerleştirerek 9 alan genişliğine 1.234 yazdırınız
    printf("%09.3f\n", 1.234);

    // hh:mm:ss biçiminde zamanı alınız, saati hh, dakikayı mm,
    // saniyeyi ss değişkenlerinde depolayınız. Grişi akışındaki
    // (:) karakterlerini atlayınız. Atama bastırma karakterini
    // kullanınız
    int hh;
    int mm;
    int ss;

    // Duzgun calismasi icin scanf("%8[^p]", s); devre disi olmali
    printf("hh:mm:ss biciminde zaman giriniz: ");
    scanf("%d%*c%d%*c%d", &hh, &mm, &ss);

    // Standart girişten "karakterler" karakter dizinini alınız ve
    // s dizisinde depolayınız. Giriş akışındaki çift tırnak
    // işaretini diziye yazdırmayın
    char s1[11];

    printf("\"karakterler\" gir: ");
    scanf("%2c%11s", &s1[0], s1);

    int hh1;
    int mm1;
    int ss1;

    // hh:mm:ss biçiminde zamanı alınız, saati hh, dakikayı mm,
    // saniyeyi ss değişkenlerinde depolayınız. Grişi akışındaki
    // (:) karakterlerini atlayınız. Atama bastırma karakterini
    // kullanmayınız
    // Duzgun calismasi icin scanf("%2c%11s", &s1[0], s1);
    // devre disi olmali
    printf("hh:mm:ss biciminde zaman giriniz: ");
    scanf("%d:%d:%d", &hh1, &mm1, &ss1);
}