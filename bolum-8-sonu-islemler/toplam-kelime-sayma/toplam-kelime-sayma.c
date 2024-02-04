// Slavnem
// Toplam Kelime Sayma
// ===================
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// Ön işlemci tanımları
#define SIZE 100
#define CUMLE 5
#define MIN_HARF 2

// main
int main(void)
{
    char cumleler[CUMLE][SIZE]; // cümleler
    char* cumlePtr; // cümlelerdeki kelimeleleri geçici olarak tutacak

    size_t toplam_kelime = 0; // girilen cümlelerdeki toplam kelime sayısı
    size_t saycumle; // girilecek cümleler için sayaç
    size_t size_cumle; // tek bir cümlenin boyutunu tutacak
    const size_t size_cumleler = (sizeof(cumleler) / sizeof(cumleler[0])); // cümle miktarı boyutu

    // döngü ile cümleler istemek
    for(saycumle = 0; saycumle < size_cumleler; saycumle++)
    {
        // cümlenin boyutu
        size_cumle = (sizeof(cumleler[saycumle]) / sizeof(cumleler[saycumle][0]));

        // kullanıcıya çıktı verip metin istemek
        // cümle girildiği gibi kelime bölümü yapıp sayabilriiz
        // fakat bu önerilmez
        printf("[%zu] metin giriniz: ", (saycumle + 1));
        fgets(cumleler[saycumle], size_cumle, stdin);
    }

    // cümleleri parçalara ayırıp kelimeleri sayma sayacı
    for(saycumle = 0; saycumle < size_cumleler; saycumle++)
    {
        // başlangıç olarak ilk kelimeyi almak
        cumlePtr = strtok(cumleler[saycumle], " ");

        // kelime bitmedikçe devam etsin
        while(cumlePtr != NULL)
        {
            // kelime olması için en az 2 harf olması lazım
            // bu yüzden ek kontrol yapıyoruz
            if(strlen(cumlePtr) >= MIN_HARF)
                ++toplam_kelime;

            // kelime parçalamasına devam etmek
            cumlePtr = strtok(NULL, " ");
        }
    }

    // bulunan kelime miktarını çıktı vermek
    printf("%s%zu\n", "Toplam bulunan kelime miktari: ", toplam_kelime);
}