//Faiz Hesaplama
//Formül: Faiz = anapara * oran * gün / 365
#include <stdio.h>

int main( void )
{
    float faiz, anapara, oran;
    int gun;

    printf("===============================\n");
    printf("C Kodlama - Faiz Hesaplama\n");
    printf("===============================\n");

    //While döngüsü ile anapara değerinin doğru yazılıp yazılmadığını kontrol etme
    printf("Ana parayi giriniz: ");
    scanf("%f", &anapara);
    while(anapara <= 0.f)
    {
        printf("Ana para 0'a esit veya daha kucuk olamaz! (HATA)\n");
        printf("Ana parayi dogru giriniz: ");
        scanf("%f", &anapara);
    }

    //While döngüsü ile faiz oranı değerinin doğru yazılıp yazılmadığını kontrol etme
    printf("Faiz oranini giriniz: ");
    scanf("%f", &oran);
    while(oran <= 0.f)
    {
        printf("Oran 0'a esit veya daha kucuk olamaz! (HATA)\n");
        printf("Faiz oranini dogru giriniz: ");
        scanf("%f", &oran);
    }

    //While döngüsü ile gün değerinin doğru yazılıp yazılmadığını kontrol etme
    printf("Gun sayisini giriniz: ");
    scanf("%d", &gun);
    while(gun <= 0.f)
    {
        printf("Gun degeri 0'a esit veya daha kucuk olamaz! (HATA)\n");
        printf("Gun degerini dogru giriniz: ");
        scanf("%d", &gun);
    }

    //Faiz Hesaplama ve ekrana yazdırma
    faiz = (anapara * oran * gun) / 365;
        
    printf("===============================\n");
    printf("Ana para = %.2f\n", anapara);
    printf("Faiz orani = %.2f\n", oran);
    printf("Gun = %d\n", gun);
    printf("===============================\n");
    printf("Faiz Miktari = %.2f\n", faiz);
    printf("===============================\n");
}