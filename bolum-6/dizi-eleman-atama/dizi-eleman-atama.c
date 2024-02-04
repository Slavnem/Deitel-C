// DİZİ TANIMINDA BAŞLANGIÇ LİSTESİ İLE İLK DEĞER ATAMA
#include <stdio.h>

// programın main ile işleyişe başlaması
int main(void)
{
    // n dizisine başlangıç listesi atanması
    int n[10] = { 32, 27, 64, 18, 95, 14, 90, 70, 60, 37 };
    size_t i; // sayaç

    printf("%s%13s\n", "Eleman", "Deger");

    // dizi içeriğinin çizelge biçiminde ekrana yazdırılması
    for(int i = 0; i < 10; i++)
    {
        printf("%7u%13d\n", i, n[i]);
    } // döngü sonu
} // main sonu