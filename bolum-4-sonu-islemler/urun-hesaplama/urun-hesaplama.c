//Ürün Hesaplama
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int secim = 0, girisUrun = 0;
    float urun1 = 2.98, urun2 = 4.50, urun3 = 9.98, urun4 = 4.49, urun5 = 6.87, toplam = 0;
    unsigned int adetUrun1 = 0, adetUrun2 = 0, adetUrun3 = 0, adetUrun4 = 0, adetUrun5 = 0;

    puts("1.Urun: 2.98TL\n2.Urun: 4.50TL\n3.Urun: 9.98TL\n4.Urun: 4.49TL\n5.Urun: 6.87TL\n");
    puts("Cikis icin 9999\n");

    while(1 > 0)
    {
        printf("Bir secim yapiniz: ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
            printf("Kac adet satildi giriniz: ");
            scanf("%d", &girisUrun);

            if(girisUrun < 0)
            {
                printf("Hatali adet sayisi! (HATA)\n");
            }
            else
            {
                toplam += (girisUrun * urun1);
                adetUrun1 += girisUrun;
            }
            break;

            case 2:
            printf("Kac adet satildi giriniz: ");
            scanf("%d", &girisUrun);

            if(girisUrun < 0)
            {
                printf("Hatali adet sayisi! (HATA)\n");
            }
            else
            {
                toplam += (girisUrun * urun2);
                adetUrun2 += girisUrun;
            }
            break;

            case 3:
            printf("Kac adet satildi giriniz: ");
            scanf("%d", &girisUrun);

            if(girisUrun < 0)
            {
                printf("Hatali adet sayisi! (HATA)\n");
            }
            else
            {
                toplam += (girisUrun * urun3);
                adetUrun3 += girisUrun;
            }
            break;

            case 4:
            printf("Kac adet satildi giriniz: ");
            scanf("%d", &girisUrun);

            if(girisUrun < 0)
            {
                printf("Hatali adet sayisi! (HATA)\n");
            }
            else
            {
                toplam += (girisUrun * urun4);
                adetUrun4 += girisUrun;
            }
            break;

            case 5:
            printf("Kac adet satildi giriniz: ");
            scanf("%d", &girisUrun);

            if(girisUrun < 0)
            {
                printf("Hatali adet sayisi! (HATA)\n");
            }
            else
            {
                toplam += (girisUrun * urun5);
                adetUrun5 += girisUrun;
            }
            break;

            case 9999:
            printf("Cikis onaylandi!\n");
            printf("Toplam satilan urun fiyat: %.2f\n", toplam);
            printf("Toplam adet:\n1.Urun: %d\n2.Urun: %d\n3.Urun: %d\n4.Urun: %d\n5.Urun: %d\n", adetUrun1, adetUrun2, adetUrun3, adetUrun4, adetUrun5);
            printf("Cikis yapiliyor...\n");
            exit(1);

            default:
            puts("Hatali secim yaptiniz! (HATA)\n");
            break;
        }
    }
}