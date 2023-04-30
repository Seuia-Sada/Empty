#include "sada.h"

#if( sada_h == 1U )

#undef  sada_h
#define sada_h 2U

#include <stdlib.h>

static uint_s v_arr_size;

uint_s s_max( const short arr[], const uint_s arr_size, short* const max, short* const min )
{
    static short index_max, index_min;

    if(arr_size < SHRT_MAX) // or ((unsigned short) -1) / 2
    {
        index_max = index_min = *arr;
        v_arr_size = arr_size;

        for(uint_s i = 1; i < arr_size; ++i)
        {
            if(index_max < arr[i])  index_max = arr[i];
            if(index_min > arr[i])  index_min = arr[i];
        }
    }

    if(max != NULL)  *max = index_max;
    if(min != NULL)  *min = index_min;

    return abs(index_max) + abs(index_min);
}

void self_pos_sort( short arr[], uint_s arr_size )
{
    short _null;

    const uint_s local_arr_size = s_max(arr, arr_size, NULL, &_null) + 1U;
    short*       local_arr[local_arr_size];

    arr_size = v_arr_size;

    for(uint_s i = 0; i < local_arr_size; ++i)
        local_arr[i] = &_null;

    for(uint_s i = 0; i < arr_size; ++i)
        *( local_arr[ arr[i] - _null ] = malloc(sizeof( short )) ) = arr[i];

    for(uint_s i = 0, j = 0; i < local_arr_size; ++i)
        if(local_arr[i]  != &_null)
            arr[j++] = *local_arr[i], free(local_arr[i]);
}

#endif

