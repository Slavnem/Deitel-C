// İki boyutlu dizi işlemleri
#include <stdio.h>

#define STUDENTS 3
#define EXAMS 4

// fonksiyon tanımlamaları
int minimum(int grades[][EXAMS], size_t pupils, size_t tests);
int maximum(int grades[][EXAMS], size_t pupils, size_t tests);
double average(const int setOfGrades[], size_t tests);
void printArray(int grades[][EXAMS], size_t pupils, size_t tests);

int main(void)
{ // main fonksiyonu başlangıcı
    size_t _student; // öğrenci sayacı

    // 3 öğrencinin notlarına başlangıç değeri atanması(satırdaki)
    int _studentGrades[STUDENTS][EXAMS] =
    { // 3 öğrenci ve onlara ait notlar dizisi
        {77,68,86,73},
        {96,87,89,78},
        {70,90,86,81}
    };

    // studentGrades dizisinin ekrana yazdırılması
    puts("Dizi:");
    printArray(_studentGrades, STUDENTS, EXAMS);

    // en yüksek ve düşük notların tespiti
    printf("\n\nEn dusuk not: %d\nEn yuksek not: %d\n",
    minimum(_studentGrades, STUDENTS, EXAMS),
    maximum(_studentGrades, STUDENTS, EXAMS));

    // her öğrencinin not ortalamasını hesaplama
    for(_student = 0; _student < STUDENTS; ++_student)
    {
        printf("%u. ogrenciye ait not ortalamasi: %2.f\n", _student, average(_studentGrades[_student], EXAMS));
    } // döngü sonu
} // main fonksiyonu sonu

// en düşük notun tespiti
int minimum(int grades[][EXAMS], size_t pupils, size_t tests)
{
    size_t i; // öğrenci sayacı
    size_t j; // sınav sayacı

    int _lowGrade = 100; // en yüksek muhtemel notun başlangıç olarak atanması

    // satırdaki notlar arasında dolaşan döngü
    for(i = 0; i < pupils; ++i)
    {
        // sütundaki notlar arasında dolaşan döngü
        for(j = 0; j < tests; ++j)
        {
            if(grades[i][j] < _lowGrade)
            {
                _lowGrade = grades[i][j];
            } // if sonu
        } // içteki döngü sonu
    } // dıştaki döngü sonu

    return _lowGrade; // en düşük notun döndürülmesi
} // minimum fonksiyonu sonu

// en yüksek notun hesap edilmesi
int maximum(int grades[][EXAMS], size_t puppils, size_t tests)
{
    size_t j; // öğrenci sayacı
    size_t i; // sınav sayacı

    int _highGrade = 0; // en düşük muhtemel notun başlangıç değeri olarak atanması

    // satırdaki notlar arasında dolaşma
    for(i = 0; i < puppils; ++i)
    {
        for(j = 0; j < tests; ++j)
        {
            if(grades[i][j] > _highGrade)
            {
                _highGrade = grades[i][j];
            } // if sonu
        } // içteki döngü sonu
    } // dıştaki döngü sonu

    return _highGrade; // en yüksek notun döndürülmesi
} // maximum fonksiyonunun sonu

// belirli bir öğrencinin not ortalamasının hesaplanması
double average(const int setOfGrades[], size_t tests)
{
    size_t i; // sınav sayacı
    int total = 0; // sınav notlarının toplamı

    // bir öğrencinin tüm notlarının toplamı
    for(i = 0; i < tests; ++i)
    {
        total += setOfGrades[i];
    } // döngü sonu

    return (double)total / tests; // ortalama
} // average fonksiyonu sonu

// Dizinin yazdırılması
void printArray(int grades[][EXAMS], size_t pupils, size_t tests)
{
    size_t i; // öğrenci sayacı
    size_t j; // sınav sayacı

    // sütun başlıklarının yazdırılması
    printf("\t\t%s", "[0]  [1]  [2]  [3]");

    // notların çizelge biçiminde yazdırılması
    for(i = 0; i < pupils; ++i)
    {
        // satır etiketlerinin yazdırılması
        printf("\nstudentGrades[%d] ", i);

        // bir öğrencinin notlarının yazdırılması
        for(j = 0; j < tests; ++j)
        {
            printf("%-5d", grades[i][j]);
        } // içteki döngü sonu
    } // dıştaki döngü sonu
} // printArray fonksiyonu