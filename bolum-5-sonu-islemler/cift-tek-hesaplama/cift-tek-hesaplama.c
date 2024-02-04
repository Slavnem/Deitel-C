// TEK ÇİFT HESAPLAMA
#include <stdio.h>

int even(int);

int main(void)
{
    int dongu, sayi;

    for(dongu = 1; dongu <= 10; dongu++)
    {
        printf("Bir sayi giriniz: ");
        scanf("%d", &sayi);

        if(even(sayi) == 1)
        {
            printf("%d cifttir\n", sayi);
        }
        else
        {
            printf("%d tektir\n", sayi);
        }
    }
}

int even(int tekcift)
{
    if(tekcift % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}