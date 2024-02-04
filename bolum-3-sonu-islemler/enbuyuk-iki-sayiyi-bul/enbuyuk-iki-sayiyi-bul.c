#include <stdio.h>

int main( void )
{
    int counter = 10, number;
    unsigned int enbuyuk = 0, yardimcibuyuk = 0;

    for(int i = 1; i <= 10; i++)
    {
        printf("%d)Bir tam sayi degeri giriniz: ", i);
        scanf("%d", &number);

        while(number < 0)
        {
            printf("%d)Negatif olmamali! Bir tam sayi degeri giriniz: ", i);
            scanf("%d", &number);
        }

        if(number >= enbuyuk)
        {
            yardimcibuyuk = enbuyuk;
            enbuyuk = number;
        }
        else if(number >= yardimcibuyuk && number < enbuyuk)
        {
            yardimcibuyuk = number;
        }
    }

    printf("=================================\n");
    printf("En buyuk sayi = %d\n", enbuyuk);
    printf("En buyuk ikinci sayi = %d\n", yardimcibuyuk);
    printf("=================================\n");
}
