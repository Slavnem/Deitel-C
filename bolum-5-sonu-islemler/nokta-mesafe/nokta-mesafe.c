// X1,Y1 VE X2,Y2 NOKTALARI ARASI MESAFE HESAPLAMA
#include <stdio.h>

unsigned int mesafe(int, int, int, int);

int main(void)
{
    int x1, x2, y1, y2;

    printf("x1 icin deger giriniz: ");
    scanf("%d", &x1);

    printf("y1 icin deger giriniz: ");
    scanf("%d", &y1);

    printf("x2 icin deger giriniz: ");
    scanf("%d", &x2);

    printf("y2 icin deger giriniz: ");
    scanf("%d", &y2);

    printf("x1[%d] y1[%d] ve x2[%d] y2[%d] arasi mesafe: kok %u\n", x1, y1, x2, y2, mesafe(x1, y1, x2, y2));
}

unsigned int mesafe(int mx1, int my1, int mx2, int my2)
{
    mx1 < 0 ? (mx1 *= +1) : (mx1 == mx1);
    my1 < 0 ? (my1 *= +1) : (my1 == my1);
    mx2 < 0 ? (mx2 *= +1) : (mx2 == mx2);
    my2 < 0 ? (my2 *= +1) : (my2 == my2);

    return ((mx1 *= mx1) + (my1 *= my1)) + ((mx2 *= mx2) + (my2 *= my2));
}