#include <stdio.h>

int main( void )
{
    int integer1, integer2, sum;

    printf("Uyari: Sayilarin arasinda bosluk birakiniz\nIki tane tam sayi giriniz: ");
    scanf("%d%d", &integer1, &integer2);

    sum = integer1 + integer2;

    printf("Toplam deger = %d\n", sum);
}
