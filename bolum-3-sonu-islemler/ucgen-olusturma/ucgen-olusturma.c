#include <stdio.h>

int main( void )
{
    int kenar1, kenar2, kenar3;

    printf("1. Kenari giriniz: ");
    scanf("%d", &kenar1);

    printf("2. Kenari giriniz: ");
    scanf("%d", &kenar2);

    printf("3. Kenari giriniz: ");
    scanf("%d", &kenar3);

    if(kenar1 <= 0 || kenar2 <= 0 || kenar3 <= 0)
    {
        printf("Herhangi bir kenar 0'a esit veya daha kucuk olamaz! (HATA)\n");
        return 0;
    }
    else if(kenar1 > 0 && kenar2 > 0 && kenar3 > 0)
    {
        if(kenar1 + kenar2 <= kenar3 ||
        kenar1 + kenar3 <= kenar2 ||
        kenar2 + kenar3 <= kenar1)
        {
            printf("Ucgenin iki kenari ucuncu kenarin toplamina esit veya kucuk olamaz! (HATA)\n");
            return 0;
        }
        else if(kenar1 + kenar2 > kenar3 &&
        kenar1 + kenar3 > kenar2 &&
        kenar2 + kenar3 > kenar1)
        {
            printf("===============================\n");
            printf("Kenar1: %d\nKenar2: %d\nKenar3: %d\n", kenar1, kenar2, kenar3);
            printf("Ucgen olusturuldu! (BASARILI)\n");
            printf("===============================\n");
        }
        else
        {
            printf("Ucgen olusturulurken bilinmeyen bir hata olustu! (HATA)\n");
        }
    }
    else
    {
        printf("Kenar hesaplanirken bilinmeyen bir hata olustu! (HATA)\n");
    }
}