// Sabit verilere sabit olmayan isaretci uzerinden
// veriler uzerinde degisiklik yapmaya calismak
#include <stdio.h>

// ++f
void f(const int *xPtr);

// +main
int main(void)
{
    int y; // y'yi tanimla

    f(&y); // f, illegal degisiklik girisiminde bulunur
}
// -main

// +f
void f(const int *xPtr)
{
    *xPtr = 100; // hata: sabit bir nesne uzerinde degisiklik yapamassiniz
}
// -f