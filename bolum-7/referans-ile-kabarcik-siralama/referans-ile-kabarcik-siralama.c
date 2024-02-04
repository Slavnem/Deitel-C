// Degerleri bir dizi icerisine almak, artan siraya gore
// siralamak ve elde edilen diziyi yazdirmak
#include <stdio.h>
#define SIZE 10

// ++bubleSort
void bubbleSort(int * const array, size_t size); // prototip

// +main
int main(void)
{
    // a dizisini kullanima hazirla
    int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};

    size_t i; // sayac

    puts("Orjinal veri icerikleri");

    // a dizisi boyunca dongu olustur
    for(i = 0; i < SIZE; i++)
    {
        printf("%4d", a[i]);
    } // for blogu sonu

    bubbleSort(a, SIZE); // diziyi sirala

    puts("\nSiralanmis veri icerikleri");

    // a dizisi boyunca dongu olustur
    for(i = 0; i < SIZE; i++)
    {
        printf("%4d", a[i]);
    } // for blogu sonu

    puts("");
}
// -main

// +bubbleSort
void bubbleSort(int * const array, size_t size)
{
    void swap(int *element1Ptr, int *element2Ptr);

    unsigned int pass; // gecis sayaci
    size_t j; // karsilastirma sayaci

    // gecisleri kontrol etme dongusu
    for(pass = 0; pass < size -1; ++pass)
    {
        // her gecis boyunca karsilastirmalari kontrol etme dongusu
        for(j = 0; j < size -1; ++j)
        {
            // siralama duzeninin disinda ise ardisik elemanlarin yerini degistir
            if(array[j] > array[j +1])
            {
                swap(&array[j], &array[j+1]);
            } // if sonu
        } // icteki for blogu sonu
    } // dis for blogu sonu
}
// -bubbleSort

// element1Ptr ve element2Ptr'nin isaret ettikleri
// bellek lokasyonlarindaki degerleri degistir

// +swap
void swap(int *element1Ptr, int *element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}
// -swap