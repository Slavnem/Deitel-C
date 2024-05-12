// Slavnem @2024-05-12
// Rastgele Erişim Dosyasına Rastgele Veri Yazma

// Kütüphaneler
#include <stdio.h>

// clientData yapısı tanımı
typedef struct
{
    unsigned int acctNum; // hesap numarası
    char lastName[15]; // hesap sahibi soyadı
    char firstName[15]; // hesap sahibi adı
    double balance; // bakiye
} clientData;

// main
int main(void)
{
    FILE* cfPtr; // credit.dat dosya işaretçisi
    clientData client = {0,"","",0.0}; // varsayılan bilgilerle clientData oluşturmak

    if((cfPtr = fopen("credit.dat", "rb+")) == NULL)
    {
        puts("Dosya Acilamadi");
        return 0;
    }

    // hesap numarası kullanıcıdan istenecek
    printf("%s", "Hesap numarasi giriniz: "
        "(1'den 100'e kadar, sonlandirmak icin 0 giriniz)\n?: ");
    scanf("%d", &client.acctNum);

    // kullanıcı dosya içine yazılan bilgileri girer
    while(client.acctNum != 0)
    {
        // kullanıcı dosya içine kopyalanan son isimi girer
        printf("%s", "Ad, soyad ve bakiye giriniz\n?: ");

        // soyad, ilk isim ve bakiye değerlerini dosyadan okur
        fscanf(stdin, "%14s%14s%lf",
            client.lastName, client.firstName, &client.balance);

        // kullanıcı tarafından belirtilen kayda konumlanır
        fseek(cfPtr, ((client.acctNum -1 ) * sizeof(clientData)), SEEK_SET);

        // dosyaya hesap ve hesap sahibinin bilgilerini yazar
        fwrite(&client, sizeof(clientData), 1, cfPtr);

        // başka bir kayıt icin hesap no ister
        printf("%s", "Hesap numarasi giriniz\n?: ");
        scanf("%d", &client.acctNum);
    }

    // dosyayı kapatmak
    fclose(cfPtr);
}