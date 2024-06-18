// Slavnem @2024-06-17
// Cümle Alıp Tersten Kelime Kelime Sıralamak

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Değişken isimlendirme
typedef char* vstring;

// Kendisine referans verebilen kelime yapısı
typedef struct ReverseWord
{
    vstring word; // kelime
    struct ReverseWord *nextPtr; // sıradaki düğüm
} ReverseWord;

typedef ReverseWord *ReverseWordPtr;

// Fonksiyon Prototipleri
int isEmpty(void* ptr);
void printList(ReverseWordPtr reverseNodePtr);
void reverse(ReverseWordPtr *reverseNodePtr, vstring str);

// main
int main(void)
{
    ReverseWordPtr reverseNodePtr = NULL;
    char cumle[100];

    // kullanıcıdan cümle almak
    printf("En fazla %d karakterli bir cumle giriniz: ", (sizeof(cumle) - 1));
    fgets(cumle, (sizeof(cumle) - 1), stdin);

    cumle[strlen(cumle) - 1] = '\0'; // sonunu NULL olarak ayarlamak

    // cümleyi tersten kelime kelime almak
    reverse(&reverseNodePtr, cumle);

    // tersten sıraladığımız kelimeleri çıktı vermek
    printList(reverseNodePtr);
}

// isEmpty
int isEmpty(void* ptr)
{
    return (ptr == NULL);
}

// printList
void printList(ReverseWordPtr reverseNodePtr)
{
    // liste boş ise
    if(isEmpty(reverseNodePtr))
    {
        puts("Liste Bos\n");
        return;
    }

    // listenin sonuna gelinmediği sürece
    while(!isEmpty(reverseNodePtr))
    {
        printf("%s --> ", reverseNodePtr->word);
        reverseNodePtr = reverseNodePtr->nextPtr;
    }

    puts("NULL");
}

// reverse
void reverse(ReverseWordPtr *reverseNodePtr, vstring str)
{
    // metin boşsa sonlandırsın
    if(isEmpty(str))
    {
        puts("\n\n* Girilen Metin Bos! *\n");
        return;
    }

    // Fonksiyon prototipi
    void firstInsert(ReverseWordPtr *nodePtr, vstring str);

    // orjinal metini geçici olarak tutmak
    vstring partStr = str;

    // başlangıçta metini parçalamak
    partStr = strtok(partStr, " ");

    // metin sonlanana kadar dönsün
    while(!isEmpty(partStr))
    {
        // listeye düğümü eklesin
        firstInsert(&(*reverseNodePtr), partStr);

        // sonraki parçayı alsın
        partStr = strtok(NULL, " ");
    }
}

// firstInsert
void firstInsert(ReverseWordPtr *nodePtr, vstring str)
{
    ReverseWordPtr newPtr; // yeni düğüm oluştur

    // düğüme bellek alanı ayır
    newPtr = malloc(sizeof(ReverseWord));

    // bellek alanı oluşmamışsa hata çıktısı ile sonlandır
    if(isEmpty(newPtr))
    {
        puts("\n\n* Bellek Alani Ayrilamadi *\n");
        return;
    }

    // düğüme metini eklesin
    newPtr->word = str;

    // listenin başına eklensin
    newPtr->nextPtr = (*nodePtr);
    (*nodePtr) = newPtr;
}