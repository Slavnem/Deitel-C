#include <stdio.h>

int main( void )
{
    int deger;

    printf("Bir tam sayi giriniz: ");
    scanf("%d", &deger);

    while(deger < 0)
    {
        printf("Pozitif bir tam sayi giriniz: ");
        scanf("%d", &deger);
    }

    printf("====================================\n");
    printf("%d\t%d\t%d\t%d\n", (deger), (deger+2), (deger+4), (deger+6));
    printf("------------------------------------\n");

    for(int i = 0; i < 5; i++)
    {
        printf("%d\t%d\t%d\t%d\n", (deger + (3 * i)), ((deger + 2) + (3 * i)), ((deger + 4) + (3 * i)), ((deger + 6) + (3 * i)));
    }

    printf("====================================\n");
}
