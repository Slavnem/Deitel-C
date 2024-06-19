// Slavnem @2024-06-19
// Süpermarket Simülasyonu

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Gerekli ön işlemci tanımlamaları
#define TIMER_MAX 720 // dakika

#define RAND_TIMER_MIN 1 // en az rastgele dakika
#define RAND_TIMER_MAX 4 // en fazla rastgele dakika

// Müşteri kuryuğu için yapı
typedef struct CustomerQueue
{
    int minute; // bekleyeceği dakika
    struct CustomerQueue *nextPtr; // kuyruktaki sıradaki müşteri
} CustomerQueue;

typedef CustomerQueue *CustomerQueuePtr;
typedef unsigned int uint;

// Fonksiyon prototipleri
int isEmpty(void *ptr);
int mallocation(CustomerQueuePtr *node);
void enqueue(CustomerQueuePtr *headPtr, CustomerQueuePtr *tailPtr, int value);
void printQueue(CustomerQueuePtr queuePtr);
void supermarket(CustomerQueuePtr *headPtr, CustomerQueuePtr *tailPtr);

// main
int main(void)
{
    CustomerQueuePtr headQueuePtr = NULL; // müşteri kafa adresi
    CustomerQueuePtr tailQueuePtr = NULL; // müşteri kuyruk adresi

    // rastgele çekirdek zamanlayıcı
    srand(time(NULL));

    // süpermarket fonksiyonunu çalıştır
    supermarket(&headQueuePtr, &tailQueuePtr);

    // süpermarket kuyruğunu çıktı versin
    printQueue(headQueuePtr);
}

// isEmpty
int isEmpty(void *ptr)
{
    return (ptr == NULL);
}

// mallocation
int mallocation(CustomerQueuePtr *nodePtr)
{
    // düğüme alan ayır
    (*nodePtr) = malloc(sizeof(CustomerQueue));

    // düğüme alan ayrılmamışsa hatalı olduğunu bildir ve döndür
    if(isEmpty(*nodePtr))
    {
        puts("\n* Bellek Alani Ayrilamadi *");
        return 0;
    }

    // her ihtimale karşı boş değilse başarı döndürsün
    return 1;
}

// enqueue
void enqueue(CustomerQueuePtr *headPtr, CustomerQueuePtr *tailPtr, int value)
{
    CustomerQueuePtr newPtr; // yeni düğüm

    // düğüme alan ayırma başarısız ise sonlansın
    if(!mallocation(&newPtr))
    {
        puts("\n* Hatadan Dolayi Kuyruga Ekleme Yapilamadi *");
        return;
    }

    // veri ataması yap
    newPtr->minute = value;
    newPtr->nextPtr = NULL;

    // kuyruğun başı boş ise başına ekle
    if(isEmpty(*headPtr))
        (*headPtr) = newPtr;
    else
        (*tailPtr)->nextPtr = newPtr;

    // kuyruğun sonuna ekle
    (*tailPtr) = newPtr;
}

// dequeue
int dequeue(CustomerQueuePtr *headPtr, CustomerQueuePtr *tailPtr)
{
    int value; // düğüm değeri
    CustomerQueuePtr tempPtr; // geçici düğüm işaretçi

    value = (*headPtr)->minute;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    // eğer kuyruk boş ise
    if(isEmpty(*headPtr))
        *tailPtr = NULL;

    free(tempPtr);
    return value;
}

// printQueue
void printQueue(CustomerQueuePtr queuePtr)
{
    // düğüm boşsa boş olduğunu bildirsin
    if(isEmpty(queuePtr))
    {
        puts("\n* Liste Bos *");
        return;
    }

    // düğüm sonlanana kadar çıktı ver
    while(!isEmpty(queuePtr))
    {
        printf("%d --> ", queuePtr->minute); // çıktı ver
        queuePtr = queuePtr->nextPtr; // sıradaki adresi al
    }

    // kuyruk sonu geldiğini belirtme
    puts("NULL");
}

// supermarket
void supermarket(CustomerQueuePtr *headPtr, CustomerQueuePtr *tailPtr)
{
    uint customertimer = 0; // müşteri için sayaç
    uint randomtimer; // kullanıcı için rastgele sayaç
    uint tasktimer; // işlem için zamanlayıcı

    // süre sınırı geçmedikçe dönsün
    while(customertimer < TIMER_MAX)
    {
        // rastgele süre sınırları içinde zamanlama vermek
        randomtimer = (rand() % RAND_TIMER_MAX) + RAND_TIMER_MIN;

        // zamanlayıcıya verilen rastgele süreyi eklemek
        customertimer += randomtimer;

        // işlem için rastgele zamanlama
        tasktimer = (rand() % RAND_TIMER_MAX) + RAND_TIMER_MIN;

        // eğer liste boş değilse ve işlem süresi listenin başındaki
        // müşterinin bekleme sırasından az ise listenin başındaki müşterinin
        // işlemini yap ve şimdiki müşteriyi sıraya ekle
        if(!isEmpty(*headPtr))
        {
            // listenin başındaki müşterinin bekleme süresi
            // işlem süresinden fazla, müşteriyi kuyruğun başından sil
            if((*headPtr)->minute >= tasktimer)
                dequeue(&(*headPtr), &(*tailPtr));
            else
                // müşterinin bekleme süresini kısalt
                (*headPtr)->minute = (tasktimer - ((*headPtr)->minute));

            // fakat eğer işlem süresi müşterinin bekleme süresinden fazla ise
            // bekleme süresini kısaltarak kuyruğa müşteriyi ekle
            enqueue(&(*headPtr), &(*tailPtr), randomtimer);

            // sonraki tura geç
            continue;
        }
        
        // kuyruk bosşa eğer ve işlem süresi müşterinin
        // bekleme süresinden kısa ise müşterinin işlemini yap
        // müşteriyi kuyruğa eklemeden sonraki tura geç
        if(tasktimer <= randomtimer)
            continue;

        // fakat eğer işlem süresi müşterinin bekleme süresinden fazla ise
        // bekleme süresini kısaltarak kuyruğa müşteriyi ekle
        enqueue(&(*headPtr), &(*tailPtr), (tasktimer - randomtimer));
    }
}