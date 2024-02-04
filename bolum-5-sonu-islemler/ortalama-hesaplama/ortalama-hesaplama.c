// ORTALAMA HESAPLAMA
#include <stdio.h>

int ortalama(int);

int main(void)
{
    int puan = 0, ort, liste = 0;
    unsigned long long int toplam = 0;

    while(puan != 999)
    {
        printf("999 cikis, puan giriniz: ");
        scanf("%d", &puan);

        while((puan < 0 || puan > 100) && puan != 999)
        {
            printf("Puani dogru giriniz: ");
            scanf("%d", &puan);
        }

        if(puan == 999)
        {
            break;
        }
        else
        {
            toplam += puan;
            liste += 1;
        }
    }

    if(liste == 0)
    {
        ort = 0;
    }
    else
    {
        ort = (toplam / liste);
    }
    
    printf("Notlarin ortalamasi: %d [%d]\n", ortalama(ort), ort);
}

int ortalama(int puanort)
{
    int notseviye, tampuan = 90;

    for(notseviye = 4; puanort < tampuan && tampuan >= 60; notseviye -= 1, tampuan -= 10);

    return notseviye;
}