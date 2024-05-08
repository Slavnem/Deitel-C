// Slavnem @2024-05-08
// Sıralı Erişim Dosyası Oluşturma

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
    FILE *cfPtr; // cfPtr = clients.dat dosyası dosya işaretçisi

    // fopen dosyayı açar. Program dosyasını oluşturamıyorsa
    if((cfPtr = fopen("clients.dat", "w")) == NULL) {
        puts("Dosya Acilamadi");
        return 0; // programı sonlandır
    }

    Hesap bankaHesap; // banka hesabı

    // Kullanıcıdan bilgileri istemek
    puts("Hesap, ad ve bakiye giriniz.");
    puts("Giris islemini sonlandirmak icin EOF giriniz.");

    printf("%s", "? ");
    scanf("%d%29s%lf", &bankaHesap.hesap, bankaHesap.ad, &bankaHesap.balance);

    // fprintf ile dosya içine hesap, isim ve bakiye değerini yazmak
    while(!feof(stdin))
    {
        fprintf(cfPtr, "%d %s %.2f\n", bankaHesap.hesap, bankaHesap.ad, bankaHesap.balance);
        printf("%s", "? ");
        scanf("%d%29s%lf", &bankaHesap.hesap, bankaHesap.ad, &bankaHesap.balance);
    }

    fclose(cfPtr); // fclose dosyayı kapatır
}