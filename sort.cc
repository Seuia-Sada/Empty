
#include <cmath>

void self_pos_sort( short arr[], const short arr_size )
{
    unsigned short i;
    short minor;

    const unsigned short local_size = [&]
    {
        short index_max = minor = arr[0];

        for(i = 1; i < arr_size; ++i)
        {
            if(index_max  < arr[i])  index_max = arr[i];
            else if(minor > arr[i])  minor     = arr[i];
        }

        return abs(index_max) + abs(minor);
    }();

    short* local_arr[local_size + 1];

    for(i = 0; i < local_size; ++i)
        local_arr[i] = nullptr;

    for(i = 0; i < arr_size; ++i)
        local_arr[arr[i] - minor] = new short{ arr[i] };

    for(long j = i = 0; j <= local_size; ++j)
        if(local_arr[j] != nullptr)
            arr[i++] = *local_arr[j], delete( local_arr[j] );
}

