// Slavnem
// Telefon Numarası

// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ön işlemci tanımlaması
#define SIZE_TEL 12

// main
int main(void)
{
    char telno[SIZE_TEL]; // telefon numarasını tutacak
    char* ptr; // ayrılan kelimeyi geçici olarak tutacak
    size_t size_telno = (sizeof(telno) / sizeof(telno[0])); // dizinin uzunluğunu tutacak
    int alankodu; // alan kodunu saklayacağımız değişken
    long numara; // alan kodundan sonraki kısımı saklama

    /*
        AÇIKLAMA: strlen kullanmamamızın nedeni,
        dizinin içi boş olduğu için direk boyutunu
        0 olarak görecek ve bu istemediğimiz bir durum
        bu yüzden sizeof ile dizinin kapladığı tüm boyutu
        dizinin ilk elemanına bölüp toplam
        indis miktarını hesaplamış oluyoruz
    */

    // kullanıcıya çıktı vermek

    do
    {
        puts("Telefon numarası giriniz (xxx xxxxxxx): ");
        fgets(telno, size_telno, stdin);
    } while(strlen(telno) < (size_telno - 1));

    // satır sonu karakterlerini silme
    telno[strcspn(telno, "\n")] = '\0';

    // kelimeyi ayırma
    ptr = strtok(telno, " ");

    // alan kodunu alacağız fakat metinin olup olmadığını
    // kontrol etmeliyiz, metin yoksa 0, varsa eğer
    // metini long türüne ordan da int olarak çevirim yapacağız
    // ve 1000 ile bölüp kalanını alacağız çünkü
    // kalan kısım 3 basamaklı alan kodu olucaktır

    // alan kodunu alma
    if(ptr != NULL)
    {
        alankodu = (int)(strtol(ptr, NULL, 0) % 1000); // tamsayı olarak alıyoruz
    }

    // alan kodundan sonrası varsa numara olarak alma
    if((ptr = strtok(NULL, " ")) != NULL)
    {
        // % 10000000, yapmamızın nedeni
        // alan kodundan sonraki kısım 7 basamaklı olmalı
        // bu yüzden bölümden kalanı alıyoruz
        numara = strtol(ptr, NULL, 0) % 10000000;
    }

    // numaranın tamamını çıktı vermek
    printf("%s%d%lu\n", "Numaranin tamami: ", alankodu, numara);
}