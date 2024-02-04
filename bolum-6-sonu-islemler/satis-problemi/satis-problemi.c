/* SORU: Her hafta için 200dolar + o hafta yapılan satışların %9 u
Satış temsilcilerinin ne kadar ödeme aldıklarını bulan (her satış
temsilcisinin ödemelerinin tamsayı olduğunu varsayın) C programı
(dizi kullanınız) yazınız */

#include <stdio.h>

#define DEPO 100

// dizideki değeri değiştirmemesi için const olarak tanımladık
void sirala(const int dizi[]);

int main(void)
{
    int dizi[DEPO]; // tamsayı dizi tanımı, DEPO kadar tamsayı alabilir

    int _para = 200; // başlangıç paramız
    size_t _sayac; // sayacımız

    // 100 tane değer atanıcak
    for(_sayac = 0; _sayac < DEPO; ++_sayac)
    {
        dizi[_sayac] = 200 + (int)_para * 0.09;
        _para++;
    }

    // diziyi yukarıdan aşşağıya sırayla yazdırma fonksiyonu
    sirala(dizi);
}

// fonksiyon tanımı
void sirala(const int dizi[])
{
    size_t _sayac; // sayaç

    // sayaç dizi boyutundan küçükse ve dizi bitmemişse, yazdır
    for(_sayac = 0; _sayac < DEPO && dizi[_sayac] != '\0'; ++_sayac)
    {
        printf("%d) %d\n", _sayac, dizi[_sayac]);
    }
}