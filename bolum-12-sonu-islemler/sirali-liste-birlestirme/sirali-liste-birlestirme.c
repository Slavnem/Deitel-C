// Slavnem @2024-06-15
// Sıralı Listeleri Birleştirme

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
    int value;
    struct IntNode *nextPtr;
} IntNode;

typedef IntNode *IntNodePtr;

// prototipler
int insert(IntNodePtr *nodePtr, int value);
void merge(IntNodePtr *firstNodePtr, IntNodePtr *secondNodePtr);
int isEmpty(IntNodePtr nodePtr);
void printList(IntNodePtr currentPtr);

// main
int main(void)
{
    IntNodePtr ilkSayilar = NULL;
    IntNodePtr ikinciSayilar = NULL;

    // NOT!
    // test amaçlı olduğu için kullanıcıdan veri almıyoruz

    // ilk düğüme sayılar ekliyoruz
    insert(&ilkSayilar, 1);
    insert(&ilkSayilar, 3);
    insert(&ilkSayilar, 6);

    // ikinci düğüme sayılar ekliyoruz
    insert(&ikinciSayilar, 2);
    insert(&ikinciSayilar, 4);
    insert(&ikinciSayilar, 5);

    // test çıktısı 1
    printList(ilkSayilar);

    // iki listeyi birleştir
    merge(&ilkSayilar, &ikinciSayilar);

    // test çıktısı birleştirme 1
    printList(ilkSayilar);
}

// insert
int insert(IntNodePtr *nodePtr, int value)
{
    IntNodePtr newPtr; // yeni düğüm
    IntNodePtr prevPtr = NULL; // önceki düğüm
    IntNodePtr currPtr = *nodePtr; // aktif düğüm

    // düğüme bellek alanı ayır
    newPtr = malloc(sizeof(IntNode));

    // alan erişilebilir değil ise
    if(newPtr == NULL)
    {
        puts("\n\n *Gecerli Bellek Alani Ayirilamiyor *\n");
        return -1;
    }

    // alan erişlebilir olduğu için atama yapıyoruz
    newPtr->value = value;
    newPtr->nextPtr = NULL;

    // listede geçerli düğüm boş değilse ve
    // girilen değer listedeki değerden büyük ise devam etsin
    while(currPtr != NULL && value > currPtr->value)
    {
        prevPtr = currPtr; // öncekinde şuanki olanı sakla
        currPtr = currPtr->nextPtr; // şimdikine sonraki düğümü ver
    }

    // eğer önceki düğüm boş ise listenin başına veri ekle
    if(prevPtr == NULL)
    {
        newPtr->nextPtr = *nodePtr;
        *nodePtr = newPtr;
    }
    else
    {
        // önceki düğümün işaret ettiği düğüm
        // yeni oluşturudğumuz düğüm olur
        // yeni düğüm ise sonraki düğüm için
        // aktif düğümü seçer ve bu sayede
        // iki düğümün arasına eklenmiş olur

        prevPtr->nextPtr = newPtr;
        newPtr->nextPtr = currPtr;
    }

    // eklenen değeri döndür
    return newPtr->value;
}

// merge
void merge(IntNodePtr *firstNodePtr, IntNodePtr *secondNodePtr)
{
    IntNodePtr createNode = malloc(sizeof(IntNode)); // geçici baş düğüm
    IntNodePtr currPtr = createNode; // geçici liste başı

    IntNodePtr mainNodePtr = (*firstNodePtr); // ilk düğümün adresi
    IntNodePtr mergNodePtr = (*secondNodePtr); // birleştirilecek düğümün adresi

    // eğer eklenecek düğüm boş ise hata çıktısıyla bildirsin
    if(isEmpty(*secondNodePtr))
    {
        puts("\n\n* Veri Eklenecek Dugum Bos *\n");
        return;
    }

    // herhangi birisi boş olana dek dönsün
    while(!isEmpty(mainNodePtr) && !isEmpty(mergNodePtr))
    {
        // eğer ilk düğümdeki değer ikinci düğümden büyük değilse
        // değer birleştirme yapmadan dönmeye devam etsin
        if(mainNodePtr->value <= mergNodePtr->value)
        {
            // ana düğümü bağla ve sonraki düğüme geçirt
            currPtr->nextPtr = mainNodePtr;
            mainNodePtr = mainNodePtr->nextPtr;
        }
        else
        {
            // birleştirilecek düğümü bağla ve sonraki düğüme geçirt
            currPtr->nextPtr = mergNodePtr;
            mergNodePtr = mergNodePtr->nextPtr;
        }

        // düğüme bağla
        currPtr = currPtr->nextPtr;
    }

    // düğümlerden biri biterse diğerini bağla
    currPtr->nextPtr = (mainNodePtr != NULL) ? (mainNodePtr) : (mergNodePtr);

    // ilk listenin başlangıç noktasını güncelle
    *firstNodePtr = createNode->nextPtr;

    // geçici düğümü serbest bırak
    free(createNode);
    createNode = NULL;
}

// isEmpty
int isEmpty(IntNodePtr nodePtr)
{
    return (nodePtr == NULL);
}

// listeyi yazdır
void printList(IntNodePtr currentPtr)
{
    // liste boş ise
    if(currentPtr == NULL)
    {
        puts("Liste Bos\n");
        return;
    }

    puts("Liste:");

    // listenin sonuna gelinmediği sürece
    while(currentPtr != NULL)
    {
        printf("%d --> ", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }

    puts("NULL\n");
}