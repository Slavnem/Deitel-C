// BASTİÇE MATEMATİK 4 İŞLEM ÖĞRETME VE SORU ÇÖZDÜRME 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int islemsec(int, int);
int toplama(int, int);
int cikarma(int, int);
int carpma(int, int);
int bolme(int, int);
int asalkontrol(int);
int tekrarson(int);
void tebriklermesaj(int);

static int dogruSayi = 0, yanlisSayi = 0;

// Ana Fonksiyon
int main(int anaIslemDurum)
{
    if(anaIslemDurum == 0)
    {
        puts("------------------------------------------");
        puts("Program sonlandiriliyor...");
        return 0;
    }
    else
    {
        srand(time(NULL));
        islemsec(2, 0);
    }
}

// Matematiksel işlemlerin fonksiyonu
int matematikIslem(int matematikSecim)
{
    switch(matematikSecim)
    {
        case 1:
            toplama(1 + (rand() % 99), 1 + (rand() % 99));
            break;
        case 2:
            int sayicikar1, sayicikar2, buyukcikar, kucukcikar;

            sayicikar1 = 1 + (rand() % 99);
            sayicikar2 = 1 + (rand() % 99);

            sayicikar1 >= sayicikar2 ? (buyukcikar = sayicikar1, kucukcikar = sayicikar2) : (buyukcikar = sayicikar2, kucukcikar = sayicikar1);

            cikarma(buyukcikar, kucukcikar);
            break;
        case 3:
            carpma(1 + (rand() % 9), 1 + (rand() % 9));
            break;
        case 4:
            int bol1, bol2, buyukbol, kucukbol;

            do
            {
                do
                {
                    bol1 = 1 + (rand() % 99);
                } while (asalkontrol(bol1) != bol1);

                do
                {
                    bol2 = 1 + (rand() % 99);
                } while (asalkontrol(bol2) != bol2);

                bol1 >= bol2 ? (buyukbol = bol1, kucukbol = bol2) : (buyukbol = bol2, kucukbol = bol1);
            } while(buyukbol % kucukbol != 0);

            bolme(buyukbol, kucukbol);
            break;
        default:
            puts("Hatali islem turu (HATA!)");
            return main(0);
            break;
    }
}

// İşlem seçimi fonksiyonu
int islemsec(int islemIstek, int islemTur)
{
    int islemsecim;

    switch(islemIstek)
    {
        case 0:
            return main(0);
            break;

        case 1:
            switch(islemTur)
            {
                case 1:
                    matematikIslem(1);
                    break;
                case 2:
                    matematikIslem(2);
                    break;
                case 3:
                    matematikIslem(3);
                    break;
                case 4:
                    matematikIslem(4);
                    break;
                default:
                    puts("Hatali islem turu (HATA!)");
                    return main(0);
                    break;
            }
            break;

        case 2:
            do
            {
                puts("1-Toplama\n2-Cikarma\n3-Carpma\n4-Bolme\n5-Cikis");
                printf("Bir islem seciniz: ");
                scanf("%d", &islemsecim);
            } while(islemsecim < 1 || islemsecim > 5);

            switch(islemsecim)
            {
                case 1:
                    matematikIslem(1);
                    break;
                case 2:
                    matematikIslem(2);
                    break;
                case 3:
                    matematikIslem(3);
                    break;
                case 4:
                    matematikIslem(4);
                    break;
                case 5:
                    return main(0);
                    break;
                default:
                    puts("Bilinmeyen bir islem turu (HATA!)");
                    return main(0);
                    break;
            }
            break;

        default:
            puts("Bilinmeyen bir komut (HATA!)");
            return main(0);
            break;
    }
}

// Tekrar mı yoksa son mu kontrol fonksiyonu
int tekrarson(int tekrarTur)
{
    /* doğru cevap miktarının yanlış cevap miktarına bölündüğünde...
    * eğer oranı 3'e eşit ise, %75 ile sınırda olur, 3'ten küçük ise, %75'ten az olur,
    * eğer oranı 3'ten fazla ise %75'ten fazla olur.
    * Bu kod da oluşabilecek tek mantık hatası ise, doğru sayısı miktarı 3'e eşit veya az girildiğinde
    * olur. 10 olarak girildiğinde veya 3'ten büyük başka sayı girildiğinde, mantık hatası da ortadan kalkar */
    int tekrar;
    double ikili;

    yanlisSayi == 0 ? (ikili = dogruSayi) : (ikili = dogruSayi / yanlisSayi);

    if(dogruSayi == 10)
    {
        puts("!!!----------------------!!!");
        if(ikili < (double)3)
        {
            puts("Basarim oraniniz %75'ten az");
        }
        else if(ikili == (double)3)
        {
            puts("Basarim oraniniz %75 ile sinirda");
        }
        else
        {
            puts("Tebrikler, basarim oraniniz %75'ten fazla");
        }
        puts("!!!----------------------!!!");

        dogruSayi = 0;
        yanlisSayi = 0;

        return main(1);
    }
    else
    {
        do
        {
            printf("Programi sonlandirmak icin[0]\nAyni turden soru cozmek icin [1]\nFarkli turden soru icin[2]\nSecim: ");
            scanf("%d", &tekrar);
        } while (tekrar < 0 || tekrar > 2);

        return islemsec(tekrar, tekrarTur);
    }
}

// Tebrik mesajı gösterme fonksiyonu
void tebriklermesaj(int tebrikTur)
{
    switch(tebrikTur)
    {
        case 1:
            puts("Toplama bitti, isterseniz bide digerlerini deneyin :)");
            break;
        case 2:
            puts("Cikarma bitti, isterseniz bide digerlerini deneyin :)");
            break;
        case 3:
            puts("Carpma bitti, isterseniz bide digerlerini deneyin :)");
            break;
        case 4:
            puts("Bolme bitti, isterseniz bide digerlerini deneyin :)");
            break;
        default:
            puts("Sizi tebrik etcektik fakat boyle herhangi bir tebrik kodu yok malesef :(");
            break;
    }
}

// Sayı asal mı değil mi kontrol için oluşturulmuş bir fonksiyon
int asalkontrol(int asal)
{
    int dongu, durum = 0;

    if(asal % 2 == 0)
    {
        return asal;
    }
    else
    {
        for(dongu = 1; dongu <= ((asal -1) /2); dongu++)
        {
            if(((asal -1) /2) % dongu == 0)
            {
                return asal;
            }
            else
            {
                durum = 0;
            }
        }

        return durum;
    }
}

// Toplama fonksiyonu
int toplama(int topla1, int topla2)
{
    int tahmin, toplam = topla1 + topla2;

    do
    {
        printf("%d arti %d kac eder: ", topla1, topla2);
        scanf("%d", &tahmin);

        tahmin == toplam ? (dogruSayi += 1) : (yanlisSayi += 1);
        tahmin < toplam ? (puts("[Bilgi] Daha buyuk bir sayi giriniz :)")): (puts("[Bilgi] Daha kucuk bir sayi giriniz :)"));
    } while (tahmin != toplam);

    tebriklermesaj(1);
    tekrarson(1);
}

// Çıkarma fonksiyonu
int cikarma(int cikar1, int cikar2)
{
    int tahmin, cikarilmis = cikar1 - cikar2;

    do
    {
        printf("%d eksi %d kac eder: ", cikar1, cikar2);
        scanf("%d", &tahmin);

        tahmin == cikarilmis ? (dogruSayi += 1) : (yanlisSayi += 1);
        tahmin < cikarilmis ? (puts("[Bilgi] Daha buyuk bir sayi giriniz :)")): (puts("[Bilgi] Daha kucuk bir sayi giriniz :)"));
    } while (tahmin != cikarilmis);

    tebriklermesaj(2);
    tekrarson(2);
}

// Çarpma fonksiyonu
int carpma(int carp1, int carp2)
{
    int tahmin, carpim = carp1 * carp2;

    do
    {
        printf("%d carpi %d kac eder: ", carp1, carp2);
        scanf("%d", &tahmin);

        tahmin == carpim ? (dogruSayi += 1) : (yanlisSayi += 1);
        tahmin < carpim ? (puts("[Bilgi] Daha buyuk bir sayi giriniz :)")): (puts("[Bilgi] Daha kucuk bir sayi giriniz :)"));
    } while (tahmin != carpim);

    tebriklermesaj(3);
    tekrarson(3);
}

// Bölme fonksiyonu
int bolme(int bolum1, int bolum2)
{
    int tahmin, bolunmus = bolum1 / bolum2;

    do
    {
        printf("%d bolu %d kac eder: ", bolum1, bolum2);
        scanf("%d", &tahmin);

        tahmin == bolunmus ? (dogruSayi += 1) : (yanlisSayi += 1);
        tahmin < bolunmus ? (puts("[Bilgi] Daha buyuk bir sayi giriniz :)")): (puts("[Bilgi] Daha kucuk bir sayi giriniz :)"));
    } while (tahmin != bolunmus);

    tebriklermesaj(4);
    tekrarson(4);
}