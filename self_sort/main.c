#include "sada.h"
#include <stdio.h>

void main( void )
{
    short var[6] = { 5, 0, -7, 10, 4, 8 };

    for(unsigned i = 0; i < 6; ++i)
        printf("%3d ", var[i]);

    printf("\n");

    self_pos_sort(var, 6);

    //self_pos_sort(var + 1, 4);

    //s_max(var, 6, NULL, NULL); \
    self_pos_sort(var, -1);

    for(unsigned i = 0; i < 6; ++i)
        printf("%3d ", var[i]);
}

