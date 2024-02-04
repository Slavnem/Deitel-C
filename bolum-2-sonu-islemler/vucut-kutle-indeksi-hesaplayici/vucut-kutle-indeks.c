#include <stdio.h>

int main( void )
{
    int kutle, boy, secim;
    double dkutle, dboy, indeks;

    printf("Libre (LB) olarak mi yoksa Kutle(KG) olarak mi hesaplamak istiyorsunuz?\n");
    printf("1-Libre (LB), Inc(inc)\n2-Kutle (KG), Santimetre(cm)\n");
    printf("Secim yapiniz: ");
    scanf("%d", &secim);
    
    if(secim < 1 || secim > 2)
    {
        printf("Hatali secim yapildi! (HATA)\n");
    }
    else if(secim > 0 && secim < 3)
    {
        // INDEKS OLCUM
        printf("\nUYARI: Kilonuzu ve boyunuzu tamsayi cinsinden giriniz\n");
        
        printf("UYARI 2: Kutlenizi ve Boyunuzu sayilarin arasinda (ornek: 84 188 ,bosluk olucak sekilde giriniz\n");
        printf("\nKutleniz ve Boyunuzu giriniz: ");
        scanf("%d%d", &kutle, &boy);
            
        if(kutle <= 0 || boy <= 0)
        {
            printf("Kutle veya boy degerinden herhangi birisi 0'a esit veya kucuk olamaz! (HATA)\n");
        }
        else if(kutle > 0 && boy > 0)
        {
            dkutle = (double)kutle;
            dboy = (double)boy;
 
            if(secim == 1)
            {
                dkutle = (kutle * 0.45);
                dboy = (dboy * 2.54);
                indeks = (dkutle) / ((dboy/100) * (dboy/100));
            }
            else if(secim == 2)
            {
                indeks = (kutle) / ((dboy/100) * (dboy/100));
            }
            else
            {
                printf("Secime gore yapilan kutle ve boy indeksi hesaplanirken bilinmeyen bir hata olustu! (HATA)\n");
            }
        }
        else
        {
            printf("Kutle ve Boy kontrolu sirasinda bilinmeyen bir hata olustu! (HATA)\n");
        }

        // INDEKS DEGERLENDIRME
        if(((kutle <= 0 || boy <= 0) == 0) && indeks <= 0)
        {
            printf("Indeks = %f\nVucut Kutle Indeksi 0'a esit veya daha kucuk olamaz! (HATA)\n", indeks);
        }
        else if(indeks > 0)
        {
            printf("----------------------------------\n");

            if(indeks > 0 && indeks < 18.49)
            {
                printf("Vucut Kutle Indeksiniz = %f\n", indeks);
                printf("Ideal kilonun altindasiniz (UYARI)\n");
            }
            else if(indeks > 18.49 && indeks < 25)
            {
                printf("Vucut Kutle Indeksiniz = %f\n", indeks);
                printf("Ideal kilodasiniz (SORUNSUZ)\n");
            }
            else if(indeks > 25 && indeks < 30)
            {
                printf("Vucut Kutle Indeksiniz = %f\n", indeks);
                printf("Ideal kilonun ustundesiniz (DIKKAT EDIN)\n");
            }
            else if(indeks > 30)
            {
                printf("Vucut Kutle Indeksiniz = %f\n", indeks);
                printf("Ideal kilonun cok uzerindesiniz (TEHLIKELI)\n");
            }
            else
            {
                printf("Indeks degerlendirmesi gosterilemedi (HATA)\n");
            }

            printf("----------------------------------\n");
        }
        else
        {
            printf("Indeks degerlendirmesi bilinmeyen bir hatadan dolayi gosterilemiyor! (HATA)\n");
        }
    }
    else
    {
        printf("Secim degerlendirilemedi bilinmeyen bir hata olustu! (HATA)\n");
    }
}
