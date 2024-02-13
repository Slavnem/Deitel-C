// Slavnem
// Sağlıklı Besin
//////////////////
// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ön işlemci tanımları
#define FALSE 0
#define TRUE 1

#define MIN_SIZE_STR 5

#define MAX_SIZE_STR 120
#define MAX_LIST_STR 10
#define MAX_ENTR_VAL 9 // girilebilecek en büyük tarif miktar

#define ASCII_NUM_START 48 // ASCI Standartına göre rakam başlama numarası

#define SYMB_TURN_TO_CUST 42 // ASCII Standartına göre * işareti
#define SYMB_TURN_TO_VAL 63 // ASCII Standartına göre ? işareti

// Fonksiyon tanımları
void kucult(char*);

// Değişken Tanımları
const char* const normal[] =
{
    "bardak krema", // 1
    "bardak sut", // 2
    "cay kasigi limon suyu", // 3
    "bardak seker", // 4
    "bardak tereyagi", // 5
    "bardak un", // 6
    "bardak mayonez", // 7
    "yumurta", // 8
    "bardak yag", // 9
    "beyaz ekmek" // 10
};

const char* const saglikli[] =
{
    "? bardak yogurt", // 1
    "?/2 bardak kaynatilmis sut ve ?/2 bardak su veya ? bardak soya sutu", // 2
    "?/2 cay kasigi sirke", // 3
    "?/2 bardak bal, ? bardak pekmez veya ?/4 bardak agave nektari", // 4
    "? bardak yogurt", // 5
    "? bardak pirinc unu veya cavdar", // 6
    "? bardak koy peyniri veya ?/8 bardak mayonez ve */8 bardak yogurt", // 7
    "* yemek kasigi misir unu, ararot nisastasi veya patates nisastasi veya * yumurta aki veya ?/2 ezilmis muz", // 8
    "?/4 bardak elma sosu", // 9
    "? tam tahil ekmegi" // 10
};

const int listdeger[] =
{
    1, 1, 1, 1, 1, 1,
    7, // mayonez
    2, // yumurta
    1, 1
};

// main
int main(void)
{
    char tarif[MAX_LIST_STR][MAX_SIZE_STR]; // sağlıklı tarifi saklayacak
    char miktar[MAX_SIZE_STR]; // hangisinden ne kadar istendiğini tutacak
    char* geciciptr; // geçici olarak tutmak

    unsigned long sayi; // kullanıcının girdiği sayıyı saklama için
    unsigned long sayimod; // sayı ile ilgili bölme, mod alma işlemlerinde kullanılacak

    unsigned short tarifsira; // hangisine dönüştürüleceğini belirtmek için sırasını bulma
    unsigned short tarifkontrol; // öyle bir tarifin var olup olmadığını kontrol etmek için
    unsigned short tarifsayac; // tarif için girilecek miktar sayacı
    unsigned short tarifson; // son girilen tarifin numarasını tutmak için
    unsigned short eksayac; // geçici olarak ek durumlarda kullanılacak

    const unsigned short size_tarif = (sizeof(tarif) / sizeof(tarif[0])); // dizi uzunluğu
    const unsigned short size_str_tarif = (sizeof(tarif[0]) / sizeof(tarif[0][0])); // en fazla karakter destekleme miktarı
    const unsigned short size_liste = (sizeof(normal) / sizeof(normal[0])); // listenin boyutu

    // kullanılabilir tarifleri kullanıcıya çıktı vermek
    puts("----------\nKULLANILABILIR\n----------");

    for(tarifsayac = 0; tarifsayac < size_liste; tarifsayac++)
    {
        // tarifi çıktı vermek
        printf("[%hu] %s\n", (tarifsayac + 1), normal[tarifsayac]);
    }

    // bilgilendirme
    puts("--------------------\nTARIFLER\n--------------------");

    // kullanıcıdan sınır aşmayacak kadar tarif almak
    // ve döngü ile hepsini dönüştürmek
    for(tarifsayac = 0; tarifsayac < size_tarif; tarifsayac++)
    {
        // geçerli metin girene kadar istemek
        // ya da 0 girilene kadar
        do
        {
            printf("[%hu] En Az %d Karakter ve Tarif giriniz: ", (tarifsayac + 1), (MIN_SIZE_STR));
            fgets(miktar, size_str_tarif, stdin); // metini almak
        } while (strlen(miktar) < MIN_SIZE_STR);

        // metinde içinde değer girme bulma
        sayi = strtoul(miktar, NULL, 0);

        // tarife miktar girmeyi sonlandırma
        if(!sayi)
        {
            tarifson = tarifsayac; // son tarif numarasını kayıtlı tutmak
            break;
        }
        // en büyük tarif miktarından fazla ise
        if(sayi > MAX_ENTR_VAL)
        {
            printf("En Fazla Girilebilecek Miktari (%d) Astiniz!\n", (MAX_ENTR_VAL));
            --tarifsayac;
            continue;
        }

        // metini küçük harflere çevirme
        kucult(miktar);

        // metinin uyuştuğu sırayı aramak
        for(tarifsira = 0, tarifkontrol = FALSE; tarifsira < size_liste; tarifsira++)
        {
            // eğer boş değilse
            if(strstr(miktar, normal[tarifsira]) != NULL)
            {
                tarifkontrol = tarifsira; // tarif sırası
                break; // döngüyü kır
            }
        }

        // eğer böyle bir tarif yoksa
        if(!(tarifkontrol + 1))
        {
            puts("Girilen Sekilde Bir Tarif Yok!"); // uyarı çıktısı
            --tarifsayac; // sayacın artmasını engelleme
            continue; // sonraki tura geçme
        }

        // tarif var
        // tarife denk geleni listeye kopyalayıp saklamak
        memcpy(tarif[tarifsayac], saglikli[tarifsira], size_str_tarif);

        // sembol yerine sayı gelecek yerleri bulma
        // ilk önce soru işaretlerini bulma
        geciciptr = strchr(tarif[tarifsayac], SYMB_TURN_TO_VAL);

        // eğer boş değilse devam etsin
        while(geciciptr != NULL)
        {
            // değerini değiştirsin
            *geciciptr = (ASCII_NUM_START) + (sayi);

            // sonrakini bulmaya çalışsın
            geciciptr = strchr((geciciptr + 1), SYMB_TURN_TO_VAL);
        }

        // yıldızlı sembolleri arama
        geciciptr = strchr(tarif[tarifsayac], SYMB_TURN_TO_CUST);

        // eğer metinde varsa dönmeye devam etsin
        while(geciciptr != NULL)
        {
            // eğer girilen sayı ölçüm ile çarpılınca
            // rakam olmayı aşmıyorsa sorun yok
            // aşıyorsa farklı işlem yapılacak
            switch((sayi * listdeger[tarifkontrol]) > MAX_ENTR_VAL)
            {
                // rakam olmayı aşmıyor
                case FALSE:
                    // değeri değiştirsin
                    *geciciptr = ((ASCII_NUM_START) + (sayi * listdeger[tarifkontrol]));
                break;
                // aşıyor
                default:
                    // metinde bulduğumuz bu sağa doğru kaydırıyoruz
                    // en fazla 2 basamaklı olmasını sağlayacağımız için
                    // +1 yaptık, sonraki sıradan başlaması için
                    // bir sonraki basamağa kaydırdık
                    memmove((geciciptr + 1), (geciciptr), strlen(geciciptr));

                    // adres hala şuanki adresi tutuyor, sonraki adresi değil
                    // bu adresdeki değeri sayının çarpmılış halini alıp
                    // bölme ve mod işlemleri ile işlem yapacağız
                    for(sayimod = 10, eksayac = 0; sayimod > 0; sayimod /= 10, eksayac++)
                    {
                        // sayıyı bölerek rakamlarını alıyoruz baştan sona olacak şekilde
                        // ASCII Standartına göre rakam başlangıcını zaten ekliyoruz
                        // sonrasında ise sayıyın çarpımlı halini belirlenen sayıya bölüyoruz
                        // ve modunu alarak tam sayı olarak rakamı almış oluyoruz
                        // örnek: (70 / 10) % 10 = 7 | (68 / 1) % 10 = 8
                        *(geciciptr + eksayac) = ((ASCII_NUM_START) + (((sayi * listdeger[tarifkontrol]) / sayimod) % 10));
                    }
                break;
            }

            // sonrakini bulmaya çalışsın
            geciciptr = strchr((geciciptr + 1), SYMB_TURN_TO_CUST);
        }
    }

    // eğer hiç tarif girilmemise sonlansın
    if(!tarifson)
        return FALSE;

    // bilgilendirme
    puts("--------------------\nSAGLIKLI\n--------------------");

    // döngü halinde tariflerin sağlıklı halini çıktı versin
    for(tarifsayac = 0; tarifsayac < tarifson; tarifsayac++)
    {
        // eğer en düşük kelime miktarından az ise sonraki tura geçsin
        if(strlen(tarif[tarifsayac]) < MIN_SIZE_STR)
            continue;
        
        // tarifi çıktı versin
        printf("[%hu] %s\n", (tarifsayac + 1), tarif[tarifsayac]);
    }
}

// kucult
void kucult(char* sptr)
{
    // boş ya bitmeyene kadar dönsün
    while(sptr != NULL && *sptr != '\0')
    {
        tolower(*sptr); // harfi küçült
        ++sptr; // sonraki adrese geç
    }
}