// BARBUT OYUNU SÜRÜM 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int bankaHesap(int);
int bankaKontrol(int);
unsigned long long int bankaBakiye(void);
int zarRastgele(void);
int barbut(int);

int main(void)
{
    int tekraroyna;

    do
    {
        int bahis;

        do
        {
            printf("%llu TL bakiyeniz bulunuyor, bahis icin miktar giriniz: ", bankaBakiye());
            scanf("%d", &bahis);
        } while (bahis <= 0 || bankaKontrol(bahis) == bahis);   

        srand(time(NULL));

        barbut(bahis);

        tekraroyna = -1;

        if(bankaBakiye() == 0)
        {
            puts("--------------------------------------------------------------");
            puts("Bu sefer para kalmadi ama kafana takma, paran olduğunda o buyuk para senin olucak, inaniyorum");
            return 1;
        }
        else
        {
            while (tekraroyna < 0 || tekraroyna > 1)
            {
                printf("Bir tur daha bahise ne dersin? (evet: 1, hayir: 0): ");
                scanf("%d", &tekraroyna);
            }

            if(tekraroyna == 0)
            {
                printf("Geriye kalan %d TL ile benim kumarim burda biter diyorsun :(\n", bankaBakiye());
                puts("Yine bekleriz kral, biz hep burdayiz o7");
            }
        }
    } while (tekraroyna != 0 && tekraroyna == 1);
}

unsigned long long int bankaHesap(int hesapMiktar)
{
    static int bankaToplam = 1000;

    if(hesapMiktar == 0)
    {
        return bankaToplam;
    }
    else
    {
        return (bankaToplam += hesapMiktar);
    }
}

int bankaKontrol(int kontrolMiktar)
{
    if(kontrolMiktar == 0)
    {
        return bankaHesap(0);
    }
    else if(kontrolMiktar > (bankaHesap(0)))
    {
        return kontrolMiktar;
    }
    else
    {
        return 0;
    }
}

unsigned long long int bankaBakiye(void)
{
    return bankaKontrol(0);
}

int zarRastgele(void)
{
    int zar1, zar2, zartoplam;

    zar1 = 1 + (rand() % 6);
    zar2 = 1 + (rand() % 6);
    zartoplam = zar1 + zar2;

    printf("Zarlar [%d] ve [%d] geldi, toplam: %d\n", zar1, zar2, zartoplam);
    return zartoplam;
}

int barbut(int barbutBahis)
{
    enum Durum { DEVAM, KAZANDI, KAYBETTI };
    enum Durum barbutDurum;

    int barbutToplam = zarRastgele();
    int barbutPuan;

    switch(barbutToplam)
    {
        case 7:
        case 11:
            barbutDurum = KAZANDI;
            break;

        case 2:
        case 3:
        case 12:
            barbutDurum = KAYBETTI;
            break;

        default:
            barbutDurum = DEVAM;
            barbutPuan = barbutToplam;
            printf("[Barbut Devam Ediyor...] Puan: %d\n", barbutPuan);
            break;
    }

    while (barbutDurum == DEVAM)
    {
        barbutToplam = zarRastgele();

        if(barbutToplam == barbutPuan)
        {
            barbutDurum = KAYBETTI;
        }
        else
        {
            if(barbutToplam == 7)
            {
                barbutDurum = KAYBETTI;
            }
        }
    }

    if(barbutDurum == KAZANDI)
    {
        bankaHesap(barbutBahis);
        puts("--------------------------------------------------------------");
        puts("Kazandin vay be. Katla paralari katla, Bi el daha oynamak iyi gider bunu ustune");
    }
    else
    {
        barbutBahis *= -1;
        bankaHesap(barbutBahis);

        if(bankaBakiye() > 0)
        {
            puts("--------------------------------------------------------------");
            puts("Buyuk parayi kazanmadan once kaybettigin kucuk bir paraydi bu. Bu sefer kesin kazancan");
        }
    }
}