// BARBUT OYUNU
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time fonksiyonu bildirimini içerir

// oyun durumunu temsil eden sabitleri listeleme
enum Status { CONTINUE, WON, LOST };

int rollDice( void ); // fonksiyon bildirim

// main fonksiyonu program yürütmesine başlar
int main( void )
{
    int sum; // atılan zarların toplamı
    int myPoint; // kazanmak için oyuncu bu puanı yapmak zorunda

    enum Status gameStatus; // CONTINUE, WON veya LOST içerebilir

    // şimdi saati kullanarak rastgele sayı üreticisini rastgele hale getirmek
    srand( time( NULL ) );

    sum = rollDice(); // zarların ilk atışı
    
    // zarların toplamına bağlı olarak oyun durumunu belirle
    switch( sum )
    {
        // ilk atışta kazan
        case 7:
        case 11:
            gameStatus = WON; // oyun kazanılmıştır
            break;
        
        // ilk atışta kaybet
        case 2:
        case 3:
        case 12:
            gameStatus = LOST; // oyun kaybedilmiştir
            break;

        // puanı hatırla
        default:
            gameStatus = CONTINUE;
            myPoint = sum;
            printf( "Point is: %d\n", myPoint );
            break; // isteğe bağlı
    } // switch sonu

    // oyun tamamlanmadıysa
    while( CONTINUE == gameStatus )
    {
        // oyuncu atış yapmaya devam etmeli
        sum = rollDice(); // zarları tekrar at

        // oyunun durumunu belirle
        if( sum == myPoint )
        {
            gameStatus = WON; // oyun bitti, oyuncu kazandı
        } // if sonu
        else
        {
            if( 7 == sum )
            {
                // 7 atarak kaybeder
                gameStatus = LOST; // oyun bitti, oyuncu kaybetti
            } // if sonu
        } // else sonu
    } // while sonu

    // galibiyet ve mağlubiyet mesajını göster
    if( WON == gameStatus )
    {
        // oyuncu kazandı
        puts( "Player wins! " );
    } // if sonu
    else
    {
        // oyuncu kaybetti
        puts( "Player loses!" );
    } // else sonu
} // main sonu

// zarları at, toplamı hesapla ve sonuçları göster
int rollDice( void )
{
    int die1; // ilk zar
    int die2; // ikinci zar
    int workSum; // zarların toplamı

    die1 = 1 + ( rand() % 6 ); // die1 değerini rastgele seç
    die2 = 1 + ( rand() % 6 ); // die2 değerini rastgele seç
    workSum = die1 + die2; // die1 ve die2'nin toplamı

    // bu atışın sonuçlarını göster
    printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );
    return workSum; // zarların toplamını gönder
} // rollDicee fonksiyonu sonu