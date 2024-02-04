#include <stdio.h>

int main( void )
{
    unsigned int counter = 0; // girilecek not sayısı
    int grade, total = 0; // not değeri ve kullanıcı tarafından girilen değerlerin toplamı
    float average; // ortalama için ondalık sayı

    // işlem kısmı
    printf("-1 Yazarak sonlandirablirsiniz. Deger giriniz: "); // kullanıcıya çıktı verip değer isteme
    scanf("%d", &grade); // kullanıcının girdiği notu oku

    while(grade != -1)
    {
        total += grade; // notu toplama ekle
        counter++; // sayacı 1 arttır

        printf("-1 yazarak sonlandirabilirsiniz, Notu giriniz: "); // kullanıcıya çıktı verip değer isteme
        scanf("%d", &grade); // değeri okuma
    } // while sonu

    // sonlandırma kısmı
    if(counter != 0)
    {
        // girilen tüm notlar için ortalamayı hesapla
        average = (float)total / counter; // ondalık kısımı da dahil etmek için float
        
        // ortalamayı virgülden sonra iki basamaklı göster
        printf("Not ortalamasi = %.2f\n", average);
    } // if sonu
    else
    {
        puts("Herhangi bir deger girilmedi");
    }  // else sonu
} // main fonksiyonu sonu
