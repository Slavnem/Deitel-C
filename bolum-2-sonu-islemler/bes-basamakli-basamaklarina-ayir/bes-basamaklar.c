#include <stdio.h>

int main( void )
{
    int besbasamak, onbinbas, binbas, yuzbas, onbas, birbas;

    printf("Bes basamakli bir sayi giriniz: ");
    scanf("%d", &besbasamak);

    if(besbasamak < 10000 || besbasamak > 99999)
    {
        printf("%d bes basamakli bir sayi degildir! (HATA)\n", besbasamak);
    }
    else if(besbasamak > 9999 && besbasamak < 100000)
    {
        onbinbas = (besbasamak / 10000);
        binbas = ((besbasamak / 1000) % 10);
        yuzbas = ((besbasamak / 100) % 10);
        onbas = ((besbasamak / 10) % 10);
        birbas = (besbasamak % 10);

        printf("Girilen sayi = %d\n", besbasamak);
        printf("On binler basamagi: %d\n", onbinbas);
        printf("Binler basamagi: %d\n", binbas);
        printf("Yuzler basamagi: %d\n", yuzbas);
        printf("Onlar basamagi: %d\n", onbas);
        printf("Birler basamagi: %d\n", birbas);
        printf("Basamak Sira: %d   %d   %d   %d   %d\n", onbinbas, binbas, yuzbas, onbas, birbas);
    }
    else
    {
        printf("Bilinmeyen bir hata olustu! (HATA)\n");
    }
}
