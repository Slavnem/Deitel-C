////////////////////////////
// Yazan: Slavnem
// Dil: C
////////////////////////////

// Kütüphaneler
#include <stdio.h>

// main
int main(void)
{
    char s[] = "31298 87.375"; // s dizisine başlangıç değeri atanması
    int x; // x tamsayı girdi değeri
    double y; // y ondalıklı girdi değeri

    /* AÇIKLAMA
        s dizisinde arasında boşluk bırakılmış değerleri
        okuyor ve sırasıyla değişken türüne göre
        aynı türdeki değişkenlere atıyoruz
        bu sayede güvenli şekilde değişken okuma yapabiliyoruz
    */
    sscanf(s, "%d%lf", &x, &y);
    printf("%s\n%s%6d\n%s%8.3lf\n",
        "The values stored in character array s are: ",
        "integer: ", x, "double: ", y);
}