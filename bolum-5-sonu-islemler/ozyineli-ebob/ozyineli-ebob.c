// ÖZYİNELİ FONKSİYON İLE EBOB BULMA
#include <stdio.h>

int ozebob(int, int, int, int);

int main(void)
{
    int ilk, ikinci;
    unsigned int enb, enk;

    do
    {
        printf("Ebob icin ilk sayiyi giriniz: ");
        scanf("%d", &ilk);
    } while(ilk <= 0);

    do
    {
        printf("Ebob icin ikinci sayiyi giriniz: ");
        scanf("%d", &ikinci);
    } while(ikinci <= 0);

    ilk >= ikinci ? (enb = ilk, enk = ikinci) : (enb = ikinci, enk = ilk);

    printf("%d ile %d ebob: %d\n", ilk, ikinci, ozebob(enb, enk, 1, 2));
}

int ozebob(int ebuyuk, int ekucuk, int durum, int dongu)
{
    if(ebuyuk % ekucuk == 0)
    {
        return ekucuk;
    }
    else
    {
        while(dongu <= ekucuk)
        {
            if(ebuyuk % dongu == 0 && ekucuk % dongu == 0)
            {
                return ozebob(ebuyuk, ekucuk, durum = dongu, dongu+1);
            }
            else
            {
                return ozebob(ebuyuk, ekucuk, durum, dongu+1);
            }
        }
    }

    return durum;
}