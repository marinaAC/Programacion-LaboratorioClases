#include <stdio.h>
#include <stdlib.h>

int main()
{

   int valor[] = {1, 3, 9, 7, 5};
   int i;
   int j;
   int max;

   max = 0;
   for (i = 0; i < 5; i++)
        if (valor[i] > max)
            max = valor[i];

        for (i = max; i > 0; i--){
        for (j = 0; j < 5; j++)
            if (valor[j] >= i)
                printf(" *");
        else
            printf("  ");

      putchar('\n');
   }

    return 0;
}
