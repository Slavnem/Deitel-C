#include <stdio.h>

int main( void )
{
    int x;

    printf("Ici bos kare icin bir deger giriniz: ");
    scanf("%d", &x);

    while(x < 3)
    {
        printf("Ici bos kare olusturulmasi icin girilen deger en az 3 olmalidir! (HATA)\n");
        printf("Ici bos kare icin deger giriniz (sonlandirmak icin 0): ");
        scanf("%d", &x);

        if(x == 0)
        {
            printf("Sonlandirma kabul edildi! Program sonlandiriliyor...\n");
            return 0;
        }
        else if (x < 3 && x != 0)
        {
            printf("Fazla hatali giris! Program sonlandiriliyor...\n");
            return 0;
        }
        else
        {
            printf("Deger kontrolunde bilinmeyen bir hata olustu! (HATA)\n");
            return 0;
        }
    }

    for(int i = 1; i <= x; i++)
    {
        printf("*");
    }
    printf("\n");

    for(int j = 1; j <= x; j++)
    {
        printf("*");
        for(int k = 1; k > 0 && k < x-1; k++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");

    }

    for(int k = 1; k <= x; k++)
    {
        printf("*");
    }
    printf("\n");
}
