// Slavnem @2024-06-22
// İkili Ağaçta İstenen Değerin Adresini Döndürmek ya da NULL Döndürmek

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön işlemci tanımlamaları
#define RANDOM_MIN 1 // rastgele en küçük sayı
#define RANDOM_MAX 20 // rastgele en büyük sayı

#define LIST_LIMIT 10 // liste limiti

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
int mallocation(TreeNodePtr *treePtr);
void insert(TreeNodePtr *treePtr, int value);
void* binaryTreeSearch(TreeNodePtr *treePtr, int data);

// main
int main(void)
{
    TreeNodePtr rootPtr = NULL; // ağaç kök yapısı

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

    // kullanıcıdan değeri almak
    printf("\nAramak istediginiz degeri giriniz: ");
    scanf("%d", &value);

    // değeri arat ve bulunup bulunmamaya göre değeri çıktı versin
    printf("Aranan Deger [%d] Adresi: %p\n", value, binaryTreeSearch(&rootPtr, value));
}

// isEmpty
int isEmpty(void *ptr)
{
    return (ptr == NULL);
}

// mallocation
int mallocation(TreeNodePtr *treePtr)
{
    // bellek alanı ayır
    (*treePtr) = malloc(sizeof(TreeNode));

    // bellek alanı ayrılamadı ise
    if(isEmpty(*treePtr))
    {
        puts("\n* Bellek Alani Ayrilamadi *");
        return 0;
    }

    // ayarlamaları yap
    (*treePtr)->leftPtr = NULL;
    (*treePtr)->rightPtr = NULL;
    (*treePtr)->value = 0;

    return 1;
}

// insert
void insert(TreeNodePtr *treePtr, int value)
{
    // eğer ağaç boş ise
    if(isEmpty(*treePtr))
    {
        // bellek alanı ayır
        if(!mallocation(&(*treePtr)))
        {
            puts("\n* Kok Agac Alan Olusturulamadi *");
            return;
        }

        // değeri ata
        (*treePtr)->value = value;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;

        return;
    }

    // eklenecek veri geçerli düğümdeki veriden küçük
    if(value < (*treePtr)->value)
        insert(&(*treePtr)->leftPtr, value);
    // eklenecek veri geçerli düğümdeki veriden daha büyük
    else if(value > (*treePtr)->value)
        insert(&(*treePtr)->rightPtr, value);
}

// binaryTreeSearch
void* binaryTreeSearch(TreeNodePtr *treePtr, int data)
{
    // düğüm boş değil ve değer eşleşti ise adresini döndür
    if(!isEmpty(*treePtr) && (*treePtr)->value == data)
        return (TreeNodePtr)(*treePtr);

    // düğüm sonuna gelinmiş ama bulunamamışsa NULL döndürsün
    if(isEmpty(*treePtr))
        return NULL;

    // değer eğer ağaçdaki değerden büyük ise sağ yöne
    // değilse sol yöne göre devam etsin
    if((*treePtr)->value < data) // sağa doğru
        binaryTreeSearch(&(*treePtr)->rightPtr, data);
    else // sola doğru
        binaryTreeSearch(&(*treePtr)->leftPtr, data);
}