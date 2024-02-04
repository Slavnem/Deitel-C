// Dizideki Elemanların Toplanması
#include <stdio.h> // kütüphaneyi ekleme
#define BOYUT 12 // en fazla dizi boyutu

// 1- Benim Yaptığım. 2-Kitabın Yaptığı.

/* 1) BENİM KİTABA BAKMADAN ANLADIĞIMLA YAPTIĞIM
* // main (ana) fonksiyon
* int main(void)
* {
*     int n[BOYUT]; // n dizisi BOYUT kadar değer alabilir
*     size_t i, toplam; // i ve toplam boyutları tanımlama
*     
*     Benim toplamı size_t ile yapmamın nedeni, toplam boyutuna eksili(-) değer verdirmeyeceğim için
* 
*     printf("Eleman Sayisi: %d\n", BOYUT); // en çok kaç eleman aldığını ekrana yazdırma
* 
*     // n dizisinin son elemanına gelene kadar ki elemanlarının i sırasındaki haline i atama
*     for(i = 0; i < BOYUT; i++)
*     {
*         n[i] = i;
*     }
* 
*     // toplam boyutunu n dizisinin i. sıradaki değeriyle toplama
*     for(i = 0; i < BOYUT; i++)
*     {
*         toplam += n[i];
*     }
* 
*     // Dizinin toplamını ekrana yazdırma
*     // size_t olduğu için %zu
*     printf("Toplam: %zu\n", toplam);
* } */

// 2) KİTABIN YAPTIĞI

// main ile programın başlaması
int main(void)
{
    // diziye başlangıç değerlerinin liste ile atanması
    int a[BOYUT] = { 1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45 };
    size_t i; // sayaç
    int toplam = 0; // dizi toplamı

    // a dizisindeki içeriklerin toplanması
    for(i = 0; i < BOYUT; i++)
    {
        toplam += a[i];
    } // döngü sonu

    printf("Dizideki elemanların toplamı: %d\n", toplam);
} // main sonu