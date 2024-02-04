// Sayaç kontrollü tekrarlama ile sınıf ortalama programı
#include <stdio.h>

int main( void )
{
    unsigned int freeval; // sonraki girilecek not sayısı
    int counter, grade, total;
    float average; // not değeri, notların toplamı, notların ortalaması

    // başlangıç değerleri atama kısımı
    total = 0;
    freeval = 1;

    printf("Kac tane ogrenci notu giriceksiniz: ");
    scanf("%d", &counter);

    // ogrenci sayisi kontrolu
    if(counter < 1)
    {
        printf("Ogrenci sayisi 0'a esit veya kucuk olamaz! (HATA)\n");
    }
    else if(counter > 0)
    {
        // işlem kısımı
        while(freeval <= counter)
        {
            printf("%d)Notu giriniz: ", freeval);
            scanf("%d", &grade);
            
            // not doğru yanlış kontrolü
            while(grade < 0)
            {
                printf("UYARI: Lutfen eksili deger girmeyiniz.\n%d)Notu giriniz: ", freeval);
                scanf("%d", &grade);

                // not kontrol bir daha
                if(grade >= 0)
                {
                   grade = grade;
                }
                else if(grade < 0)
                {
                    printf("Yine eksili deger girdiniz (UYARI)\n");
                }
                else
                {
                    printf("Not kontrol dongusunde bilinmeyen bir hata olustu! (HATA)\n");
                }
            } // kontrol while sonu

            // not hesaplama
            total += grade;
            freeval++;
        } // while sonu

        // sonlandırma kısmı
        average = (float)total / counter;

        printf("Sinif toplam notu = %d\n", total);
        printf("Sinif ortalama notu = %.2f\n", average);
    }
} // main fonksiyonu sonu
