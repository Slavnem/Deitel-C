// Slavnem @2024-02-26
// Karakter Göz Ardı

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    int month1;
    int day1;
    int year1;
    int month2;
    int day2;
    int year2;

    printf("%s", "mm-dd-yyyy seklinde tarih giriniz: ");
    scanf("%d%*c%d%*c%d", &month1, &day1, &year1);

    printf("ay = %d gun = %d yil = %d\n\n", month1, day1, year1);

    printf("%s", "mm/dd/yyyy seklinde tarih giriniz: ");
    scanf("%d%*c%d%*c%d", &month2, &day2, &year2);

    printf("ay = %d gun = %d yil = %d\n", month2, day2, year2);
}