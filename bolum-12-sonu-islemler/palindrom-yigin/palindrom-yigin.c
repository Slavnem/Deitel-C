// Slavnem @2024-06-18
// Palindrom İçin Yığın

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII standartına göre karakter sınırlandırması
#define ASCII_CASE_DIFF 32
#define ASCII_UPPER_MIN 65
#define ASCII_UPPER_MAX (ASCII_UPPER_MIN + 25)
#define ASCII_LOWER_MIN 97
#define ASCII_LOWER_MAX (ASCII_LOWER_MIN + 25)

// Kendine işaret eden yapı
typedef struct PalNode
{
    char let; // harf
    struct PalNode *nextPtr; // sıradaki
} PalNode;

typedef PalNode *PalNodePtr;
typedef char* vstring;
typedef unsigned int uint;
typedef const uint cuint;

// Fonksiyon prototipleri
int mallocation(PalNodePtr *nodePtr);
char lowercase(char character);
void push(PalNodePtr *nodePtr, char data);
int isEmpty(void* ptr);
int palindrom(PalNodePtr *nodePtr, vstring str);

// main
int main(void)
{
    PalNodePtr palNodePtr = NULL;

    // bellek alanı oluşmamışsa bildiri
    if(!mallocation(&palNodePtr))
        return 0;

    // geçici depolayıcı
    char buffer[20];

    // kullanıcıdan metini almak
    printf("En fazla %d karakter olucak sekilde kelime giriniz: ", (sizeof(buffer) - 1));
    scanf("%19s", buffer);

    // metinin uzunluğunu tutmak
    cuint sizeBuffer = strlen(buffer);

    // geçici metini bitene kadar yığına ekle
    uint counter;
    
    for(counter = 0; counter < sizeBuffer; counter++)
    {
        // yığına ekle
        push(&palNodePtr, buffer[counter]);
    }

    // palindrom durumuna göre çıktı ver
    printf("\"%s\" palindrom %s\n",
        buffer,
        (palindrom(&palNodePtr, buffer) ? "metindir" : "degildir")
    );
}

// mallocation
int mallocation(PalNodePtr *nodePtr)
{
    // bellek alanı ayır
    (*nodePtr) = malloc(sizeof(PalNode));

    // bellek alanı oluşmamış
    if(isEmpty(*nodePtr))
    {
        puts("\n\n* Bellek Alani Olusturulamadi *\n");
        return 0;
    }

    // bellek alanı ayırma başarılı
    return 1;
}

// lowercase
char lowercase(char character)
{
    return (character >= ASCII_UPPER_MIN && character <= ASCII_UPPER_MAX) ?
        (character - ASCII_CASE_DIFF) : character;
}

// push
void push(PalNodePtr *nodePtr, char data)
{
    PalNodePtr newPtr; // yeni düğüm oluştur

    // bellek alanı oluşmamışsa bildiri
    if(!mallocation(&newPtr))
        return;

    // yığının tepesine ekle
    newPtr->let = data;
    newPtr->nextPtr = (*nodePtr);
    (*nodePtr) = newPtr;
}

// isEmpty
int isEmpty(void* ptr)
{
    return (ptr == NULL);
}

// palindrom
int palindrom(PalNodePtr *nodePtr, vstring str)
{
    // yığını geçici olarak tut
    PalNodePtr currPtr = (*nodePtr);

    cuint sizeStr = strlen(str); // metin boyutu

    uint strcounter = 0; // orijinal metin için sayaç
    uint status = 0; // palindrom olma durumu

    // yığın bitene kadar çıktı ver
    while(!isEmpty(currPtr))
    {
        // küçük ve büyük harfe tekabül etmiyorsa sonraki tura geçsin
        if
        (
            (currPtr->let < ASCII_LOWER_MIN || currPtr->let > ASCII_LOWER_MAX) &&
            (currPtr->let < ASCII_UPPER_MIN || currPtr->let > ASCII_UPPER_MAX)
        )
        {
            // sıradaki adrese geç ve döngüde sonraki tura geç
            currPtr = currPtr->nextPtr;
            continue;
        }

        // ana metin karakter değilse karakter olana kadar dönsün
        while
        (
            (str[strcounter] < ASCII_LOWER_MIN || str[strcounter] > ASCII_LOWER_MAX) &&
            (str[strcounter] < ASCII_UPPER_MIN || str[strcounter] > ASCII_UPPER_MAX) &&
            strcounter < sizeStr
        )
        {
            strcounter++;
        }

        // metin sonuna gelinmiş ve hala eşleşme yoksa sonlansın
        if(strcounter >= sizeStr && !status)
            return 0;

        // eğer metindeki harf ile yığındaki harf eşleşmiyorsa palindrom değildir
        if(lowercase(str[strcounter]) != lowercase(currPtr->let))
            return 0;

        // eşleşme var, durumu 1'e ayarla
        status = 1;

        currPtr = currPtr->nextPtr; // sonraki düğüm
        strcounter++; // sonraki harf için sayacı arttır
    }

    return status;
}