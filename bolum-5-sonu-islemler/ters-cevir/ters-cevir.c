// GİRİLEN SAYIYI TERS ÇEVİRME
#include <stdio.h>

void ters(long long int);

int main(void)
{
    long long int sayi;

    do
    {
        printf("cevirmek icin pozitif sayi giriniz: ");
        scanf("%lld", &sayi);
    } while(sayi <= 0);

    ters(sayi);
}

void ters(long long int cevir)
{
    int dongu;

    for(dongu = 1; cevir % dongu != cevir; dongu *= 10)
    {
        printf("%d ", ((cevir / dongu) % 10));
    }
    puts("");
}