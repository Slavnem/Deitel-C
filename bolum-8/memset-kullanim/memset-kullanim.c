// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    char string1[15] = "BBBBBBBBBBBBBBB"; // string1'e başlangıç değeri atanması

    printf("string1 = %s\n", string1);
    printf("string1 after memset = %s\n", (char*)memset(string1, 'b', 7));
}