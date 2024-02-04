// Slavnem
// ASCII Kod Çıktı
// ===============
// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    int ascii_num; // ASCII standartına göre girilecek numarayı tutacak

    // kullanıcıdan girdi istemek
    printf("Bir ASCII numarasi giriniz: ");
    scanf("%d", &ascii_num);

    // çıktıyı verme
    printf("%s%d%s%c\n", "Girilen numara: ", ascii_num, " | Cikti: ", (char)(ascii_num));
}