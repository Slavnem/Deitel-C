// Slavnem
// Metin Sayı Dönüştürme Fonksiyonlarım
// ====================================
// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define ASCII_NEG 45
#define ASCII_POINT 46
#define ASCII_NUM_START 48
#define ASCII_NUM_END 57

// Fonksiyon tanımları
double mtndob(const char*);
long mtnlng(const char*, int);
unsigned long mtnulng(const char*, int);

// main
int main(void)
{
    // test amaçlı metin
    const char* yazi = "Bu yazi milattan once -55 yilinda yapildi. 13.82 milyar yasinda. 129864 derece.";

    // test amaçlı değişkenler
    double dsayi = mtndob(yazi);
    long sayi = mtnlng(yazi, 0);
    unsigned long usayi = mtnulng(yazi, 0);

    // test çıktıları
    printf("double sayi: %lf\n", dsayi);
    printf("long sayi: %ld\n", sayi);
    printf("unsigned long sayi: %lu\n", usayi);
}

// mtndob
double mtndob(const char* metin)
{
    double sayi = 0; // saklayacağımız sayı
    int negative = 0; // negatiflik durumu
    size_t sayac; // sayaç ile ondalıklı kısımdan sonrasını tutma

    // metin içi işlem
    while(metin != NULL && (*metin) != '\0')
    {
        // sayı bulundu
        if((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
        {
            // eğer sayıdan önce negatiflik varsa kayıt tutulsun
            if((metin - 1) != NULL && *(metin - 1) == ASCII_NEG)
                negative = 1;

            while((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
            {
                // sonraki basamağa geçmek için
                // sayının kendisini 10'la çarpıyoruz
                // sonraki basamağa geçip üstüne
                // şuanki sayıyı ekleyip sayıyı
                // genişletmiş oluyoruz
                // metinin değeri ile ASCII_NUM_START
                // çıkarma işlemi yapılma sebebi, 1 girildiğinde
                // ASCII karşılığı 1 değil, 49 olduğu için
                // ASCII standartına göre başlangıçtan çıkarınca
                // 49 - 48 yani 1 bulmuş oluyoruz
                sayi = (sayi * 10) + (*metin - ASCII_NUM_START);

                // sonraki konuma geç
                ++metin;
            }

            // eğer nokta varsa ondalıklı, yoksa normaldir
            if(*metin != ASCII_POINT)
            {
                sayi = 0; // sayıyı sıfırla
                negative = 0; // negatifliği sıfırla
                ++metin; // sonraki konuma geç
                continue; // ana döngüde sonraki tura geç
            }
            else
                ++metin; // sonraki bellek adresine geç

            // ondalıklı kısım için sayaç
            // sayaç 10la çarpılarak gidicek bu sayede ondalıklı kısmın devamını bulacağız
            for(sayac = 10; ((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END); sayac *= 10, ++metin)
            {
                sayi += (((double)(*metin - ASCII_NUM_START)) / sayac);
            }

            // sayı alındı, döngüyü kır
            break;
        }

        // olası bir durumda sonraki konuma geç
        ++metin;
    }

    // negatif yap
    if(negative)
        sayi *= (-1);

    // sayıyı döndürüyoruz
    return sayi;
}

// mtnlng
long mtnlng(const char* metin, int sistem)
{
    long sayi = 0; // saklayacağımız sayı
    long gecici; // sayıyla yapıalcak işlemi geçici tutacak
    int negative = 0; // negatiflik durumu
    size_t sayac; // istenilen sisteme çevirilirken kullanılacak

    // metin içi işlem
    while(metin != NULL && (*metin) != '\0')
    {
        // sayı bulundu
        if((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
        {
            // eğer sayıdan önce negatiflik varsa kayıt tutulsun
            if((metin - 1) != NULL && *(metin - 1) == ASCII_NEG)
                negative = 1;

            while((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
            {
                // sonraki basamağa geçmek için
                // sayının kendisini 10'la çarpıyoruz
                // sonraki basamağa geçip üstüne
                // şuanki sayıyı ekleyip sayıyı
                // genişletmiş oluyoruz
                // metinin değeri ile ASCII_NUM_START
                // çıkarma işlemi yapılma sebebi, 1 girildiğinde
                // ASCII karşılığı 1 değil, 49 olduğu için
                // ASCII standartına göre başlangıçtan çıkarınca
                // 49 - 48 yani 1 bulmuş oluyoruz
                sayi = (sayi * 10) + (*metin - ASCII_NUM_START);

                // sonraki konuma geç
                ++metin;
            }

            // eğer sayı bulma bittiyse ve nokta geliyorsa
            // bu sayıyı double türünde almak gerekli
            // bu yüzden kayıtlı değerleri sıfırlıyoruz
            if((*metin) == ASCII_POINT)
            {
                sayi = 0;
                negative = 0;
            }
            // değilse de istediğimizi aldık
            // döngüyü kırıyoruz
            else
                break;
        }

        // sonraki konuma geç
        ++metin;
    }

    // eğer sayı negatifse, sayıyı negatife çeviriyoruz
    // değilse de kendisine eşitliyoruz
    negative ? (sayi *= (-1)) : (sayi = sayi);

    // kullanıcının girdiği sisteme çeviriyoruz sayıyı
    // ve negatif olmamalı sayı
    // en az 2lik sistem var o yüzden 1den büyükse dedik
    if(sistem > 1 && !negative)
    {
        gecici = sayi; // geçici değişkenen sayının değerini atama
        sayi = 0; // sayıyı da sıfırlıyoruz

        // kullanıcının girdiği numara sistemine göre
        // sayıyı o sisteme göre ayarlamak
        for(sayac = 1; gecici > 0; sayac *= 10)
        {
            sayi += ((gecici % sistem) * sayac);
            gecici /= sistem;
        }
    }

    // sayıyı otomatik döndürüyoruz
    return sayi;
}

// mtnulng
unsigned long mtnulng(const char* metin, int sistem)
{
    unsigned sayi = 0; // saklayacağımız sayı
    unsigned gecici; // sayıyla yapıalcak işlemi geçici tutacak
    int sayac; // istenilen sisteme çevirilirken kullanılacak

    // metin içi işlem
    while(metin != NULL && (*metin) != '\0')
    {
        // eğer negatiflik varsa ya da ondalıklı ise işlem farklı
        if((metin - 1) != NULL && (*(metin - 1) == ASCII_NEG || *(metin - 1) == ASCII_POINT))
        {
            // sayı bulunmayana kadar sonraki konuma geçsin
            while((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
                ++metin;
        }
        // negatiflik yok
        else 
        {
            // sayı bulundu ve negatif değil
            // sayı bulunmayana kadar dönsün
            // sayı bulundu
            if((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
            {
                while((*metin) >= ASCII_NUM_START && (*metin) <= ASCII_NUM_END)
                {
                    // sonraki basamağa geçmek için
                    // sayının kendisini 10'la çarpıyoruz
                    // sonraki basamağa geçip üstüne
                    // şuanki sayıyı ekleyip sayıyı
                    // genişletmiş oluyoruz
                    // metinin değeri ile ASCII_NUM_START
                    // çıkarma işlemi yapılma sebebi, 1 girildiğinde
                    // ASCII karşılığı 1 değil, 49 olduğu için
                    // ASCII standartına göre başlangıçtan çıkarınca
                    // 49 - 48 yani 1 bulmuş oluyoruz
                    sayi = (sayi * 10) + (*metin - ASCII_NUM_START);

                    // sonraki konuma geç
                    ++metin;
                }

                // eğer sayı bulma bittiyse ve nokta geliyorsa
                // bu sayıyı double türünde almak gerekli
                // bu yüzden kayıtlı değerleri sıfırlıyoruz
                // sonraki tura geçirtiyoruz
                if((*metin) == ASCII_POINT)
                {
                    sayi = 0;
                    continue;
                }
                // değilse de istediğimizi aldık
                // döngüyü kırıyoruz
                else
                    break;
            }
        }

        // sonraki konuma geç
        ++metin;
    }

    // kullanıcının girdiği sisteme çeviriyoruz sayıyı
    // ve negatif olmamalı sayı
    // en az 2lik sistem var o yüzden 1den büyükse dedik
    if(sistem > 1)
    {
        gecici = sayi; // geçici değişkenen sayının değerini atama
        sayi = 0; // sayıyı da sıfırlıyoruz

        // kullanıcının girdiği numara sistemine göre
        // sayıyı o sisteme göre ayarlamak
        for(sayac = 1; gecici > 0; sayac *= 10)
        {
            sayi += ((gecici % sistem) * sayac);
            gecici /= sistem;
        }
    }

    // sayıyı otomatik döndürüyoruz
    return sayi;
}