// Slavnem @2024-06-27
// Sinyal İşlemek

// Kütüphaneler
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon prototipi
void signalHandler(int signalValue);

// main
int main(void)
{
    int i; // 100 defa işleyecek döngü için oluşturulan sayaç
    int x; // 1-50 arasındaki rastgele değerleri tutacak değişken

    signal(SIGINT, signalHandler); // sinyal yakalayıcıyı kaydet
    srand(time(NULL));

    // 1 den 100 e çıkış sayıları
    for(i = 1; i <= 100; ++i)
    {
        x = 1 + rand() % 50; // SIGINT sinyali oluşturmak için rastgele sayılar üret

        // x değeri 25 olduğunda SIGINT sinyal oluştur
        if(x == 25)
            raise(SIGINT);

        printf("%-4d", i);

        // i değeri 10 un katı olduğu durumda alt satıra geç
        if(i % 10 == 0)
            printf("%s", "\n");
    }
}

// signalHandler
void signalHandler(int signalValue)
{
    int response; // kullanıcının sinyale yanıtı (1 veya 2)

    printf("%s%d%s\n%s",
        "\nKesinti sinyali ( ", signalValue ," ) alindi.",
        "Devam etmek ister misiniz (1 = evet ya da 2 = hayir)? ");

    scanf("%d", &response);

    // geçersiz cevap durumunu kontrol et
    while(response != 1 && response != 2)
    {
        printf("%s", "(1 = evet ya da 2 = hayir)? ");
        scanf("%d", &response);
    }

    // çıkma zamanı geldi mi belirle
    if(response == 1) // bir sonraki SIGINT için sinyal yakalayıcı kaydet
        signal(SIGINT, signalHandler);
    else
        exit(EXIT_SUCCESS);
}