// Slavnem @2024-05-08
// Sıralı Erişim Dosya Okuma ve Çıktı

// Kütüphaneler
#include <stdio.h>

// Yapı
typedef struct
{
    unsigned int hesap; // hesap numarası
    char ad[30]; // hesap adı
    double balance; // hesap bakiyesi
} Hesap;

// main
int main(void)
{
    FILE* cfPtr; // cfPtr = clients.dat dosya işaretçisi

    // fopen dosyayı açar, dosya açılamıyorsa programı oluşturur
    if((cfPtr = fopen("clients.dat", "r")) == NULL)
    {
        puts("Dosya Acilamiyor");
        return 0;
    }

    Hesap bankaHesap; // banka hesabı

    // dosyadan hesab, isim, bakiye okur
    printf("%-10s%-13s%-15s\n", "Hesap", "Isim", "Bakiye");
    fscanf(cfPtr, "%d%29s%lf", &bankaHesap.hesap, bankaHesap.ad, &bankaHesap.balance);

    // dosyanın sonunda değilken
    while(!feof(cfPtr))
    {
        // veriyi oluşturduğumuz yapıya başlangıçta aktarmıştık
        // dosya sonu gelmediği için veriyi çıktı veriyoruz
        // sıradaki veriyi alıyoruz, dosya sonu değilse eğer
        // bu döngü devam eder dosya sonu gelene kadar
        printf("%-10d%-13s%7.2f\n", bankaHesap.hesap, bankaHesap.ad, bankaHesap.balance);
        fscanf(cfPtr, "%d%29s%lf", &bankaHesap.hesap, bankaHesap.ad, &bankaHesap.balance);
    }

    fclose(cfPtr); // dosya kapatma
}