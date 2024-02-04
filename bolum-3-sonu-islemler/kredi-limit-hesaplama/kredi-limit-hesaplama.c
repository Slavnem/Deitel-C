// Kredi Limit Hesaplama
#include <stdio.h>

int main( void )
{
    int islemDurum = 1, hesapNumara, baslangicBalans, toplamHarcama, toplamYatirilan, krediLimit;
    unsigned int balans;
    
    while(islemDurum == 1)
    {
        printf("====================================================\n");
        printf("Islem yapmak istiyormusunuz (Evet:1 | Hayir:2): ");
        scanf("%d", &islemDurum);

        if(islemDurum != 1)
        {
            return 0;
        }
        else if(islemDurum == 1)
        {
            printf("Hesap numarasini giriniz: ");
            scanf("%d", &hesapNumara);
    
            while(hesapNumara <= 0)
            {
                printf("Hesap numarasi 0'a esit veya daka kucuk olamaz! (HATA)\n");
                printf("Hesap numarasini dogru sekilde giriniz: ");
                scanf("%d", &hesapNumara);
            }
    
            printf("Baslangic balansini giriniz: ");
            scanf("%d", &baslangicBalans);
    
            if(baslangicBalans <= 0)
            {
                printf("Baslangic balansi 0'a esit veya daha kucuk olamaz! (HATA)\n");
                printf("(UYARI) Bir kere daha yanlis girisinizde program sona ericektir!\n");
                printf("Baslangic balansini dogru sekilde giriniz: ");
                scanf("%d", &baslangicBalans);
    
                if(baslangicBalans <= 0)
                {
                    printf("Program fazla hatali giristen dolayi sonlandiriliyor...\n");
                    return 0;
                }
            }
    
            printf("Toplam harcamayi giriniz: ");
            scanf("%d", &toplamHarcama);
    
            if(toplamHarcama < 0)
            {
                printf("Toplam harcama eksili olamaz! (HATA)\n");
                printf("Toplam harcamayi dogru sekilde giriniz: ");
                scanf("%d", &toplamHarcama);
    
                if(toplamHarcama < 0)
                {
                    printf("Program fazla hatali giristen dolayi sonlandiriliyor...\n");
                    return 0;
                }
            }
    
            printf("Toplam yatirilan miktari giriniz: ");
            scanf("%d", &toplamYatirilan);
    
            if(toplamYatirilan < 0)
            {
                printf("Toplam yatirilan miktar eksili olamaz! (HATA)\n");
                printf("Toplam yatirilan miktari dogru giriniz: ");
                scanf("%d", &toplamYatirilan);
    
                if(toplamYatirilan < 0)
                {
                    printf("Program fazla hatali giristen dolayi sonlandiriliyor...\n");
                    return 0;
                }
            }
    
            printf("Kredi limitini giriniz: ");
            scanf("%d", &krediLimit);
    
            if(krediLimit <= 0)
            {
                printf("Toplam kredi limiti 0'a esit veya daha kucuk olamaz! (HATA)\n");
                printf("Toplam kredi limitini dogru giriniz: ");
                scanf("%d", &krediLimit);
    
                if(krediLimit <= 0)
                {
                    printf("Program fazla hatali giristen dolayi sonlandiriliyor...\n");
                    return 0;
                }
            }
    
            balans = (baslangicBalans + toplamYatirilan);
            printf("Balans = %d\n", balans);
    
            if(balans > krediLimit)
            {
                printf("Kredi limiti asimi!\n");
            }
            else if(balans <= krediLimit)
            {
                printf("Geriye kalan kredi miktari = %d\n", (krediLimit - balans));
            }
            else
            {
                printf("Balans ve Kredi limit hesabi yapilirken bilinmeyen bir hata olustu! (HATA)\n");
            }
        }
        else
        {
            printf("Islem kontrolu sirasinda bilinmeyen bir hata olustu! (HATA)\n");
        }
    }
}