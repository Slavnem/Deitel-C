//En Küçük Sayıyı Bul
#include <stdio.h>

int main( void )
{
    unsigned int enk = 5;
    int sayi;

    for(int i = 0; i < 10; i++)
    {
        printf("Bir sayi giriniz: ");
        scanf("%d", &sayi);

        while(sayi < 0)
        {
            printf("Pozitif olmali! Bir sayi giriniz: ");
            scanf("%d", &sayi);
        }

        if(sayi < enk)
        {
            enk = sayi;
        }
    }

    printf("En kucuk sayi = %d\n", enk);
}