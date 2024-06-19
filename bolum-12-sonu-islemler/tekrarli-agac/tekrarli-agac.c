// Slavnem @2024-06-19
// Tekrarlı Değer İçerebilen Ağaç Yapısı

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön işlemci tanımlamaları
#define RANDOM_MIN 1 // rastgele en küçük sayı
#define RANDOM_MAX 10 // rastgele en büyük sayı

#define LIST_LIMIT 20 // liste limiti

// Ağaç yapısı
typedef struct TreeNode
{
    struct TreeNode *leftPtr; // sol kısım
    int value; // değer
    struct TreeNode *rightPtr; // sağ kısım
} TreeNode;

typedef TreeNode *TreeNodePtr;
typedef unsigned int uint;

// Fonksiyon prototipleri
int isEmpty(void *ptr);
void insert(TreeNodePtr *treePtr, int value);
void preOrder(TreeNodePtr treePtr);
void inOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

// main
int main(void)
{
    uint randcounter; // rastgele sayaç
    uint randnum; // rastgele numara için geçici değişken

    TreeNodePtr rootPtr = NULL; // ağaç kök yapısı

    // rastgele çekirdek zamanlayıcısı
    srand(time(NULL));

    // desteklenen limit kadar ağaç listesine değeri eklemek
    for(randcounter = 0; randcounter < LIST_LIMIT; randcounter++)
    {
        randnum = (rand() % RANDOM_MAX) + RANDOM_MIN; // belirli limit içinde rastgele sayı almak
        printf("%3d ", randnum); // değeri çıktı versin
        insert(&rootPtr, randnum); // kök yapıya değeri aktarsın
    }

    // ağacı önce-kök dolaş
    puts("\n\npreOrder dolasimi:");
    preOrder(rootPtr);

    // ağacı orta-kök dolaş
    puts("\n\ninOrder dolasimi:");
    inOrder(rootPtr);

    // ağacı sonra-kök dolaşımı
    puts("\n\npostOrder dolasimi:");
    postOrder(rootPtr);

    puts(""); // boş satır
}

// isEmpty
int isEmpty(void *ptr)
{
    return (ptr == NULL);
}

// insert
void insert(TreeNodePtr *treePtr, int value)
{
    // eğer ağaç boş ise
    if(isEmpty(*treePtr))
    {
        // bellek alanı ayır
        (*treePtr) = malloc(sizeof(TreeNode));

        if(isEmpty(*treePtr))
        {
            // bellek alanı oluşmamışsa hatayla sonlandır
            puts("\n\nBellek Alani Ayrilamadi *\n");
            return;
        }

        // değeri ata
        (*treePtr)->value = value;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;

        return;
    }

    // eklenecek veri geçerli düğümdeki veriden küçük ya da eşitse
    if(value < (*treePtr)->value)
        insert(&(*treePtr)->leftPtr, value);
    // eklenecek veri geçerli düğümdeki veriden daha büyük
    else
        insert(&(*treePtr)->rightPtr, value);
}

// preOrder
void preOrder(TreeNodePtr treePtr)
{
    // eğer ağaç boş değil ise
    if(!isEmpty(treePtr))
    {
        printf("%3d", treePtr->value);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

// inOrder
void inOrder(TreeNodePtr treePtr)
{
    // eğer ağaç boş değil ise dolaş
    if(!isEmpty(treePtr))
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->value);
        inOrder(treePtr->rightPtr);
    }
}

// postOrder
void postOrder(TreeNodePtr treePtr)
{
    // eğer ağaç boş değil ise
    if(!isEmpty(treePtr))
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->value);
    }
}