// Sıralı dizi de ikili arama
#include <stdio.h>
#define SIZE 15

// fonksiyon tanımlamaları
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);

// main fonksiyonu başlangıcı
int main(void)
{
    int a[SIZE]; // a dizisinin oluşturulması
    size_t i; // a dizisindeki elemanlara başlangıç değeri atayan sayaç
    int key; // a dizisindeki değerin konumunu belirten değişken
    size_t result; // anahtarın konumu veya -1 tutan değişken

    for(i = 0; i < SIZE; i++)
    {
        a[i] = 2 * i;
    } // döngü sonu

    do // AÇIKLAMA: Normal kitap da do while yok ama ben kontrol amaçlı do while ile yaptım
    {
        printf("%s", "0-28 arasi sayi giriniz: ");
        scanf("%d", &key);
    } while(key < 0 || key > 28); // istenilen değer girilmesse dön

    printHeader();

    // a dizisinin anahatarının aranması
    result = binarySearch(a, key, 0, SIZE -1);

    // sonuçların görüntülenmesi
    if(result != -1)
    {
        printf("\n%d degeri %d icinde bolunmustur\n", key, result);
    } // if sonu
    else
    {
        printf("\n%d bulunamadi!\n", key);
    } // else sonu
} // main fonksiyonu sonu

// dizi içinde ikili aramanın gerçekleştirilmesi
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    int middle; // variable(değişken) dizinin orta elemanını tutan değişken

    // düşük indisin yüksek indisten büyük olmasına kadar devam eden döngü
    while(low <= high)
    {
        // aranacak alt dizinin orta elemanının tespit edilmesi
        middle = (low + high) / 2;

        // döngü sırasında kullanılan alt dizinin görüntülenmesi
        printRow(b, low, middle, high);

        // orta elemanla anahtar uyuşursa, orta elemanın dönmesi
        if(searchKey == b[middle])
        {
            return middle;
        } // if sonu

        // anahtar orta elemandan küçükse, yeni yüksek değerin atanması
        else if(searchKey < b[middle])
        {
            high = middle -1; // dizi sonunda düşüğün aranması
        } // else if sonu

        // anahtar orta elemandan büyükse, yeni düşük değerin atanması
        else
        {
            low = middle +1; // dizi sonunda yükseğin aranması
        } // else sonu
    } // while sonu

    return -1; // anahtarın bulunamaması
} // ikili arama fonksiyonu sonu

// çıkış için başlık yazdırılması
void printHeader(void)
{
    unsigned int i; // sayaç

    puts("\nIndisler:");

    // sütun başının çıktısı
    for(i = 0; i < SIZE; ++i)
    {
        printf("%3u ", i);
    } // döngü sonu

    puts(""); // çıktı da yeni satır yazdırılması

    // karakterlerin yazdırılması
    for(i = 1; i <= 4 * SIZE; ++i)
    {
        printf("%s", "-");
    } // döngü sonu

    puts(""); // çıktı da yeni satır yazdırılması
} // printHeader fonksiyonu sonu

// bir satır çıktı ile
// işlem gören dizi parçasının yazdırılması
void printRow(const int b[], size_t low, size_t mid, size_t high)
{
    size_t i; // b dizisinde dolaşmak için sayaç

    // dizi için oluşturulan döngü
    for(i = 0; i < SIZE; ++i)
    {
        // alt dizi kapsamı dışında kalan boşlukların yazdırılması
        if(i < low || i > high)
        {
            printf("%s", "");
        } // if sonu
        else if(i == mid)
        { // orta elemanın görüntülenmesi
            printf("%3d*", b[i]); // orta elemanın işaretlenmesi
        } // else if sonu
        else
        { // alt dizideki diğer elemanların yazdırılması
            printf("%3d ", b[i]);
        } // else sonu
    } // döngü sonu

    puts(""); // yeni satırın yazdırılması
} // printRow fonksiyonu sonu