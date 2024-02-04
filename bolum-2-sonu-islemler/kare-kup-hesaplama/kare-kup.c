#include <stdio.h>

int main( void )
{
    int basamak;

    printf("UYARI!: Fazla birikmemesi için en fazla iki basamak ile sinirlandirildi\n");
    printf("Bir sayi giriniz: ");
    scanf("%d", &basamak);

    if(basamak < 1 || basamak > 99)
    {
        printf("Girilen sayi (%d) iki basamakli degildir! (HATA)\n", basamak);
    }
    else if(basamak > 0 && basamak < 100)
    {
        for(int bas = 1; bas <= basamak; bas++)
        {
            printf("-----------------\n");
            printf("sayi: %d\n", bas);
            printf("karesi: %d\n", (bas * bas));
            printf("kupu: %d\n", (bas * bas * bas));
        }
    }
    else
    {
        printf("Bilinmeyen bir hata olustu! (HATA)\n");
    }
}
