#include <stdio.h>

int main( void )
{
    double toplamBenzinpara = 0;
    double toplamPara = 0;
    double benzin = 22.70;
    double yuzkmYakilanbenzin = 9.4;
    double kmYakilanbenzin = (yuzkmYakilanbenzin / 100);

    char araba[] = "Alfa Romeo 145 1.6 (Boxer Motor) 100BG";
    char yakitTuru[] = "Benzin";

    int parkUcret = 0;
    int bankaSecim;
    int gunlukYol;
    int gunlukPark = 0;
    int ogsToplamgecis = 0;
    int ogsToplampara = 0;
    int ogsVakifbank = 95;
    int ogsGarantibbva = 120;
    int ogsDenizbank = 55;
    int ogsIsbankasi = 80;
    int ogsZiraatbankasi = 100;

    printf("--------------------------------------------------\n");
    printf("Sisteme kayitli benzin litre fiyati: %fTL\n", benzin);
    printf("Sisteme kayitli araba: %s\n", araba);
    printf("Sisteme kayitli yakit turu: %s\n", yakitTuru);
    printf("Sisteme kayitli OGS gecis ucreti:\n");
    printf(":Vakif Bank: %d\n", ogsVakifbank);
    printf(":Garanti BBVA: %d\n", ogsGarantibbva);
    printf(":Deniz Bank: %d\n", ogsDenizbank);
    printf(":Is Bankasi: %d\n", ogsIsbankasi);
    printf(":Ziraat Bankasi: %d\n", ogsZiraatbankasi);
    printf("--------------------------------------------------\n");
    printf("UYARI: Bosluk birakmayiniz\n\n");

    printf("Gunluk kac km yol gidiyorsunuz yaziniz: ");
    scanf("%d", &gunlukYol);

    toplamBenzinpara = (double)(kmYakilanbenzin * gunlukYol);

    printf("Gunluk ne kadar park ucreti oduyorsunuz yaziniz: ");
    scanf("%d", &gunlukPark);
    printf("Gun icinde kac kac OGS'den geciyorsunuz yaziniz: ");
    scanf("%d", &ogsToplamgecis);

    if(ogsToplamgecis < 0)
    {
        printf("Eksili miktarda giris yapamazsiniz! (HATA)\n");
    }
    else if(ogsToplamgecis == 0)
    {
        printf("Toplam yakilan benzin parasi = %f TL\n", toplamBenzinpara);
        
        toplamPara = (toplamBenzinpara + gunlukPark);
        printf("Toplam harcanan para = %f TL\n", toplamPara);
    }
    else if(ogsToplamgecis > 0)
    {
        printf("Bankalar\n1:Vakif Bank: %d\n2:Garanti BBVA: %d\n3:Deniz Bank: %d\n4:Is Bankasi: %d\n5:Ziraat Bankasi: %d\n", ogsVakifbank, ogsGarantibbva, ogsDenizbank, ogsIsbankasi, ogsZiraatbankasi);
        printf("Hangi banka ile gecis yaptiniz yaziniz: ");
        scanf("%d", &bankaSecim);

        if(bankaSecim <= 0)
        {
            printf("Hatali banka secimi yapildi!(HATA)\n");
        }
        else if(bankaSecim > 0)
        {
            if(bankaSecim == 1)
            {
                ogsToplampara = (ogsToplamgecis * ogsVakifbank);
            }
            else if(bankaSecim == 2)
            {
                ogsToplampara = (ogsToplamgecis * ogsGarantibbva);
            }
            else if(bankaSecim == 3)
            {
                ogsToplampara = (ogsToplamgecis * ogsDenizbank);
            }
            else if(bankaSecim == 4)
            {
                ogsToplampara = (ogsToplamgecis * ogsIsbankasi);
            }
            else if(bankaSecim == 5)
            {
                ogsToplampara = (ogsToplamgecis * ogsZiraatbankasi);
            }

            toplamPara = (toplamBenzinpara + ogsToplampara + gunlukPark);
            printf("Toplam yakilan benzin parasi = %f TL\n", toplamBenzinpara);
            printf("Toplam harcanan para = %f TL\n", toplamPara);
        }
        else
        {
            printf("Banka seciminde bilinmeyen bir hata olustu!(HATA)\n");
        }
    }
    else
    {
        printf("OGS Hesaplamasında bilinmeyen bir hata olustu!(HATA)\n");
    }
}
