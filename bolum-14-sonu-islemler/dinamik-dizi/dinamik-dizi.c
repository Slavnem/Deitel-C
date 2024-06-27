// Slavnem @2024-06-27
// Dinamik Dizi Tahsisi

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// NULL kontrolcüsü
#ifndef NULLER
#define NULLER(x) (x == NULL)
#endif

// En düşük bellek tahsisi miktarı
#ifndef MALLOC_MIN
#define MALLOC_MIN 3
#endif

// En yüksek bellek tahsisi miktarı
#ifndef MALLOC_MAX
#define MALLOC_MAX 10
#endif

// Bellek tahsis sınırları
#if !defined(MALLOC_MIN) || !defined(MALLOC_MAX)
#error "Bellek Tahsis Sinirlari Tanimli Degil!"
#endif

// Tamsayı dizi çıktı verici
#ifndef IPRINTARR
#define IPRINTARR(intarr, arrsize) { \
    printf("\nListe: "); \
    for(int counter = 0; counter < arrsize; counter++) { \
        printf("%-2d ", intarr[counter]); \
    } \
    puts(""); \
}
#endif

// Değişken isimlendirmeleri
typedef int* iptr;
typedef unsigned int uint;

// Fonksiyon prototipi
static void mem_cleanup(void);
static void signal_message(int signalValue);
static void exit_message(void);

// tamsayı dizisi
static iptr intarray = NULL;

// main
int main(void)
{
    atexit(mem_cleanup); // program bellek temizleyicisi
    atexit(exit_message); // program sonlandırma mesajcısı

    // sinyal durumları oluşturma
    signal(SIGINT, signal_message); // kullanıcı kaynaklı kesinti
    signal(SIGABRT, signal_message); // anormal kesinti
    signal(SIGTERM, signal_message); // düzgün şekilde sonlandırma
    signal(SIGKILL, signal_message); // zorla işlemi sonlandırma
    signal(SIGHUP, signal_message); // terminal kapanması ya da kullanıcı oturum sonlanması
    signal(SIGSEGV, signal_message); // izinsiz bellek erişimi ya da segmentasyon hatası (segmentation fault)

    // dizi değer miktarını tutacak değişken
    int arrsizer;

    // geçici sayaç
    uint arrcounter;

    // geçici değer tutucu
    int tempvalue;

    // kullanıcıdan geçerli miktar girilene kadar değer alma
    do
    {
        printf("En dusuk %d, en yuksek %d olacak sekilde bellek tahsisi icin deger giriniz: ",
            MALLOC_MIN, MALLOC_MAX
        );
        scanf("%d", &arrsizer);
    } while (arrsizer < MALLOC_MIN || arrsizer > MALLOC_MAX);

    // dizi için bellek tahsis etmek
    intarray = malloc(arrsizer * sizeof(int));

    // bellek tahsisi eğer başarısız ise
    if(NULLER(intarray))
    {
        puts("\nTamsayi dizi icin bellek tahsisi basarisiz oldu");
        exit(EXIT_FAILURE);
    }

    // bellek tahsis edildiği için, sayaç ile kullanıcıdan değerleri almak ve diziye kaydetmek
    for(arrcounter = 0; arrcounter < arrsizer; arrcounter++)
    {
        printf("%d) deger giriniz: ", (arrcounter + 1));
        scanf("%d", &intarray[arrcounter]);
    }

    // değerleri kaydedildiği diziyi çıktı vermek
    IPRINTARR(intarray, arrsizer);

    // diziyi yarıya bölünecek şekilde yeniden boyutlandır
    arrsizer /= 2;
    intarray = realloc(intarray, (arrsizer * sizeof(int)));

    if(NULLER(intarray))
    {
        puts("\nDizi yeniden boyutlandirilamadi!");
        exit(EXIT_FAILURE);
    }

    // diziyi tekrar çıktı versin
    puts("\n* Dizi yarisi kadar olacak sekilde yeniden boyutlandilirdi *");
    IPRINTARR(intarray, arrsizer);
}

// mem_cleanup -> bellek temizleyici
static void mem_cleanup(void)
{
    // bellek boş mu kontrol etsin
    if(!NULLER(intarray))
    {
        free(intarray); // belleği temizleme
        intarray = NULL; // belleğin adresini NULL yap
    }

    // bilgi çıktısı
    printf("\n* Bellek Basariyla Temizlendi *\n");
}

// signal_message -> sinyal bildirici
static void signal_message(int signalValue)
{
    // sinyal kodunu kullanıcıya bildirme
    printf("\n\n* Sinyal Kesinti Kodu: %d *\n", signalValue);
    exit(EXIT_SUCCESS);
}

// exit_message -> Çıkış mesajı
static void exit_message(void)
{
    puts("\nProgram Sonlandiriliyor...");
}