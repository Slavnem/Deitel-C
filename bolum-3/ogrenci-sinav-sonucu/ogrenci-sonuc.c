#include <stdio.h>

int main( void )
{
    unsigned int ogrenci = 10, kalan = 0, gecen = 0, deger;

    for(int i = 1; i <= ogrenci; i++)
    {
        printf("%d)Sonucu Giriniz (kaldiysa=1, gectiyse=2): ", i);
        scanf("%d", &deger);

        while(deger != 1 && deger != 2)
        {
            printf("Girilen deger gecersizdir!\n");
            printf("%d)Sonucu Giriniz (Kaldiysa=1, Gectiyse=2): ", i);
            scanf("%d", &deger);
        }

        if(deger == 1)
            kalan++;
        else if(deger == 2)
            gecen++;
        else
            printf("Kalan ya da gecen bulunamadi! (HATA)\n");
    }

    if(gecen >= 8)
        printf("Egitmen Odul Kazandi! (BASARI)\n");
}