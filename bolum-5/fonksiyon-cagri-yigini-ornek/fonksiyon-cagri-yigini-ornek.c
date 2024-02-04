// FONKSİYON ÇAĞRI YIĞINI ÖRNEK
#include <stdio.h>

int square( int );

int main()
{
    int a = 10; // square'e değer (main'deki yerel otomatik değişken)

    printf("%d karesi: %d\n", a, square( a )); // kareyi göster
} // main sonu

// bir tam sayının karesini gönder
int square( int x ) // x bir yerel değişkendir
{
    return x * x; // kareyi hesapla ve sonucu gönder
} // square fonksiyonu sonu