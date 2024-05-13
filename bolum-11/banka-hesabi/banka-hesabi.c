// Slavnem @2024-05-13
// Banka Hesabı İşleme

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>

// Ön Tanımlamalar
#define ACCTNUM_MIN 1
#define ACCTNUM_MAX 100

// clientData yapısı tanımlanır
typedef struct
{
    unsigned int acctNum; // hesap numarası
    char lastName[15]; // hesap sahibi soyadı
    char firstName[15]; // hesap sahibi adı
    double balance; // bakiye
} clientData;

// Numaralandırma
enum RECORDS
{
    ECOPY = 1, // kayıtları başka yere kopyalamak için
    EUPDATE, // kayıtı güncellemek için
    ENEW, // yeni kayıt oluşturmak için
    EDELETE // kayıtı silmek için
};

// Dosya isimi
const char* const globFileNamePtr = "credit.dat";

// Fonksiyon tanımlamaları
unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

// main
int main(void)
{
    FILE* cfPtr; // credit.dat dosya işaretçisi
    unsigned int choice; // kullanıcı seçimi

    // fopen dosyayı açar, eğer açılmıyorsa null döndürür
    if((cfPtr = fopen(globFileNamePtr, "rb+")) == NULL)
    {
        puts("Dosya Acilamiyor");
        return 0;
    }

    // eylemi belirtmek için kullanıcıya olanak sağlama
    while((choice = enterChoice()) != 5)
    {
        switch(choice)
        {
            // kayıt dosyasından metin dosyayı oluştur
            case ECOPY:
                textFile(cfPtr);
                break;
            // kayıt güncelle
            case EUPDATE:
                updateRecord(cfPtr);
                break;
            // kayıt oluştur
            case ENEW:
                newRecord(cfPtr);
                break;
            // varolan kayıtı sil
            case EDELETE:
                deleteRecord(cfPtr);
                break;
            // kullanıcı geçerli bir seçim yapmadıysa görüntüler
            default:
                puts("Yanlis Secim!");
                break;
        }
    }

    // fclose ile dosyayı kapatma
    fclose(cfPtr);
}

// çıktı almak için biçimlendirilmiş metin oluşturur
void textFile(FILE *readPtr)
{
    const char* const privFileNamePtr = "accounts.txt"; // dosya isimi
    FILE *writePtr; // accounts.txt dosya işaretçisi
    int result; // fread herhangi bir bayt okumuşmu test eder

    // varsayılan bilgiyle clientData oluşturur
    clientData client = {0,"","",0.0};

    // fopen dosyayı açar, eğer yoksa çıkış yapar
    if((writePtr = fopen(privFileNamePtr, "w")) == NULL)
    {
        puts("Dosya Acilamiyor");
        return;
    }

    rewind(readPtr); // işaretçiyi dosyanın başlangıcına ayarlar
    fprintf(writePtr, "%-7s%-16s%-16s%10s\n",
        "Numara", "Soyad", "Ad", "Bakiye");

    // rastgele erişimli dosyadan metin dosyasına tüm kayıtları kopyalar
    while(!feof(readPtr))
    {
        // kayıtı fread ile okumak
        result = fread(&client, sizeof(clientData), 1, readPtr);

        // eğer geçerli kayıt yoksa sonraki tura geçsin
        if(result == 0 || client.acctNum < 1) {
            continue;
        }

        // metin dosyasına tek kayıt yazar
        fprintf(writePtr, "%-7d%-16s%-16s%10.2f\n",
            client.acctNum, client.lastName,
            client.firstName, client.balance);
    }

    // fclose ile dosyayı kapatıyoruz
    fclose(writePtr);
}

// kayıtta dengei günceller
void updateRecord(FILE *fPtr)
{
    unsigned int accountNu = 0; // hesap numarası
    double money; // işlem tutarı
    char buffer[3]; // geçici depolayıcı

    // kayıt için boş müşteri oluşturma
    clientData client = {0,"","",0.0};

    // güncellenecek hesap numarasını ister
    while(accountNu < ACCTNUM_MIN || accountNu > ACCTNUM_MAX)
    {
        printf("Guncellemek icin hesap numarasi giriniz: (%d-%d): ", (ACCTNUM_MIN), (ACCTNUM_MAX));
        scanf("%3s", buffer);

        // girilen metini sayıya çevir
        accountNu = (unsigned int)strtoul(buffer, NULL, 0);
    }

    // dosya işaretçisini dosyadaki doğru kayıta iletir
    fseek(fPtr, ((accountNu - 1) * (sizeof(clientData))), SEEK_SET);

    // dosyadan kayıt okur
    fread(&client, sizeof(clientData), 1, fPtr);

    // eğer hesap mevcut değilse hata görüntüler
    if(client.acctNum < 1)
    {
        printf("Hesap %d bilgi icermiyor!\n", accountNu);
        return;
    }

    // kayıt güncelle
    printf("%-7d%-16s%-16s%10.2f\n\n",
        client.acctNum, client.lastName,
        client.firstName, client.balance);

    // kullanıcıdan işlem tutarını ister
    printf("%s", "Islem ucretini (+) ya da odemeyi giriniz (-): ");
    scanf("%lf", &money);

    client.balance += money; // bakiyeyi günceller

    printf("%-7d%-16s%-16s%10.2f\n",
        client.acctNum, client.lastName,
        client.firstName, client.balance);

    // dosya işaretçisini dosyadkai doğru kayıda iletir
    fseek(fPtr, ((client.acctNum - 1) * sizeof(clientData)), SEEK_SET);

    // dosyadaki eski kayıdın üzerine güncellenmiş kayıtı yazar
    fwrite(&client, sizeof(clientData), 1, fPtr);
}

// varolan bir kayıtı siler
void deleteRecord(FILE *fPtr)
{
    clientData client; // dosyadan okunan kayıtları tutar
    clientData freeClient = {0,"","",0.0}; // boş kayıt

    unsigned int accountNu = 0; // hesap numarası
    char buffer[3]; // geçici depolayıcı

    // silinecek hesabın numarasını elde eder
    while(accountNu < ACCTNUM_MIN || accountNu > ACCTNUM_MAX)
    {
        printf("Silinecek hesabin numarasini giriniz (%d-%d): ", (ACCTNUM_MIN), (ACCTNUM_MAX));
        scanf("%3s", buffer);

        accountNu = (unsigned int)strtoul(buffer, NULL, 0);
    }

    // dosya işaretçisini dosyadaki doğru kayıda iletir
    fseek(fPtr, ((accountNu - 1) * sizeof(clientData)), SEEK_SET);

    // dosyadan kayıt okur
    fread(&client, sizeof(clientData), 1, fPtr);

    // eğer kayıt mevcut değilse hata görüntüler
    if(client.acctNum < 1)
    {
        printf("Hesap %d mevcut degil!\n", accountNu);
        return;
    }

    // dosya işaretçisi dosyadaki doğru kayıta iletir
    fseek(fPtr, ((accountNu - 1) * sizeof(clientData)), SEEK_SET);

    // varolan kayıtı boş kayıtla değiştirir
    fwrite(&freeClient, sizeof(clientData), 1, fPtr);
}

// yeni kayıt olusturur ve ekler
void newRecord(FILE *fPtr)
{
    // varolan bilgiyle clientData oluşturur
    clientData client = {0,"","",0.0};

    unsigned int accountNu = 0; // hesap numarası
    char buffer[3]; // geçici depolayıcı

    // oluşturulacak hesabın numarasını elde eder
    while(accountNu < ACCTNUM_MIN || accountNu > ACCTNUM_MAX)
    {
        printf("Yeni hesap numarasi giriniz (%d-%d): ", (ACCTNUM_MIN), (ACCTNUM_MAX));
        scanf("%3s", buffer);

        accountNu = (unsigned int)strtoul(buffer, NULL, 0);
    }

    // dosya işaretçisini dosyadaki doğru kayıta iletir
    fseek(fPtr, ((accountNu - 1) * sizeof(clientData)), SEEK_SET);

    // dosyadan kayıtı okur
    fread(&client, sizeof(clientData), 1, fPtr);

    // eğer hesap zaten mevcutsa hata görüntüler
    if(client.acctNum > 0)
    {
        printf("Hesap %d Zaten Bilgi Iceriyor!", accountNu);
        return;
    }

    // kullanıcı soyadı, adı ve bakiyeyi girer
    printf("%s", "Soyad, ad ve bakiyeyi giriniz: ");
    scanf("%14s%14s%lf",
        client.lastName, client.firstName, &client.balance);

    client.acctNum = accountNu;

    // dosya işaretçisini dosyadaki doğru kayıta iletir
    fseek(fPtr, ((client.acctNum - 1) * sizeof(clientData)), SEEK_SET);

    // dosyaya kayıtı ekler
    fwrite(&client, sizeof(clientData), 1, fPtr);
}

// kullanıcıya seçme menüsü sunar
unsigned int enterChoice(void)
{
    // kullanıcının seçimini saklamak için olan değişken
    unsigned int menuChoice;

    printf("%s", "\nSecim giriniz\n"
        "1 - Depolanmis hesap verilerini \"accounts.txt\" dosyasına kopyala\n"
        "2 - Hesap verisini guncelle\n"
        "3 - Yeni hesap olustur\n"
        "4 - Hesabi sil\n"
        "5 - Sonlandir\n?: ");

    scanf("%d", &menuChoice); // seçeneği kullanıcıdan al
    return menuChoice;
}