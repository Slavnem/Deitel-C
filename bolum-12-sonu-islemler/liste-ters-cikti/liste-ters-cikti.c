// Slavnem @2024-06-22
// Tamsayı İçeren Listeyi Ters Çıktı Vermek

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön tanımlamalar
#define RANDOM_MIN 1
#define RANDOM_MAX 100

#define LIST_LIMIT 20

// Değişken tanımlamaları
typedef unsigned int uint;

// Düğüm yapısı
typedef struct LinkedList
{
    uint value;
    struct LinkedList *nextPtr;
} LinkedList;

typedef LinkedList *LinkedListPtr;

// Fonksiyon prototipleri
int isEmpty(void *ptr);
int mallocation(LinkedListPtr *nodePtr);
void insert(LinkedListPtr *nodePtr, uint data);
void printListBackward(LinkedListPtr *nodePtr);

// main
int main(void)
{
    // liste düğümü
    LinkedListPtr linkedListPtr = NULL;

    // rastgele sayı ve döngü için değişkenler
    uint counter;
    uint randomnum;

    // çekirdek rastgele zamanlayıcısı
    srand(time(NULL));

    // liste sayı sınırına kadar dönsün
    puts("\nListe Deger Ekleme:");
    for(counter = 0; counter < LIST_LIMIT; counter++)
    {
        // rastgele sayıyı hesapla, çıktı ver ve düğüme ekle
        randomnum = (rand() % RANDOM_MAX) + RANDOM_MIN;
        printf("%-3d --> ", randomnum);
        insert(&linkedListPtr, randomnum);
    }
    puts(""); // boş satır

    // listeyi tersten yazdır
    puts("\nTersten Liste:");
    printListBackward(&linkedListPtr);
    puts(""); // boş satır
}

// isEmpty
int isEmpty(void *ptr)
{
    return (ptr == NULL);
}

// mallocation
int mallocation(LinkedListPtr *nodePtr)
{
    // bellek alanı ayırsın
    (*nodePtr) = malloc(sizeof(LinkedList));

    // bellek alanı ayrımı kontrolü
    if(isEmpty(*nodePtr))
    {
        puts("\n* Bellek Alani Ayrilamadi *");
        return 0;
    }

    // değişken değer ayarlamaları
    (*nodePtr)->value = 0;
    (*nodePtr)->nextPtr = NULL;

    return 1;
}

// inser
void insert(LinkedListPtr *nodePtr, uint data)
{
    LinkedListPtr prevPtr = NULL;
    LinkedListPtr currPtr = (*nodePtr);
    LinkedListPtr newPtr;

    // yeni düğüm için bellek alan ayrımı kontrolü
    if(!mallocation(&newPtr))
    {
        puts("\n* Yeni Dugum Icin Bellek Ayrilamadi *");
        return;
    }

    // yeni düğüme değerleri ata
    newPtr->value = data;
    newPtr->nextPtr = NULL;

    // liste düğüm sonuna kadar ve düğümdeki değer
    // ekelenecek yeni değerden küçük olana dek dönsün
    while(!isEmpty(currPtr) && currPtr->value < data)
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextPtr;
    }

    // eğer son adres boş ise, düğümün başına eklesin
    if(isEmpty(prevPtr))
    {
        newPtr->nextPtr = (*nodePtr);
        (*nodePtr) = newPtr;

        return;
    }

    // liste düğümünün sonuna eklesin
    prevPtr->nextPtr = newPtr;
    newPtr->nextPtr = currPtr;
}

// printListBackward
void printListBackward(LinkedListPtr *nodePtr)
{
    // düğüm boş olmadıkça sonuna kadar gitsin
    if(!isEmpty(*nodePtr))
        printListBackward(&(*nodePtr)->nextPtr);
    else
        return;

    // değeri çıktı versin
    printf("%-3d --> ", (*nodePtr)->value);
}