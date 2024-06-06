// Slavnem @2024-06-06
// Listeye Düğümler Eklemek ve Listeden Düğüm Silmek

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// kendine referans verebilen yapı
struct listNode {
    char data; // her listNode bir karakter içermektedir
    struct listNode *nextPtr; // bir sonraki düğüm işaretçisi
};

typedef struct listNode ListNode; // listNode yapısı ile eş anlamlı
typedef ListNode *ListNodePtr; // ListNode* ile eş anlamlı

// prototipler
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

// main
int main(void)
{
    ListNodePtr startPtr = NULL; // başlangıçta düğüm yok
    unsigned int choice; // kullanıcı seçimi
    char item; // kullanıcı tarafından girilen karakter

    instructions(); // menüyü göster
    printf("%s", "? ");
    scanf("%u", &choice);

    // kullanıcı 3 seçmediği sürece döngü oluştur
    while(choice != 3)
    {
        switch(choice)
        {
            case 1:
                printf("%s", "Karakter giriniz: ");
                scanf("\n%c", &item);
                insert(&startPtr, item); // nesneyi listeye ekle
                printList(startPtr);
                break;
            case 2: // bir eleman sil
                // eğer boş değil ise
                if(!isEmpty(startPtr))
                {
                    printf("%s", "Silmek icin karakter giriniz: ");
                    scanf("\n%c", &item);

                    // eğer karakter bulunduysa karakteri kaldır
                    if(delete(&startPtr, item))
                    { // nesneyi kaldır
                        printf("%c silindi\n", item);
                        printList(startPtr);
                    }
                    else
                    {
                        printf("%c bulunamadi\n\n", item);
                    }
                }
                else
                {
                    puts("List is empty\n");
                }
                break;
            default:
                puts("Gecersiz secenek\n");
                instructions();
                break;
        }

        printf("%s", "? ");
        scanf("%u", &choice);
    }

    puts("Calisma Sonu");
}

// program komutlarını kullanıcıya görüntüle
void instructions(void)
{
    puts("Secim giriniz:\n"
        " 1 - Listeye eleman ekleme\n"
        " 2 - Listeden eleman silmek\n"
        " 3 - Sonlandirma");
}

// yeni bir değeri sıralanmış düzende listeye ekle
void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr; // yeni düğüm işaretçisi
    ListNodePtr previousPtr; // listedeki önceki düğümün işaretçisi
    ListNodePtr currentPtr; // listede mevcut düğüm işaretçisi

    newPtr = malloc(sizeof(ListNode)); // düğüm oluştur

    if(newPtr != NULL)
    { // alan erişilebilir ise
        newPtr->data = value; // değeri düğüme yerleştir
        newPtr->nextPtr = NULL; // düğüm başka bir düğüme bağlanmıyor

        previousPtr = NULL;
        currentPtr = *sPtr;

        // listede geçerli lokasyonu bulmak için düğüm oluştur
        while(currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr; // ilerlemeye devam et...
            currentPtr = currentPtr->nextPtr; // ... bir sonraki düğüme
        }

        // listenin başında yeni düğüm ekle
        if(previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        { // previousPtr ve currentPtr arasında yeni düğüm ekle
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%c eklenemedi. Uygun bellek yok\n", value);
    }
}

// bir liste elemanını sil
char delete(ListNodePtr *sPtr, char value)
{
    ListNodePtr previousPtr; // listede bir önceki düğüm işaretçisi
    ListNodePtr currentPtr; // listede mevcut düğüm işaretçisi
    ListNodePtr tempPtr; // geçici düğüm işaretçisi

    // ilk düğümü sil
    if(value == (*sPtr)->data)
    {
        tempPtr = *sPtr; // düğüm kaldırılıyor iken sakla
        *sPtr = (*sPtr)->nextPtr; // düğümü sıralamadan kaldır
        free(tempPtr); // kaldırılmış düğümü serbest bırak
        return value;
    }
    else
    {
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        // listede geçerli lokasyonu bulmak için döngü oluştur
        while(currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr; // yürümeye devam et
            currentPtr = currentPtr->nextPtr; // ... bir sonraki düğüme
        }

        // currentPtr deki düğümü sil
        if(currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }

    return '\0';
}

// liste boş ise 1 değil ise 0 döndür
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

// listeyi yazdır
void printList(ListNodePtr currentPtr)
{
    // liste boş ise
    if(isEmpty(currentPtr))
    {
        puts("Liste Bos\n");
    }
    else
    {
        puts("Liste:");

        // listenin sonuna gelinmediği sürece
        while(currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}