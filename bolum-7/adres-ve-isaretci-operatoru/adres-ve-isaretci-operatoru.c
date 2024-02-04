// & ve * isaretci operatorlerini kullanmak
#include <stdio.h>

// +main
int main(void)
{
    int a; // bir tamsayi
    int *aPtr; // bir tamsayi isaretcisi

    a = 7;
    aPtr = &a; // aPtr'yi a'nin adresine ayarla

    printf("a'nin adresi: %p\naPtr'nin degeri: %p\n", &a, aPtr);
    puts("-------------------");
    printf("a'nin degeri: %d\n*aPtr'nin degeri: %d\n", a, *aPtr);
    puts("-------------------");
    printf("& ve * operatorlerinin kullanimlari\n&*aPtr: %p\n*&aPtr: %p\n", &*aPtr, *&aPtr);
}
// -main