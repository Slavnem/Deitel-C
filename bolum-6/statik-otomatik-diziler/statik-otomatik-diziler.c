// STATİK VE OTOMATİK DİZİLERİN FARKI
#include <stdio.h>

void staticArrayInit(void); // fonksiyon tanımı
void automaticArrayInit(void); // fonksiyon tanımı

// main fonksiyonu ile program başlangıcı
void main(void)
{
    puts("Her fonksiyona yapilan ilk cagri:");
    staticArrayInit();
    automaticArrayInit();

    puts("Her fonksiyona yapilan ikinci cagri:");
    staticArrayInit();
    automaticArrayInit();
} // main sonu

// static yerel diziyi gösteren fonksiyon
void staticArrayInit(void)
{
    // ilk fonksiyon çağrısında elemanlara 0 atanması
    static int array1[3];
    size_t i; // sayaç

    puts("\nDegerlerin staticArrayInit fonksiyonuna girisi:");

    // array1 içeriğinin çıktısı
    for(i = 0; i <= 2; i++)
    {
        printf("array1[%u] = %d ", i, array1[i]);
    } // döngü sonu

    puts("\nDegerlerin staticArrayInit fonksiyonundan cikisi:");

    // array1 içeriğinini değiştirilmesi ve çıkışı
    for(i = 0; i <= 2; i++)
    {
        printf("array1[%u] = %d ", i, array1[i] += 5);
    } // döngü sonu
} // staticArrayInit fonksiyonu sonu

// automatic yerel diziyi gösteren fonksiyon
void automaticArrayInit(void)
{
    // Her çağrısında elemanlara ilk değer ataması
    int array2[3] = { 1, 2,3 };
    size_t i; // sayaç

    puts("\nDegerlerin automaticArrayInit fonksiyonına girisi:");

    // array2 içeriğinin çıktısı
    for(i = 0; i <= 2; i++)
    {
        printf("array2[%u] = %d ", i, array2[i]);
    } // döngü sonu

    puts("\nDegerlerin automaticArrayInit fonksiyonundan cikisi:");

    // array2 içeriğinin değiştirilmesi ve çıktısı
    for(i = 0; i <= 2; i++)
    {
        printf("array2[%u] = %d ", i, array2[i] += 5);
    } // döngü sonu
} // automaticArrayInit fonksiyon sonu