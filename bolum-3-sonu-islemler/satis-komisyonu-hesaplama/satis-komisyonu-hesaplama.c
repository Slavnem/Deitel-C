#include <stdio.h>

int main( void )
{
    int islemDurum = 1, satisMiktar, komisyonMiktar;
    unsigned int maasMiktar, ekparaMiktar = 200;

    while(islemDurum == 1)
    {
        printf("====================================================\n");
        printf("Islem yapmak istiyormusunuz (Evet:1 | Hayir:2): ");
        scanf("%d", &islemDurum);

        if(islemDurum != 1)
        {
            return 0;
        }
        else if(islemDurum == 1)
        {
            printf("Haftalik ne kadar satis yapildi giriniz: ");
            scanf("%d", &satisMiktar);

            komisyonMiktar = (int)(satisMiktar / 9);
            maasMiktar = komisyonMiktar + ekparaMiktar;

            printf("Maas = %d\n", maasMiktar);
        }
        else
        {
            printf("Islem kontrolu sirasinda bilinmeyen bir hata olustu! (HATA)\n");
        }
    }
}