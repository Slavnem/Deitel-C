// Slavnem @2024-06-22
// Metin Ağacının Derinliğini Hesaplamak

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön tanımlamalar
#define RANDOM_LIMIT_MIN 1
#define RANDOM_LIMIT_MAX 50

#define LIST_LIMIT 10

// Değişken tanımlamaları
typedef unsigned int uint;

// Kendine referans verebilen ağaç yapısı
typedef struct TreeNode
{
    struct TreeNode *leftPtr;
    uint value;
    struct TreeNode *rightPtr;
} TreeNode;

typedef TreeNode *TreeNodePtr;

// Fonksiyon prototipleri
int isEmpty(void* ptr);
int mallocation(TreeNodePtr *nodePtr);
void insert(TreeNodePtr *nodePtr, uint data);
void depth(TreeNodePtr *nodePtr, uint* depthPtr);

// main
int main(void)
{
    // ağaç yapısı
    TreeNodePtr rootPtr = NULL;
    
    // kök derinliğini tutacak değişken
    static uint rootDepth = 0;

    // rastgele çekirdek zamanlayıcı
    srand(time(NULL));

    // rastgele değer tutmak ve sayaç için değişken
    uint random;
    uint counter;

    // limit kadar ekleme yapsın
    for(counter = 0; counter < LIST_LIMIT; counter++)
    {
        // rastgele değeri hesaplasın ve ağaca eklesin
        random = (rand() % RANDOM_LIMIT_MAX) + RANDOM_LIMIT_MIN;
        printf("%-3d ", random);
        insert(&rootPtr, random);
    }

    // ağaç derinliğini hesaplasın
    depth(&rootPtr, &rootDepth);

    // ağaç derinliğini çıktı versin
    printf("\nAgac Derinligi: %-d\n", rootDepth);
}

// isEmpty
int isEmpty(void* ptr)
{
    return (ptr == NULL);
}

// mallocation
int mallocation(TreeNodePtr *nodePtr)
{
    // bellek alanı ayır
    (*nodePtr) = malloc(sizeof(TreeNode));

    // bellek alanı ayrılmamışsa bildirip sonlansın
    if(isEmpty(*nodePtr))
    {
        puts("\n* Bellek Alani Ayrilamadi *");
        return 0;
    }

    // tanımlamalarını yapmak
    (*nodePtr)->value = 0;
    (*nodePtr)->leftPtr = NULL;
    (*nodePtr)->rightPtr = NULL;

    return 1;
}

// insert
void insert(TreeNodePtr *nodePtr, uint data)
{
    // ağaç boşsa kök olarak ekleme yapsın
    if(isEmpty(*nodePtr))
    {
        // bellek alanı oluşturulma kontrolü
        if(!mallocation(&(*nodePtr)))
        {
            puts("\n* Kok Yapisi Icin Bellek Alani Ayrilamadi *");
            return;
        }

        // tanımlamaları yap
        (*nodePtr)->value = data;
        (*nodePtr)->leftPtr = NULL;
        (*nodePtr)->rightPtr = NULL;

        return;
    }

    // eğer değer küçük kısımdan küçük ya da eşitse sol ağaca
    // küçük tarafa eklesin, değilse sağ yani büyük tarafa eklesin
    if(data <= (*nodePtr)->value)
        insert(&(*nodePtr)->leftPtr, data);
    else
        insert(&(*nodePtr)->rightPtr, data);
}

// depth
void depth(TreeNodePtr *nodePtr, uint* depthPtr)
{
    if(!isEmpty(*nodePtr))
    {
        (*depthPtr)++; // derinlik sayacını 1 arttırsın
        depth(&(*nodePtr)->leftPtr, depthPtr); // sol tarafı dolaşsın
        depth(&(*nodePtr)->rightPtr, depthPtr); // sağ tarafı dolaşsın
    }
}