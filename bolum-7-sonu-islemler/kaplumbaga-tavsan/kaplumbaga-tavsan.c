// include
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define
#define MAX_UZUNLUK 70
#define MIN_UZUNLUK 1

#define HAYVAN 2

#define MIN_RAND 1
#define MAX_RAND 10

// enum
enum Hayvan {
    KAPLUMBAGA = 0,
    TAVSAN = 1
};
enum OyunDurum {
    BOS = 0,
    BASLANGIC = 1,
    DEVAM = 2,
    BITIS = 3,
    HATA = 4
};
enum Coklu {
    COKLU_RASTGELE = 0,
    COKLU_ARTTIRICI = 1,
    COKLU_HATAKONTROL = 2
};

/* ACIKLAMA:
* Bir cok hata cikti bu programi kodlayana kadar, kimisi basitdi kimisi ise karmasik
* tabi hatalar cozuldu ama bu hatalardan da iyi bir ders de cikarmis oldum.
* kodlarken bazi mantiksal seylere de dikkat etmem gerektigini bi kere daha anladim */

// + main
int main(void)
{
    // ++ submain
    void submain(void);

    submain();
}
// - main

// + submain
void submain(void)
{
    // ++ oyun
    void oyun(void);

    // rastgele zamanlayici
    srand(time(NULL));

    // oyun basliyor
    oyun();
}
// - submain

// + oyun
void oyun(void)
{
    // ontanim
    void rastgeleUretici(int*); // rastgele sayi ureten fonksiyon
    void arttirici(int*); // gelen sayiyi arttiran fonksiyon, tur icin olusturuldu ama genel kullanilabilir
    void hataKontrol(int*); // hata oldugunda cikti veren fonksiyon

    // ontanimlama
    void (*cokluPtr[])(int*) = {
        rastgeleUretici,
        arttirici,
        hataKontrol
    };

    void durumHesaplayici(const size_t*, int*, const int*, int*, int*);
    void mesajMini(const char*[]);
    void kazananBul(const size_t*, int*, int*, const int*);

    // tum degiskenler

    // ouun basidan sonuna kadar olucaklari icin static
    static int ilerleme_dizi[HAYVAN] = { 1,1 }; // 0: kaplumbaga, 1: tavsan
    static int kazanan = BOS; // baslangicta kazanan olmadigindan BOS
    static int kazanan_sira = -1; // baslangicta kazananin sirasi olmadigindan -1
    static int tur = 1; // tur
    static int oyun_durum = BOS; // oyun durumunu baslangicta BOS a ayarlamak

    int rastgele; // dongu de surekli olusturulacak olan rastgele sayinin degiskeni
    int hareket_tur; // hayvanlarin yaptigi hareketin turu

    size_t sayac; // hayvan sayaci

    oyun_durum = BASLANGIC; // oyun durumunu oyun basliyacagi icin BASLANGIC a ayarlamak

    // hayvanlarin isimleri
    const char* hayvanlar[] = {
        "Kaplumbaga",
        "Tavsan"
    };

    // tavsanin hareketi
    const char* tavsan_hareketPtr[] = {
            "Hareket yok",
            "9 kare saga",
            "12 kare sola",
            "1 kare saga",
            "2 kare sola"
    };

    // kaplumbaganin hareketi
    const char* kaplumbaga_hareketPtr[] = {
            "3 kare saga",
            "6 kare sola",
            "1 kare saga"
    };

    // tavsanin yaptigi hareketlerin turu
    const char* tavsan_hareket_turPtr[] = {
        "Uyku",
        "Buyuk sicrama",
        "Buyuk kayma",
        "Kucuk sicrama",
        "Kucuk kayma"
    };

    // kaplumbaganin yaptigi hareketlerin turu
    const char* kaplumbaga_hareket_turPtr[] = {
        "Hizli yuruyus",
        "Kayma",
        "Yavas yuruyus"
    };

    // kaplumbaganin tavsani isirdiginda cikacak olan ozel mesaj
    const char* mesajPtr[] = {
        "OUCH!!!"
    };

    // kazanma mesajlari
    const char* kazanmaPtr[] = {
        "KAPLUMBAGA KAZANDI!!! YAY!!!",
        "TAVSAN KAZANDI. Yuch."
    };

    // ilk tur ise ozel mesaj
    if(tur == 1)
    {
        puts("BANG !!!!!");
        puts("VE YARIS BASLADI !!!!!");
    }
    
    // oyun bitmedikce veya hata vermedikce devam edicek
    while(oyun_durum == BASLANGIC || oyun_durum == DEVAM)
    {
        for(sayac = 0; sayac < HAYVAN; sayac++)
        {
            /* UYARI: biz bir dongu olusturdugumuz icin,
            * ilk tur da bitmis olsa bile bunu kaydetmedigimizden
            * ve bittigi icin donguyu kirmadigimizdan, ikinci ne zaman
            * biterse aslinda o zaman bitmis olucak, peki biz ne yapmaliyiz
            * bittimi bitmedi mi diye ek bir fonksiyon ile kontrol edebiliriz
            * veyaa... bir if else ile bunun kontrolunu de saglayabiliriz
            * ben bir fonksiyon almiyacagim, if else ile BITIS veya HATA
            * durumlari olusmus ise, donguyu kirdiricam */

            (*cokluPtr[COKLU_RASTGELE])(&rastgele); // rastgele sayi uretme (1-10 arasinda)
            durumHesaplayici(
                &sayac,
                &ilerleme_dizi[sayac],
                &rastgele,
                &hareket_tur,
                &oyun_durum); // durum kontrolu

            // dongu devam ettigi icin
            // hayvanlar hakkindaki bilgileri kullaniciya gosterme ciktisi
            printf(
            "%d) " // tur numara
            "[%d] " // ilerleyis kare
            "%s" // hayvan
            "\t%s" // hareket tur
            "\t%d" // zaman yuzdesi
            "\t%s" // gecerli hareket
            "\n",
            tur,
            ilerleme_dizi[sayac],
            hayvanlar[sayac],
            sayac == 0 ? (kaplumbaga_hareketPtr[hareket_tur]) : (tavsan_hareketPtr[hareket_tur]),
            (rastgele * 10),
            sayac == 0 ? (kaplumbaga_hareket_turPtr[hareket_tur]) : (tavsan_hareket_turPtr[hareket_tur])
            );

            // kaplumbaga ile tavsan ayni konumda ise
            // kaplumbaga tavsani isirir
            if(ilerleme_dizi[KAPLUMBAGA] == ilerleme_dizi[TAVSAN])
            {
                mesajMini(&mesajPtr[0]); // OUCH !!!
            }

            // oyun bitti, donguyu kirabiliriz
            if(oyun_durum == BITIS)
                break;

            // hata mesaji varsa cikti versin
            else if(oyun_durum == HATA)
                (*cokluPtr[COKLU_HATAKONTROL])(&oyun_durum);
            
        }

        // yeni tur icin tur sayacini arttirma
        (*cokluPtr[COKLU_ARTTIRICI])(&tur);
    }
    
    // kazanani belirleme
    for(sayac = 0; sayac < HAYVAN; sayac++)
    {
        // kazanani hesaplamak icin olusturulmus fonksiyon
        // dongu bitene kadar hepsini hesaplicak ve en son kazanani
        // bulmus olucak

        kazananBul(&sayac, &kazanan_sira, &kazanan, &ilerleme_dizi[sayac]);
    }

    // oyunun son durumu
    switch(oyun_durum)
    {
        // duzgunce bitmisse
        case BITIS:
            // kazanan
            printf(
                "\n%s\n", // kazanan
                kazanmaPtr[kazanan_sira]);

            puts("Oyun basariyla bitti!");
        break;

        // hatali bitmisse
        case HATA:
            puts("Oyun bir hata sonucu sonlandirildi...");
            break;

        // baska bir durum olusmussa eger
        default:
            printf("\nOyun Durum Kodu: %d\n", oyun_durum);
            break;
    }
}
// - oyun

// + rastgeleUretici
void rastgeleUretici(int* sayiPtr)
{
    // istenen aralikta olmasi icin ayarlanmis formul de
    // bir rastgele sayi uretmek
    *sayiPtr = MIN_RAND + (rand() % MAX_RAND);
}
// - rastgeleUretici

// + durumHesaplayici
void durumHesaplayici(
    const size_t* hayvanPtr,
    int* yolPtr,
    const int* hareketPtr,
    int* hareket_turPtr,
    int* oyundurumPtr
)
{
    // ontanim
    void ilerlemeKontrol(const int*, int*);

    // hayvanlar
    switch(*hayvanPtr)
    {
        // kaplumbaga icin kontrol
        case KAPLUMBAGA:
            if(*hareketPtr >= 1 && *hareketPtr <= 5)
            {
                *yolPtr += 3;
                *hareket_turPtr = 0; // hizli yuruyus
            }

            else if(*hareketPtr >= 6 && *hareketPtr <= 7)
            {
                // eger cikarildiginda 0 veya 0'dan dusuk cikiyorsa sonuc
                // otomatikmen yarisin baslangicina atsin (MIN_UZUNLUK)
                if(*yolPtr <= 6)
                {
                    *yolPtr = MIN_UZUNLUK;
                }

                // degilse zaten direk sayiyi cikarsin
                else
                {
                    *yolPtr -= 6;
                }

                *hareket_turPtr = 1; // kayma
            }

            else if(*hareketPtr >= 8 && *hareketPtr <= 10)
            {
                *yolPtr += 1;
                *hareket_turPtr = 2;
            }

            else
            {
                // hata
                *oyundurumPtr = HATA;

                printf(
                    "Boyle bir komut yok\n"
                    "Hata Kodu: %d\n", *oyundurumPtr);
            }
        break;
        
        // tavsan icin kontrol
        case TAVSAN:
            if(*hareketPtr >= 1 && *hareketPtr <= 2) 
            {
                *hareket_turPtr = 0; // uyku
            }

            else if(*hareketPtr >= 3 && *hareketPtr <= 4)
            {
                *yolPtr += 9;
                *hareket_turPtr = 1; // buyuk sicrama
            }

            else if(*hareketPtr == 5)
            {
                // eger cikarildiginda 0 veya 0'dan dusuk cikiyorsa sonuc
                // otomatikmen yarisin baslangicina atsin (MIN_UZUNLUK)
                if(*yolPtr <= 12)
                {
                    *yolPtr = MIN_UZUNLUK;
                }

                // degilse zaten direk sayiyi cikarsin
                else
                {
                    *yolPtr -= 12;
                }

                *hareket_turPtr = 2; // buyuk kayma
            }

            else if(*hareketPtr >= 6 && *hareketPtr <= 8)
            {
                *yolPtr += 1;
                *hareket_turPtr = 3; // kucuk sicrama
            }
            
            else if(*hareketPtr >= 9 && *hareketPtr <= 10)
            {
                if(*yolPtr <= 2)
                {
                    *yolPtr = MIN_UZUNLUK;
                }
                else
                {
                    *yolPtr -= 2;
                }

                *hareket_turPtr = 4; // kucuk kayma
            }
        break;

        // kontrol icin boyle hayvan yok
        default:
            printf(
                "Kontrol icin boyle bir hayvan kodu yok\n"
                "Hayvan Kodu: %zu\n", *hayvanPtr);
        
            // HATA
            *oyundurumPtr = HATA;
        break;
    }

    // ilerlemeyi kontrol etme
    // yol zaten isaretci olarak geldiginden
    // bir daha adres (&) belirtmeye gerek yok
    ilerlemeKontrol(yolPtr, oyundurumPtr);
}
// - durumHesaplayici

// + ilerlemeKontrol
void ilerlemeKontrol(const int* ilerleme_seviyePtr, int* ilerleme_durumPtr)
{
    // yolu bitirmisse BITIS    
    if(*ilerleme_seviyePtr >= MAX_UZUNLUK)
        *ilerleme_durumPtr = BITIS;

     // hata olusmussa HATA
     // sonrasinda diger fonksiyon programi durdurucak zaten

     // UYARICI:
     // eger   <= MIN_UZUNLUK der isek, benimde saatlerdir cozumunu aradigim soruna neden olur
     // cunku en az 1 olabilir ama biz boyle yapar isek, 1'e esit veya kucuk ise hata versin deriz
     // ama zaten daha baslangicta bile 1. sirada baslamiyorlar mi?
    else if(*ilerleme_seviyePtr < MIN_UZUNLUK)
        *ilerleme_durumPtr = HATA;

    // hicbiri olmamissa eger program devam ediyodur DEVAM
    else
        *ilerleme_durumPtr = DEVAM;
}
// - ilerlemeKontrol

// + turArttirici
void arttirici(int* sayiPtr)
{
    (*sayiPtr) += 1;
}
// - turArttirici

// + hataKontrol
void hataKontrol(int* hataPtr)
{
    if(*hataPtr == HATA)
        printf("Hata kodu: %d\n",*hataPtr);
}
// - hataKontrol

// + mesajMini
void mesajMini(const char* mesajPtr[])
{
    puts(*mesajPtr);
}
// - mesajMini

// + kazananBul
void kazananBul(
    const size_t* yeni_siraPtr, 
    int* lider_siraPtr,
    int* liderPtr,
    const int* yeniPtr)
{
    // yeni puan eskisinden buyuk ise
    // yeni lider puan ve lider sira...
    // yeni puan ve yeni puanin sirasidir

    if(*yeniPtr > *liderPtr)
    {
        *liderPtr = *yeniPtr;
        *lider_siraPtr = *yeni_siraPtr;
    }
}
// - kazananBul