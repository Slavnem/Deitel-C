// Slavnem @2024-06-22
// Metin'e Ait Kelimeler İle İkili Ağaç Oluşturmak

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ön değişken isimlendirmeleri
typedef char* vstring;

// Yapı tasarımı
typedef struct StrNode
{
    struct StrNode *leftPtr;
    vstring str;
    struct StrNode *rightPtr;
} StrNode;

typedef StrNode *StrNodePtr;

// Fonksiyon prototipleri
int isEmpty(void* ptr);
int mallocation(StrNodePtr *nodePtr);
void insert(StrNodePtr *nodePtr, vstring word);
void preOrder(StrNodePtr nodePtr);
void inOrder(StrNodePtr nodePtr);
void postOrder(StrNodePtr nodePtr);

// main
int main(void)
{
    StrNodePtr rootPtr = NULL;

    // geçici depolayıcı
    char buffer[50];

    // kullanıcıdan metini almak
    printf("En fazla %d karakter olucak sekilde metin giriniz: ", (sizeof(buffer) - 1));
    fgets(buffer, (sizeof(buffer) - 1), stdin);

    // sonunu NULL olarak ayarlamak
    buffer[strlen(buffer) - 1] = '\0';

    // metini parçalamaya başla
    vstring tempWord = strtok(buffer, " ");

    // metin bitmedikçe dönsün
    while(!isEmpty(tempWord))
    {
        // kelimeyi ağaca eklesin
        insert(&rootPtr, tempWord);

        // sonraki kelimeyi al
        tempWord = strtok(NULL, " ");
    }

    // ağacı önce-kök dolaş
    puts("\npreOrder dolasimi:");
    preOrder(rootPtr);

    // ağacı orta-kök dolaş
    puts("\ninOrder dolasimi:");
    inOrder(rootPtr);

    // ağacı sonra-kök dolaşımı
    puts("\npostOrder dolasimi:");
    postOrder(rootPtr);

    puts(""); // boş satır
}

// isEmpty
int isEmpty(void* ptr)
{
    return (ptr == NULL);
}

// mallocation
int mallocation(StrNodePtr *nodePtr)
{
    // bellek alanı ayır
    (*nodePtr) = malloc(sizeof(StrNode));

    // alan ayrılmamışsa bunu bildir
    if(isEmpty(*nodePtr))
    {
        puts("\n* Bellek Alani Ayrilamadi *");
        return 0;
    }

    // alan ayrılan değilken için düzenlemeleri yap
    (*nodePtr)->str = NULL;
    (*nodePtr)->leftPtr = NULL;
    (*nodePtr)->rightPtr = NULL;

    // işlem başarılı
    return 1;
}

// insert
void insert(StrNodePtr *nodePtr, vstring word)
{
    // ana düğüm boş ise düğüm oluştursun
    if(isEmpty(*nodePtr))
    {
        // bellek alanı ayrımı kontrolü
        if(!mallocation(&(*nodePtr)))
        {
            puts("\n* Dugum Baslangici Olusturulamadi *");
            return;
        }

        // düğüm başlangıcı oluştu, ayarlamalarını yap
        (*nodePtr)->str = word;
        (*nodePtr)->leftPtr = NULL;
        (*nodePtr)->rightPtr = NULL;

        // yeni düğüm oluşturulduğu için burada sonlandırsın
        return;
    }

    // eklenecek veri geçerli düğümdeki veriden küçük ya da eşitse
    if(strcmp(word, (*nodePtr)->str) <= 0)
        insert(&(*nodePtr)->leftPtr, word);
    // eklenecek veri geçerli düğümdeki veriden daha büyük
    else
        insert(&(*nodePtr)->rightPtr, word);
}

// preOrder
void preOrder(StrNodePtr nodePtr)
{
    if(!isEmpty(nodePtr))
    {
        printf("%s --> ", (nodePtr->str));
        preOrder(nodePtr->leftPtr);
        preOrder(nodePtr->rightPtr);
    }
}

// inOrder
void inOrder(StrNodePtr nodePtr)
{
    if(!isEmpty(nodePtr))
    {
        inOrder(nodePtr->leftPtr);
        printf("%s --> ", (nodePtr->str));
        inOrder(nodePtr->rightPtr);
    }
}

// postOrder
void postOrder(StrNodePtr nodePtr)
{
    if(!isEmpty(nodePtr))
    {
        postOrder(nodePtr->leftPtr);
        postOrder(nodePtr->rightPtr);
        printf("%s --> ", (nodePtr->str));
    }
}