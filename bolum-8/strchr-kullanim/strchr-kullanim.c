// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    const char* string = "This is a test"; // işaretçiye başlangıç değeri atanması
    char character1 = 'a'; // character1'e başlangıç değeri atanması
    char character2 = 'z'; // character2'e başlangıç değeri atanması

    // character1 karakter dizini içinde bulunuyorsa
    if(strchr(string, character1) != NULL)
    {
        printf("\'%c\' was found in \"%s\".\n", character1, string);
    }
    else
    { // character1 bulunmuyorsa
        printf("\'%c\' was not found in \"%s\".\n", character1, string);
    }

    // character2 karakter dizini içinde bulunuyorsa
    if(strchr(string, character2) != NULL)
    {
        printf("\'%c\' was found in \"%s\".\n", character2, string);
    }
    else
    { // character1 bulunmuyorsa
        printf("\'%c\' was not found in \"%s\".\n", character2, string);
    }
}