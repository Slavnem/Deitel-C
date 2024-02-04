// sizeof oepratorunu bir dizi aidna uygulamak
// dizideki bayt sayisini dondurur
#include <stdio.h>
#define SIZE 20

// ++getSize
size_t getSize (float *ptr); // prototip

// +main
int main(void)
{
    float array[SIZE]; // dizi olustur

    printf("Dizinin bayt boyutu: %lu\n"
    "getSize ile dondurulmus numaranin bayt boyutu: %lu\n",
    sizeof(array), getSize(array));

    // getSize(array) demek ile getSize(&array[0]) demek ayni sey
}
// -main

// ptr'nin boyutunu dondur

// +getSize
size_t getSize (float *ptr)
{
    return sizeof(*ptr);
}
// -getSize