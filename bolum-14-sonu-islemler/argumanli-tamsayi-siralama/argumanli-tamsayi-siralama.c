// Slavnem @2024-06-27
// Argümanlı Şekilde Tamsayı Artan "-a" ya da Azalan "-d" Şekilde Sıralayan Program

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// true
#ifdef true
#undef true
#define true 1
#else
#define true 1
#endif

// false
#ifdef false
#undef false
#define false 0
#else
#define false 0
#endif

// Sıralama türleri
#ifdef SORT_LOWER
#undef SORT_LOWER
#endif

#define SORT_LOWER "-d"

#ifdef SORT_HIGHER
#undef SORT_HIGHER
#endif

#define SORT_HIGHER "-a"

// NULL kontrolcü
#ifdef NULLER
#undef NULLER
#endif

#define NULLER(x) (x == NULL)

// Dizi boyutu hesaplayıcı
#ifdef SSIZEARR
#undef SSIZEARR
#endif

#define SSIZEARR(arr) (sizeof(arr) / sizeof(arr[0]))

// Dizi boyutu hesaplayıcı yoksa hata versin
#ifndef SSIZEARR
#error "Dizi boyutu hesaplayıcı yok!"
#endif

// Dizi çıktı verici tanımlıysa kaldırıp baştan tanımlansın
#ifdef PRINTARR
#undef PRINTARR
#endif

#define PRINTARR(arr) { \
    int sizearr = SSIZEARR(arr); \
    for(int i = 0; i < sizearr; i++) { printf("%-2d ", arr[i]); } \
    puts(""); \
}

// Dizi çıktı veriyi yoksa
#ifndef PRINTARR
#error "Dizi çıktı verici yok!"
#endif

// Değişken isimlendirme
typedef const char* const string;
typedef unsigned int uint;
typedef int* iptr;
typedef uint* uptr;

// Fonksiyon prototipi
static void sort(string sorttype, uint sizearr, uptr arr);

// main
int main(int argc, string argv[])
{
    // argümanın olup olmadığını kontrol etmek
    if(NULLER(argv[1]))
    {
        // bildiri çıktısı
        puts(
            "\nArtan siralama icin \'-a\', Azalan siralama icin \'-d\' girmek zorunlu!\n"
            "Gecerli arguman olmadigi icin program sonlandiriliyor"
        );

        // başarısız
        exit(EXIT_FAILURE);
    }

    // Sıralama türleri olmak zorunda
    assert(SORT_LOWER);
    assert(SORT_HIGHER);

    // tamsayı dizi
    uint nums[] = {
        1, 5, 2, 7, 4,
        3, 8, 9, 0, 6
    };

    // diziyi başlangıçta çıktı vermek
    puts("Sayilar Dizi:");
    PRINTARR(nums);

    // argümana göre sıralatmak
    sort(argv[1], SSIZEARR(nums), &nums[0]);

    // dizinin sıralanmış halini çıktı vermek
    puts("\nSiralanmis Dizi:");
    PRINTARR(nums);
}

// sort
static void sort(string sorttype, uint sizearr, uptr arr)
{
    // dizi ya da dizi uzunluğu boşsa bildirsin
    if(sizearr < 1 || NULLER(arr))
    {
        puts("Dizi Bos!");
        exit(EXIT_FAILURE);
    }

    // sıralama fonksiyonları
    void lowersort(uint sizearr, uptr* arr);
    void highersort(uint sizearr, uptr* arr);

    // sıralama türü kontrolü
    if(strcmp(sorttype, SORT_HIGHER) != 0 && strcmp(sorttype, SORT_LOWER) != 0)
    {
        printf("\'%s\' gecersiz bir siralama turudur\n", sorttype);
        return;
    }

    // türüne göre sıralama yapsın
    (strcmp(sorttype, SORT_HIGHER) == 0) ?
        highersort(sizearr, &arr) : lowersort(sizearr, &arr);    
}

// lowersort -> Azdan Çoğa
void lowersort(uint sizearr, uptr* arr)
{
    uint counter; // ana sayaç
    uint counterin; // iç sayaç
    uint temp; // geçici değer depolayıcı

    // baloncuk sıralama ile yapacağız
    for(counter = 0; counter < sizearr; counter++)
    {
        // iç döngü
        for(counterin = (counter + 1); counterin < sizearr; counterin++)
        {
            // ana sayaçtaki değer iç sayaçtakinden büyükse
            if(*(*arr + counter) > *(*arr + counterin))
            {
                // ana sayaçtaki değer geçici olarak sakla
                // sonrasında değerlerin yerini değiştir
                temp = *(*arr + counter);
                *(*arr + counter) = *(*arr + counterin);
                *(*arr + counterin) = temp;
            }
        }
    }
}

// highersort -> Çoktan Azalana
void highersort(uint sizearr, uptr* arr)
{
    uint counter; // ana sayaç
    uint counterin; // iç sayaç
    uint temp; // geçici değer depolayıcı

    // baloncuk sıralama ile yapacağız
    for(counter = 0; counter < sizearr; counter++)
    {
        // iç döngü
        for(counterin = (counter + 1); counterin < sizearr; counterin++)
        {
            // ana sayaçtaki değer iç sayaçtakinden büyükse
            if(*(*arr + counter) < *(*arr + counterin))
            {
                // ana sayaçtaki değer geçici olarak sakla
                // sonrasında değerlerin yerini değiştir
                temp = *(*arr + counter);
                *(*arr + counter) = *(*arr + counterin);
                *(*arr + counterin) = temp;
            }
        }
    }
}