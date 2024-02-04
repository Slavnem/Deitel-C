// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <string.h>

// main
int main(void)
{
    // diziye başlangıç değeri atanması
    char string[] = "This is a sentence with 7 tokens";
    char* tokenPtr; // gösterge oluşturulması

    printf("%s\n%s\n\n%s\n",
        "The string to be tokenized is: ", string,
        "The tokens are: ");

    tokenPtr = strtok(string, " "); // cümleyi parçalara ayırmaya başlaması

    /*
        AÇIKLAMA: Belirlenen metini kelimelere ayırmak
        için belirli bir karakter girmek ve o karakteri
        her gördüğünde kelime olarak ayırması.
        İlk olarak metinin (string) ilk kelimesini ayırıp almak
        sonrasında döngü ile metinin adresini tutan değişkeni
        kelimeleri ayırıp almasını sağlayıp çıktı vermek
    */

    // tokenPtr NULL olana kadar cümleyi ayırmaya devam edilmesi
    while(tokenPtr != NULL)
    {
        printf("%s\n", tokenPtr);
        tokenPtr = strtok(NULL, " "); // bir sonraki parçanın alınması
    }
}