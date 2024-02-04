// PİSAGOR ÜÇLÜSÜ
#include <stdio.h>

int main( void )
{
    for(int x = 1; x < 500; x++)
    {
        for(int y = 1; y <= x; y++)
        {
            unsigned int pisagor = ((x * x) + (y * y));

            /*
            P değeri pisagor değerinin kendisine bölündüğünde yine kendisini
            örnek: 169 / 13 = 13, 25 /5 = 5, 4 / 2 = 2...
            veren sayını 1 eksiği olcağından tam sonucu bulmaz bizde bu yüzden
            pisagor değerini işlem yaparken 1 arttırıyoruz, while ile de yapılabilir
            */
            for(int p = 1; pisagor / p != p && p < pisagor / p && p++;)
            {
                if((p * p) == pisagor)
                {
                    printf("%d-%d-%d pisagor\n", x, y, p);
                }
            }
        }
    }
}