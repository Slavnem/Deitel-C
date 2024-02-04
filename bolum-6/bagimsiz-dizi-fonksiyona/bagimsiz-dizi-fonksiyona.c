// Dizilerin Ve Bağımsız Dizi Elemanlarının Fonksiyonlara Geçirilmesi
#include <stdio.h>
#define BOYUT 5

// fonksiyon tanımlaması
void modifyArray(int[], size_t);
void modifyElement(int);

// main fonksiyonu ile programın başlaması
int main(void)
{
    int a[BOYUT] = {0,1,2,3,4}; // a dizisine başlangıç değeri atama
    size_t i; // sayaç

    puts("Tum dizinin referans ile gecirilmesinin etkisi:\n\nOrjinal dizinin değerleri:");

    // orjinal dizinin çıktısı
    for(i = 0; i < BOYUT; ++i)
    {
        printf("%3d", a[i]);
    } // döngü sonu

    puts("");

    // modifyArray fonksiyonuna dizinin referansının geçirilmesi
    modifyArray(a, BOYUT);

    puts("Degistirilen dizinin degerleri:");

    // değiştirilen dizinin çıktısı
    for(i = 0; i < BOYUT; ++i)
    {
        printf("%3d", a[i]);
    } // döngü sonu

    // a[3] içindeki değerin çıktısı
    printf("\n\nDeger ile dizi elemani gecirmenin etkisi\n\na[3] elemaninin degeri: %d\n", a[3]);

    modifyElement(a[3]); // dizi elemanı a[3]'ün değerle geçirilmesi

    printf("a[3] elemaninin degeri: %d\n", a[3]);
} // main sonu

/* modifyArray fonksiyonunda "b" nin, orjinal dizideki "a"nin bellekteki yerini göstermesi */
void modifyArray(int b[], size_t size)
{
    size_t j; // sayaç

    // her elemanı 2 ile çarpma
    for(j = 0; j < size; ++j)
    {
        b[j] *= 2; // orjinal diziyi gerçek olarak değiştirme
    } // döngü sonu
} // modifyArray fonksiyonu sonu

/* modifyElement fonksiyonunda "e"nin main fonksiyonundan gelen
a[3] dizi elemanının yerel kopyası olması */
void modifyElement(int e)
{
    // parametreyi 2 ile çarpma
    printf("modifyElement degeri: %d\n", e *= 2);
} // modifyElement fonksiyonu sonu