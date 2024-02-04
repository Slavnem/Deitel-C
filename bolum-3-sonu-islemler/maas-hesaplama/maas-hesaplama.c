//Gerekli başlık dosyamızı ekliyoruz
#include <stdio.h>

//int main otomatik başlar
int main( void )
{
    // Değerlerimizi tanımlıyoruz
    int saat = 0;
    float saatlikpara, maas, ekmaas;

    // Program başta -1 değeri girilene kadar çalışsın
    while(saat != -1)
    {
        // Değeri okuyoruz ve ona göre kontrol yapıyoruz
        printf("Calisilan saati girin: (bitirmek icin: -1) ");
        scanf("%d", &saat);

        // Eger en basta -1 girmiş ise
        if(saat == -1)
        {
            printf("Cikis komutu aktif edildi! Program sonlandiriliyor...\n");
            return 0;
        }

        // Eğer istediğimiz değer değilse tekrar uyarıyoruz ve tekrar uymassa programı sonlandırıyoruz
        if(saat <= 0 && saat != -1)
        {
            printf("Calisilan saati dogru giriniz, bir dahaki hata da program sonlanacaktir!: ");
            scanf("%d", &saat);

            if(saat <= 0)
            {
                printf("Fazla hatali giris! Program sonlandiriliyor...\n");
                return 0;
            }
        }

        printf("Calisanin saatlik ucretini giriniz (00.00 TL): ");
        scanf("%f", &saatlikpara);

        if(saatlikpara <= 0)
        {
             printf("Calisanin saatlik ucretini dogru giriniz, bir dahaki hata da program sonlanacaktir: ");
             scanf("%f", &saatlikpara);

             if(saatlikpara <= 0)
             {
                 printf("Fazla hatali giris! Program sonlandiriliyor...\n");
                 return 0;
             }
        }
        else if(saatlikpara > 0)
        {
            // 40 saatten fazla çalışmışsa eğer, 40 saati geçtiği tüm saatler için 1.5 katı ödenir
            // Örnek: 42 saat, 40 saat için 10tl, 40x10 = 400, 2x(10x1.5) = 30, 400 + 30 = 430
            if(saat > 40)
            {
                ekmaas = ((saat - 40) * (saatlikpara * 1.5));
                maas = ((40 * saatlikpara) + (ekmaas));
            }
            // Eğer 40 saate eşitse veya daha az ise ama 0 saatten de fazla ise ikinci yöntemi yapıyoruz
            else if(saat <= 40 && saat > 0)
            {
                maas = (saat * saatlikpara);
            }
            // Bilinmeyen bir hata oluştu ise bunu ekrana çıktı verip programı sonlandırıyoruz
            else
            {
                printf("Maas hesaplanirken bilinmeyen bir hata olustu! (HATA)\n");
                return 0;
            }
        }

        // Maas için gerekli işlemler doğru ve hazırsa ekrana maaş değerini gösteriyoruz
        if(maas != 0 && maas > 0)
        {
            // Program en son maaş çıktısı veriyoruz 
            printf("==================================\n");
            printf("Maas = %.2f\n", maas);
            printf("==================================\n");
        }
    }
}
