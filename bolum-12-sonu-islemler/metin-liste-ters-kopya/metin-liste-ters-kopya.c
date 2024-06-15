// Slavnem @2024-06-15
// Metin İçeren Bağlı Liste Oluşturup Tersten Kopyasını Oluşturma

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// kendine işaret eden metin yapısı
typedef struct StrNode
{
    char str[11]; // 10 + 1(NULL) karakterli bir dizi
    struct StrNode *nextPtr; // sıradaki düğüm
} StrNode;

typedef StrNode *StrNodePtr;

// prototipler
int isEmpty(StrNodePtr nodePtr);
void insert(StrNodePtr *nodePtr, char* str);
void reverse(StrNodePtr *nodePtr, StrNodePtr *reverseNodePtr);
void printList(StrNodePtr nodePtr);

// main
int main(void)
{
    StrNodePtr stringNode = NULL;
    StrNodePtr stringReverseNode = NULL;

    // bu diziye test amaçlı metinler eklemek
    insert(&stringNode, "DeneMe MEt");
    insert(&stringNode, "Blabla42blab32la");
    insert(&stringNode, "Slavnem Technology");

    // Listenin orijinal hali
    printf("Orjinal Liste:\n");
    printList(stringNode);

    // tersten kopyalama yaptırma...
    reverse(&stringNode, &stringReverseNode);

    // Ters listeyi yazdırma
    printf("Ters Liste:\n");
    printList(stringReverseNode);
}

// isEmpty
int isEmpty(StrNodePtr nodePtr)
{
    return (nodePtr == NULL);
}

// insert
void insert(StrNodePtr *nodePtr, char* str)
{
    // yeni düğüm oluşturup bellek alanı ayırma ve
    // aktif düğümün adresini geçici olarak tutmak
    StrNodePtr newPtr;
    StrNodePtr currPtr = (*nodePtr);
    StrNodePtr prevPtr = NULL;

    newPtr = malloc(sizeof(StrNode));

    // alan oluşturulmamılşsa hata çıktısı
    if(isEmpty(newPtr))
    {
        puts("\n\n* Bellek Alani Ayirilamadi *\n");
        return;
    }

    // metini kopyalamak ve null sonlandırıcısı eklemek
    strncpy(newPtr->str, str, sizeof(newPtr->str) - 1);
    newPtr->str[sizeof(newPtr->str - 1)] = '\0';

    newPtr->nextPtr = NULL; // sıradaki düğüm boş

    // liste sonuna kadar git
    while(!isEmpty(currPtr))
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextPtr;
    }

    // eğer düğüm boş ise direk düğümün başına eklesin
    if(isEmpty(prevPtr))
    {
        newPtr->nextPtr = (*nodePtr);
        (*nodePtr) = newPtr;
    }
    else
    {
        // yeni düğümü listenin sonuna ekle
        prevPtr->nextPtr = newPtr;
        newPtr->nextPtr = currPtr;
    }
}

// reverse
void reverse(StrNodePtr *nodePtr, StrNodePtr *reverseNodePtr)
{
    // geçerli düğüm boşsa sonlandırsın
    if(isEmpty(*nodePtr))
    {
        return;
    }

    // şuanki düğümü geçici olarak sakla
    StrNodePtr tempNodePtr = (*nodePtr);

    // Yeni bir düğüm oluştur
    StrNodePtr newPtr;
    newPtr = malloc(sizeof(StrNode));

    // bellek alanı oluşmamış
    if(isEmpty(newPtr))
    {
        // yeni bellek alanı açılamıyor
        // o zamana kadar kaydedilen düğüm döndürülsün
        puts("\n\n* Bellek Alani Ayrilamadi *\n");
        return;
    }

    // değeri düğüme ekle
    strncpy(newPtr->str, tempNodePtr->str, (sizeof(tempNodePtr->str) - 1));
    newPtr->str[(sizeof(newPtr->str) - 1)] = '\0'; // dizi sonu NULL sonlandırma

    // yeni düğümü ters listeye ekle
    newPtr->nextPtr = (*reverseNodePtr);
    (*reverseNodePtr) = newPtr;

    // düğüm sonuna kadar fonksiyon kendini özyinelesin
    reverse(&(tempNodePtr->nextPtr), &(*reverseNodePtr));
}

// printList
void printList(StrNodePtr currentPtr)
{
    // liste boş ise
    if(isEmpty(currentPtr))
    {
        puts("Liste Bos\n");
        return;
    }

    // listenin sonuna gelinmediği sürece
    while(!isEmpty(currentPtr))
    {
        printf("%s --> ", currentPtr->str);
        currentPtr = currentPtr->nextPtr;
    }

    puts("NULL\n");
}