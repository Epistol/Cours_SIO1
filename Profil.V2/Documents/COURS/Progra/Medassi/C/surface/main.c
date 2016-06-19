#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    float fx;

    x = -10;

    while (x<=10) {
        fx = 1 / x;
        printf("f( %d", x);
        printf(") = %f \n", fx);

        x++;
    }




    return 0;
}
