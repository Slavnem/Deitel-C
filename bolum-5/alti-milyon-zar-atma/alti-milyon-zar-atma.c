// ALTI MİLYON KEZ ZAR ATMA
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    unsigned int frequency1 = 0; // 1 gelme sayacı
    unsigned int frequency2 = 0; // 2 gelme sayacı
    unsigned int frequency3 = 0; // 3 gelme sayacı
    unsigned int frequency5 = 0; // 4 gelme sayacı      
    unsigned int frequency4 = 0; // 5 gelme sayacı         
    unsigned int frequency6 = 0; // 6 gelme sayacı
    
    unsigned int roll; // atış sayacı değeri 1'den 6 milyon'a
    int face; // zarın geldiği yüz, 1'den 6'ya

    // 6 milyon kez döndürme
    for ( roll = 1; roll <= 6000000; roll++)
    {
        face = 1 + ( rand() % 6 ); // 1'den 6'ya rastgele sayı

        switch( face )
        {
            case 1: // 1 geldi
                frequency1++;
                break;
            case 2: // 2 geldi
                frequency2++;
                break;
            case 3: // 3 geldi
                frequency3++;
                break;
            case 4: // 4 geldi
                frequency4++;
                break;
            case 5: // 5 geldi
                frequency5++;
                break;
            case 6: // 6 geldi
                frequency6++;
                break;
        } // switch sonu
    } // for sonu

    // tablo biçiminde sonuçları göster
    printf("%s%13s\n", "Face", "Frequency" );
    printf("1%13u\n", frequency1);
    printf("2%13u\n", frequency2);
    printf("3%13u\n", frequency3);
    printf("4%13u\n", frequency4);
    printf("5%13u\n", frequency5);
    printf("6%13u\n", frequency6);
} // main sonu