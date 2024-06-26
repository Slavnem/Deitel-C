// Slavnem @2024-06-27
// "exit" Ve "atexit" Fonksiyonları Kullanımı

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// Fonksiyon prototipi
void print(void);

// main
int main(void)
{
    int answer; // kullanıcının menü seçimi

    atexit(print); // print fonksiyonunu kaydet
    puts("\"exit\" fonksiyonu ile sonlandirmak icin 1"
        "\nnormal sonlandirmak için 2'ye tiklayiniz");
    scanf("%d", &answer);

    // cevap 1 ise exit fonksiyonunu çağır
    if(answer == 1)
    {
        puts("\nProgram \"exit\" fonksiyonu kullanilarak sonlandiriliyor");
        exit(EXIT_SUCCESS);
    }

    puts("\n\"main\" sonuna gelindigi icin program sonlandiriliyor");
}

// print
void print(void)
{
    puts("\"print\" fonksiyonu program sonlandirilirken kullaniliyor"
        "\nProgram sonlandirildi");
}