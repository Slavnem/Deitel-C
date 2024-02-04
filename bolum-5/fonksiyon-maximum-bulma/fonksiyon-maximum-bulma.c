// FONKSİYON İLE MAXİMUM BULMA
#include <stdio.h>

int maximum(int x, int y, int z); // fonksiyon bildirimi

int main( void )
{
    int number1;
    int number2;
    int number3;

    printf("%s", "Uc tane tam sayi giriniz: ");
    scanf("%d%d%d", &number1, &number2, &number3);

    // number1, number2, number3
    // maximum fonksiyon çağrısına argümanlardır
    printf("En buyuk: %d\n", maximum(number1, number2, number3));
} // main sonu

int maximum(int x, int y, int z)
{
    int max = x;

    if(y > max)
    {
        max = y;
    }

    if(z > max)
    {
        max = z;
    }

    return max; // max en büyük değeri döndür
} // maximumu fonksiyonu sonu