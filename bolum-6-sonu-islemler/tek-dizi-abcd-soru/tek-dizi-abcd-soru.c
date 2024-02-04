// A, B, C ve D sorularını yanıtlama
// A: 10 elemanlı counts tamsayı dizisinin elemanlarına başlangıç değeri olarak 0 atayan ifade
// B: 15 elemanlı tamsayı bonus dizisinin her elemanına 1 ekleyen ifade
// C: ondalıklı monthlyTemperatures dizisine 12 adet klavyeden değer okuyan ifade
// D: tamsayı bestScores dizisinin 5 elemanının değerini sütun şeklinde ekrana yazdıran ifade

#include <stdio.h>

#define COUNTS_DEGER 10
#define BONUS_DEGER 15
#define TEMPERATURES_DEGER 12
#define BEST_DEGER 5

void counts(void);
void bonus(void);
void monthlyTemperatures(void);
void bestScores(void);

// main fonksiyonu başlangıcı
int main(void)
{
    counts();
    bonus();
    monthlyTemperatures();
    bestScores();
} // main fonksiyonu sonu

// counts fonksiyonu başlangıcı
void counts(void)
{
    unsigned short countsDizi[COUNTS_DEGER];
    size_t _counts_sayac;

    for(_counts_sayac = 0; _counts_sayac < COUNTS_DEGER; _counts_sayac++)
    {
        countsDizi[_counts_sayac] = 0;
        printf("%d) %d\n", _counts_sayac+1, countsDizi[_counts_sayac]);
    }

    puts("---------------counts sonu---------------");
} // counts fonksiyonu sonu

// bonus fonksiyonu başlangıcı
void bonus(void)
{
    unsigned short bonusDizi[BONUS_DEGER] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
    size_t _bonus_sayac;

    for(_bonus_sayac = 0; _bonus_sayac < BONUS_DEGER; _bonus_sayac++)
    {
        bonusDizi[_bonus_sayac] += 1;
        printf("%d) %d\n", _bonus_sayac+1, bonusDizi[_bonus_sayac]);
    }

    puts("---------------bonus sonu---------------");
} // bonus fonksiyonu sonu

// monthlyTemperatures fonksiyonu başlangıçı
void monthlyTemperatures(void)
{
    size_t _temperatures_sayac;
    double temperaturesDizi[TEMPERATURES_DEGER];
    double _temperatures_deger;

    for(_temperatures_sayac = 0; _temperatures_sayac < TEMPERATURES_DEGER; _temperatures_sayac++)
    {
        do
        {
            printf("%d) ondalikli sayi giriniz: ", _temperatures_sayac+1);
            scanf("%lf", &_temperatures_deger);
        } while (_temperatures_deger < 0.1);
        
        temperaturesDizi[_temperatures_sayac] = _temperatures_deger;
    }

    for(_temperatures_sayac = 0; _temperatures_sayac < TEMPERATURES_DEGER; _temperatures_sayac++)
    {        
        printf("%d) %.2lf\n", _temperatures_sayac+1, temperaturesDizi[_temperatures_sayac]);
    }

    puts("--------monthlyTemperatures sonu--------");
} // monthlyTemperatures fonksiyonu sonu 

// bestScores fonksiyonu başlangıcı
void bestScores(void)
{
    unsigned short bestDizi[BEST_DEGER] = { 0,1,2,3,4 };
    size_t _best_sayac;

    for(_best_sayac = 0; _best_sayac < BEST_DEGER; _best_sayac++)
    {
        printf("%d ", bestDizi[_best_sayac]);
    }

    puts("");
    puts("------------bestScores sonu------------");
} // bestScores fonksiyonu sonu