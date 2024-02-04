// KARAKTER DİZİLERİNİ KARAKTER DİZİNLERİ GİBİ GÖSTERME
#include <stdio.h>
#define BOYUT 20

// program main fonksiyonu ile başlar
int main(void)
{
    char string1[BOYUT]; // 20 karakter ayrılması
    char string2[] = "string literal"; // 15 karakter ayrılması
    size_t i; // sayaç

    // kullanıcı tarafından girilen karakter dizinini string1 dizisine okuma
    printf("%s", "Karakter dizini giriniz (en fazla 19 karakter): ");
    scanf("%19s", string1); // 19 karakterden fazla girdinin kabul edilmemesi

    // karakter dizininin gösterilmesi
    printf("string1: %s\nstring2: %s\nstring1 karakterler arasi bosluk ile yazdirilmasi:\n", string1, string2);

    // null karakter gelene kadar ekrana yazdırılması
    for(i = 0; i < BOYUT && string1[i] != '\0'; i++)
    {
        printf("%c ", string1[i]);
    } // döngü sonu

    puts("");
} // main sonu
