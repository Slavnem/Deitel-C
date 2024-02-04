// Dizi değerlerini artan sırada sıralama
#include <stdio.h>
#define SIZE 10

int main(void)
{
    // a dizisine başşangıç değeri atama
    int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};
    int pass; // dolaşma sayacı
    size_t i; // karşılaştırma sayacı
    int hold; // elemanları yer değiştirirken kullanılacak geçici değişken

    puts("Orjinal siradaki veriler");

    // orjinal dizinin yazdırılması
    for(i = 0; i < SIZE; i++)
    {
        printf("%4d", a[i]);
    } // döngü sonu

    // kabarcık sıralama
    // dolaşmayı kontrol eden döngü
    for(pass = 1; pass < SIZE; pass++)
    {
        // her dolaşmadaki karşılaştırma sayısını kontrol eden döngü
        for(i = 0; i < SIZE -1; i++)
        {
            /* komşu elemanları karşılaştırma ve 
            ilk eleman ikinciden büyükse yer değiştirme */
            if(a[i] > a[i+1])
            {
                hold = a[i];
                a[i] = a[i+1];
                a[i+1] = hold;
            } // if sonu
        } // iç döngü sonu
    } // dış döngü sonu

    puts("\nElemanlarin artan sirada siralanmasi");

    // sıralı dizinin çıktısı
    for(i = 0; i < SIZE; i++)
    {
        printf("%4d", a[i]);
    } // döngü sonu

    puts("");
} // main sonu