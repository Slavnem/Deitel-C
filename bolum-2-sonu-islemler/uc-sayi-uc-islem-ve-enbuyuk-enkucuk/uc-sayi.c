#include <stdio.h>

int main( void )
{
    int x, y, z, enb, enk;

    printf("Uyari: Sayilarin arasinda bosluk birakiniz\nUc tane tam sayi giriniz: ");
    scanf("%d%d%d", &x, &y, &z);

    printf("Girilen uc sayinin toplami = %d\n", (x+y+z));
    printf("Girilen uc sayinin carpimi = %d\n", (x*y*z));
    printf("Girilen uc sayinin ortalamasi = %d\n", ((x+y+z)/3));

    enb = x;
    enk = y;
  
    // EN BUYUK
    if(x >= y && x >= z)
    {
        enb = x;
        printf("En buyuk sayi = %d\n", enb);
    }
    else if(y >= x && y >= z)
    {
        enb = y;
        printf("En buyuk sayi = %d\n", enb);
    }
    else if(z >= x && z >= y)
    {
        enb = z;
        printf("En buyuk sayi = %d\n", enb);
    }
    else
    {
        printf("Istenmeyen bir hata olustu! (HATA)\n");
    }

    // EN KUCUK
    if(y <= x && y <= z)
    {
        enk = y;
        printf("En kucuk sayi = %d\n", enk);
    }
    else if(z <= y && z <= x)
    {
        enk = z;
        printf("En kucuk sayi = %d\n", enk);
    }
    else if(x <= y && x <= z)
    {
        enk = x;
        printf("En kucuk sayi = %d\n", enk);
    }
    else
    {
        printf("Istenmeyen bir hata olustu! (HATA)\n");
    }
}
