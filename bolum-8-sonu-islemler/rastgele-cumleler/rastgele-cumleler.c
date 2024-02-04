// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Ön işlemci tanımları
#define KELIME 4
#define CUMLE 20
#define BOYUT 100

// Değişken tanımları
const char* const __articleCPtr[] =
{
    "the", "a", "one",
    "some", "any"
};

const char* const __nounCPtr[] =
{
    "boy", "girl", "dog",
    "town", "car"
};

const char* const __verbCPtr[] =
{
    "drove", "jumped", "ran",
    "walked", "skipped"
};

const char* const __prepositionCPtr[] =
{
    "to", "from", "over",
    "under", "on"
};

// dizileri numaralandırma
enum EDIZILER
{
    ED_ARC = 0,
    ED_NOUN,
    ED_VERB,
    ED_PREPOS
};

// dizilerin boyutlarını alma
const size_t __sizeDiziler = KELIME;
const size_t __sizeKelimeler[] =
{
    (sizeof(__articleCPtr) / sizeof(__articleCPtr[0])), // article
    (sizeof(__nounCPtr) / sizeof(__nounCPtr[0])), // noun
    (sizeof(__verbCPtr) / sizeof(__verbCPtr[0])), // verb
    (sizeof(__prepositionCPtr) / sizeof(__prepositionCPtr[0])) // preposition
};

// main
int main(void)
{
    // çekirdekten rastgele sayı almasını sağlama
    srand(time(NULL));

    char cumleDizi[CUMLE][BOYUT]; // cümleleri tutacak olan dizi
    char* kelimetemp = NULL; // geçici olarak kelime tutacak
    int rastgele; // rastgele sayıyı tutacak

    size_t sayac; // cümle sayacına ait tur numarasını tutacak
    size_t saykelime; // kelime sayacına ait tur numarasını tutacak

    // diziye ait boyut
    const size_t sizeCumle = (sizeof(cumleDizi) / sizeof(cumleDizi[0]));
    const size_t sizeCumleA = (sizeof(cumleDizi[0]) / sizeof(cumleDizi[0][0]));

    // döngü bitene kadar cümle oluştursun
    for(sayac = 0; sayac < sizeCumle; sayac++)
    {
        // herhangi bir veri olabilmesine karşın dizi satırını temizliyoruz
        strcpy(cumleDizi[sayac], "");

        // 4 tane dizi olduğu için 4 defa rastgele sayı seçmeliyiz
        for(saykelime = 0; saykelime < KELIME; saykelime++)
        {
            // anlık diziden rastgele kelime numarası seçmek
            rastgele = (rand() % (__sizeKelimeler[saykelime]));

            // rastgele bulunan sayıya göre kelime almak
            switch(saykelime)
            {
                case ED_ARC: // artcile
                    strcat(cumleDizi[sayac], __articleCPtr[rastgele]);
                    break;
                case ED_NOUN: // noun
                    strcat(cumleDizi[sayac], __nounCPtr[rastgele]);
                    break;
                case ED_VERB: // verb
                    strcat(cumleDizi[sayac], __verbCPtr[rastgele]);
                    break;
                case ED_PREPOS: // preposition
                    strcat(cumleDizi[sayac], __prepositionCPtr[rastgele]);
                    break;
            }

            // eğer son döngüye gelmemişse bir sonraki kelime için sona boşluk bırakmalı
            if(saykelime != (KELIME - 1))
                strcat(cumleDizi[sayac], " ");
            // son kelime
            else
            {
                // cümlenin başı büyük harf
                cumleDizi[sayac][0] = toupper(cumleDizi[sayac][0]);

                // cümlenin sonuna nokta
                strcat(cumleDizi[sayac], ".");
            }
        }

        printf("[%d] Cumle: %s\n", (sayac + 1) ,cumleDizi[sayac]);
    }
}