// Slavnem @2024-05-09
// Kredi Sorgulama Programı

// Kütüphaneler
#include <stdio.h>

// Yapı
typedef struct
{
    unsigned int account; // hesap numarası
    char name[30]; // hesap ismi
    double balance; // hesap bakiyesi
} KrediHesap;

// main
int main(void)
{
    FILE* cfPtr; // clients.dat dosyası işaretçisi

    if((cfPtr = fopen("clients.dat", "r")) == NULL)
    {
        puts("Dosya Acilamadi");
        return 0; // programı sonlandır
    }

    // kredihesap yapısını kullanarak yapı oluştur
    KrediHesap krediHesap;

    unsigned int request; // istek numarası

    // rapor seçenekleri
    printf("%s", "Istek numarasi giriniz: \n"
        "1 - Hesap bakiyesi 0 olanlari listele\n"
        "2 - Kredi bakiyeli olanları listele\n"
        "3 - Para çekme bakiyeli olanları listele\n"
        "4 - Calistir ya da Sonlandir? ");
    scanf("%u", &request);

    // kullanıcının seçimlerini değerlendirme
    while(request != 4)
    {
        // dosyadan hesap, isim, bakiye okuma
        fscanf(cfPtr, "%d%29s%lf", &krediHesap.account, krediHesap.name, &krediHesap.balance);

        switch(request)
        {
            case 1:
                puts("\n0 bakiyeli hesaplar:");

                // dosya içeriğini okuma
                while(!feof(cfPtr))
                {
                    if(krediHesap.balance == 0)
                        printf("%-10d%-13s%7.2f\n", krediHesap.account, krediHesap.name, krediHesap.balance);
                
                    // dosyadan hesap isim bakiye okuma
                    fscanf(cfPtr, "%d%29s%lf", &krediHesap.account, krediHesap.name, &krediHesap.balance);
                }
                break;
            case 2:
                puts("\nKredi bakiyeli hesaplar:");

                // sonlanana kadar dosya içeriğini okuma
                while(!feof(cfPtr))
                {
                    if(krediHesap.balance < 0)
                        printf("%-10d%-13s%7.2f\n", krediHesap.account, krediHesap.name, krediHesap.balance);
                
                    // dosyadan hesap isim bakiye okuma
                    fscanf(cfPtr, "%d%29s%lf", &krediHesap.account, krediHesap.name, &krediHesap.balance);
                }
                break;
             case 3:
                puts("\nPara cekme bakiyeli hesaplar:");

                // sonlanana kadar dosya içeriğini okuma
                while(!feof(cfPtr))
                {
                    if(krediHesap.balance > 0)
                        printf("%-10d%-13s%7.2f\n", krediHesap.account, krediHesap.name, krediHesap.balance);
                
                    // dosyadan hesap isim bakiye okuma
                    fscanf(cfPtr, "%d%29s%lf", &krediHesap.account, krediHesap.name, &krediHesap.balance);
                }
                break;
        }

        rewind(cfPtr); // cfPtr'nin dosyadan başladığı yere dönüş

        printf("%s", "\n? ");
        scanf("%d", &request);
    }

    puts("Calisma sonu.");
    fclose(cfPtr); // fclose ile dosyayı kapatma
}