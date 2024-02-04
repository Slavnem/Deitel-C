// Sabit verilere sabit isaretci uzerinde degisiklik yapmaya calismak
#include <stdio.h>

// +main
int main(void)
{
    int x = 5; // x ilk degerin atanmasi
    int y; // y'yi tanimla

    // ptr, sabit bir tamsayiya isaret eden sabit bir isaretcidir
    // ptr daima ayni bolgeye isaret eder
    // bu bolgede bulunan tamsayi uzerinde degisiklik yapilamaz

    const int *const ptr = &x; // ilkdeger atama GECERLI
    printf("%d\n", *ptr);

    *ptr = 7; // hata: *ptr, const turundedir, yeni deger ile iliskilendirilemez
    ptr = &y; // hata: ptr, const turundedir, yeni adres atanamaz
}
// -main