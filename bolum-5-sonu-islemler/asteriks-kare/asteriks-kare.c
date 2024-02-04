// ASTERİKS İLE KARE
#include <stdio.h>

int side(int);

int main(void)
{
    int sayi;

    do
    {
        printf("Kac kare olsun sayi giriniz: ");
        scanf("%d", &sayi);
    } while(sayi <= 0);

    side(sayi);
}

int side(int kare)
{
    int i, j;

    for(i = 1; i <= kare; i++)
    {
        for(j = 1; j <= kare; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}