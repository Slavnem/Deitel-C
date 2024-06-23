// Slavnem @2024-04-23
// #error İle #pragma Ön İşlemcileri Kullanımı

// Kütüphaneler
#include <stdio.h>

#if 0
    Bir daha tanımlanma sorunlarını önlemek için
    #pragma once kullanılır ama biz dosya da zaten
    işlemler yaptığımız için #pragma once kullanmıyoruz
    #pragma once
#endif

// Hata kontrolü
#define TEST_VALUE 5 // test amaçlı

// Değişkeni kontrol ediyoruz ve eğer hatalıysa zaten
// derleyici (gcc) bunun bir hata olduğunu bildiricektir
#if TEST_VALUE < 5
#error "TEST_VALUE değeri 5'den Küçük"
#endif

// örnek
void fonksiyonum() {
    // GCC'de kullanılmayan değişken uyarısını devre dışı bırakma
    #pragma GCC diagnostic ignored "-Wunused-variable"
    int unusedVar; // Bu değişken kullanılmadığı için normalde uyarı verir, ancak pragma ile devre dışı bırakıldı.
}

// main
int main(void)
{
    fonksiyonum(); // test amaçlı fonksiyonu çağırıyoruz

    // test çıktısı
    printf("\nTest Degeri: %d\nProgram Basariyla Calisti...\n", TEST_VALUE);
}