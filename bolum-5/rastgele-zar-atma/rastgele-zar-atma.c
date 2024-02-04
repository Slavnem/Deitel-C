// RASTGELE SAYI İLE ZAR ATMA
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    unsigned int i; // sayaç
    unsigned int seed; // rastgele sayı üreticisi çekirdeği için kullanılan sayı

    printf( "%s", "Enter seed: " );
    scanf( "%u", &seed ); // işaretsiz tam sayı için %u

    srand( seed ); // rastgele sayı üreticisi çekirdeği gir

    // 10 kez dön
    for ( int i = 1; i <= 10; i++ )
    {
        // 1'den 6'ya kadar rastgele sayı seç ve çıkışa gönder
        printf( "%10d", 1 + ( rand() % 6) );

        // sayaç 5'e bölünebilirse, yeni satırdan başla
        if( i % 5 == 0 )
        {
            puts( "" );
        } // if sonu
    } // for sonu
} // main sonu