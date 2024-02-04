// Dizinin doğrusal olarak aranması
#include <stdio.h>
#define SIZE 100

// fonksiyon tanımlaması
size_t linearSearch(const int array[], int key, size_t size);

// main fonksiyonu başlangıcı
int main(void)
{
    size_t x; // a dizisindeki 0-99 eleman için sayaç tanımlaması
    size_t element; // anahtarın konumu veya -1 tutacak olan değişken
    
    int a[SIZE]; // a dizisinin tanımlanması
    int searchKey; // a dizisindeki aranacak anahtar

    // veri üretme
    for(x = 0; x < SIZE; x++)
    {
        a[x] = 2 * x;
    }  // döngü sonu

    puts("Tamsayi arama anahtari giriniz: ");
    scanf("%d", &searchKey);

    // a dizisinde anahtar aranması
    element = linearSearch(a, searchKey, SIZE);

    // sonuçların görüntülenmesi
    if(element != -1)
    {
        printf("Bulunan deger: %d\n", element);
    }
    else
    {
        puts("Deger bulunamadi!");
    } // else sonu
} // main fonksiyonu sonu

// anahtar ile her elemanın doğru konum bulunana kadar
// veya dizi sonuna ulaşana kadar devam etmesi, eleman bulundu ise
// konumu, bulunmadı ise -1 döndürmesi
size_t linearSearch(const int array[], int key, size_t size)
{
    size_t n; // sayaç

    // dizi içinde döngü ile dolaşılması
    for(n = 0; n < size; n++)
    {
        if(array[n] == key)
        {
            return n; // konumun döndürülmesi
        } // if sonu
    } // döngü sonu

    return -1; // anahtar bulunamaması
} // linearSearch fonksiyonu sonu