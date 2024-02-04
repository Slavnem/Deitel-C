// Dizi İsminin Dizinin İlk Elemanının Adresi İle Aynı Olması
#include <stdio.h>

// main fonksiyonunun programı başlatması
void main(void)
{
    char array[5]; // 5 boyutlu dizi oluşturması

    printf("array = %p\n&array[0] = %p\n%array = %p\n", array, &array[0], &array);
} // main sonu