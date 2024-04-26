// Slavnem @2024-04-26
// Ayları Numaralandırma

// Kütüphaneler
#include <stdio.h>

// numaralandırma sabitleri ayları temsil eder
enum months {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

// main
int main(void)
{
    enum months month; // 12 aydan herhangi birini içerebilir

    // işaretçi dizisi başlatılıyor
    const char* monthName[] = {
        "", "January", "February", "March",
        "April", "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    // aylar for döngüsüne sokuluyor
    for(month = JAN; month <= DEC; month++)
    {
        printf("%2d%11s\n", month, monthName[month]);
    }
}