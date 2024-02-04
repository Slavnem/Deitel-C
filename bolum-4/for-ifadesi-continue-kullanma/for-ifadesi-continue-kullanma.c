//For ifadesi continue kullanma
#include <stdio.h>

int main( void )
{
    unsigned int x;

    for(x = 1; x <= 10; x++)
    {
        if(x == 5)
        {
            continue;
        }

        printf("%u ", x);
    }

    printf("\nX degeri 5'e esit oldugunda continue kullanilip geri kalan kodlar calistirildi\n");
}