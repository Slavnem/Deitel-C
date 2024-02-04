// Anket verilerinin diziler ile analizi
// Verilerin medyan, mod ve ortalamasının hesaplanması
#include <stdio.h>
#define SIZE 99

// fonksiyon tanımlamaları
void ortalama(const unsigned int[]);
void medyan(unsigned int[]);
void mod(unsigned int[], unsigned const int[]);
void bubbleSort(unsigned int[]);
void printArray(unsigned const int[]);

// main fonksiyonu ile programı başlatma
int main(void)
{
    unsigned int frequency[10] = {0}; // dizi frekansı başlangıç değer ataması

    // cevap dizisine başlangıç değer ataması
    unsigned int response[SIZE] = 
    {
        6,7,8,9,8,7,8,9,8,9,7,8,9,5,9,8,7,8,7,8,
        6,7,8,9,3,9,8,7,8,7,7,8,9,8,9,8,9,7,8,9,
        6,7,8,7,8,7,9,8,9,2,7,8,9,8,9,8,9,7,5,3,
        5,6,7,2,5,3,9,4,6,4,7,8,9,6,8,7,8,9,7,8,
        7,4,4,2,5,3,8,7,5,6,4,5,6,1,6,5,7,8,7,
    };

    // cevapların işlenmesi
    ortalama(response);
    medyan(response);
    mod(frequency, response);
} // main sonu

// cevap değerlerinin ortalamasını hesaplama
void ortalama(const unsigned int answer[])
{
    size_t j; // dizi elemanlarını toplama sayacı
    unsigned int toplam = 0; // dizi elemanlarının toplamını tutan değişken

    printf("%s\n%s\n%s\n", "*********", "Ortalama", "*********");

    // cevap değerlerinin tümü
    for(j = 0; j < SIZE; j++)
    {
        toplam += answer[j];
    } // döngü sonu

    printf("Tum verilerin ortalamasi tum elemanlardaki degerlerin"
    "toplaminin eleman sayisina olan bolumudur\n"
    "[%u] Bu calistirmanin ortalamasi: %u / %u = %.4f\n\n",
    SIZE, toplam, SIZE, (double) toplam / SIZE);
} // ortalama fonksiyonu sonu

// dizinin sıralanması ve orta elemanın bulunması
void medyan(unsigned int answer[])
{
    printf("%s\n%s\n%s\n%s", "*********", "Medyan - Orta", "*********", "Siralanmamis dizi");

    printArray(answer); // sıralanmış dizinin çıktısı
    bubbleSort(answer); // dizinin sıralanması

    printf("\n\n%s", "Siralanmis dizi");
    printArray(answer);

    // orta elemanın gösterilmesi
    printf("\n\nOrtanca eleman olan %u\n"
    "Dizideki %u eleman icinden secilmistir\n"
    "Bu calistirmanin orta elemani %u\n\n",
    SIZE / 2, SIZE, answer[SIZE / 2]);
} // orta fonksiyonu sonu

// en sık karşılaşılan cevabın bulunması
void mod(unsigned int freq[], const unsigned int answer[])
{
    size_t rating; // frekans dizisinde en çok karşılaşılan eleman için sayaç
    size_t j; // 0-98 cevap dizisi için sayaç
    
    unsigned int h; // frekans dizisi değerleri çizelgesi için sayaç
    unsigned int largest = 0; // en yüksek frekans
    unsigned int modValue = 0; // en sık karşılaşılan cevap

    printf("\n%s\n%s\n%s\n", "*********", "Mod", "*********");

    // frekansa 0 başlangıç değeri atanması
    for(rating = 1; rating <= 9; rating++)
    {
        freq[rating] = 0;
    } // döngü sonu

    // frekansların toplanması
    for(j = 0; j < SIZE; j++)
    {
        ++freq[answer[j]];
    } // döngü sonu

    // cevap sütunları başlığının çıktısı
    printf("%s%11s%19s\n%36s\n%36s\n", "Cevap", "Frekans", "Cizelge", "1 1 2 2", "5 0 5 0 5");

    // cevapların yazdırılıması
    for(rating = 1; rating <= 9; rating++)
    {
        printf("%3u%6u\t", rating, freq[rating]);

        // mod değeri ve en yüksek frekans değerinin takibi
        if(freq[rating] > largest)
        {
            largest = freq[rating];
            modValue = rating;
        } // if sonu

        // frekans değerlerinden oluşan çizelge sütununun yazdırılması
        for(h = 1; h <= freq[rating]; h++)
        {
            printf("%s", "*");
        } // iç döngü sonu

        puts(""); // yeni satır yazdırma
    } // dış döngü sonu

    // mod değerinin yazdırılması
    printf("\nMod en sik karsilasilan degerdir\n"
    "Bu calismada mod %u, %u kez bulunmustur\n", modValue, largest);
} // mod fonksiyonu sonu

// kabarcık algoritmasıyla diziyi sıralayan fonksiyon
void bubbleSort(unsigned int a[])
{
    size_t j; // karşılaştırma sayacı

    unsigned int pass; // dolaşma sayacı
    unsigned int hold; // yer değiştirme için geçici değişken

    // dolaşma sayılarını kontrol eden döngü
    for(pass = 1; pass < SIZE; pass++)
    {
        // her dolaşmadaki karşılaştırma sayılarını kontrol eden döngü
        for(j = 0; j < SIZE -1; j++)
        {
            // sıralama dışı ise yer değiştirme
            if(a[j] > a[j+1])
            {
                hold = a[j];
                a[j] = a[j+1];
                a[j+1] = hold;
            } // if sonu
        } // iç döngü sonu
    } // dış döngü sonu
} // kabarcık sıralama fonksiyonu sonu

// dizi içeriğinin yazdırılması (her sırada 20 değer)
void printArray(const unsigned int a[])
{
    size_t j; // sayaç

    // dizi içeriğinin yazdurılması
    for(j = 0; j < SIZE; j++)
    {
        if(j % 20 == 0)
        {
            // her 20 değerden sonra satır başı
            puts("");
        } // if sonu

        printf("%2u", a[j]);
    } // döngü sonu
} // dizi yazdırılması fonksiyonu sonu