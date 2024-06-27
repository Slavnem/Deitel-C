// Slavnem @2024-06-27
// Sinyal Tutucu

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Fonksiyon prototipleri
static void handle_sigabrt(int signalValue);
static void handle_sigint(int signalValue);

// main
int main(void)
{
    // test için değişken
    int test;

    signal(SIGABRT, handle_sigabrt); // anormal sonlandirmalar için sinyal tutucu
    signal(SIGINT, handle_sigint); // ctrl+c tarzı kesintileri tutucu sinyal

    // kullanıcı bilgilendirme için çıktı
    puts(
        "Programi Ctrl+c veya Ctrl+d ile sonlandırabilirsiniz\n"
        "Programi sonlandirana kadar rastgele sayi alinacak"
    );

    do
    {
        printf("sayi giriniz [1: sonlandirma]: ");
        scanf("%d", &test);
    } while (test != 1);
}

// handle_sigabrt
static void handle_sigabrt(int signalValue)
{
    printf("\n* SIGABRT [%d] Sinyali Yakalandi. Anormal Sonlandirma\n", signalValue);
    abort(); // program sonlandırma
}

// handle_sigint
static void handle_sigint(int signalValue)
{
    printf("\n* SIGINT [%d] Sinyali Yakalandi. Kesinti Sonlandirma\n", signalValue);
    exit(EXIT_SUCCESS); // program sonlandırma
}