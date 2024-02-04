// Slavnem
// Metin Analizi
// =============
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ön işlemci tanımları
#define MIN_SIZE_LET 2 // kelime en az harf miktarı
#define SIZE_LEN 8 // kelime uzunluğu tutan dizi uzunluğu

#define ASCII_LENGTH 25 // ASCII standartına göre harf miktarı
#define ASCII_SPACE 32 // boşluk tuşu

// ASCII standartına göre harf numaralandırmaları
#define ASCII_A_START 65
#define ASCII_A_END (ASCII_A_START + 25)

#define ASCII_a_START (ASCII_A_END + 7)
#define ASCII_a_END (ASCII_a_START + 25)

#define BFALSE 0 // bool, false
#define BTRUE 1 // bool, true

// main
int main(void)
{
    // test amaçlı kullanılacak metin
    static const char* const anametin = "To be, or not to be: that is the question: Whether 'tis nobler in the mind to suffer";
    char kopyametin[(strlen(anametin) + 1)]; // +1 olması, sonda '\0' için yer ayırma
    char testmetin[(sizeof(kopyametin) / sizeof(kopyametin[0]))]; // kopyametin le aynı metini içeren metin
    
    char* kopyakelime; // kopya metindeki kontrol edilen kelimeyi geçici olarak tutma
    char* kopyaadres = kopyametin; // kopya metinin adresini tutacak
    char* testadres;
    
    size_t sayac; // aynısından kaç tane kelime bulunduğunu sayacak
    size_t eksayac; // ek amaç için

    int kelimeuzunluk[SIZE_LEN] = {0}; // harf miktarına göre kelime uzunluğu

    // ana metinin olduğu bellek adresindeki değeri
    // direk değişkene kopyalıyoruz fakat
    // değişkenin desteklediği uzunluğu aşmadan
    memcpy(kopyametin, anametin, (sizeof(kopyametin) / sizeof(kopyametin[0])));

    // kopya metindeki harfleri küçültmek ve noktama işaretlerini silmek
    while(kopyaadres != NULL && *kopyaadres != '\0')
    {
        // harf kontrol
        switch(isalpha(*kopyaadres))
        {
            // harf değil
            case BFALSE:
                *kopyaadres = ASCII_SPACE; // boşluk tuşu
            break;
            // otomatik
            default:
                // küçük harfe çevirip kaydetmek
                *kopyaadres = tolower(*kopyaadres);
            break;
        }

        // sonraki bellek adresine geçmek
        ++kopyaadres;
    }

    // metinin kopyasını testmetin de saklayacağız
    // bir daha aynı işlemleri yapmamak için
    strcpy(testmetin, kopyametin);

    // A kısmı, harften kaç kez olduğunu araştırma
    puts("---------------------\nA Kismi - Harf Kontrol\n---------------------");

    // her harfi metine arama
    for(sayac = 0; sayac < ASCII_LENGTH; sayac++)
    {
        // harf için sayaç sıfırlama
        eksayac = 0;

        // metinde o harfi aramak
        kopyakelime = strchr(kopyametin, (ASCII_a_START + sayac));

        while(kopyakelime != NULL)
        {
            ++eksayac; // sayacı 1 arttır
            kopyakelime = strchr((kopyakelime + 1), (ASCII_a_START + sayac)); // sonraki harfi ara
        }

        // kaç kez bulunduğunu bildiren bilgilendime çıktısı
        printf("%c%s%zu%s\n", (ASCII_a_START + sayac), " harfi ", eksayac, " kez bulundu");
    }

    // B kısmı, aynı kelime uzunluğundan kaç kez olduğu
    puts("---------------------\nB Kismi - Uzunluk Kontrol\n---------------------");

    // boşluk olmayan kısımları alma
    kopyakelime = strtok(kopyametin, " ");

    // kelime kelime alıp harf uzunluklarınna göre listeyi arttırma
    while(kopyakelime != NULL)
    {
        // o kelime uzunluğuna ait kısımı arttırma
        ++kelimeuzunluk[(strlen(kopyakelime) - MIN_SIZE_LET)];

        // sonraki kelimeyi alma
        kopyakelime = strtok(NULL, " ");
    }

    // kelimenin harf uzunluğuna göre kaç adet olduğuğnu liste olarak çıktı verme
    for(sayac = 0; sayac < (SIZE_LEN); sayac++)
    {
        // aynı kelime uzunuluğundan kaç adet var bilgi çıktısı
        printf("%zu%s%zu\n", (sayac + MIN_SIZE_LET), " kelime uzunlugu gorunme sayisi: ", kelimeuzunluk[sayac]);
    }

    // C kısmı, aynı kelimeden kaç kez olduğunu sayma
    puts("---------------------\nC Kismi - Kelime Sayaç\n---------------------");

    // metinin çıktısını verme
    printf("%s%s\n", "Metin: ", (anametin));

    // metin parçalama yapmıştık, testmetin de
    // kopyasını saklıyorduk, o kopyasını bir daha
    // kopyametine kopyalıyoruz
    strcpy(kopyametin, testmetin);

    // kopyaadres tekrardan kopya metine işaret edicek
    kopyaadres = kopyametin;

    // metini parçalara ayırıp sayma
    kopyaadres = strtok(kopyametin, " ");

    // kelime sonuna gelmedikçe
    while(kopyaadres != NULL)
    {
        // eğer kelime boyutundan küçükse sonraki kelimeyi bulmaya çalışsın
        while(strlen(kopyaadres) < MIN_SIZE_LET)
        {
            // sonraki kelimeyi alsın
            kopyaadres = strtok(NULL, " ");
        }

        // metinin içinde kelimeyi arama
        kopyakelime = strstr(testmetin, kopyaadres);

        // sayaç yenileme
        sayac = 0;

        // metin eşleşdikçe devam etsin
        while(kopyakelime != NULL)
        {
            testadres = kopyakelime;

            while(isalpha(*testadres) && testadres != NULL)
            {
                *testadres = ASCII_SPACE;
                ++testadres;
            }

            ++sayac; // sayacı 1 arttır

            // bir sonraki kısımda arasın
            kopyakelime = strstr((kopyakelime + 1), kopyaadres);
        }

        // metinde bulunmuşsa kaç kez bulunduğunu çıktı versin
        if(sayac)
            printf("%zu%s%s\n", (sayac), " kez ", (kopyaadres));

        // sonraki kelimeyi almak
        kopyaadres = strtok(NULL, " ");
    }
}