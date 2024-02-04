// Indisleme ve isaretci gosterimlerini diziler ile kullanmak
#include <stdio.h>
#define ARRAY_SIZE 4

// +main
int main(void)
{
    int b[] = { 10,20,30,40 };
    int *bPtr = b; // bPtr olustur ve b dizisine isaret ettir
    size_t i; // sayac
    size_t offset; // sayac

    // b dizisini dizi indis gosterimini kullanarak cikti olarak sun
    for(i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("b[%u]: %d\n", i, b[i]);
    } // for blogu sonu

    // b dizisini dizi adi ve isaretci/offset gosterimi kullanarak cikti olarak sun
    puts("\nPointer/offset notaion where\n"
    "the pointer is the array name");

    // b dizisi boyunca dongu olustur
    for(i = 0; i < ARRAY_SIZE; ++i)
    {
        printf("bPtr[%u]: %d\n", i, bPtr[i]);
    } // for blogu sonu

    // b dizisini bPtr ve isaretci/offset gosterimi kullanarak cikti olarak sun
    for(offset = 0; offset < ARRAY_SIZE; ++offset)
    {
        printf("*(bPtr + %u): %d\n", offset, *(bPtr + offset));
    } // for blogu sonu
}
// -main