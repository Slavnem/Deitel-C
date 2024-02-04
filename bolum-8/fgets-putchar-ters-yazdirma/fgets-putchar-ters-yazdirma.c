////////////////////////////
// Yazan: Slavnem
// Dil: C
////////////////////////////

/*
    AÇIKLAMA ÖNEMLİ:
    normalde kitap da reverse(sentence) dan önce
    printf yerine puts ile çıktı veriyor fakat
    reverse fonksiyonu kullandığı putchar gereği
    kendi üstüne bir satır boşluk koyuyor. Kitapın
    çıktığı yıldan şuanki (2024) yılına kadar
    derleyicilerin kod okuması güncellendiği için
    bu durum normal. Bu yüzden satır sonu
    bitmesin diye printf koyuldu
*/

/*
    KRİTİK BİLGİ AÇIKLAMASI:
    const char* smetin = "blabla";
    const char* const smetin = "blabla";

    bu ikisinin arasındaki ince fark şu:
    const char* smetin = "blabla";
    smetin = "degisti";

    bu islem "const char* smetin" için
    başarılı olucaktır. çünkü koruma var gibi
    gözüksede aslında bellek adresine erişip
    değiştirebiliriz.
    örnek: smetin[0] = 'd'; [hatalı]
    örnek: smetin = "degisti"; [başarılı]
    const char* da hatalı yazan kullanımlar
    hatalıdır. Çünkü const diziye erişmemizi
    engeller ama bellek adresinden erişmemizi değil !!!
    bu yüzden const char* const smetin = "blabla";
    kullanırız ki hem diziden değiştirmeye çalışma
    hem de bellek adresinden değiştirmeyi çalışma
    engellensin diye, sondaki const ifadesi bunu sağlar
    örnek: smetin[0] = 'd';   [hatalı]
    örnek: smetin = "degisti";   [hatalı]
*/

// Kütüphaneler
#include <stdio.h>

// Ön işlemci tanımları
#define SIZE 80

// Ön Fonksiyon Tanımları
void reverse(const char* const sPtr);

// main
int main(void)
{
    char sentence[SIZE]; // char türünde dizi tanımı

    puts("Enter a line of text: ");

    // bir satır metin okumak için fgets kullanımı
    fgets(sentence, SIZE, stdin);

    printf("\nThe line printed backward is: ");
    reverse(sentence);

    // boş satır
    puts("");
}

// öz yinelemeli biçimde karakterlerin tersten karakter dizini içine yerleştirilmesi
void reverse(const char* const sPtr)
{
    // karakter dizini sonu ise
    if('\0' == sPtr[0])
    {
        return;
    }
    // karakter dizini sonu değilse
    else
    {
        reverse(&sPtr[1]); // öz yinelemenin yapıldığı basamak
        putchar(sPtr[0]); // putchar ile karakter görüntüleme
    }
}