#include <stdio.h>

int main( void )
{
    int x;
    
    printf("Pozitif bir tam sayi degeri giriniz: ");
    scanf("%d", &x);
    
    if(x <= 0)
    {
        printf("0'a esit veya kucuk sayilar pozitif degildir! (HATA)\n");
    }
    else if((x % 2) == 0)
    {
        printf("%d cift sayidir\n", x);
    }
    else if((x % 2) == 1)
    {
        printf("%d tek sayidir\n", x);
    }
    else
    {
        printf("Bilinmeyen bir hata olustu! (HATA)\n");
    }
}
