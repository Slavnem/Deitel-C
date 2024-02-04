// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    char s1[17]; // s1 dizisinin tanımlanması
    char s2[] = "Copy this string"; // s2 dizisine başlangıç değeri atanması

    /*
        AÇIKLAMA: Kopyalanan dizideki (s2) veriler
        istenen diziye belirli boyut kadarı kopyalanır
    */

    memcpy(s1, s2, 17);
    printf("%s\n%s\"%s\"\n",
        "After s2 is copied into s1 with memcpy, ",
        "s1 contains ", s1);
}