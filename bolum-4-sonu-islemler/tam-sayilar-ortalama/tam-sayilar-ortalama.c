//Tam Sayılar Ortalama
#include <stdio.h>

int main( void )
{
    unsigned int toplam = 0, tur = 0;
    float ortalama = 0.0f;
    int sayi;

    while(sayi != 9999)
    {
        printf("Bir sayi giriniz: ");
        scanf("%d", &sayi);

        if(sayi == 9999)
        {
            printf("Suana kadar ki sayilarin ortalamasi = %.2f\n", ortalama);
            printf("Cikis degeri girildi! Program sonlandiriliyor...\n");
            break;
        }

        while(sayi < 1)
        {
            printf("Pozitif olmalidir. Bir sayi giriniz: ");
            scanf("%d", &sayi);
        }

        tur += 1;
        toplam += sayi;
        ortalama = toplam / tur;
    }
}