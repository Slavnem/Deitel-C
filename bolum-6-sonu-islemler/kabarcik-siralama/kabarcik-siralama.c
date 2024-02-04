#include <stdio.h>

#define UST_SINIR 40

/* fonksiyon tanımlamaları 
bir tanesi dizileri sıralayacağı için değiştirme hakkı var fakat
diğeri sadece sıralanmış hali yazdırcağından const yaptık */
void sirala(unsigned int dizi[], size_t _ust_sinir);
void yazdir(const unsigned int dizi[], size_t _ust_sinir);

// main fonksiyonu başlangıcı
int main(void)
{
    // dizimizin boyutunu ve dizimizin içine değerleri tanımlıyoruz
    unsigned int dizi[UST_SINIR] =
    { 1,3,4,0,9,6,8,7,2,5,
    14,12,19,13,17,16,15,18,10,11,
    20,22,24,26,28,21,23,25,27,29,
    30,31,33,35,37,39,32,34,36,38 };

    sirala(dizi, UST_SINIR); // dizimizi ve boyutunu bildirip fonksiyon ile sıralıyoruz
} // main fonksiyonu sonu

// sirala fonksiyonu başlangıcı
void sirala(unsigned int dizi[], size_t _ust_sinir)
{
    size_t _sayac; // kalan sayılar için sayaç
    size_t _ic_sayac; // karşılaştırma için sayaç

    unsigned int _gecici;

    for(_sayac = _ust_sinir; _sayac > 0; --_sayac)
    { // üst sınıra ayarlıyoruz ve 0 dan büyükse sayı karşılaştırmasını azaltıyoruz
        for(_ic_sayac = 0; _ic_sayac < _sayac - 1; _ic_sayac++)
        { // eğer 10 sayı kaldıysa, şuanki sayıyı diğerleyirle karşılaştırdığımızdan
            // örnek: 10-1 yani sayac -1
            if(dizi[_ic_sayac] > dizi[_ic_sayac + 1])
            {
                _gecici = dizi[_ic_sayac]; // geçici olarak şuanki sayıyı tut
                dizi[_ic_sayac] = dizi[_ic_sayac +1]; // şuanki sayıya şonraki küçük sayıyı ata
                dizi[_ic_sayac +1] = _gecici; // sonraki sayıya şuanki büyük sayıyı ata
            }
        }
    }

    yazdir(dizi, _ust_sinir);
} // sirala fonksiyonu sonu

// yazdir fonksiyonu başlangıcı
void yazdir(const unsigned int dizi[], size_t _ust_sinir)
{
    size_t _yazdir_sayac; // döngü için sayaç

    // üst sınıra kadar dön ve ekrana yazdır
    for(_yazdir_sayac = 0; _yazdir_sayac < _ust_sinir; _yazdir_sayac++)
    {
        printf("%d) %d\n", _yazdir_sayac+1, dizi[_yazdir_sayac]);
    }
} // yazdir fonksiyonu başlangıcı