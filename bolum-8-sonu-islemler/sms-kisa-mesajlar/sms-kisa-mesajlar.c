// Slavnem
// Sms Kısa Mesajlar
////////////////////
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ön İşlemci Tanımlamaları
#define FALSE 0
#define TRUE 1

#define MIN_LEN_STR 2 // en kısa metin uzunluğu
#define MAX_LEN_STR 160 // en uzun metin uzunluğu

// Değişken Tanımlamaları
static const char* const __kisaltmalarPtr[] =
{
    "sa", "as", "nbr", "slm",
    "tmm", "mrb", "ayn", "eyv",
    "saol"
};

static const char* const __normalPtr[] =
{
    "selamun aleykum", "aleykum selam",
    "naber", "selam", "tamam", "meraba",
    "aynen", "eyvallah", "sagol"
};

const unsigned short __size_kisaltmalar = (sizeof(__kisaltmalarPtr) / sizeof(__kisaltmalarPtr[0]));
const unsigned short __size_normal = (sizeof(__normalPtr) / sizeof(__normalPtr[0]));

enum EDONUSTURUCULER
{
    EMSG_KISA, // kısa metine dönüştürücü
    EMSG_UZUN // uzun metine dönüştürücü
};

// main
int main(void)
{
    // Fonksiyon Tanımlamaları
    void MesajDonusturucu(const unsigned short, const char* const);

    // Değişkenler
    char strtext[MAX_LEN_STR];

    do
    { // kullanıcıdan metin almak
        printf("%s%d%s",
            "En Fazla ", MAX_LEN_STR, " Miktarinda Karakter Giriniz: ");

        fgets(strtext, MAX_LEN_STR, stdin);

        // strlen - 1 olmasının sebebi uzunluğa \n karakterini
        // dahil ediyor, bu yüzden - 1 yapıyoruz
        strtext[(strlen(strtext) - 1)] = '\0'; // satır sonunu silmek
    } while (strlen(strtext) < MIN_LEN_STR);

    // mesaj donusumunun adresini tutma
    printf("%s%s\n", "Girilen Metin: ", strtext);

    // mesaj dönüşümlerini çıktı vermek
    MesajDonusturucu(EMSG_KISA, strtext); // uzun mesaj
    MesajDonusturucu(EMSG_UZUN, strtext); // kısa mesaj
}

// MesajDonusturucu
void MesajDonusturucu(const unsigned short type_msg, const char* const strptr)
{
    // Fonksiyon Tanımlamaları
    char* Kucult(const char*);
    void kisaMesajDonusturucu(const char* const);
    void uzunMesajDonusturucu(const char* const);

    void (*donusturuculer[])(const char* const) =
    {
        kisaMesajDonusturucu,
        uzunMesajDonusturucu
    };

    // TÜR GEÇERLİLİK KONTROLÜ
    switch(type_msg)
    {
        case EMSG_KISA: // kısa mesaja çevirme
        case EMSG_UZUN: // uzun mesaja çevirme
            // olması gerekenden az karakter içeriyorsa
            if(strlen(strptr) < MIN_LEN_STR)
                return;

            // dönüştürücü fonksiyonun döndürdüğü bellek adresini döndürme
            (*donusturuculer[type_msg])(strptr);
            return;
        // geçersiz tür
        default:
            printf("%s\n", "Gecersiz Tur Numarasi Girdiniz. Fonksiyon Sonlandiriliyor...");
            return;
    }

    return;
}

// Kucult
char* Kucult(const char* const strptr)
{
    char string[strlen(strptr)]; // alınan metinin uzunluğu kadar tutmak
    char* stringptr = string; // metinin adresini vermek

    unsigned short strsayac; // metin sayacı
    const unsigned short size_string = (sizeof(string) / sizeof(string[0]));

    // ana metini kopyalamak
    strcpy(string, strptr);

    // metin devam ettikeç dönmeye devam etsin
    for(strsayac = 0; strptr[strsayac] != '\0' && strsayac < size_string; strsayac++)
    {
        string[strsayac] = tolower(string[strsayac]);
    }

    // küçültülmüş metinin adresini döndürmek
    return stringptr;
}

// kisaMesajDonusturucu
void kisaMesajDonusturucu(const char* const msgptr)
{
    char kopyalongmsg[strlen(msgptr)]; // ana metnin kopyasını tutacak
    char* addrmsg; // mesaj adresini geçici olarak tutacak

    unsigned short longsayac; // uzun kelime için sayaç
    unsigned short longkontrol; // kelime bulunup bulunmadığı kontrol
    unsigned short toplamuzunluk; // metinin uzun halinin uzunluğunu tutmak için

    strcpy(kopyalongmsg, msgptr); // ana metinin içeriğini kopya metine kopyalamak

    addrmsg = strtok(kopyalongmsg, " "); // parçalar halinde saklamak
    toplamuzunluk = 0; // toplam kelime miktarı sıfırlama

    // oluşabilecek tüm metin uzunluğunu
    while(addrmsg != NULL)
    {
        // kısa mesajlar ile döngü ile karşılaştırma
        for(longsayac = 0, longkontrol = FALSE; longsayac < __size_kisaltmalar; longsayac++)
        {
            if(strcmp(Kucult(addrmsg), __normalPtr[longsayac]) == 0)
            {
                toplamuzunluk += strlen(__kisaltmalarPtr[longsayac]); // kelimenin uzun halinin uzunluğunu eklemek
                longkontrol = TRUE; // kontrol bulundu
                break; // döngüyü kırma
            }
        }

        // eğer kontrol de bulunmamışsa normal kelimedir
        if(!longkontrol)
            toplamuzunluk += strlen(addrmsg);

        // sonraki parçayı alsın
        addrmsg = strtok(NULL, " ");

        // eğer sonraki adres boş değilse boşluk eklesin
        if(addrmsg != NULL)
            toplamuzunluk += 1;
    }

    // eğer hiç metin yoksa boş dönsün
    if(!toplamuzunluk)
        return;

    // hesaplanan uzunlukla yeni karakter dizisi oluşturma
    char longmsg[toplamuzunluk];

    // metinin içini temizlemek
    memcpy(longmsg, "", (sizeof(longmsg) / sizeof(longmsg[0])));

    // tekrardan kelime işlemi yapılacak
    strcpy(kopyalongmsg, msgptr);

    addrmsg = strtok(kopyalongmsg, " "); // parçalar halinde saklamak

    // bitmedikçe devam etsin
    while(addrmsg != NULL)
    {
        // kısa mesajlar ile döngü ile karşılaştırma
        for(longsayac = 0, longkontrol = FALSE; longsayac < __size_kisaltmalar; longsayac++)
        {
            if(strcmp(Kucult(addrmsg), __normalPtr[longsayac]) == 0)
            {
                strcat(longmsg, __kisaltmalarPtr[longsayac]); // kopya metine kelimenin uzun halini ekleme
                longkontrol = TRUE; // kontrol bulundu
                break; // döngüyü kırma
            }
        }

        // eğer kontrol de bulunmamışsa normal kelimedir
        if(!longkontrol)
            strcat(longmsg, addrmsg);

        // sonraki parçayı alsın
        addrmsg = strtok(NULL, " ");

        // eğer sonraki adres boş değilse boşluk eklesin
        if(addrmsg != NULL)
            strcat(longmsg, " ");
    }

    // adrese yeniden metinin tam adresini verme
    addrmsg = longmsg;

    // bilgi çıktısı
    printf("%s%s\n", "Kisa Hali: ", addrmsg);

    return;
}

// uzunMesajDonusturucu
void uzunMesajDonusturucu(const char* const msgptr)
{
    char kopyalongmsg[strlen(msgptr)]; // ana metnin kopyasını tutacak
    char* addrmsg; // mesaj adresini geçici olarak tutacak

    unsigned short longsayac; // uzun kelime için sayaç
    unsigned short longkontrol; // kelime bulunup bulunmadığı kontrol
    unsigned short toplamuzunluk; // metinin uzun halinin uzunluğunu tutmak için

    strcpy(kopyalongmsg, msgptr); // ana metinin içeriğini kopya metine kopyalamak

    addrmsg = strtok(kopyalongmsg, " "); // parçalar halinde saklamak
    toplamuzunluk = 0; // toplam kelime miktarı sıfırlama

    // oluşabilecek tüm metin uzunluğunu
    while(addrmsg != NULL)
    {
        // kısa mesajlar ile döngü ile karşılaştırma
        for(longsayac = 0, longkontrol = FALSE; longsayac < __size_kisaltmalar; longsayac++)
        {
            if(strcmp(Kucult(addrmsg), __kisaltmalarPtr[longsayac]) == 0)
            {
                toplamuzunluk += strlen(__normalPtr[longsayac]); // kelimenin uzun halinin uzunluğunu eklemek
                longkontrol = TRUE; // kontrol bulundu
                break; // döngüyü kırma
            }
        }

        // eğer kontrol de bulunmamışsa normal kelimedir
        if(!longkontrol)
            toplamuzunluk += strlen(addrmsg);

        // sonraki parçayı alsın
        addrmsg = strtok(NULL, " ");

        // eğer sonraki adres boş değilse boşluk eklesin
        if(addrmsg != NULL)
            toplamuzunluk += 1;
    }

    // eğer hiç metin yoksa boş dönsün
    if(!toplamuzunluk)
        return;

    // hesaplanan uzunlukla yeni karakter dizisi oluşturma
    char longmsg[toplamuzunluk];

    // metinin içini temizlemek
    strcpy(longmsg, "");

    // tekrardan kelime işlemi yapılacak
    strcpy(kopyalongmsg, msgptr);

    addrmsg = strtok(kopyalongmsg, " "); // parçalar halinde saklamak

    // bitmedikçe devam etsin
    while(addrmsg != NULL)
    {
        // kısa mesajlar ile döngü ile karşılaştırma
        for(longsayac = 0, longkontrol = FALSE; longsayac < __size_kisaltmalar; longsayac++)
        {
            if(strcmp(Kucult(addrmsg), __kisaltmalarPtr[longsayac]) == 0)
            {
                strcat(longmsg, __normalPtr[longsayac]); // kopya metine kelimenin uzun halini ekleme
                longkontrol = TRUE; // kontrol bulundu
                break; // döngüyü kırma
            }
        }

        // eğer kontrol de bulunmamışsa normal kelimedir
        if(!longkontrol)
            strcat(longmsg, addrmsg);

        // sonraki parçayı alsın
        addrmsg = strtok(NULL, " ");

        // eğer sonraki adres boş değilse boşluk eklesin
        if(addrmsg != NULL)
            strcat(longmsg, " ");
    }

    // adrese yeniden metinin tam adresini verme
    addrmsg = longmsg;

    // bilgi çıktısı
    printf("%s%s\n", "Uzun Hali: ", addrmsg);

    return;
}