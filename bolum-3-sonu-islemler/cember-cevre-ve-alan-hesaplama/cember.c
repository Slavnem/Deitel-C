#include <stdio.h>

int main( void )
{
    double pideger = 3.14159;
    int cevre, alan;
    int yaricap;
    
    printf("Tam sayi olacak sekilde yaricap degerini giriniz: ");
    scanf("%d", &yaricap);

    cevre = (2 * pideger * yaricap);
    alan = (pideger * (yaricap * yaricap));

    if(yaricap <= 0)
    {
        printf("Yaricap degeri 0'dan kucuk veya 0'a esit olamaz! (HATA)\n");
    }
    else if(yaricap > 0)
    {
        printf("Girdiginiz yaricap degeri = %d\n", yaricap);
        printf("Dairenin cevresi = %d\n", cevre);
        printf("Dairenin alani = %d\n", alan);
    }
    else
    {
        printf("Bilinmeyen bir hata olustu! (HATA)\n");
    }
}
