// Slavnem @2024-06-26
// "goto" Deyimi

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    int count = 1; // sayaç oluştur

    start: // etiket
        if(count > 10)
            goto end;

        printf("%d ", count);
        ++count;

        goto start; // satır 9'daki start etiketine git

    end: // etiket
        putchar('\n');
}