// EN BÜYÜK ORTAK BÖLEN (EBOB) BULMA
#include <stdio.h>

long int ebob(long long int, long long int);

int main(void)
{
    long long int ilksayi, ikincisayi;

    do
    {
        printf("Ilk sayiyi giriniz: ");
        scanf("%lld", &ilksayi);
    } while(ilksayi <= 0);

    do
    {
        printf("Ikinci sayiyi giriniz: ");
        scanf("%lld", &ikincisayi);
    } while(ikincisayi <= 0);

    printf("Ilk[%lld] ve ikinci[%lld] sayiya ait ebob: %ld\n", ilksayi, ikincisayi, ebob(ilksayi, ikincisayi));
}

long int ebob(long long int ilk, long long int ikinci)
{
    long int durum = 1, dongu, enkucuk;

    ilk < ikinci ? (enkucuk = ilk) : (enkucuk = ikinci);

    if(ilk == 1 || ikinci == 1)
    {
        return durum;
    }
    else
    {
        for(dongu = 2; dongu <= enkucuk; dongu++)
        {
            if(ilk % dongu == 0 && ikinci % dongu == 0)
            {
                durum = dongu;
            }
        }
    }

    return durum;
}