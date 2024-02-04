#include "stdio.h"

#define MIN_R 1
#define MAX_R 36

///////////////////////////
// fonksiyon on tanimlari
///////////////////////////
void ptrDaireCevre(const double* yaricap, double* sonuc);
void ptrDaireAlan(const double* yaricap, double* sonuc);
void ptrKureHacim(const double* yaricap, double* sonuc);
void ptrYazdirDiziCC(const char* arrayPtr[], const size_t big_size, const size_t small_size);
void ptrBilgilendir(const char* islem, const double* yaricap, const double* sonuc);

double powd(const double* deger, const size_t tur);

void (*ptrFonks[])(const double*, double*) =
{
    ptrDaireCevre,
    ptrDaireAlan,
    ptrKureHacim
};

///////////////////////////
// degiskenler
///////////////////////////
enum BOOL
{
    FALSE = 0,
    TRUE = 1
};

enum SECIM
{
    SEC_DAIRECEVRE = 0,
    SEC_DAIREALAN = 1,
    SEC_KUREHACIM = 2
};

const char* secimMenuDiziPtr[] =
{
    "Daire Cevre Hesaplama",
    "Daire Alan Hesaplama",
    "Kure Hacim Hesaplama"
};

const double pi = 3.14;

const size_t sizeSecimMenu = (sizeof(secimMenuDiziPtr) / sizeof(secimMenuDiziPtr[0]));

///////////////////////////
// fonksiyonlar
///////////////////////////
int main(void)
{
    int __secim;
    int __kontrol;

    double __yaricap;
    double __sonuc;

    do {
        // ekrana menuleri cikti ver ve kullanicidan deger iste
        ptrYazdirDiziCC(secimMenuDiziPtr, sizeSecimMenu, 1);
        printf("Bir secim yapiniz: ");
        scanf("%d", &__secim);

        // istenen degeri girene kadar yaricap girmesini saglamak        
        do
        {
            printf("Bir yaricap degeri giriniz: ");
            scanf("%lf", &__yaricap);
        } while(__yaricap < 0.1);

        // deger dogru ise TRUE degilse FALSE
        switch(__secim)
        {
            case 0:
            case 1:
            case 2:
                __kontrol = TRUE;
                break;
            default:
                __kontrol = FALSE;
                break;
        }
    } while(__kontrol != TRUE);

    // girilen degere gore islem
    switch(__secim)
    {
        // DAIRE CEVRE HESAPLAMA
        case 0:
            (*ptrFonks[SEC_DAIRECEVRE])(&(__yaricap), &(__sonuc));
            break;
        // DAIRE ALAN HESAPLAMA
        case 1:
            (*ptrFonks[SEC_DAIREALAN])(&(__yaricap), &(__sonuc));
            break;
        // KURE HACIM HESAPLAMA
        case 2:
            (*ptrFonks[SEC_KUREHACIM])(&(__yaricap), &(__sonuc));
            break;
        // BILINMEYEN DEGER
        default:
            printf("Bilinmeyen bir deger girdiniz [%d]. Program sonladiriliyor...\n", __secim);
            return 0;
    }

    // girilen secime gore sonuclari cikti verme
    switch(__secim)
    {
        case 0: // DAIRE CEVRE SONUC
        case 1: // DAIRE ALAN SONUC
        case 2: // KURE HACIM SONUC
            ptrBilgilendir(secimMenuDiziPtr[__secim], &(__yaricap), &(__sonuc));
            break;
        // BILINMEYEN DEGER
        default:
            printf("Bilinmeyen bir deger girdiniz [%d]. Program sonladiriliyor...\n", __secim);
            return 0;
    }
}

void ptrDaireCevre(const double* yaricap, double* sonuc)
{
    *(sonuc) =  (2 * (pi) * (*(yaricap)));
}

void ptrDaireAlan(const double* yaricap, double* sonuc)
{
    *(sonuc) = ((pi) * (powd(yaricap, 2)));
}

void ptrKureHacim(const double* yaricap, double* sonuc)
{
    *(sonuc) = ((4/3) * (pi) * (powd(yaricap, 3)));
}

void ptrYazdirDiziCC(const char* arrayPtr[], const size_t big_size, const size_t small_size)
{
    size_t __bigcounter;
    size_t __smallcounter;

    for(__bigcounter = 0; __bigcounter < (big_size); __bigcounter++)
    {
        for(__smallcounter = 0; __smallcounter < (small_size); __smallcounter++)
        {
            printf("[%d] ", __bigcounter);
            printf("%s", arrayPtr[__bigcounter]);
        }-

        puts(""); // bos satir
    }
}

void ptrBilgilendir(const char* islem, const double* yaricap, const double* sonuc)
{
    printf("\n===================\n");
    printf("Secilen Islem: %s\n", islem);
    printf("Secilen Yaricap: %2.lf\n", *(yaricap));
    printf("Sonuc: %2.lf\n", *(sonuc));
    printf("===================\n");
}

double powd(const double* deger, const size_t tur)
{
    double __gecici = *(deger);
    size_t __sayac;

    for(__sayac = 1; __sayac < tur; __sayac++)
    {
        // ussu hesapla
        __gecici *= *(deger);
    }

    // bulunan sayiyi dondur
    return __gecici;
}