//For ifadesi break kullanma
#include <stdio.h>

int main( void )
{
    unsigned int x;

    for(x = 1; x <= 10; x++)
    {
        if(x == 5)
        {
            break;
        }

        printf("%u ", x);
    }

    printf("\nx == %u oldugunda dongu kirildi\n", x);
}