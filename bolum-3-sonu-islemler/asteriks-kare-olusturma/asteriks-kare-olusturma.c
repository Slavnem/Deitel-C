#include <stdio.h>

int main( void )
{
    int x;

    printf("Karenin uzunluk ve yuksekligi icin bir deger giriniz: ");
    scanf("%d", &x);

    while(x < 1)
    {
        printf("Kare icin en az 1 olmalidir! (UYARI)\n");
        printf("Karenin uzunluk ve yuksekligi icin bir deger giriniz (Cikis: 0): ");
        scanf("%d", &x);

        if(x == 0)
        {
            printf("Cikis kabul edildi! Program sonlandiriliyor...\n");
            return 0;
        }
        else if(x < 1 && x != 0)
        {
            printf("Fazla hatali giris! Program sonlandiriliyor...\n");
            return 0;
        }
        else
        {
            printf("Deger kontrol edilirken bilinmeyen bir hata olustu! (HATA)\n");
        }
    }

    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
