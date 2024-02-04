// Dizilerde const anahtar sözcüğünün kullanımı
#include <stdio.h>

void tryToModifyArray(const int[]); // fonksiyonun tanımlanması

// main fonksiyonu
int main(void)
{
    int a[] = {10,20,30}; // a dizisine başlangıç değeri ataması

    tryToModifyArray(a);

    printf("%d %d %d\n", a[0], a[1], a[2]);
} // main sonu

/* tryToModifyArray fonksiyonunda b dizisi const olarak belirtilmiş olduğundan
main içinde orjinal a dizisini değiştirmek için kullanılamaz */
void tryToModifyArray(const int b[])
{
    b[0] /= 2; // hata
    b[1] /= 2; // hata
    b[2] /= 2; // hata
} // tryToModifyArray sonu