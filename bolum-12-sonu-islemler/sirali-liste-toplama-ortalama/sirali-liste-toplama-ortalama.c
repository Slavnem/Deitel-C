// Slavnem @2024-06-15
// Sıralı Listeye Rastgele Sayı Ekleme, Toplama ve Ortalama Hesaplama

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ön tanımlamalar
#define VALUE_MIN 1
#define VALUE_MAX 100
#define LIMIT_VALUE 25

// kendine referans veren yapı
typedef struct IntNode
{
    int value;
    struct IntNode *nextPtr;
} IntNode;

typedef IntNode *IntNodePtr;
typedef unsigned int uint;

// prototipler
int insert(IntNodePtr *nodePtr, int value);
int isEmpty(IntNodePtr nodePtr);
void calculator(IntNodePtr nodePtr);

// main
int main(void)
{
    IntNodePtr nodeInt = NULL; // düğüm yapısı
    uint counter; // sayaç
    uint tempVal; // geçici sayı

    srand(time(NULL)); // rastgele zamanlayıcı

    // döngü ile değer eklesin
    for(counter = 0; counter < LIMIT_VALUE; counter++)
    {
        // rastgele sayı oluşturmak
        tempVal = ((rand() % VALUE_MAX) + VALUE_MIN);

        // rastgele değeri düğüme ekletmek
        insert(&nodeInt, tempVal);
    }

    // yapılanlar ile hesaplama yaptırma ve çıktısını verdirmek
    calculator(nodeInt);
}

// insert
int insert(IntNodePtr *nodePtr, int value)
{
    IntNodePtr newPtr; // yeni boş düğüm
    IntNodePtr prevPtr = NULL; // önceki düğüm adresi
    IntNodePtr currPtr = *nodePtr; // şuanki düğüm

    // yeni düğüme bellek alanı ayır
    newPtr = malloc(sizeof(IntNode));

    // bellek alanı eğer oluşmamış ise
    if(isEmpty(newPtr))
    {
        puts("\n\n* Yeni Dugum Icin Bellek Alani Ayrilamadi *\n");
        return 0;
    }

    // yeni alan erişilebilir olduğu için atama yapıyoruz
    newPtr->value = value;
    newPtr->nextPtr = NULL;

    // listedeki geçerli düğüm boş değilse
    // ve listedeği değerden büyük ise devam etsin dönmeye
    while(!isEmpty(currPtr) && currPtr->value < newPtr->value)
    {
        // şuanki (curr) düğüm bir sonraki düğüme geçeceğimiz için
        // artık önceki (prev) düğüm olmuştur ve artık şuanki düğüm
        // sıradaki düğüm önceki düğümün işaret ettiği sıradaki düğümdür (nextPtr)
        prevPtr = currPtr;
        currPtr = currPtr->nextPtr;
    }

    // eğer önceki veri boş ise listenin başına ekle
    if(isEmpty(prevPtr))
    {
        newPtr->nextPtr = *nodePtr;
        *nodePtr = newPtr;
    }
    else
    {
        // önceki düğümün işaret ettiği düğüm
        // yeni oluşturudğumuz düğüm olur
        // yeni düğüm ise sonraki düğüm için
        // aktif düğümü seçer ve bu sayede
        // iki düğümün arasına eklenmiş olur

        prevPtr->nextPtr = newPtr;
        newPtr->nextPtr = currPtr;
    }

    // eklenen düğüme ait değeri döndür
    return newPtr->value;
}

// isEmpty
int isEmpty(IntNodePtr nodePtr)
{
    return (nodePtr == NULL);
}

// calculator
void calculator(IntNodePtr nodePtr)
{
    // düğümün adresini geçici olarak tutuyoruz
    IntNodePtr listPtr = nodePtr;

    uint sum = 0; // toplam
    uint count; // sayaç
    float avg = 0.0; // ortalama

    // liste bitene kadar değer toplama yapıyoruz
    // sayaç ile de sayı miktarını tutuyoruz
    for(count = 0; !isEmpty(listPtr); count++)
    {
        // toplam değer ekle ve sonraki adrese geç
        sum += (listPtr->value);
        listPtr = listPtr->nextPtr;
    }

    // ortalama hesaplama
    avg = (sum / count);

    // test çıktılarını vermek
    puts("====================");
    printf("%s\n", "* HESAPLAYICI SONUCU *");
    printf("%s %u\n", "Toplam Girilen Sayi:", count);
    printf("%s %u\n", "Toplama Sonucu:", sum);
    printf("%s %.2f\n", "Ortalama Sonucu:", avg);
    puts("====================");
}