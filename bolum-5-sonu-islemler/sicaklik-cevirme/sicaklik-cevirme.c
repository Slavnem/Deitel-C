// FAHRENHEİT VE CELCİUS SICAKLIK ÇEVİRME, DÖNÜŞTÜRME
#include <stdio.h>

int celcius(int);
int fahrenheit(int);

int main(void)
{
    int celciusDerece, fahrenheitDerece;

    printf("Celcius derecesi giriniz: ");
    scanf("%d", &celciusDerece);

    printf("Fahrenheit derecesi giriniz: ");
    scanf("%d", &fahrenheitDerece);

    printf("%d celcius = %d fahrenheit\n", celciusDerece, fahrenheit(celciusDerece));
    printf("%d fahrenheit = %d celcius\n", fahrenheitDerece, celcius(fahrenheitDerece));
}

int celcius(int fDerece)
{
    return ((fDerece - 32) * 0.5556);
}

int fahrenheit(int cDerece)
{
    return ((cDerece * 1.8) + 32);
}