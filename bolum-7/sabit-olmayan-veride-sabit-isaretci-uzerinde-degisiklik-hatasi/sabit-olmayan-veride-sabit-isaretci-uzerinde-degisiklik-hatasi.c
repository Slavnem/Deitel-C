// Sabit olmayan verilere sabit isaretci uzerinde degisiklik yapmaya calismak
#include <stdio.h>

// +main
int main(void)
{
    int x; // x'i tanimla
    int y; // y'yi tanimla

    // ptr, ptr uzerinden degistirilebilir bir tamsayiya isaret eden sabit bir isaretcidir
    // fakat daima ayni bellek bolgesine isaret eder
    int * const ptr = &x;


    *ptr = 7; // izin verilir: *ptr, const turunde degil
    ptr = &y; // hata: ptr, const turunde, yeni bir adresle iliskilendirilemez
}
// -main