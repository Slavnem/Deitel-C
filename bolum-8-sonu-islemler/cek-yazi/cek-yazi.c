// Slavnem
// Çek Yazı
// ========
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ön işlemci tanımlamaları
#define BFAL 0 // false
#define BTRU 1 // true

#define SIZE_STR 150 // en fazla metin uzunluğu
#define SIZE_CEK 9 // en fazla çek uzunluğu

#define LIMITBAS 3 // basamak limiti

#define MIN_CEK 1.00 // en düşük çek miktarı

// Fonksiyon tanımlamaları
void printcek(char*, const double* const, const size_t* const);

// Değişken tanımları
enum EBASE
{
    BASE_HUN = 0, // yüzler basamağı
    BASE_TOU, // binler basamağı
    BASE_MIL, // milyonlar basamağı
    BASE_BIL // milyarlar basamağı
};

enum EBASA
{
    BASA_YU = 0, // yüzler
    BASA_BI, // birler
    BASA_ON // onlar
};

const char* const rakamlarArrPtr[] = {
    "Bir", "Iki", "Uc", "Dort",
    "Bes", "Alti", "Yedi", "Sekiz", "Dokuz"
};

const char* const ondaliklarArrPtr[] =
{
    "On", "Yirmi", "Otuz", "Kirk", "Elli",
    "Altmis", "Yetmis", "Seksen", "Doksan"
};

const char* const basamaklarArrPtr[] = {
    "Yuz", "Bin", "Milyon", "Milyar"
};

// main
int main(void)
{
    char cek[SIZE_STR]; // çek metnini tutacak
    size_t size_cek = (sizeof(cek) / sizeof(cek[0])); // çek metininin uzunluğu
    double cektutar; // çek tutarını tutacak
    
    // kullanıcıdan çek tutarı istemek
    // en küçük çek miktarından küçük olduğu sürece dönsün
    do
    {
        printf("Cek Tutari Giriniz: "); // kullanıcıya çıktı vermek
        fgets(cek, size_cek, stdin); // satırdaki veriyi almak

        // satır sonları kısmını metin sonuna çevirmek
        cek[strcspn(cek, "\n")] = '\0';

        // metini ondalıklı sayıya çevirmek
        cektutar = strtod(cek, NULL);
    } while(cektutar < MIN_CEK);

    // çek ile işlemleri yapıp çıktı verecek
    printcek(cek, &cektutar, &size_cek);
}

// printcek
void printcek(char* cekPtr, const double* const cektutarPtr, const size_t* const size_cekPtr)
{
    // eğer çek değeri 1.0'dan küçükse mantık hatasını bildirip
    // işlemi sonlandırmalıyız
    // aksit takdirde diğer işlemleri yapsın
    if(*cektutarPtr < MIN_CEK)
    {
        printf("%s\n", "Gecersiz Cek Tutari. Hesaplama Yapilamiyor");
        return;
    }

    // geçersiz metin uzunluğu girilmişse hata mesajıyla yine çıktı versin
    if(*size_cekPtr < SIZE_CEK)
    {
        printf("%s%zu%s%d%s\n",
            "Girilen Cek Metin Uzunlugu Miktari (",
            (*size_cekPtr), ") Olmasi Gereken Cek Metini Uzunlugundan (",
            (SIZE_STR), ") Kisa. Hesaplama Yapilamiyor");

        return;
    }

    // başlangıçta metin içeriğini temizlemek
    strcpy(cekPtr, "");

    // ---------------------
    // BAŞLANGIÇTA SORUN YOK
    // ---------------------

    char* gecici;

    unsigned int _tutarbasamak; // çek tutarının ondalıksız basamağı
    unsigned int _tempsayi; // geçici olarak sayı tutacak

    size_t _basamakmod; // her basamak için mod miktarı

    // ilk önce ondalıklı kısmı almak
    // kodun sonlarında doğru almıyoruz çünkü
    // belirli bir adres vermedik bu yüzden hata olmaması için
    // başta metini ayarlayıp bellek adresinde bu metinin
    // tutulduğu kısımın adresini veriyoruz
    // bu sayede bellekte yeni değişken oluşturulmuş kadar
    // yer kaplamıyor, sadece işletim sistemine göre
    // 64 bit sistemlerde char* 8 byte yer kaplıyor
    // ve kod hatası olmuyor
    sprintf(gecici, "ve %d/100", ((int)(*cektutarPtr * 100) % 100));

    // ondalıklı kısım hariç kaç basamak olduğunu hesaplama
    for(_tutarbasamak = 0, _basamakmod = 1;
        (int)(*cektutarPtr) % _basamakmod != (int)(*cektutarPtr);
        _tutarbasamak++, _basamakmod *= 10);

    // basamak basamak ilerleme
    for(_basamakmod /= 10; _tutarbasamak > 0 && _basamakmod > 0; _tutarbasamak--, _basamakmod /= 10)
    {
        // basamağa göre sayıyı almak
        _tempsayi = (((int)*cektutarPtr / _basamakmod) % 10);

        // 1'den küçükse sonraki tura geçsin
        if(!_tempsayi)
            continue;

        // eğer metin boyutunu aşmaya dayandıysa
        // bilgi mesajı verip sonlansın
        if(strlen(cekPtr) == *size_cekPtr)
        {
            // bilgilendirme mesajı
            printf("%s%d%s%zu%s\n",
                "Boyut Sinirina Gelindi. Yazilmis Olan Karakter Boyutu: ", strlen(cekPtr),
                " Metin En Fazla Karakter Depolama Boyutu", (*size_cekPtr),
                " Hesaplama Sonlandiriliyor...");

            return; // hesaplama sonu
        }

        // basamağa göre metin ekleme
        switch(_tutarbasamak % LIMITBAS)
        {
            // birler
            case BASA_BI: // kalan: 1
                switch(_tutarbasamak >= LIMITBAS)
                {
                    // basamak değeri, "bin", "milyon"...
                    // eklenmeli ise işlem farklı
                    case BTRU:
                        // eğer sayı 1'ise "Bir Bin" gibi yazım
                        // hataları olmaması için ek kontrol yapılacak
                        if(_tempsayi > 1)
                        {
                            strcat(cekPtr, rakamlarArrPtr[_tempsayi - 1]); // rakama eş değer metini ve boşluk ekleme
                            strcat(cekPtr, " "); // basamak ismi eklendiğinden ek boşluk ekleme
                        }

                        // basamak ismini ekleme
                        strcat(cekPtr, basamaklarArrPtr[(int)(_tutarbasamak / LIMITBAS)]); // basamak ismini ekleme
                    break;
                    // normal rakam ismi eklenmeli
                    default:
                        strcat(cekPtr, rakamlarArrPtr[_tempsayi - 1]);
                        break;
                }
            break;
            // onlar
            case BASA_ON: // kalan: 2
                // rakama eş değer metini ve boşluk eklemek
                strcat(cekPtr, ondaliklarArrPtr[_tempsayi - 1]);
            break;
            // yüzler
            case BASA_YU: // kalan: 0
                // rakama eş değer metini ve boşluk eklemek ama bir değilse
                if(_tempsayi > 1)
                {
                    strcat(cekPtr, rakamlarArrPtr[_tempsayi - 1]);
                    strcat(cekPtr, " "); // basamak ismi eklendiğinden ek boşluk ekleme
                }

                // yüzler olduğunu eklemek
                strcat(cekPtr, basamaklarArrPtr[BASE_HUN]);
            break;
        }

        // metin sonuna gelmemişse boşluk ekleme
        if(_tutarbasamak)
            strcat(cekPtr, " ");
    }

    // ondalikli kisimdan oncesini ekledik
    // eğer ondalikli kisim 00'dan büyükse
    // yazacağız yoksa gerek yok
    if(((int)(*cektutarPtr * 100) % 100) == 0)
        printf("%s\n", cekPtr); // çek metinini çıktı vermek

    // ondalıklı kısımla ilgili metini ekleme
    strcat(cekPtr, gecici);

    // .00 değilse ondalıklı kısım, işlem farklı
    printf("%s\n", cekPtr);
}