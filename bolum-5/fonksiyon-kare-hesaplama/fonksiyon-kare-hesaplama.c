//FONKSİYON İLE KARE HESAPLAMA
#include <stdio.h>

// fonksiyonu sonra kullanıcağımızı önceden bildiriyoruz
int square(int y);

int main( void )
{
    int x; // sayaç

    // 10 kez dön ve her seferinde x'in karesini hesapla ve çıkışa gönder
    for(x = 1; x <= 10; x++)
    {
        printf("%d ", square(x)); // fonksiyon çağrısı
    }

    puts("");
}

// square fonksiyon tanımlaması parametresinin karesini gönderir
int square(int y) // y argümanının fonksiyona bir kopyasıdır
{
    return y * y;
}