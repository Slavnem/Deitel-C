// Slavnem
// Alfabe Bulma Sayısı
// ===================
// Kütüphaneler
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Ön işlemci tanımları
#define SIZE 100
#define ALFABE 26
#define CUMLE 5
#define ASCII_A 65 // ASCII standartına göre büyük harf başlangıcı
#define ASCII_a 97 // ASCII standartına göre küçük harf başlangıcı
#define COLWITH 8 // tek satırda yazılacak sütun sınırı

// Fonksiyon tanımları
void printCizelge(const int* const, const size_t* const, const size_t* const);

// main
int main(void)
{
    char cumleler[CUMLE][SIZE]; // cümleleri depolayacak olan dizi

    char* cumlePtr; // geçici olarak cümle adresini tutacak olan değişken

    size_t cumlesayac; // cümleleri sayacak olan sayaç
    size_t size_temp; // geçici olarak dizideki konumun boyutunu tutacak
    size_t size_alfabe; // kaç tane harfe kadar desktelendiğini geçici olarak tutacak

    // tutulacak cümlelerin miktarını saklayacak
    const size_t size_cumle = (sizeof(cumleler) / sizeof(cumleler[0]));

    int harfler[CUMLE][ALFABE] = {0}; // metinde hangi harften kaç defa olduğunu sayma
    int harfsayac; // harften kaç tane bulunduğunu tutan geçici sayaç


    // kullanıcıdan cümleler almak
    for(cumlesayac = 0; cumlesayac < size_cumle; cumlesayac++)
    {
        // kaç karaktere kadar depolayabileceğini tutuyor geçici olarak
        size_temp = (sizeof(cumleler[cumlesayac]) / sizeof(cumleler[cumlesayac][0]));

        // kullanıcıdan metin isteyip depoladık
        // depolama esnasında alfabe sayımı yapabiliriz ama önerilmez
        printf("[%zu] cumle giriniz: ", (cumlesayac + 1));
        fgets(cumleler[cumlesayac], size_temp, stdin);

        // satır sonu karakterlerini silme
        cumleler[cumlesayac][strcspn(cumleler[cumlesayac], "\n")] = '\0';
    }

    // metinlerin içinde hangi harften kaç defa bulunduğunu saymak
    for(cumlesayac = 0; cumlesayac < size_cumle; cumlesayac++)
    {
        // şuanki dizinin kaç harf desteklediğini tutmak
        size_alfabe = (sizeof(harfler[cumlesayac]) / sizeof(harfler[cumlesayac][0]));

        // desteklenen harf miktarı kadar işlem yapmak
        for(harfsayac = 0; harfsayac < size_alfabe; harfsayac++)
        {
            // başta küçük harfler için harfin geçici konumunu tutmak
            // ASCII_a yazmamızın nedeni ASCII standartlarına göre
            // küçük harfler 97'den başlar, bir daha "97" yazmak yerine
            // ASCII_a yazarak bunu düzgünce yapmış oluyoruz
            cumlePtr = strchr((cumleler[cumlesayac]), tolower(ASCII_a + harfsayac));

            // harf bulunuyorsa devam etsin
            while(cumlePtr != NULL)
            {
                // harfin bulunduğunu konumdaki sayıyı 1 arttırma
                ++harfler[cumlesayac][harfsayac];

                // cümle içinde harfin bir sonraki konumunu almak
                cumlePtr = strchr((cumlePtr + 1), tolower(ASCII_a + harfsayac));
            }

            // şimdi ise aynısı sadece büyük harfler için
            // normalde toupper kullanmasak da olur çünkü ASCII_A diyerek
            // zaten ASCII standartına göre "65" yani büyük harf demiş oluyoruz
            // fakat biz bu soru da rahatça gösterme amaçlı yinede kullanıyoruz
            cumlePtr = strchr((cumleler[cumlesayac]), toupper(ASCII_A + harfsayac));

            // harf bulunuyorsa devam etsin
            while(cumlePtr != NULL)
            {
                // harfin bulunduğunu konumdaki sayıyı 1 arttırma
                ++harfler[cumlesayac][harfsayac];

                // cümle içinde harfin bir sonraki konumunu almak
                cumlePtr = strchr((cumlePtr + 1), toupper(ASCII_A + harfsayac));
            }
        }
    }

    // metin okuma ve harf sayma işlemleri bitti
    // kullanıcıya bilgilendirme amaçlı çıktı verme
    printCizelge(harfler[0], &size_cumle, &size_alfabe);
}

// printCizelge
void printCizelge(const int* const harfler, const size_t* const size_metinler, const size_t* const size_harfler)
{
    size_t saycumle; // cümleler için sayaç
    size_t sayharf; // harfler için sayaç

    // cümlelerin miktarı kadar dönmesini sağlayan döngü
    for(saycumle = 0; saycumle < (*size_metinler); saycumle++)
    {
        // daha yazılacak metinler varsa
        if(saycumle != (*size_metinler))
            puts("\n-------------------");
        
        // cümle numarasını çıktı verme
        printf("|%zu|\n", (saycumle + 1));

        // girilen metini çıktı vermek
        for(sayharf = 0; sayharf < (*size_harfler); sayharf++)
        {
            // tam bölünüyorsa boş satır oluştur
            if(sayharf % COLWITH == 0)
                puts("");

            // o harfin büyük küçük farketmeksizin kaç defa bulunduğunu çıktı vermek
            // AÇIKLAMA: *(harfler + (saycumle * (*size_harfler)) + sayharf)
            // bu şu anlama gelir: "harfler" in olduğu adrese git,
            // adres numarasına saycumlenin değeri ilye size_harfler işaretçisinin değerini topla
            // ve sayharfin değerini bunlara ek olarak toplayıp ekle
            // yani harf[3][7] nolu adresdeki değere erişmek için
            // *(harfler + (3 * (*size_harfler)) + 7)
            // normal bir dizi argümanı almak yerine bellek adresi olarak almamızın ana nedeni:
            // performansı arttırma ve ek güvenlik sağlama, çünkü "const int* const" diyerek
            // bu bellek adresindeki değerlerin değişemeyeceğini belirtmiş oluyoruz
            printf("[%c%c]: %02d ", (ASCII_A + sayharf), (ASCII_a + sayharf), *(harfler + (saycumle * (*size_harfler)) + sayharf));
        }
    }

    puts(""); // boş satır
}