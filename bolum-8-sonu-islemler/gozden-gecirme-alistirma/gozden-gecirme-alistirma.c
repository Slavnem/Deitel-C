// Slavnem
// Kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Ön işlemci tanımlamaları
#define SIZE 100

// Fonksiyon tanım
void swrite(const char* const);

// main
int main(void)
{
    char c = 'c'; // karakter tutacak olan değişken
    int x, y, z; // tam sayılar
    double d, e, f; // ondalıklı sayılar
    char* ptr; // karakter dizisi tutacak
    char s1[SIZE], s2[SIZE]; // karakter dizinleri

    // baslangic olarak karakteri cikti veriyoruz
    printf("%s%c\n", "Karakter: ", c);

    // karakteri büyük harfe çevirip kaydediyoruz
    c = toupper(c);

    // büyük yapılmış karakteri tekrar çıktı veriyoruz
    printf("%s%c\n", "Karakter: ", c);

    // c rakam mı değil mi kontrol
    puts(""); // boş satır
    isdigit(c) ? (printf("%c%s\n", c, " rakamdir")) : (printf("%c%s\n", c, " rakam degildir"));

    // c değişkeni kontrol karakteri mi değil mi kontrol
    puts(""); // boş satır
    iscntrl(c) ? (printf("%c%s\n", c, " kontrol karakteridir")) : (printf("%c%s\n", c, " kontrol karakteri degildir"));

    // s1 dizisi için klavyeden metin okuma
    puts(""); // boş satır
    fgets(s1, SIZE, stdin);

    // s1 dizisine kaydedilmiş veriyi ekrana yazdırma
    swrite(s1);

    // s1 dizisi içinde c karakterine en son rastlanan konumu ptr değişkenine atamak
    puts(""); // boş satır
    ptr = strrchr(s1, c);

    // c değişkeninin değerini ekrana yazdırma
    putchar(c);

    // c değeri harf olup olmadığını kontrol etmek
    puts(""); // boş satır
    isalpha(c) ? (printf("%c%s\n", c, " harftir")) : (printf("%c%s\n", c, " harf degildir\n"));

    // karakter okuyup saklama
    puts("\nBir karakter giriniz: ");
    scanf("%c", &c);

    // s1 içinde s2'nin ilk göründüğü konuma ptr atama
    ptr = strstr(s1, s2);

    // c karakterininin yazdırılabilir mi değil mi olduğunu kontrol etmek
    puts(""); // boş satır
    isprint(c) ? (printf("%c%s", c, " yazdirilabilir\n")) : (printf("%c%s", c, " yazdirilamaz\n"));

    // double değer tutan dizideki değerleri değişkenlere atama
    sscanf("1.27 10.3 9.432", "%f%f%f", &d,&e,&f);

    // s2 dizisini s1 dizisine kopyalama
    strcpy(s1, s2);

    // s2 dizisindeki herhangi bir karakterin s1 de gözüktüğü konumu ptr'a atama
    ptr = strpbrk(s1, s2);

    // s1 karakter dizini ile s2 karakter dizini karşılaştırıp sonucu çıktı vermek
    printf("\ns1 karsilastirma s2: %d\n", memcmp(s1, s2, SIZE));

    // s1 dizisinde c değişkeninin görüldüğü ilk yeri ptr değişkenine atamak
    ptr = strchr(s1, c);

    // x, y, z değişkenlerinin içeriğini sprintf ile s1 dizisine atama
    // her değer 7 karakterlik alan kaplamalı
    sprintf(s1, "x: %7d | y: %7d | z: %7d\n", &x, &y, &z);

    // s2 deki 10 karakteri s1 dizinine ekleme
    strncat(s1, s2, 10);

    // s1 içindeki karakter dizinin uzunluğunu çıktı verme
    printf("\n%s%d\n", "s1 karakter dizini uzunluğu: ", strlen(s1));

    // s2 ilk parça ataması ptr değişkenine
    ptr = strtok(s2, ",");

    // s2'yi virgül ile parça parça ayırmak
    while(ptr != NULL)
        ptr = strtok(NULL, ",");

    // sesliHarf karakter dizinine 2 farklı yolla "AEIOU" ilk değeri verme
    // char sesliHarf[] = "AEIOU"; // 1.yol
    // char sesliHarf[] = {'A','E','I','O','U'}; // 2.yol

    // test
    char z1[50] = "jack", z2[50] = "jill", z3[50];
    printf("\nmetin kopyalama ve ekleme: %s\n", strcat(strcat(strcpy(z3, z1), " and "), z2));
    printf("\nmetin:\nz1: %s\nz2: %s\nz3: %s\n", z1, z2, z3);
    printf("\nuzunluk:\nz1: %u\nz2: %u\nz3: %u\n", strlen(z1), strlen(z2), strlen(z3));

    // hata
    // char w1[5];
    // strncpy(w1, "hello", 5);
    // printf("\n%s\n", w1);

    // hata
    //char w2[12];
    // strcpy(w2, "Welcome Home");
}

// swrite
void swrite(const char* const sPtr)
{
    // karakter dizini sonu ise
    if(sPtr[0] == '\0')
        return;

    // karakter dizini sonu değil
    putchar(sPtr[0]); // karakteri çıktı vermek
    swrite(&sPtr[1]); // metinin kalan kısmını öz yineleme ile devam ettirmek
}