#include <stdio.h>

int main( void )
{
    int kenar1, kenar2, hipotenus;

    printf("Dik Ucgen Formul: Hipotenusun karesi = Dik kenarlarin karesi toplami\n");
    printf("1.Kenari giriniz (30Derece): ");
    scanf("%d", &kenar1);

    printf("2.Kenari giriniz (60Derece): ");
    scanf("%d", &kenar2);

    printf("Hipotenusu giriniz (90Derece): ");
    scanf("%d", &hipotenus);

    if(kenar1 <= 0 ||
    kenar2 <= 0 ||
    hipotenus <= 0)
    {
        printf("Herhangi bir kenar 0'a esit veya kucuk olamaz! (HATA)\n");
        return 0;
    }
    else if(kenar1 > 0 &&
    kenar2 > 0 &&
    hipotenus > 0)
    {
        if((kenar1 * kenar1) + (kenar2 * kenar2) == (hipotenus * hipotenus))
        {
            printf("====================================\n");
            printf("Kenar1: %d\nKenar2: %d\nHipotenus: %d\n", kenar1, kenar2, hipotenus);
            printf("Dik Ucgen Olusturuldu! (BASARILI)\n");
            printf("====================================\n");
        }
        else if((kenar1 * kenar1) + (kenar2 * kenar2) != (hipotenus * hipotenus))
        {
            printf("====================================\n");
            printf("Kenar1: %d\nKenar2: %d\nHipotenus: %d\n", kenar1, kenar2, hipotenus);
            printf("Dik Ucgen Olusturulamadi! (BASARISIZ)\n");
            printf("====================================\n");
        }
        else
        {
            printf("Dik ucgen olusturuluken bilinmeyen bir hata olustu! (HATA)\n");
        }
    }
    else
    {
        printf("Kenar kontrol edilirken bilinmeyen bir hata olustu! (HATA)\n");
    }
}