// 100 KERE DE KAÇ KEZ YAZI VE KAÇ KEZ TURA GELİYOR HESAPLAMA
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void para(unsigned int);

static unsigned int yazi = 0;
static unsigned int tura = 0;

int main(void)
{
    srand(time(NULL));

    para(100);

    printf("Yazi miktari %u\nTura miktari: %u\n", yazi, tura);
}

void para(unsigned int tur)
{
    int dongu;

    for(dongu = 1; dongu <= tur; dongu++)
    {
        rand() % 2 == 0 ? (yazi += 1) : (tura += 1);
    }
}