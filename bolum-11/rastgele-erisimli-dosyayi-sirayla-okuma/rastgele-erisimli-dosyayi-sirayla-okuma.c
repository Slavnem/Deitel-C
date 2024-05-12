// Slavnem @2024-05-13
// Rastgele Erişimli Dosyayı Sırayla Okuma

// Kütüphaneler
#include <stdio.h>

// müşteriVeri yapısı tanımı
typedef struct
{
    unsigned int acctNum; // hesap numarası
    char lastName[15]; // hesap sahibi soyadı
    char firstName[15]; // hesap sahibi adı
    double balance; // hesap bakiyesi
} clientData;

// main
int main(void)
{
    FILE* cfPtr; // credit.dat dosya işaretçisi
    int result; // fread hiç bayt okuyup okumadığını test eder

    // varsayılan bilgiye göre clientData oluşturulur
    clientData client = {0,"","",0.0};

    // fopen dosyayı açar, dosya açılmıyorsa çıkış yapar
    if((cfPtr = fopen("credit.dat", "rb")) == NULL)
    {
        puts("Dosya Acilamiyor");
        return 0;
    }

    printf("%-6s%-16s%-16s%10s\n",
        "Nu", "Soyad", "Ad", "Bakiye");

    // dosyadan tüm kayıtları eof'a kadar okur
    while(!feof(cfPtr))
    {
        result = fread(&client, sizeof(clientData), 1, cfPtr);

        // geçersiz kayıt
        if(result == 0 || client.acctNum < 1) {
            continue; // sonraki tura geç
        }

        // kaydı görüntüler
        printf("%-6d%-16s%-16s%10.2f\n",
            client.acctNum, client.lastName,
            client.firstName, client.balance);
    }

    // dosyayı kapat
    fclose(cfPtr);
}