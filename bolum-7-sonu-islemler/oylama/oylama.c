///////////////////////////
// Yazan: Slavnem
// Dil: C
///////////////////////////

// Kütüphaneler
#include <stdio.h>

// Program ön işlemci tanımları
// satır ve sütun
#define VOTE_ROW 5
#define VOTE_COLUMN 10

// sıradaki konu ya da program sonu
#define NEXT_VOTE 99
#define END_VOTE 999
#define KILL_VOTE -1

// değerlendirme puan sınır
#define MIN_VAL_VOTE 1
#define MAX_VAL_VOTE (VOTE_COLUMN)

// oy girme miktarları sınırlandırma
#define MIN_VOTE_ENTER 0
#define MAX_VOTE_ENTER 10

// ... kez de 1 tekrarla
#define REPEAT_AFTER_TIMES (MAX_VOTE_ENTER)

// numaralandırma
enum PROG_RETURN
{
    PROG_FALSE = 0, // hata
    PROG_TRUE = 1, // başarılı
    PROG_LEAK = 2 // kod açığı
};

enum VOTMINAX
{
    VOT_MIN = 0,
    VOT_MAX = 1
};

// Fonksiyon
int main(void)
{
    // fonksiyon tanımı
    int procVote(void);

    // fonksiyonu çalıştırıp döndürmek
    return procVote();
}

// genel kullanım için yapılmış fonksiyonlar tanımları
void siprintarr(const char*[], const int*, const size_t*);
void simultprintarr(char*[], const int*, const int*, const size_t*, const size_t*);

// procVote
int procVote(void)
{
    // en düşük, en yüksek, ortalama
    // oylamayı bulmayı sağlayan
    // fonksiyonların ön tanımı
    void voteAvg(const int*, int*, const size_t*, const size_t*);
    void voteMin(const int*, const size_t*, char*[]);
    void voteMax(const int*, const size_t*, char*[]);

    void(*voteOrd[])(const int*, const size_t*, char*[]) =
    {
        voteMin,
        voteMax
    };

    // değişkenler
    char* strSubject[] =
    { // sosyal bilinclilik konuları
        "Yardimlasma",
        "Siyasi Meseleler",
        "Kuresel Problemler",
        "Ozgurluk",
        "Nezaket"
    };

    const char* strVoteMsg[] =
    {
        "Siradaki oylama konusu",
        "Oylamayi durdur",
        "Oylamayi zorla bitir, programi kapat"
    };

    const int iVoteMsg[] =
    {
        NEXT_VOTE,
        END_VOTE,
        KILL_VOTE
    };

    int ivote[VOTE_ROW][VOTE_COLUMN] = {0}; // oylama bilgilerini tutan dizi
    int avgivote[(sizeof(ivote) / sizeof(ivote[0]))] = {0}; // konulara ait oralama puanı tutacak olan dizi
    int __getvoteval; // kullanıcının girdiği değer
    int __controlval; // kontrol değeri

    size_t __size_strvotemsg = (sizeof(strVoteMsg) / sizeof(strVoteMsg[0]));
    size_t __size_ivote_row = sizeof(ivote) / sizeof(ivote[0]);
    size_t __size_ivote_column = (sizeof(ivote) / sizeof(ivote[0][0]) / __size_ivote_row);
    size_t __size_avgivote = (sizeof(avgivote) / sizeof(avgivote[0]));
    size_t __vcount; // konu sayaç
    size_t __vselcount = 0; // oylama miktar sayaç
    size_t __allcount = 0; // ne olduğu önemsiz hepsini sayan sayaç

    // döngüler ile konu konu oylama yapmak
    for(__vcount = 0; __vcount < __size_ivote_row && __getvoteval != END_VOTE; __vcount++)
    {
        // seçilen konudaki giriş miktarını saymayı sıfırlama
        __vselcount = 0;

        // her şeyi sayac sayaçı sıfırlama
        __allcount = 0;

        // kontrol değerini sıfırlama
        __controlval = 0;

        // sıradaki konuya geçilmedikçe ve oylama sonlandırılmadıkça
        // ve girilen oy miktarı sınırlandırmayı aşmadıkça
        // dönsün
        while(__controlval != NEXT_VOTE && __controlval != END_VOTE && __vselcount < MAX_VOTE_ENTER)
        {
            // belirli kez sayıdan sonra tekrar konuyu çıktı versin
            if(__allcount % REPEAT_AFTER_TIMES == 0) {
                siprintarr(strVoteMsg, &iVoteMsg[0], &__size_strvotemsg); // komutları çıktı vermek
                printf("\n[%s] %d-%d\n", strSubject[__vcount], MIN_VAL_VOTE, MAX_VAL_VOTE);
            }

            // her şeyi sayan sayaçı arttırma
            __allcount++;

            // değer almak, sıradaki konuya geçilmek isteniyorsa döngüyü kırmak
            printf("(%d) Puan giriniz: ", (__vselcount + 1));
            
            // en fazla 2 basamaklı ve tek basamaklı ise 0 koysun başına
            scanf("%3d", &__getvoteval);

            // DEĞER ALMADA SORUN YOK AMA ÇIKTI VERMELERDE HATA VAR
            // SATIR 135'DEN SONRA MANTIK HATALARI VAR
            // PROGRMA ORTALAMA HESAPLAMA DA YAPMIYOR
            // voteAvg fonksiyonu hesaplamada sorun yaşıyor!

            // puan almak
            switch(__getvoteval >= MIN_VAL_VOTE && __getvoteval <= MAX_VAL_VOTE)
            {
                // puan doğru
                case PROG_TRUE:
                    __vselcount += 1; // sayacı arttır

                    // verilen puanın tutulduğu yerdeki değeri arttır
                    ivote[__vcount][__getvoteval - 1] += 1;
                break;
                // diğer işlemler
                default:
                    // istenen değer girilmemişse eğer
                    // girilen değeri kontrol değerine atama
                    __controlval = __getvoteval;

                    // kontrol komutları
                    switch(__controlval)
                    {
                        // program zorla sonlandırıldı
                        case KILL_VOTE:
                            return PROG_FALSE;
                    }
                break;
            }
        }

        // oylama bitir
        if(__controlval == END_VOTE)
        {
            puts(""); // boş satır
            break;
        }
    }

    // oylama bitti
    // dizilerin puan ortalamasını almak
    voteAvg(&ivote[0][0], &avgivote[0], &__size_ivote_row, &__size_ivote_column);

    // en yüksek puan alan
    (*voteOrd[VOT_MAX])(&avgivote[0], &__size_avgivote, strSubject);

    // en düşük puan alan
    (*voteOrd[VOT_MIN])(&avgivote[0], &__size_avgivote, strSubject);

    // bilgileri çıktı vermek
    simultprintarr(&strSubject[0], &ivote[0][0], &avgivote[0], &__size_ivote_row, &__size_ivote_column);
}

// ortalama
void voteAvg(const int* ivotearrPtr, int* avgvotearrPtr, const size_t* size_ivoteRowPtr, const size_t* size_ivoteColPtr)
{
    int __totalvotepoint; // geçici olarak satıra ait otplam puanı tutacak
    int __totalvotetrue; // geçici olarak toplam kaç oy girildiğini tutacak
    int __tempvotenum; // geçici olarak toplam oy sayısını

    size_t __vrowcount; // satır sayacı
    size_t __vcolcount; // sütun sayacı

    // döngüyle hesaplamak
    for(__vrowcount = 0; __vrowcount < (*size_ivoteRowPtr); __vrowcount++)
    {
        // değer sıfırlama
        *(avgvotearrPtr + __vrowcount) = 0;

        // geçici oylama toplayıcısı sıfırlama
        __totalvotetrue = 0;

        // geçici satır puan toplayıcısını sıfırlama
        __totalvotepoint = 0;

        // sütun sütun değer bulma
        for(__vcolcount = 0; __vcolcount < (*size_ivoteColPtr); __vcolcount++)
        {
            // konuma ait değeri geçici olarak depolama
            __tempvotenum = *(ivotearrPtr +  __vcolcount + (__vrowcount * (*size_ivoteColPtr)));

            // girilen toplam oy miktarını arttırma
            __totalvotetrue += __tempvotenum;

            // toplam puanı arttırma ama
            // bulunduğumuz sütundan kaç kez aynı puan verilmişse
            // o kadar kez eklesin
            __totalvotepoint += (__tempvotenum) * (__vcolcount + 1);
        }

        // toplanan değeri sütun sayısına bölüp diziye aktarmak
        // eğer toplam girilen oy sayısı 0'dan fazla ise hesaplasın
        if(__totalvotetrue)
        {
            *(avgvotearrPtr + __vrowcount) = (__totalvotepoint) / (__totalvotetrue);
        }
    }
}

// en düşük puan
void voteMin(const int* votearrPtr, const size_t* size_votearrPtr, char* strVote[])
{
    int __tempIndex = 0; // geçici olarak en düşük değeri içeren index
    size_t __votecount; // sayaç

    // döngüyle en düşük indexi bulma
    for(__votecount = 1; __votecount < *(size_votearrPtr); __votecount++)
    {
        *(votearrPtr + __votecount) < *(votearrPtr + __tempIndex) ? (__tempIndex = __votecount) : (__tempIndex == __tempIndex);
    }

    // ekrana çıktıyı vermek
    printf("En dusuk puana sahip olan konu: %s\n", (strVote[__tempIndex]));
}

// en yüksek puan
void voteMax(const int* votearrPtr, const size_t* size_votearrPtr, char* strVote[])
{
    int __tempIndex = 0; // geçici olarak en yüksek değeri içeren index
    size_t __votecount; // sayaç

    // döngüyle en büyük indexi bulma
    for(__votecount = 1; __votecount < *(size_votearrPtr); __votecount++)
    {
        *(votearrPtr + __votecount) > *(votearrPtr + __tempIndex) ? (__tempIndex = __votecount) : (__tempIndex == __tempIndex);
    }

    // ekrana çıktıyı vermek
    printf("En buyuk puana sahip olan konu: %s\n", (strVote[__tempIndex]));
}

// SIPRINTARR
void siprintarr(const char* sarrPtr[], const int* iarrPtr, const size_t* sizeptr_sarrPtr)
{
    size_t __sicount; // sayaç

    // hoş görünüm için
    puts("===================");

    // döngü ile çıktı vermek
    // değerler boş değilse dönsün
    for(__sicount = 0; (sarrPtr[__sicount]) != NULL && (iarrPtr + __sicount) != NULL && __sicount < *(sizeptr_sarrPtr); __sicount++)
    {
        printf("[%d] %s\n", *(iarrPtr + __sicount), (sarrPtr[__sicount]));
    }

    // hoş görünüm için
    puts("===================");
}

// SIMULTPRINTARR
void simultprintarr(char* strarrPtr[], const int* valarrPtr, const int* avgarrPtr, const size_t* size_vRowPtr, const size_t* size_vColPtr)
{
    size_t __smiucountrow; // satır sayaç
    size_t __smiucountcol; // sütun sayaç

    // satır ve sonrasında sütuna göre
    // konu isimiyile birlikte çıktı
    // ve ortalama notu da çıktı vermek
    for(__smiucountrow = 0; __smiucountrow < *(size_vRowPtr); __smiucountrow++)
    {
        // satıra ait konuyu yazdırmak
        printf("\n[%s]\n", (strarrPtr[__smiucountrow]));

        // sütun çıktıları
        for(__smiucountcol = 0; __smiucountcol < *(size_vColPtr); __smiucountcol++)
        {
            // puandan kaç adet olduğunu yazdırmak
            printf("[%d]:%d ", (__smiucountcol + 1), *(valarrPtr + __smiucountcol + (__smiucountrow * (*size_vColPtr))));
        }

        // ortalama oy
        printf("| ortalama oy: %d", *(avgarrPtr + __smiucountrow));

        // boş satır
        puts("");
    }
}