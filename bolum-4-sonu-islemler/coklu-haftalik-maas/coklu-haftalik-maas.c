// ÇOKLU HAFTALIK MAAŞ HESAPLAMA
#include <stdio.h>

int main( void )
{
    int secim = 0;

    puts("===================================");
    puts("Haftalik Maas\nMudurler kod: 1\nSaatlik calisanlar kod: 2\nSiparis calisanlari kod: 3\nParca calisanlar kod: 4\nProgram Sonlandirma: 9999\n");
    puts("===================================");

    while(1 > 0)
    {
        printf("Bir secim giriniz: ");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                unsigned int mudurMaas = 0;
                printf("Mudur ne kadar maas aliyor: ");
                scanf("%d", &mudurMaas);
                printf("Haftalik maas: %d\n", mudurMaas);
                break;
            case 2:
                unsigned int mesaiSaat = 0, mesaiMaas = 0;
                float toplamMesaiMaas = 0.f;

                while(mesaiSaat <= 0)
                {
                    printf("Bir hafta da kac saat calisiyor: ");
                    scanf("%d", &mesaiSaat);
                }
                while(mesaiMaas <= 0)
                {
                    printf("Saatlik ucret: ");
                    scanf("%d", &mesaiMaas);
                }

                toplamMesaiMaas = (40 * mesaiMaas);

                if(mesaiSaat > 40)
                {
                    toplamMesaiMaas += ((mesaiSaat - 40) * (mesaiMaas * 1.5));
                }
                printf("Haftalik maas: %.2f\n", toplamMesaiMaas);
                break;
            case 3:
                int kuryeSatis = 0;
                float kuryeMaas = 250.f;

                while(kuryeSatis <= 0)
                {
                    printf("Ne kadar satis yaptiniz: ");
                    scanf("%d", &kuryeSatis);
                }

                kuryeMaas += (kuryeSatis * 5.7);
                printf("Kurye maas: %.2f\n", kuryeMaas);
                break;
            case 4:
                int parcaUcret = 0;
                unsigned int parcaMaas = 0;

                while(parcaUcret <= 0)
                {
                    printf("Parcaci ucret: ");
                    scanf("%d", &parcaUcret);
                }

                parcaMaas = parcaUcret + (100/*boya*/) + (500/*bujiler*/);
                puts("+Bujiler degisti +Araba boyandi");
                printf("Parca Maas: %d\n", parcaMaas);
            case 9999:
                puts("Haftalik Maaslar:"); 
                printf("Mudur Maas: %d\n", mudurMaas);
                printf("Saatlik Isci Maas: %.2f\n", toplamMesaiMaas);
                printf("Kurye Maas: %.2f\n", kuryeMaas);
                printf("Parcaci Maas: %d\n", parcaMaas);
                puts("Program sonlandiriliyor...");
                return 1;
            default:
                puts("Istenmeyen secim yaptiniz!");
                break;
        }
    }
}