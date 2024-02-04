// RASTGELE SAYI İLE ZAR ATMA
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    unsigned int i; // sayaç

    // 20 defa dön
    for( i = 1; i <= 20; i++)
    {
        // 1'den 6'ya kadar rastgele sayı çek ve çıkışa gönder
        printf("%10d", 1 + (rand() % 6) );

        // sayaç 5'e bölünebilirse yeni satırdan başla
        if ( i % 5 == 0)
        {
            puts("");
        } // if sonu
    } // for sonu
} // main sonu