// MAİN FONKSİYONU ÖZYİNELEMELİ
#include <stdio.h>

int sayacmain = 0;

int main(int sayac)
{
    if(sayacmain <= 5)
    {
        printf("%d\n", sayacmain);
        main(sayacmain +=1);
    }
}