// FONKSİYONU ÖZYİNELEME İLE FİBONACCİ BULMA
#include <stdio.h>

unsigned long long int ozfibonacci(unsigned long long int);

int main(void)
{
    int sayi;

    do
    {
        printf("Fibonacci icin sayi giriniz: ");
        scanf("%d", &sayi);
    } while (sayi < 0);
    
    printf("%d fibonacci: %llu\n", sayi, ozfibonacci(sayi));
}

unsigned long long int ozfibonacci(unsigned long long int fibo)
{
    if(fibo == 0 || fibo == 1)
    {
        return fibo;
    }
    else
    {
        return ozfibonacci(fibo-1) + ozfibonacci(fibo-2);
    }
}