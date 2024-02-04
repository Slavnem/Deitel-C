// Çok boyutlu dizilerin tanımlanması
#include <stdio.h>

void printArray(int[][3]); // fonksiyon tanımlaması

// main fonksiyonu başlangıcı
int main(void)
{
    // array1, array2 ve array3 dizilerine başalngıç değeri atanması
    int array1[2][3] = {{1,2,3}, {4,5,6}};
    int array2[2][3] = {1,2,3,4,5};
    int array3[2][3] = {{1,2}, {4}};

    puts("array1 de yer alan degerin satirla gosterilmesi:");
    printArray(array1);

    puts("array2 de yer alan degerin satirla gosterilmesi:");
    printArray(array2);

    puts("array3 de yer alan degerin satirla gosterilmesi:");
    printArray(array3);
} // main fonksiyonu sonu

// 2 satır ve 3 sütun halinde dizinin ekrana yazdırılması
void printArray(int a[][3])
{ // printArray fonksiyonu başlangıcı
    size_t i; // satır sayacı
    size_t j; // sütun sayacı

    // satırda dolaşan döngü
    for(i = 0; i <= 1; i++)
    {
        // sütun değerlerinin yazdırılması
        for(j = 0; j <= 2; j++)
        {
            /* Kitapda olmayan açıklama: a nın 1. dizisinin i indisinin,
            2.dizisindeki j indisini yaz diyoruz */
            printf("%d ", a[i][j]);
        } // iç döngü sonu

        printf("\n"); // yeni satır yazdırılması
    } // dış döngü sonu
} // printArray fonksiyonu sonu