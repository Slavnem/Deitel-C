// MATH.H KÜTÜPHANESİ İLE KÜP BULMA
#include <stdio.h>

int cube(int y); // fonksiyon bildirimi

int main(void)
{
    int x;

    for(x = 1; x <= 10; x++)
    {
        printf("%d kup: %d\n", x, cube(x));
    }
}

int cube(int y)
{
    return y * y * y;
}