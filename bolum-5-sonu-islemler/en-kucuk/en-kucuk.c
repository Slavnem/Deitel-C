// GİRİLEN SAYILARDAN EN KÜÇÜĞÜ BULAN FONKSİYON
#include <stdio.h>

int main(void)
{
    int dongu, tur;
    float sayi, enkucuk = 0;

    do
    {
        printf("Kac tane sayi girmek istersiniz [2-10]: ");
        scanf("%d", &tur);
    } while(tur <= 1 || tur > 10);

    for(dongu = 1; dongu <= tur; dongu++)
    {
        printf("%d) sayiyi giriniz [0.0]: ", dongu);
        scanf("%f", &sayi);

        if(sayi < enkucuk)
        {
            enkucuk = sayi;
        }
    }

    printf("Girdiginiz %d tane sayidan en kucugu: %f\n", tur, enkucuk);
}