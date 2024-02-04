#include <stdio.h>

int main( void )
{
    int testsayi;
    unsigned int birlerb, onlarb, yuzlerb, binlerb, onbinlerb;

    printf("Bes basamakli bir sayi giriniz ve palindrom testi yapalim: ");
    scanf("%d", &testsayi);

    while(testsayi < 10000 || testsayi > 99999)
    {
        printf("Hatali sayi! Bes basamakli olmak zorunda (Cikis: 0): ");
        scanf("%d", &testsayi);

        if(testsayi == 0)
        {
            printf("Cikis onaylandi! Program sonlandiriliyor...\n");
            return 0;
        }
        else if((testsayi < 10000 || testsayi > 99999) && testsayi != 0)
        {
            printf("Fazla hatali giris! Program sonlandiriliyor...\n");
            return 0;
        }
        else if(testsayi > 9999 && testsayi < 100000)
        {
            //BOS
        }
        else
        {
            printf("Sayi kontrol edilirken bilinmeyen bir hata olustu! (HATA)\n");
        }
    }

    onbinlerb = (int)(testsayi / 10000);
    binlerb = (int)((testsayi / 1000) % 10);
    yuzlerb = (int)((testsayi / 100) % 10);
    onlarb = (int)((testsayi / 10) % 10);
    birlerb = (int)((testsayi / 1) % 10);

    if(onbinlerb == birlerb && binlerb == onlarb)
    {
        printf("Girdiginiz sayi [%d], palindrom sayidir! (BASARILI)\n", testsayi);
    }
    else if(onbinlerb != birlerb || binlerb != onlarb)
    {
        printf("Girdiginiz sayi [%d], palindrom sayi degildir! (BASARISIZ)\n", testsayi);
    }
}
