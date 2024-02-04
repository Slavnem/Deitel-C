#include <stdio.h>

int main( void )
{
    int dama;

    printf("Dama tahtasi icin sayi giriniz: ");
    scanf("%d", &dama);

    if(dama <= 1)
    {
        printf("Dama deseni olması icin en az 2 girilmelidir! (HATA)\n");
        return 0;
    }

    for(int i = 1; i <= dama; i++)
    {
        for(int j = 1; j <= dama; j++)
        {
            printf("* ");
        }
        printf("\n");

        for(int k = 1; k <= dama; k++)
        {
            printf(" *");
        }
        printf("\n");
    }
}