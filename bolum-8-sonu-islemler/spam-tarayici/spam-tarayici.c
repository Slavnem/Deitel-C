// Slavnem
// Spam Tarayıcı
////////////////
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ön İşlemci Tanımlamaları
#define FALSE 0
#define TRUE 1

#define MIN_SIZE_STR 2 // en az karakter tutumu
#define MAX_SIZE_STR 512 // en fazla karakter tutumu

#define MAX_SPAM_WORD 30 // en fazla spam kelimesi
#define MAX_SPAM_POINT 5 // en fazla spam puanı

// Fonksiyon Tanımlamaları
void spamKontrol(char*, const char* const[], const unsigned short, const unsigned short, const unsigned short);

// Değişken Tanımlamaları
static const char* const __spamWordPtr[] = // spam kelimeleri
{ // küfür ağırlıklı kelimeler seçildi
    "mal", "aptal", "salak", "beyinsiz",
    "gerizakali", "sakat", "pic", "akilsiz",
    "oc", "ozurlu", "got", "tas kafali",
    "yavsak", "ibne", "pust", "got veren"
};

// main
int main(void)
{
    static char strText[MAX_SIZE_STR]; // metin
    static const unsigned short size_strText = (sizeof(strText) / sizeof(strText[0])); // metinin max uzunluğu

    // kullanıcıdan geçerli metin girene
    // kadar metin isteme
    do
    {
        printf("E-Mail icin metin giriniz: ");
        fgets(strText, size_strText, stdin);
    } while(strlen(strText) < MIN_SIZE_STR);

    // metin içindeki spam kontrolü sayacı
    // işlemlerini yapacak fonksiyon
    spamKontrol(strText, __spamWordPtr, (sizeof(__spamWordPtr) / sizeof(__spamWordPtr[0])), MIN_SIZE_STR, MAX_SPAM_POINT);
}

// spamKontrol
void spamKontrol(char* sptr, const char* const spamwordptr[], const unsigned short size_spamwords, const unsigned short minlen, const unsigned short maxspam)
{
    // eğer metin uzunluğu geçerli uzunluktan az ise
    // bilgi çıktısı verip işlem yapmasın
    // ek kontrol
    if(strlen(sptr) < minlen)
    {
        // bilgi çıktısı
        printf("%s%hu%s\n",
            "En Az Karakter Miktaridan (", (minlen), ") Az Karakter Girdiniz");

        return;
    }

    // kucult fonksiyon tanımı
    void kucult(char*);

    // metini küçültmek
    kucult(sptr);

    // değişkenler
    char* geciciAddrPtr; // geçici adres için
    
    unsigned short toplamspam; // toplam bulunan spam kelimesi
    unsigned short spamsayac; // spam kelime sayacı

    // döngü ile kelime kelime kontrol
    for(toplamspam = 0, spamsayac = 0; spamsayac < size_spamwords; spamsayac++)
    {
        // ilk kelime eşleşme yerini tutmak
        geciciAddrPtr = strstr(sptr, spamwordptr[spamsayac]);

        // kelimeyi buldukça dönsün
        while(geciciAddrPtr != NULL)
        {
            ++toplamspam; // toplam spam miktarını arttırmak
            geciciAddrPtr = strstr((geciciAddrPtr + 1), spamwordptr[spamsayac]); // sonraki kelimeyi aramak
        }
    }

    // kaç tane spam kelimesi bulunduğu çıktısı, bilgilendirme
    printf("%s%hu%s\n",
        "Toplam ", (toplamspam), " Adet Spam Kelimesi Bulundu");

    // spam mesajı olarak algılanıp algılanmadığı kontrolü
    switch(toplamspam > maxspam)
    {
        // spam sınırı aşıldı
        case FALSE:
            printf("%s\n", "Girilen Metin Spam Olarak Algilanmadi");
        return;
        // spam sınırı aşılmadı
        default:
            printf("%s%hu%s\n",
                "Girilen Metin Spam Siniri (", (maxspam), ") Asimindan Dolayi Spam Olarak Degerlendirildi");
        return;
    }

    // nolur nolmaz fonksiyon dönüp sonlansın
    return;
}

// kucult
void kucult(char* sptr)
{
    // bitmedikçe devam etsin
    while(sptr != NULL && *sptr != '\0')
    {
        *sptr = tolower(*sptr); // harfi küçültme
        ++sptr; // sonraki konuma geçmek
    }
}