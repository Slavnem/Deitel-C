// Slavnem
// Tür Çevirme
// ==============
// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ön işlemci tanımlamaları
#define SIZE_STR 100 // metin en fazla karakter boyutu
#define MIN_STR 5 // soru en düşük karakter boyutu
#define MAX_INDEX 3 // en fazla indeks numarası
#define MIN_VALUE 0.1 // en düşük değer
#define MIN_LEN_WORD 2 // en düşük kelime uzunluğu

#define METER 1 // 1 metre
#define FEET (METER * 3.28) // 1 metredeki feet miktarı
#define INC (METER * 39.37) // 1 metredeki inç miktarı

#define LITER 1 // 1 litre
#define KUART (LITER * 0.94) // 1 litredeki kuart miktarı

#define KG 1 // 1 kilo
#define LB (KG * 2.2) // 1 kilogramdaki libre miktarı

#define FALSE 0 // yanlış
#define TRUE 1 // doğru

// Fonksiyon tanımlamaları
char* cevirici(const char* const, const size_t);

// Değişken tanımlamaları
const char* const turler[][MAX_INDEX] =
{
    { "metre", "feet", "inc" },
    { "litre", "kuart" },
    { "kilogram", "libre" }
};

const double donusum_turler[][MAX_INDEX] =
{
    { METER, FEET, INC },
    { LITER, KUART },
    { KG, LB }
};

const char* const sorular[] =
{
    "kac", "kaç"
};

// Metini küçültme
void kucult(char*);

// main
int main(void)
{
    char soru[SIZE_STR]; // soruyu tutacak
    char cevap[SIZE_STR]; // soruya verilecek cevabı tutacak

    do
    {
        // kullanıcıdan soru istemek
        printf("%s%d%s",
            "En az ", MIN_STR, " karakterli soru giriniz: ");

        // metini almak
        fgets(soru, SIZE_STR, stdin);

        // satır sonları kısmını metin sonuna çevirmek
        soru[strcspn(soru, "\n")] = '\0';
    } while (strlen(soru) < MIN_STR);

    // metin ile işlem yapıp kaydetme
    strcpy(cevap, (cevirici(soru, SIZE_STR)));

    // test çıktısı
    printf("Soru: %s\n", soru);
    printf("Cevap: %s\n", cevap);
}

// kucult
void kucult(char* metinPtr)
{
    // metinin adresini tutmak
    char* gecici = metinPtr;

    // metin devam ediyorsa dönsün
    while(gecici != NULL && *gecici != '\0')
    {
        // harfi küçültmek
        tolower(*gecici);

        // sonraki adrese geçmek
        ++gecici;
    }
}


// cevirici
char* cevirici(const char* const soruPtr, const size_t size_soruPtr)
{
    double sayi; // girilen sayıyı ondalıklı olarak tutma

    char kopya[size_soruPtr]; // ana metnin kopyası için
    char* kopyaPtr = kopya; // kopya metininin adresini tutmak

    char* kelime1Ptr; // bulunan ilk kelime
    char* kelime2Ptr; // bulunan ikinci kelime

    unsigned short anasayac;
    unsigned short icsayac;
    unsigned short kontrol; // kontrol amaçlı
    unsigned short idtur; // genel çevirim türü
    unsigned short idcevirilen; // metinde ilk bulunan kelime id
    unsigned short iddonusturme; // metinde son bulunan kelime id
    unsigned short idtemp; // geçici amaçla kullanmak

    // ana metnin kopyasını almak
    // tüm harfleri küçültmek
    memcpy(kopya, soruPtr, size_soruPtr);

    // harfleri küçültmek
    kucult(kopya);

    // sayıyı metin içinden alma
    sayi = strtod(kopya, NULL);

    // geçerli bir boyut girmemişse
    if(sayi < MIN_VALUE)
    {
        printf("%s%.1f%s\n",
            "En Dusuk Miktardan (", MIN_VALUE, ") Az Girdiniz");

        return "ERR";
    }

    // soru kelimesi arama
    // soru kelimesi yoksa sonlandırma
    for(anasayac = 0, kontrol = FALSE; (anasayac < (sizeof(sorular) / sizeof(sorular[0]))) && !kontrol; anasayac++)
    {
        // kelime bulundu
        if(strstr(kopya, sorular[anasayac]) != NULL)
            kontrol = TRUE;
    }

    // ana türler ve onların içindeki kelimelerle kontrol etmek
    for(anasayac = 0, kontrol = FALSE; anasayac < (sizeof(turler) / sizeof(turler[0])) && !kontrol; anasayac++)
    {
        // tür içinde sayaçla kontrol
        for(icsayac = 0; icsayac < (sizeof(turler[anasayac]) / sizeof(turler[anasayac][0])) && !kontrol; icsayac++)
        {
            // eğer belirli kelime uzunluğundan kısa ise
            // ya da NULL değilse kontrol etmeli
            // yoksa sonraki tura geçsin
            if(turler[anasayac][icsayac] == NULL || strlen(turler[anasayac][icsayac]) < MIN_LEN_WORD)
                continue;

            // eğer kelime bulunmassa NULL döner
            // bulunursa sorun yok
            kelime1Ptr = strstr(kopya, turler[anasayac][icsayac]);

            // metin bulunmuşsa
            if(kelime1Ptr != NULL)
            {
                idtur = anasayac; // kelimenin olduğunu ana tür
                idcevirilen = icsayac; // kelimenin bulunduğu id
                kontrol = TRUE;
            }
        }
    }

    // ilk kelime hiç bulunmadıysa fonksiyonu sonlandırmak
    if(kelime1Ptr == NULL || !kontrol)
    {
        printf("%s\n", "ANA OLCUM TURU YOK | NULL");
        return "ERR";
    }

    // eğer ilk kelime bulunmuşsa ikinci kelime de
    // tur un oldugu dizi de kontrol edecegiz
    for(icsayac = 0, kontrol = FALSE; icsayac < (sizeof(turler[idtur]) / sizeof(turler[idtur][0])) && !kontrol; icsayac++)
    {
        // eğer belirli kelime uzunluğundan kısa ise
        // ya da NULL değilse kontrol etmeli
        // yoksa sonraki tura geçsin
        if(turler[idtur][icsayac] == NULL || strlen(turler[idtur][icsayac]) < MIN_LEN_WORD)
            continue;

        // kelime bulunup bulunmadığı kontrol
        kelime2Ptr = strstr(kopya, turler[idtur][icsayac]);

        // diğer kelime ile aynı değilse
        // ve boş değilse kelime bulundu
        if(kelime1Ptr != kelime2Ptr && kelime2Ptr != NULL)
        {
            iddonusturme = icsayac; // kelimenin olduğu numarayı tutmak
            kontrol = TRUE;
        }
    }

    // ikinci kelime hiç bulunmadıysa fonksiyonu sonlandırmak
    if(kelime2Ptr == NULL || !kontrol)
    {
        printf("%s\n", "DONUSTURULECEK OLCUM TURU YOK | NULL");
        return "ERR";
    }

    // bulunan kelime bellek adreslerini karşılaştırma
    switch(kelime2Ptr > kelime1Ptr)
    {
        // ikinci kelime daha önce var
        case FALSE:
            idtemp = idcevirilen; // kelime 1 id
            idcevirilen = iddonusturme;
            iddonusturme = idtemp;
            break;
    }

    // alınan sayı 1'den aşağı değilse işlem yapsın
    // çevirilen ve dönüştürme, daha anlaşılabilir olması için
    // örnekle açıklayacağım, örnek:
    // 1 metre kaç feet ?
    // burada cevirilen metre dir, ve donusturme ise feet dir
    // çünkü metre'yi feet'e çevirildiğinden, çevirilen metre
    // dönüştürme feet'dir. Bunu kodu açıklayan basit örnek.
    if(sayi)
    {
        // değeri hesaplamak
        sayi /= (donusum_turler[idtur][idcevirilen]);
        sayi *= (donusum_turler[idtur][iddonusturme]);
    }

    // ana metinin içini temizleme
    memcpy(kopya, "", size_soruPtr);

    // kopya metini ayarlama
    sprintf(kopya, "%lf %s", sayi, turler[idtur][iddonusturme]);

    // cevabı bulunan metinin adresini döndürme
    return kopyaPtr;
}
