// ÇOKLU TABAN ARİTMETİĞİ
// 1'DEN 256'YA KADAR 10'AR 10'AR ARTACAK ŞEKİLDE 2Lİ 8Lİ 10LU 16LI TABAN ARTİMETİĞİNİ BUL
#include <stdio.h>

int main( void )
{
    for(int i = 10; i < 256; i+= 10)
    {
        unsigned int yedek = i;
        
        printf("%d ikilik sistem: ", i);
        for(;yedek >= 2;)
        {
            printf("%d", (yedek % 2));
            yedek /= 2;
        }

        if(yedek < 2)
        {
            printf("%d", yedek % 2);
        }

        printf("\n");

        yedek = i;
        printf("%d sekizlik sistem: ", i);
        for(;yedek >= 8;)
        {
            printf("%d", (yedek % 8));
            yedek /= 8;
        }

        if(yedek < 8)
        {
            printf("%d", yedek % 8);
        }

        printf("\n");

        yedek = i;
        printf("%d onluk sistem: ", i);
        for(;yedek >= 10;)
        {
            printf("%d", (yedek % 10));
            yedek /= 10;
        }

        if(yedek < 10)
        {
            printf("%d", yedek % 10);
        }

        printf("\n");

        yedek = i;
        printf("%d onaltilik sistem: ", i);
        for(;yedek >= 16;)
        {
            printf("%d", (yedek % 16));
            yedek /= 16;
        }

        if(yedek < 16)
        {
            printf("%d", yedek % 16);
        }

        printf("\n");

        puts("TERSTEN OKUYUN!");
    }

    /*for(int i = 10; i < 11; i += 10)
    {
        unsigned int yedekSayi, ikiAritmetik = i, sekizAritmetik = i, onAritmetik = i, onaltiAritmetik = i;

        printf("%d Ikilik sistem: ", i);
        for(;ikiAritmetik > 1; ikiAritmetik = (int)(i / 2))
        {
            printf("%u", (ikiAritmetik % 2));
        }
    }*/

    /*int a = 20;

    //printf("%d\n", (a / 2));
    printf("%d\n", (a % 2));

    a = a/2;

    //printf("%d\n", (a / 2));
    printf("%d\n", (a % 2));

     a = a/2;

    //printf("%d\n", (a / 2));
    printf("%d\n", (a % 2));


 a = a/2;

    //printf("%d\n", (a / 2));
    printf("%d\n", (a % 2));

    if(a / 2 < 1)
    {
        printf("%d\n", a);
    }*/

}