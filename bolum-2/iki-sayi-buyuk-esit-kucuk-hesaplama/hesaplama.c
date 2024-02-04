#include <stdio.h>

int main( void )
{
    int num1, num2;

    printf("Uyari: Sayilarin arasinda bosluk birakiniz\nIki tane tam sayi giriniz ve arasındaki iliskiyi size gosterelim\nIlk sayi: ");
    scanf("%d%d",&num1, &num2);
    
    if(num1 == num2)
    {
        printf("%d esittir %d\n", num1, num2);
    }
    else if(num1 < num2)
    {
        printf("%d kucuktur, %d buyuktur\n", num1, num2);
    }
    else if(num1 > num2)
    {
        printf("%d buyuktur, %d kucuktur\n", num1, num2);
    }
    else
    {
        printf("Istenmeyen bir hata olustu (HATA)\n");
    }
}
