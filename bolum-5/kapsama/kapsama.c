// KAPSAMA (Yerel[local] - Küresel[global] - Statik[static])
#include <stdio.h>

void useLocal( void ); // fonksiyon bildirimi
void useStaticLocal( void ); // fonksiyon bildirimi
void useGlobal( void ); // fonksiyon bildirimi

int x = 1; // genel değişken

int main( void )
{
    int x = 5; // main'e yerel değişken

    printf("local x in outer scope of main is %d\n", x);

    {
        // yeni kapsam başlar
        int x = 7; // yeni kapsam yerel değişken

        printf("local x in inner scope of main is %d\n", x);
    } // yeni kapsam sonu

    printf("local x in inner scope of main is %d\n", x);

    useLocal(); // useLocal'in otomatik yerel x'i vardır
    useStaticLocal(); // useStaticLocal'in static yerel x'i vardır
    useGlobal(); // useGlobal genel x'i kullanır
    useLocal(); // useLocal otomatik yerel x'e tekrar başlangıç değeri verir
    useStaticLocal(); // static yerel x önceki değerini korur
    useGlobal(); // genel x de değerini korur

    printf("\nlocal x in main is: %d\n", x);   
} // main sonu

// useLocal her çağrıda x yerel değişkenine yeniden başlangıç değeri verir
void useLocal( void )
{
    int x = 25; // useLocal her çağrıldığında başlangıç değeri verilir

    printf("\nlocal x in useLocal is %d after entering useLocal\n", x);
    x++;
    printf("local x in useLocal is %d before exiting useLocal\n", x);
} // useLocal fonksiyonu sonu

// useStaticLocal static x yerel değişkenine fonksiyon yalnızca ilk çağrıldığı
// zaman başalngıç değeri verilir. x'in değeri bu fonksiyona yapılan çağrılar
// arasında saklanır
void useStaticLocal( void )
{
    // program başlamadan önce başlangıç değeri verilir
    static int x = 50;

    printf("\nlocal static x is %d on entering useStaticLocal\n", x);
    x++;
    printf("local static x is %d on exiting useStaticLocal\n", x);
} // useStaticLocal fonksiyonu sonu

// useGlobal fonksiyonu her çağrıda x genel değişkenini değiştirir
void useGlobal( void )
{
    printf("\nglobal x is %d on entering useGlobal\n", x);
    x *= 10;
    printf("global x is %d on exiting useGlobal\n", x);
} // useGlobal fonksiyonu sonu