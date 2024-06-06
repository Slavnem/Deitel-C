// Slavnem @2024-06-07
// Kuyruk İşleme ve Sürdürme

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// kendine referans verebilen yapı
struct queueNode
{
    char data; // data değişkenini char olarak tanımla
    struct queueNode *nextPtr; // queueNode işaretçisi
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

// fonksiyon prototipleri
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
void instructions(void);

// main
int main(void)
{
    QueueNodePtr headPtr = NULL; // headPtr ilklendir
    QueueNodePtr tailPtr = NULL; // tailPtr ilklendir
    unsigned int choice; // kullanıcı menü seçimi
    char item; // kullanıcı tarafından char girişi

    instructions(); // menüyü görüntüle
    printf("%s", "? ");
    scanf("%u", &choice);

    // kullanıcı 3 girmediği sürece
    while(choice != 3)
    {
        switch(choice)
        {
            // değeri kuyruğa al
            case 1:
                printf("%s", "Karakter giriniz: ");
                scanf("\n%c", &item);
                enqueue(&headPtr, &tailPtr, item);
                printQueue(headPtr);
                break;
            // değeri kuyruktan çıkar
            case 2:
                // kuyruk boş değil ise
                if(!isEmpty(headPtr))
                {
                    item = dequeue(&headPtr, &tailPtr);
                    printf("%c kuyruktan silindi\n", item);
                }
                
                printQueue(headPtr);
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

// program komutlarını kullanıcıya göster
void instructions(void)
{
    puts("Secim giriniz:\n"
        " 1 - Kuyruga veri ekle\n"
        " 2 - Kuyruktan veri sil\n"
        " 3 - Sonlandir");
}

// kuyruk sonundan bir düğüm ekle
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value)
{
    QueueNodePtr newPtr; // yeni düğüm işaretçisi

    newPtr = malloc(sizeof(QueueNode));

    // alan erişilebilir ise
    if(newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        // boş ise baş kısıma düğüm ekle
        if(isEmpty(*headPtr))
        {
            *headPtr = newPtr;
        }
        else
        {
            (*tailPtr)->nextPtr = newPtr;
        }

        *tailPtr = newPtr;
    }
    else
    {
        printf("%c eklenemedi. Bellek musait degil\n", value);
    }
}

// kuyruğun başından düğümü kaldır
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    char value; // düğüm değeri
    QueueNodePtr tempPtr; // geçici düğüm işaretçi

    value = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    // eğer kuyruk boş ise
    if(*headPtr == NULL)
    {
        *tailPtr = NULL;
    }

    free(tempPtr);
    return value;
}

// kuyruk boş ise 1 aksi halde 0
int isEmpty(QueueNodePtr headPtr)
{
    return headPtr == NULL;
}

// kuyruğu yazdır
void printQueue(QueueNodePtr currentPtr)
{
    // kuyruk boş ise
    if(currentPtr == NULL)
    {
        puts("Kuyruk bos\n");
    }
    else
    {
        puts("Kuyruk:");

        // kuyruğun sonu olmadığı sürece
        while(currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}