// Slavnem @2024-06-07
// Basit Bir Yığın Programı

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// kendine referans verebilen yapı
struct stackNode
{
    int data; // data değişkenini int olarak tanımla
    struct stackNode *nextPtr; // stackNode işaretçisi
};

typedef struct stackNode StackNode; // stackNode yapısı için eş anlamlı
typedef StackNode *StackNodePtr; // StackNode* yapısı için eş anlamlı

// prototipler
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

// main
int main(void)
{
    StackNodePtr stackPtr = NULL; // yığının tepesine işaret eder
    unsigned int choice; // kullanıcı menü seçimi
    int value; // kullanıcı tamsayı giriş değeri

    instructions(); // menü görüntüle
    printf("%s", "? ");
    scanf("%u", &choice);

    // kullanıcı 3 girmediği sürece
    while(choice != 3)
    {
        switch(choice)
        { // değeri yığına ekle
            case 1:
                printf("%s", "Tamsayi giriniz: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            // değeri yığından kaldır
            case 2:
                // yığın boş değil ise
                if(!isEmpty(stackPtr))
                {
                    printf("Silinen deger: %d\n", pop(&stackPtr));
                }

                printStack(stackPtr);
                break;
            default:
                puts("Yanlis secim\n");
                instructions();
                break;
        }

        printf("%s", "? ");
        scanf("%u", &choice);
    }

    puts("Calisma sonu");
}

// program komutlarını kullanıcıya görüntüler
void instructions(void)
{
    puts("Secim giriniz:\n"
        "1 - Yigina deger ekleyiniz\n"
        "2 - Yigindan deger siliniz\n"
        "3 - Programi sonlandir");
}

// yığına tepesinden bir düğüm ekle
void push(StackNodePtr *topPtr, int info)
{
    StackNodePtr newPtr; // yeni düğüm işaretçisi

    newPtr = malloc(sizeof(StackNode));

    // düğümü yığının tepesine ekle
    if(newPtr != NULL)
    {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
    {
        printf("%d eklenemedi. Bellek musait degil\n", info);
    }
}

// yığın tepesinden bir düğüm kaldır
int pop(StackNodePtr *topPtr)
{
    StackNodePtr tempPtr; // geçici düğüm işaretçisi
    int popValue; // düğüm değeri

    tempPtr = *topPtr;
    popValue = (*topPtr)->data;

    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

// yığını yazdır
void printStack(StackNodePtr currentPtr)
{
    // yığın boş ise
    if(currentPtr == NULL)
    {
        puts("Yigin bos\n");
    }
    else
    {
        puts("Yigin:");

        // yığının sonu değil iken
        while(currentPtr != NULL)
        {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}

// yığın boş ise 1 aksi halde 0 döndür
int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}