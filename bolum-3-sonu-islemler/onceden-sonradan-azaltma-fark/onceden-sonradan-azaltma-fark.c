#include <stdio.h>

int main( void )
{
    int i ;

    printf("Bir tam sayi degeri giriniz: ");
    scanf("%d", &i);

    printf("=================================\n");
    printf("Onceden azaltma: (-1) + %d = %d\n", i, (-1 + i));
    printf("Sonradan azaltma: %d - (1) = %d\n", i, (i - 1));
    printf("=================================\n");
}
