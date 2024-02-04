//Kredi Limit Hesaplama
#include <stdio.h>

int main( void )
{
    unsigned int musteriNO_1 = 1202212, musteriNO_2 = 2202212, musteriNO_3 = 3202212;
    unsigned int musteriBALANS_1 = 3000, musteriBALANS_2 = 5000, musteriBALANS_3 = 4000;
    unsigned int musteriKREDI_1 = 6000, musteriKREDI_2 = 7000, musteriKREDI_3 = 9000;
    unsigned int musteriKREDI_YENI_1 = musteriKREDI_1/2, musteriKREDI_YENI_2 = musteriKREDI_2/2, musteriKREDI_YENI_3 = musteriKREDI_3/2;
    int musteriDURUM_1 = (musteriKREDI_YENI_1 - musteriBALANS_1),
    musteriDURUM_2 = (musteriKREDI_YENI_2 - musteriBALANS_2),
    musteriDURUM_3 = (musteriKREDI_YENI_3 - musteriBALANS_3);

    printf("=================================================\n");
    printf("Musteri 1 ID: %d\nMusteri 1 Balans: %d\nMusteri 1 Kredi Limit: %d\nMusteri 1 Yeni Kredi Limit: %d\nDurum: %d\n",
    musteriNO_1, musteriBALANS_1, musteriKREDI_1, musteriKREDI_YENI_1, musteriDURUM_1);
    printf("=================================================\n");
    printf("Musteri 2 ID: %d\nMusteri 2 Balans: %d\nMusteri 2 Kredi Limit: %d\nMusteri 2 Yeni Kredi Limit: %d\nDurum: %d\n",
    musteriNO_2, musteriBALANS_2, musteriKREDI_2, musteriKREDI_YENI_2, musteriDURUM_2);
    printf("=================================================\n");
    printf("Musteri 3 ID: %d\nMusteri 3 Balans: %d\nMusteri 3 Kredi Limit: %d\nMusteri 3 Yeni Kredi Limit: %d\nDurum: %d\n",
    musteriNO_3, musteriBALANS_3, musteriKREDI_3, musteriKREDI_YENI_3, musteriDURUM_3);
    printf("=================================================\n");
}