// Slavnem
// Metin Kopyalama Ekleme Fonksiyonlarım
// =====================================
// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define SIZE 100

// Fonksiyon tanımları
char* mtnkpy(char*, const char*);
char* mtnbkpy(char*, const char*, size_t);
char* mtnekl(char*, const char*);
char* mtnbekl(char*, const char*, size_t);

// main
int main(void)
{
    char metin[SIZE] = "deneme metini";
    char ek[] = "ek yazi";
    char test[SIZE];
    char test2[SIZE];

    // test amaçlı ekrana çıktı verme
    printf("kopyalama: %s\n", mtnkpy(test, metin));
    printf("kopyalama boyut: %s\n", mtnbkpy(test2, metin, 4));
    printf("ekle: %s\n", mtnekl(test, metin));
    printf("ekle boyut: %s\n", mtnbekl(test, ek, 5));
}

// mtnkpy
char* mtnkpy(char* mtn1, const char* mtn2)
{
    // kopyalayacağımız değişkenin adresini tutmak
    char* orginalPtr = mtn1;

    // ilk metine ikinci metindeki veriyi kopyalıyoruz
    // kopyalanacak olan metin bitene kadar devam etsin
    while(*mtn2 != '\0')
    {
        *mtn1 = *mtn2;

        mtn1++;
        mtn2++;
    }

    // metnin sonu geldiği için kopyalacağımız
    // değişkenin sonunu sonlandırıyoruz
    *mtn1 = '\0';

    // kopyalanmış metini döndürüyoruz
    return orginalPtr;
}

// mtnbkpy
char* mtnbkpy(char* mtn1, const char* mtn2, size_t byt)
{
    // kopyalayacağımız değişkenin adresini tutmak
    char* originalPtr = mtn1;
    size_t count; // boyutu aşmamak için sayaç

    // ilk metine ikinci metindeki veriyi kopyalıyoruz
    // kopyalanacak olan metin boyutu bitene kadar devam etsin
    for(count = 0; count < byt; count++)
    {
        // metin sonu gelmişse sonlansın
        if(*mtn2 == '\0')
            break;

        // metin kopyalamaya devam etsin
        *mtn1 = *mtn2;

        // sonraki adrese geçsinler
        ++mtn1;
        ++mtn2;
    }

    // metnin sonu geldiği için kopyalacağımız
    // değişkenin sonunu sonlandırıyoruz
    *mtn1 = '\0';

    // adresi döndürüyoruz
    return originalPtr;
}

// mtnekl
char* mtnekl(char* mtn1, const char* mtn2)
{
    // ekleme yapacağımız değişkenin adresini tutmak
    char* originalPtr = mtn1;
    char* kontrolPtr = NULL;

    // ilk metine ikinci metindeki veriyi ekliyoruz
    // eklenecek olan metin bitene kadar devam etsin
    while(*mtn1 != '\0')
    {
        // sonraki konuma geç
        ++mtn1;
    }

    // son noktasına geldik, son noktayı tutmak
    kontrolPtr = mtn1;

    // kontrol amaçlı tutulan konuma ek olarak
    // ekleyeceğimiz veriyi ana metin bitene kadar
    // üstüne ekliyoruz
    while(*mtn2 != '\0')
    {
        // ana metinden veri ekliyoruz
        *kontrolPtr = *mtn2;

        // sonraki bellek adreslerine geçiyoruz
        ++kontrolPtr;
        ++mtn2;
    }

    // veri ekleme bittiği için ekleme yaptığımız
    // değişkenin sonunu sonlandırıyoruz
    *kontrolPtr = '\0';

    // üstüne veri eklediğimiz metini
    // geçici olarak tutan değişkeni döndürüyoruz
    return originalPtr;
}

// mtnbekl
char* mtnbekl(char* mtn1, const char* mtn2, size_t byt)
{
    // ekleme yapacağımız değişkenin adresini tutmak
    char* originalPtr = mtn1;
    char* kontrolPtr = NULL;
    size_t count; // boyutu aşmamak için sayaç

    // ilk metine ikinci metindeki veriyi ekliyoruz
    // eklenecek olan metin bitene kadar devam etsin
    while(*mtn1 != '\0')
    {
        // sonraki konuma geç
        ++mtn1;
    }

    // son noktasına geldik, son noktayı tutmak
    kontrolPtr = mtn1;

    // kontrol amaçlı tutulan konuma ek olarak
    // ekleyeceğimiz veriyi ana metin sayaç sonlanana
    // kadar üstüne ekliyoruz
    for(count = 0; count < byt; count++)
    {
        // ana metinden veri ekliyoruz
        *kontrolPtr = *mtn2;

        // sonraki bellek adreslerine geçiyoruz
        ++kontrolPtr;
        ++mtn2;
    }

    // veri ekleme bittiği için ekleme yaptığımız
    // değişkenin sonunu sonlandırıyoruz
    *kontrolPtr = '\0';

    // üstüne veri eklediğimiz metini
    // geçici olarak tutan değişkeni döndürüyoruz
    return originalPtr;
}