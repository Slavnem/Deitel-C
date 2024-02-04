// 40 ÖĞRENCİ ANKET ANALİZİ
#include <stdio.h>

#define CEVAP_BOYUTU 40 // dizi boyutlarının belirlenmesi
#define FREKANS_BOYUTU 11

// main ile program işleyişi başlar
int main(void)
{
    size_t cevap; // 40 cevap için döngü sayacı
    size_t puan; // 1-10 arası frekans için döngü sayacı

    // frekans sayaçlarına 0 atanması
    int frekans[FREKANS_BOYUTU] = { 0 };

    // sonuçların cevap dizisine yerleştirilmesi
    int cevaplar[CEVAP_BOYUTU] = { 1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
    1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6,
    5, 6, 7, 5, 6, 4, 8, 6, 8, 10 };

    // her cevap için cevap dizisindeki elemanın değerinin seçilmesi
    // ve bu değerin frelans dizisinde indis olarak
    // eleman arttırılması için kullanılması
    for(cevap = 0; cevap < CEVAP_BOYUTU; ++cevap)
    {
        ++frekans[cevaplar[cevap]];
    } // döngü sonu

    // sonuçların görüntülenmesi
    printf("%s%17s\n", "Oylama", "Frekans");

    // frekansların çizelge biçiminde yazdırılması
    for(puan = 1; puan < FREKANS_BOYUTU; ++puan)
    {
        printf("%6d%17d\n", puan, frekans[puan]);
    } // döngü sonu
} // main sonu