// Slavnem @2024-06-23
// Ünite Sonu Örnekler

// NO, YES önişlemcileri
#define NO 0
#define YES 1

// Kütüphane ekle
// #include "common.h"

// 3000 Satırdan sonrasını yeniden isimlendirme
// #line 3000 "after3000.h"

// ifdef kullanmadan TRUE tanımlı ise kaldır ve 1 olarak tekrar tanımla
#ifndef TRUE
#define TRUE 1
#else
#undef TRUE
#define TRUE 1
#endif

// eğer TRUE 0 değil ise FALSE 0 yap, değilse 1 yap
#if TRUE == 1
#define FALSE 0
#else
#define FALSE 1
#endif

// Küp hacimi hesaplayan makro
#define CUBE_VOLUME(x) ((x) * (x) * (x))

// printf için
#include <stdio.h>

// main
int main(void)
{
    printf("true: %d\n", TRUE);
    printf("false: %d\n", FALSE);
    printf("3 icin kup hacmi: %d\n", CUBE_VOLUME(3));

    puts(""); // boş satır

    // Ön tanımlı makro değerlerini yazdır
    printf("__LINE__ = %d\n", __LINE__);
    printf("__FILE__ = %s\n", __FILE__);
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);
    printf("__STDC__ = %d\n", __STDC__);
}