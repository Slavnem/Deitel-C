// Slavnem @2024-06-22
// İkili Ağaç Dolaşma Yöntemlerini Kullanarak Kuyruğa Değerleri Eklemek

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön işlemci tanımlamaları
#define RANDOM_MIN 1 // rastgele en küçük sayı
#define RANDOM_MAX 45 // rastgele en büyük sayı

#define LIST_LIMIT 15 // liste limiti

// Değişken tanımlamaları
typedef unsigned int uint;

// Ağaç yapısı
typedef struct TreeNode
{
    struct TreeNode *leftPtr; // sol kısım
    int value; // değer
    struct TreeNode *rightPtr; // sağ kısım
} TreeNode;

typedef TreeNode *TreeNodePtr;

// Kuyruk Yapısı
typedef struct QueueNode
{
    int value; // değer
    struct QueueNode *nextPtr; // sıradaki düğüm
} QueueNode;

typedef QueueNode *QueueNodePtr;

// Fonksiyon prototipleri
int isEmpty(void *ptr);
int mallocationTree(TreeNodePtr *treePtr);
int mallocationQueue(QueueNodePtr *queuePtr);
void insert(TreeNodePtr *treePtr, int data);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int data);
void levelOrder(TreeNodePtr treePtr, QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void printQueue(QueueNodePtr currentPtr);

// main
int main(void)
{
    TreeNodePtr rootPtr = NULL; // ağaç kök yapısı

    QueueNodePtr headPtr = NULL; // headPtr ilklendir
    QueueNodePtr tailPtr = NULL; // tailPtr ilklendir

    uint randcounter; // rastgele sayaç
    uint randnum; // rastgele numara için geçici değişken
    int value; // kullanıcıdan değer almak için

    // rastgele çekirdek zamanlayıcısı
    srand(time(NULL));

    // desteklenen limit kadar ağaç listesine değeri eklemek
    for(randcounter = 0; randcounter < LIST_LIMIT; randcounter++)
    {
        randnum = (rand() % RANDOM_MAX) + RANDOM_MIN; // belirli limit içinde rastgele sayı almak
        printf("%-3d ", randnum); // değeri çıktı versin
        insert(&rootPtr, randnum); // kök yapıya değeri aktarsın
    }

    // ağaç yapısını kuyruk yapısına aktar
    levelOrder(rootPtr, &headPtr, &tailPtr);

    // kuyruğu yazdır
    printQueue(headPtr);
}

// isEmpty
int isEmpty(void *ptr)
{
    return (ptr == NULL);
}

// mallocationTree
int mallocationTree(TreeNodePtr *treePtr)
{
    // bellek alanı ayır
    (*treePtr) = malloc(sizeof(TreeNode));

    // bellek alanı ayrılamadı ise
    if(isEmpty(*treePtr))
    {
        puts("\n* Agac Icin Bellek Alani Ayrilamadi *");
        return 0;
    }

    // ayarlamaları yap
    (*treePtr)->leftPtr = NULL;
    (*treePtr)->rightPtr = NULL;
    (*treePtr)->value = 0;

    return 1;
}

// mallocationQueue
int mallocationQueue(QueueNodePtr *queuePtr)
{
    // bellek alanı ayır
    (*queuePtr) = malloc(sizeof(QueueNode));

    // bellek alanı ayrılamadı ise
    if(isEmpty(*queuePtr))
    {
        puts("\n* Kuyruk Icin Bellek Alani Ayrilamadi *");
        return 0;
    }

    // ayarlamaları yap
    (*queuePtr)->nextPtr = NULL;
    (*queuePtr)->value = 0;

    return 1;
}

// insert
void insert(TreeNodePtr *treePtr, int data)
{
    // eğer ağaç boş ise
    if(isEmpty(*treePtr))
    {
        // bellek alanı ayır
        if(!mallocationTree(&(*treePtr)))
        {
            puts("\n* Kok Agac Icin Alan Olusturulamadi *");
            return;
        }

        // değerleri atamak
        (*treePtr)->value = data;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;

        return;
    }

    // eklenecek veri geçerli düğümdeki veriden küçük
    if(data < (*treePtr)->value)
        insert(&(*treePtr)->leftPtr, data);
    // eklenecek veri geçerli düğümdeki veriden daha büyük
    else if(data > (*treePtr)->value)
        insert(&(*treePtr)->rightPtr, data);
}

// enqueue
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int data)
{
    // yeni düğüm oluştur ve bellek alanı ayır
    QueueNodePtr newPtr = NULL;

    if(!mallocationQueue(&newPtr))
    {
        puts("\n* Kuyruk Icin Yeni Dugum Olusturulamadi *");
        return;
    }

    // değerleri ayarla
    newPtr->value = data;
    newPtr->nextPtr = NULL;

    // kuyruk başı boşsa kuyruğun başına ekle
    if(isEmpty(*headPtr))
        (*headPtr) = newPtr;
    else // kuyruğa ekle
        (*tailPtr)->nextPtr = newPtr;

    // kuyruğa ekle
    (*tailPtr) = newPtr;
}

// levelOrder
void levelOrder(TreeNodePtr treePtr, QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    // eğer ağaç boş değil ise dolaş
    if(!isEmpty(treePtr))
    {
        // sol tarafını dolaş
        levelOrder(treePtr->leftPtr, &(*headPtr), &(*tailPtr));
        
        // değeri kuyruğa ekle
        enqueue(&(*headPtr), &(*tailPtr), (treePtr->value));

        // sağ tarafını dolaş
        levelOrder(treePtr->rightPtr, &(*headPtr), &(*tailPtr));
    }
}

// kuyruğu yazdır
void printQueue(QueueNodePtr currentPtr)
{
    // kuyruk boş ise
    if(isEmpty(currentPtr))
    {
        puts("\n* Kuyruk bos *");
        return;
    }

    puts("\nKuyruk:");

    // kuyruğun sonu olmadığı sürece
    while(currentPtr != NULL)
    {
        printf("%d --> ", currentPtr->value);
        currentPtr = currentPtr->nextPtr;
    }

    puts("NULL");
}