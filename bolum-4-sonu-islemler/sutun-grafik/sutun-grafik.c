//Sütun Grafik
#include <stdio.h>

int main( void )
{
    int sayi = 0;

    printf("Sutun icin bir sayi giriniz: ");
    scanf("%d", &sayi);

    if(sayi < 0)
    {
        printf("Negatif kabul edilemez! (HATA)\n");
    }
    else
    {
        for(int i = 0; i < sayi; i++)
        {
            printf("*");
        }
    }
}