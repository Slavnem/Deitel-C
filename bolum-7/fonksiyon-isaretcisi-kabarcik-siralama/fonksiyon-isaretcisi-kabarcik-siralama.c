// Fonksiyon isaretcileri kullanarak cok amacli siralama programi
#include <stdio.h>
#define SIZE 10

// prototipler
void bubble(int work[], size_t size, int(*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(void)
{
    int order; // artan siralama icin 1 veya azalan siralama icin 2
    size_t counter; // sayac

    // siralanmamis a dizini yukle
    int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};

    printf("%s", "Kucukten buyuge icin 1 giriniz\n"
    "Buyukten kucuge icin 2 giriniz: ");
    scanf("%d", &order);

    puts("\nOrjinal dizi icerigi");

    // orjinal diziyi goster
    for(counter = 0; counter < SIZE; ++counter)
    {
        printf("%5d", a[counter]);
    } // for blogu sonu

    // diziyi artan sekilde sirala, artan siralama talebini
    // belirtmek icin arguman olarak ascending fonksiyonunu aktar
    if(order == 1)
    {
        bubble(a, SIZE, ascending);
        puts("\nKucukten buyuge siralanmis dizi");
    } // if blogu sonu
    else
    {
        // descending fonksiyonuna aktar
        bubble(a, SIZE, descending);
        puts("\nBuyukten kucuge siralanmis dizi");
    } // else blogu sonu

    // sirali diziyi goster
    for(counter = 0; counter < SIZE; ++counter)
    {
        printf("%5d", a[counter]);
    } // for blogu sonu

    puts("\n");
} // main sonu

// cok amacli kabarcik siralama, compare parametresi siralama seklini belirleyen
// karsilastirma fonksiyonuna isaret eden bir isaretcidir
void bubble(int work[], size_t size, int(*compare)(int a, int b))
{
    unsigned int pass; // pass sayaci
    size_t count; // karsilastirma sayaci

    void swap(int *element1Ptr, int *element2Ptr); // prototip

    // pas gecisleri kontrol eden dongu
    for(pass = 1; pass < size; ++pass)
    {
        // her pas gecis icin karsilastirma numarasini kontrol eden dongu
        for(count = 0; count < size -1; ++count)
        {
            // bitisik elemanlar siraya uymuyor ise yerlerini degistir
            if((*compare)(work[count], work[count +1]))
            {
                swap(&work[count], &work[count +1]);
            } // if blogu sonu
        } // for blogu sonu
    } // for blogu sonu
} // bubble fonksiyonu sonu

// element1Ptr ve element2Ptr'nin isaret ettikleri bellek bolgelerindeki
// degerleri degistir
void swap(int *element1Ptr, int *element2Ptr)
{
    int hold; // gecici olarak saklama degiskeni

    hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // swap fonksiyonu sonu

// elemanlarin artan siralama sekline gore
// siraya uygun olup olmadiklarini belirle
int ascending(int a, int b)
{
    return b < a; // b degeri a'dan daha dusuk ise degistirilmelidir
} // ascending fonksiyonu sonu

// elemanlarin azalan siralama sekline gore
// siraya uygun olup olmadiklarini belirle
int descending(int a, int b)
{
    return b > a; // b degeri a'dan daha buyuk ise degistirilmelidir
} // descending fonksiyonu sonu