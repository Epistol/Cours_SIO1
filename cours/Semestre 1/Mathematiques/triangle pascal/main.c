#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int i = 0;
    int j= 1;

    printf("choisir 'n' : ");
    scanf("%d", &n);

    int triangle[n][n];

    triangle[0][0] = 1;
    triangle[0][1] = 1;
    printf("1\n");

   for (i=0; i<n; i++)
    {
        triangle[i][0] = 1;
        printf("%d\t", triangle[i][0]);
        for (j = 1; j<i+1; j++)
        {
            triangle[i][j+1] = 1;
            triangle[i][j] = triangle[i-1][j-1]+triangle[i-1][j];
            printf("%d\t", triangle[i][j]);
        }
        triangle[i][j+1] = 1;
        printf("%d\n", triangle[i][j+1]);
    }

    return 0;
}
