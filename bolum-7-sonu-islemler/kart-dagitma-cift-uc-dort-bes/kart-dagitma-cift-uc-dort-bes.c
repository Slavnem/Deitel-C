// Kart karistirma ve dagitma
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS (SUITS * FACES)

// prototipler
// ++shuffle
void shuffle(unsigned int wDeck[][FACES]); // karistirma wDeck uzerinde degisiklik yapar
// ++deal
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[]); // dagitmak diziler uzerinde degisiklik yapmaz

// +main
int main(void)
{
    // suit dizisini yukle
    const char* suit[SUITS] = { "Hearts","Diamonds","Clubs","Spades" };

    // face dizisini yukle
    const char* face[FACES] = {
    "Ace","Deuce","Three","Four",
    "Five","Six","Seven","Eight",
    "Nine","Ten","Jack","Queen","King" };

    // deck dizisini yukle
    unsigned int deck[SUITS][FACES] = { 0 };

    srand(time(NULL)); // cekirdek rastgele sayi uretici

    shuffle(deck); // desteyi karistir
    deal(deck, face, suit); // desteyi dagit
}
// -main

// deck icerisindeki kartlari karistir
// +shuffle
void shuffle(unsigned int wDeck[][FACES])
{
    size_t row; // satir numarasi
    size_t column; // sutun numarasi
    size_t card; // sayac

    // kartlarin herbiri icin deck yuvasini rastgele olarak sec
    for (card = 1; card < CARDS; ++card)
    {
        // kullanilmayan yuva bulunana kadar rastgele olarak sec
        do
        {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0); // do...while blogu sonu

        // secilen deck yuvasi icerisine kart numarasini yerlestir
        wDeck[row][column] = card;
    } // for blogu sonu
}
// -shuffle

// deck icerisindeki kartlari dagit
// +deal
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[])
{
    // ++Printer
    void Printer(const char* [], const char* [], const unsigned int*, unsigned int, unsigned int);

    // ++flosPrinter
    void flosPrinter(const char*, unsigned int[], unsigned int);

    const char* wToplu[] = { "tekli", "ciftli", "uclu", "dortlu", "besli" };

    size_t card; // kart sayaci
    size_t row; // satir sayaci
    size_t column; // sutun sayaci

    size_t wface_sayac = 1; // sayac

    const char* wgecici = wSuit[0]; // geciciye dizinin ilk elemanini veriyoruz

    unsigned int tgecici = 0;
    unsigned int wcFace[SUITS] = { 0 };
    unsigned int wuFace[SUITS] = { 0 };
    unsigned int wdFace[SUITS] = { 0 };
    unsigned int wbFace[FACES] = { 0 };

    // kartlarin herbirini dagit
    for (card = 1; card <= CARDS; ++card)
    {
        // wDeck satirlari boyunca dongu olustur
        for (row = 0; row < SUITS; ++row)
        {
            // gecerli satir icin wDeck sutunlari boyunca dongu olustur
            for (column = 0; column < FACES; ++column)
            {
                // eger slot gecerli karti iceriyorsa karti goruntule
                if (wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t'); // 2 sutun bicimi

                    if (wgecici == wSuit[row])
                    {
                        ++wface_sayac;
                    }
                    else
                    {
                        if (wface_sayac == 2)
                        {
                            ++wcFace[tgecici];
                        }
                        if (wface_sayac == 3)
                        {
                            ++wuFace[tgecici];
                        }
                        else if (wface_sayac == 4)
                        {
                            ++wdFace[tgecici];
                        }
                        else if (wface_sayac == 5)
                        {
                            ++wbFace[tgecici];
                        }

                        wface_sayac = 1;
                        wgecici = wSuit[row];
                        tgecici = row;

                        // test: degerlere yeni baslangic degeri veriyormu kontrol ciktisi
                        // printf("\nsayac: %zu\twgecici: %s\ttgecici: %hd\n",wface_sayac, wgecici, tgecici);
                    }

                    // test: ekrana kart, kart numarasini ve sayacin ciktisini verme kontrol ciktisi
                    // printf("\nsayac: %zu\twgecici: %s\ttgecici: %hd\n", wface_sayac, wgecici, tgecici);
                } // if blogu sonu
            } // for blogu sonu
        } // for blogu sonu
    } // for blogu sonu

    puts("\n");
    Printer(wSuit, wToplu, &wcFace[0], 2, SUITS);

    puts("\n");
    Printer(wSuit, wToplu, &wuFace[0], 3, SUITS);

    puts("\n");
    Printer(wSuit, wToplu, &wdFace[0], 4, SUITS);

    puts("\n");
    Printer(wSuit, wToplu, &wbFace[0], 5, SUITS);
}
// -deal

// +Printer
void Printer(
    const char* wSuit[],
    const char* wToplu[],
    const unsigned int* countArray,
    unsigned int number,
    unsigned int limit
)
{
    size_t counter;
    unsigned int miktar;

    printf("%s\n", wToplu[number - 1]);
    puts("===================");

    for (counter = 0; counter < limit; counter++)
    {
        miktar = *(countArray + counter);

        if (miktar >= 1)
        {
            printf("%5s %hd %s %s\n",
                wSuit[counter], miktar, "tane", wToplu[number - 1]);
        }
    }
}
