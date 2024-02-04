// C99 da değişken uzunluklu dizilerin kullanılması
#include <stdio.h>

// fonksiyon tanımlamaları
void print1DArray(int size, int arr[size]);
void print2DArray(int row, int col, int arr[row][col]);

int main(void)
{
    int arraySize; // 1 boyutlu dizinin uzunluğu
    int row1, col1, row2, col2; // 2 boyutlu dizinin satır ve sütun sayıları

    do
    {
        printf("%s", "Tek boyutlu bir dizi uzunlugu giriniz: ");
        scanf("%d", &arraySize);
    } while (arraySize < 1);

    do
    {
        printf("Iki boyutlu bir dizi icin satir ve sutun sayisi giriniz: ");
        scanf("%d %d", &row1, &col1);
    } while (row1 < 1 || col1 < 1);

    do
    {
        printf("%s", "Iki boyutlu baska bir dizi icin satir ve sutun sayisi giriniz: ");
        scanf("%d %d", &row2, &col2);
    } while(row2 < 1 || col2 < 1);

    int array[arraySize]; // tek boyutlu değişken uzunluklu dizi tanımlaması
    int array2D1[row1][col1]; // iki boyutlu değişken uzunluklu dizi tanımlaması
    int array2D2[row2][col2]; // iki boyutlu değişken uzunluklu dizi tanımlaması

    // değişken uzunluklu dizilerde sizeof operatörünün test edilmesi
    printf("\nsizeof ile dizi uzunlugu %d byte'tir\n", sizeof(array));

    // tek boyutlu diziye eleman atanması
    for(int i = 0; i < arraySize; ++i)
    {
        array[i] = i * i;
    } // döngü sonu

    // 2 boyutlu diziye eleman atanması
    for(int i = 0; i < row1; ++i)
    {
        for(int j = 0; j < col1; ++j)
        {
            array2D1[i][j] = i + j;
        } // döngü sonu
    } // döngü sonu

    // ikinci 2 boyutlu diziye eleman atanması
    for(int i = 0; i < row2; ++i)
    {
        for(int j = 0; j < col2; ++j)
        {
            array2D2[i][j] = i + j;
        } // döngü sonu
    } // döngü sonu

    puts("\nTek boyutlu dizi:");
    print1DArray(arraySize, array); // tek boyutlu değişken uzunluk dizinin geçirilmesi

    puts("\nIlk 2 boyutlu dizi:");
    print2DArray(row1, col1, array2D1); // fonksiyona ilk 2 boyutlu dizinin geçirilmesi

    puts("\nIkinci 2 boyutlu dizi:");
    print2DArray(row2, col2, array2D2); // fonksiyona ikinci 2 boyutlu dizinin geçirilmesi
} // main sonu

void print1DArray(int size, int array[size])
{
    // dizi içeriğinin yazdırılması
    for(int i = 0; i < size; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    } // döngü sonu
} // print1DArray fonksiyonu sonu

void print2DArray(int row, int col, int arr[row][col])
{
    // dizi içeriğinin yazdırılması
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            printf("%5d", arr[i][j]);
        } // döngü sonu

        puts("");
    } // döngü sonu
} // print2DArray fonksiyonu sonu