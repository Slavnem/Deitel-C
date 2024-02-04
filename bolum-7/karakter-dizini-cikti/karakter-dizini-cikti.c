// Sabit verilere sabit olmayan isaretciyi kullanarak
// her seferinde bir karakter dizini karakteri yazdirmasi
#include <stdio.h>

// ++printCharacters
void printCharacters(const char *sPtr);

// +main
int main(void)
{
    // char diziyi ilklendir
    char string[] = "salam dunya ben massaka";

    puts("Yazi: ");
    printCharacters(string);
    puts("");
}
// -main

// sPtr, isaret ettigi karakter uzerinde degisiklik yapamaz.
// yani, sPtr bir "read-only" (sadece oku) isaretcisidir

// +printCharacters
void printCharacters(const char *sPtr)
{
    // tum string boyunca dongu olustur
    for(; *sPtr != '\0'; ++sPtr)
    {
        printf("%c", *sPtr);
    } // for blogu sonu
}
// -printCharacters