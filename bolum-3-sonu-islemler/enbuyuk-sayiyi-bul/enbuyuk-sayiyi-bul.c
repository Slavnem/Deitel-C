#include <stdio.h>

int main( void )
{
    int counter = 10, number;
    unsigned int largest = 0;

    for(int i = 1; i < counter; i++)
    {
        printf("%d)Sayiyi giriniz: ", i);
        scanf("%d", &number);

        while(number < 0)
       {
           printf("%d)Sayi negatif olmamali!, sayiyi giriniz: ", i);
           scanf("%d", &number);
       }

        if(number > largest)
        {
            largest = number;
        }
    }

    printf("======================\n");
    printf("En buyuk sayi = %d\n", largest);
    printf("======================\n");
}
