// KATSAYI KONTROL ETME
#include <stdio.h>

int katsayi(int);

int main(void)
{
    int dongu, kattest;

    for(dongu = 1; dongu <= 10; dongu++)
    {
        printf("Katsayi testi icin sayi giriniz: ");
        scanf("%d", &kattest);

        if(katsayi(kattest) == 1)
        {
            printf("%d onceki sayinin katsayisidir\n", kattest);
        }
        else
        {
            printf("%d onceki sayinin katsayisi degildir\n", kattest);
        }
    }
}

int katsayi(int kat)
{
    static int onceki = 1;

    if(kat % onceki == 0)
    {
        onceki = kat;
        return 1;
    }
    else
    {
        onceki = kat;
        return 0;
    }
}