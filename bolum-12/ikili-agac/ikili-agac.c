// Slavnem @2024-06-08
// İkili Ağaç (Binary Tree) Oluşturma ve Dolaşma

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// kendine referans verebilen yapı
struct treeNode
{
    struct treeNode *leftPtr; // sol alt ağaç işaretçisi
    int data; // düğüm değeri
    struct treeNode *rightPtr; // sağ alt ağaç işaretçisi
};

typedef struct treeNode TreeNode; // treeNode yapısı için eş anlamlı
typedef TreeNode *TreeNodePtr; // TreeNode* için eş anlamlı

// prototipler
void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

// main
int main(void)
{
    unsigned int i; // 1-10 döngü için sayaç
    int item; // rastgele sayıları tutmak için değişken
    TreeNodePtr rootPtr = NULL; // ağaç başlangıçta boş

    srand(time(NULL));
    puts("Agaca yerlestirilmis sayilar:");

    // 0 ve 14 arasında rastgele değerleri ağaca ekle
    for(i = 1; i <= 10; i++)
    {
        item = rand() % 15;
        printf("%3d", item);
        insertNode(&rootPtr, item);
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

// ağaca düğüm ekle
void insertNode(TreeNodePtr *treePtr, int value)
{
    // eğer ağaç boş ise
    if(*treePtr == NULL)
    {
        *treePtr = malloc(sizeof(TreeNode));

        // bellek ayrılmış ise verileri ata
        if(*treePtr != NULL)
        {
            ( *treePtr )->data = value;
            ( *treePtr )->leftPtr = NULL;
            ( *treePtr )->rightPtr = NULL;
        }
        else
        {
            printf("%d eklenemedi. Bellek musait degi\n", value);
        }
    }
    else
    {
        // eklenecek veri geçerli düğümdeki veriden daha küçük
        if(value < ( *treePtr )->data)
        {
            insertNode(&(( *treePtr )->leftPtr), value);
        }
        // eklenecek veri geçerli düğümdeki veriden daha büyük
        else if(value > ( *treePtr )->data)
        {
            insertNode(&(( *treePtr )->rightPtr), value);
        }
        // tekrar eden veri değeri göz ardı edilir
        else
        {
            printf("%s", " dup ");
        }
    }
}

// ağacı orta-kök dolaşmayla başla
void inOrder(TreeNodePtr treePtr)
{
    // eğer ağaç boş değil ise dolaş
    if(treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

// ağacı önce-kök dolaşmaya başla
void preOrder(TreeNodePtr treePtr)
{
    // eğer ağaç boş değil ise
    if(treePtr != NULL)
    {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

// ağacı sonra-kök dolaşmaya başla
void postOrder(TreeNodePtr treePtr)
{
    // eğer ağaç boş değil ise
    if(treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}