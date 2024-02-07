// Slavnem
// Çek Koruma
// ==========
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ön işlemci tanımları
#define SIZE 9

#define AFDOB 3 // .00 kısmının uzunluğu
#define BASLIMIT 3 // basamak limiti
#define BASEMOD 3 // basamak değeri

#define MIN_CEK 1.00 // en düşük çek miktarı

#define ASCII_COMMA 44 // ASCII standartına göre virgül
#define ASCII_NUM_START 48 // ASCI standartına göre rakam başlangıcı

// main
int main(void)
{
    char cek[SIZE]; // çek metnini tutacak

    double cektutar; // çek tutarını tutacak
    
    int ceksayac; // boşlukları sayacak
    int miktarvirgul; // konması gereken virgül miktarını tutacak
    
    size_t cekmod;  // sayının kaç basamaklı olduğunu anlamayı sağlayacak

    // kullanıcıdan çek tutarı istemek
    // en küçük çek miktarından küçük olduğu sürece dönsün
    do
    {
        printf("Cek Tutari Giriniz: "); // kullanıcıya çıktı vermek
        fgets(cek, SIZE, stdin); // satırdaki veriyi almak

        // metini ondalıklı sayıya çevirmek
        cektutar = strtod(cek, NULL);
    } while(cektutar < MIN_CEK);

    // metin bitişi
    cek[SIZE] = '\0';

    // metin icini koruma yapma
    for(ceksayac = 0; ceksayac < SIZE; cek[ceksayac] = '*', ceksayac++);

    // bölümünden kalan kendisine eşit olana kadar
    // sayı bölünebilir demek
    for(ceksayac = 0, cekmod = 1; (int)cektutar % cekmod != (int)cektutar; cekmod *= 10, ceksayac++);

    // konulacak virgül miktarı
    if(ceksayac)
        miktarvirgul = (int)(ceksayac / BASEMOD);
    else
        miktarvirgul = 0;

    // eğer girilen tutar virgül konulacak miktardan az ise
    switch(ceksayac <= BASLIMIT)
    {
        // en fazla 3 basamak
        case 1:
            // çek metininie girilen tutarı aktarma
            // ceksayac ile ondalıksız kısım basamağı hesaplandı
            // AFDOB ile ondalıklı kısmın uzunluğu (3) eklendi
            sprintf(&cek[(SIZE - (ceksayac + AFDOB))], "%.2lf", cektutar);
        break;
        // 3 basamaktan fazla
        default:
            // ondalıklı kısmı ekleme
            sprintf(&cek[(SIZE - (AFDOB + 1))], "%.2lf", (cektutar - (int)cektutar));

            // döngü ile rakam rakam ekliyoruz
            for(ceksayac += miktarvirgul, cekmod /= 10;
                ceksayac > 0;
                ceksayac--, cekmod /= 10)
            {
                // virgül miktarı 0'dan fazla ise ve
                // sayaçdan virgül miktarı çıkarıldığında
                // ve basamak miktarına bölümünde 0 kalırsa
                // virgül koyma yapsın, virgül miktarıdan 1 düşürsün
                if(miktarvirgul &&  (ceksayac % BASEMOD == miktarvirgul))
                {
                    miktarvirgul -= 1; // virgülden 1 azaltmak
                    cekmod *= 10; // eksilmesini engellemek

                    // virgül koyup sonraki konuma geçiyoruz
                    cek[(SIZE - (ceksayac + AFDOB))] = ASCII_COMMA;
                    continue;
                }

                // ondalıklı kısımdan sonrasını da saymamız gerek
                // yoksa 7 karakterlik yer kaplaması gerekirken
                // 4 karaktere göre hesap yapmış olucak
                // konuma sayının ASCII standartına göre karşılığını
                // bulmak için ASCII standartı rakam başlangıcı ile
                // rakamı topluyoruz, bu sayede karakter olarak
                // başarılı şekilde ekliyebiliyoruz
                // (int)cektutar olmasının sebebi ise ondalıklı kısım
                // şuan için işimize yaramıyor ondan tamsayı kısmını alıyoruz
                cek[(SIZE - (ceksayac + AFDOB))] = (ASCII_NUM_START) + ((int)(cektutar / cekmod) % 10);
            }
        break;
    }

    // çek bilgisini çıktı vermek
    printf("Cek: %s\n", cek);
}