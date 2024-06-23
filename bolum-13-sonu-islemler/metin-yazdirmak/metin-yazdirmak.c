// Slavnem @2024-06-23
// Karakter Dizini (Metin) Yazdırmak

// Kütüphaneler
#include <stdio.h>

// Metin yazdırma tanımlıysa kaldırsın
#ifdef PRINT
#undef PRINT
#endif

// Metin yazdırma tanımlasın
// Sonuna \n eklemedim çünkü fgets otomatik ekliyor
#define PRINT(x) printf("\n%s", x)

// Boyut hesaplatmak için (SECURE SIZESTR)
#ifdef SSIZESTR
#undef SSIZESTR
#endif

#define SSIZESTR(x) (sizeof(x) - 1)

// main
int main(void)
{
    // karakter depolamak için değişken
    char buffer[100];

    // kullanıcıdan metin istemek ve yazdırmak
    printf("En fazla %d karakter olucak şekilde metin giriniz: ", SSIZESTR(buffer));
    fgets(buffer, SSIZESTR(buffer), stdin);

    // girilen metini çıktı vermek
    PRINT(buffer);
}