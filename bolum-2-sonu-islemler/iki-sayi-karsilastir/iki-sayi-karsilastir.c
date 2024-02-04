#include <stdio.h>

int main( void )
{
    int x, y;
    printf("Uyari: Sayilarin arasinda bosluk birakiniz\nIki tane tam sayi giriniz: ");
    scanf("%d%d", &x, &y);
    
    if(x == y)
    {
        printf("%d esittir %d\n", x, y);
    }
    else if(x < y)
    {
        printf("%d kucuktur, %d buyuktur\n", x, y);
    }
    else if(x > y)
    {
        printf("%d buyuktur, %d kucuktur\n", x, y);
    }
    else
    {
        printf("Istenmeyen bir hata olustu!\n");
    }
}
