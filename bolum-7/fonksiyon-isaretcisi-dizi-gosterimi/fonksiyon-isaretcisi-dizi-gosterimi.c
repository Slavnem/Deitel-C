// Fonksiyon isaretcileri dizisinin gosterimi
#include <stdio.h>

// prototipler
void function1(int a);
void function2(int b);
void function3(int c);

int main(void)
{
    // herbiri bir tamsayi arguman alan ve void turunden 3 fonksiyona isaret
    // eden fonksiyon isaretci dizisinin yuklenmesi
    void(*f[3])(int) = {function1, function2, function3};

    size_t choice; // kullanıcı seciminin tutulacagi degisken

    printf("%s", "0 ve 2 arasinda bir sayi giriniz, 3 ise bitis: ");
    scanf("%zu", &choice);

    // kullanici seciminin isleme alinmasi
    while(choice >= 0 && choice < 3)
    {
        // f dizisi icerisindeki choice konumunda bulunan fonksiyonu
        // cagir ve choice'i bir arguman olarak aktar
        (*f[choice])(choice);

        printf("%s", "0 ve 2 arasinda bir sayi giriniz, 3 ise bitis: ");
        scanf("%zu", &choice);
    }// while blogu sonu

    puts("Program calismasi tamamlandi");
} // main sonu

void function1(int a)
{
    printf("%d girdiniz, fonksiyon1 calisti\n\n", a);
} // function1 blogu sonu

void function2(int b)
{
    printf("%d girdiniz, fonksiyon2 calisti\n\n", b);
} // function2 blogu sonu

void function3(int c)
{
    printf("%d girdiniz, fonksiyon3 calisti\n\n", c);
} // function3 blogu sonu