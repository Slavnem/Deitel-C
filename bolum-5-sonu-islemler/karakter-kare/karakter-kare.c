// KARAKTER İLE KARE OLUŞTURMAK
#include <stdio.h>

void fillCharacter(int, int);

int main(void)
{
    int kareMiktar, karakterTur;

    do
    {
        printf("Kare icin miktar giriniz: ");
        scanf("%d", &kareMiktar);
    } while(kareMiktar <= 0);

    do
    {
        printf("Kare icin karekter(sayi) giriniz: ");
        scanf("%d", &karakterTur);
    } while (karakterTur <= 0);
    
    fillCharacter(kareMiktar, karakterTur);
}

void fillCharacter(int kare, int karakter)
{
    int dongu, tur;

    for(dongu = 1; dongu <= kare; dongu++)
    {
        for(tur = 1; tur <= kare; tur++)
        {
            printf("%d", karakter);
        }
        printf("\n");
    }
}