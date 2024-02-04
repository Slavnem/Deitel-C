#include <stdio.h>

int main( void )
{
    int x, y;
    
    printf("Uyari: Sayilarin arasinda bosluk birakiniz\nIki tane tam sayi giriniz: ");
    scanf("%d%d", &x, &y);

    printf("Girilen iki sayinin toplami = %d\n", (x+y));
    printf("Girilen iki sayinin cikarmasi = %d\n", (x-y));
    printf("Girilen iki sayinin carpimi = %d\n", (x*y));

    if(x == 0 || y == 0)
    {
        printf("\nSayilar: %d %d\nSayilardan herhangi birisi 0 girildiginden bolme islemi yapilamaz! (HATA)\n", x, y);
    }
    else if(x != 0 && y != 0)
   {
       printf("Girilen iki sayinin bolumu = %d\n", (x/y));
   }
   else
   {
       printf("Bilinmeyen bir hata olustu!\n");
   }

   printf("Girilen iki sayinin kalani = %d\n", (x%y));
}
