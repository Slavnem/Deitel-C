// Slavnem @2024-06-14
// Listeleri Birbirine Bağlama

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data; // karakter
    struct Node *nextPtr; // sıradaki düğüm
} Node;

typedef Node *NodePtr;

// prototipler
NodePtr insertNode(NodePtr nodePtr, char value);
NodePtr concatenate(NodePtr firstNodePtr, NodePtr secondNodePtr);

// main
int main(void)
{
    // iki tane düğüm oluşturuyoruz
    Node ilkNode;
    Node ikinciNode;

    // düğümlere ilk değerlerini atama
    insertNode(&ilkNode, 'a');
    insertNode(&ikinciNode, 'B');

    // test amaçlı ilk düğüme bağlanan düğümün
    // değerinin adresini işlem öncesi çıktı vermek
    printf("Islem Oncesi: Ilk Node Next Ptr Data Addr: %p\n", &ilkNode.nextPtr->data);

    // ilk düğüme ikinci düğümü bağlama
    concatenate(&ilkNode, &ikinciNode);

    // test amaçlı ilk düğüme bağlanan düğümün
    // değerinin adresini işlem sonrası çıktı vermek
    // ve gerçek ikinci düğümün değerinin adresini çıktı vermek
    printf("Islem Sonrasi: Ilk Node Next Ptr Data Addr: %p\n", &ilkNode.nextPtr->data);
    printf("Ikinci Node Data Addr: %p\n", &ikinciNode.data);
}

// insertNode
NodePtr insertNode(NodePtr nodePtr, char value)
{
    // eğer bağlantı boş değil ise
    if(nodePtr != NULL)
    {
        // değer ata ve sonraki düğümü boş bırak
        (nodePtr)->data = value;
        (nodePtr)->nextPtr = NULL;

        // aktif düğümü döndür
        return (nodePtr);
    }

    // bağlantı (node) boş ise
    nodePtr = malloc(sizeof(Node));

    // değer ataması yap ve sonraki düğümü boş bırak
    (nodePtr)->data = value;
    (nodePtr)->nextPtr = NULL;

    // düğümü döndür
    return (nodePtr);
}

// concatenate
NodePtr concatenate(NodePtr firstNodePtr, NodePtr secondNodePtr)
{
    // eğer ilk düğüm boş ise NULL dönmelidir
    // çünkü ikinci düğüm ilkine bağlanamamış olur
    if(firstNodePtr == NULL)
    {
        (firstNodePtr)->nextPtr = NULL;
        return NULL;
    }

    // eğer ikinci düğüm boş ise ilk düğüme bağlanamaz
    // bu yüzdne ilk düğümün işaret ettiği adres NULL olur
    if(secondNodePtr == NULL)
    {
        (firstNodePtr)->nextPtr = NULL;
        return NULL;
    }

    // iki düğümde boş olmadığı için ilk düğüme
    // ikinci düğümü bağlıyoruz
    (firstNodePtr)->nextPtr = (secondNodePtr);

    // bağlantı yapılan adresi döndür
    return (firstNodePtr)->nextPtr;
}