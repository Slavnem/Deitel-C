// Slavnem @2024-04-26
// Union Ondalıklı Kullanımı

// Kütüphaneler
#include <stdio.h>

// Union Yapılar
typedef union
{
    float f;
    double d;
    long double x;
} floatingPoint;

// İsimlendirme

// main
int main(void)
{
    // union nesnesi oluşturma
    floatingPoint myFloats;

    // bu nesneye değerleri atama ve çıktı verme
    myFloats.f = 33.312; // float
    printf("float: %f | double: %lf | long double: %Lf\n", myFloats.f, myFloats.f, myFloats.f);

    myFloats.d = 456.3126455454; // double
    printf("float: %f | double: %lf | long double: %Lf\n", myFloats.d, myFloats.d, myFloats.d);

    myFloats.x = 78769797756.4846546548645; // long double
    printf("float: %f | double: %lf | long double: %Lf\n", myFloats.x, myFloats.x, myFloats.x);
}