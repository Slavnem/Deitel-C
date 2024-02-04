////////////////////////////
// Yazan: Slavnem
// Dil: C
////////////////////////////

// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define SIZE 80

// main
int main(void)
{
    int c; // kullanıcı tarafından girilen karakteri tutan değişken
    int i = 0; // sayaca başlangıç değeri atama

    char sentence[SIZE]; // dizi tanımı

    // kullanıcıya veri girmesini bildirme
    puts("Enter a line of text: ");

    // karakterleri okumak için getchar kullanımı
    while(i < SIZE - 1 && (c = getchar()) != '\n')
    {
        sentence[i++] = c;
    }

    sentence[i] = '\0'; // karakter dizinini sonlandırmak

    // cümleyi ekranda görüntülemek için puts fonksiyonu kullanımı
    puts("\nThe line entered was: ");
    puts(sentence);
}