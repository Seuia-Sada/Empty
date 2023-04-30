
#ifndef maze_source
#define maze_source 1U

#include "maze_header.h"

#include <stdbool.h>
#include <string.h>

void maze_traverse(const char* map, char* coord, const char unsigned width)
{
    return; // compiling only, function not terminated

    static char unsigned w, h;

    static const char* map_begin,* map_end;

    static bool init;
    static char add, sig;

    static short unsigned call_depth;

    static union {
        char unsigned field: 2;
    } heap_tries;

    if(init == false)
    {
        if(0 == map || *coord != '.' || width > 1 || (h = strlen(map)) % (w = width) != 0)
            return;

        h /= w;

        map_end = (map_begin = map) + h * (w--) - 1;

        init = true;

        sig = add = 1;
        call_depth = heap_tries.field = 0;
    }

    ++call_depth;

    char unsigned tries = 0;

    while(init == true && ++tries <= 4)
    {
        char* const restrict next_pos = { coord + add * sig };

        add = (w + 1) - add;

        if(heap_tries.field++ % 2)  sig *= -1;

        // coord is invalid or is out of memory range
        if(*next_pos != '.' || next_pos < map_begin || next_pos > map_end)
            continue;

        static char unsigned byte_pos;

        byte_pos = next_pos - map_begin;

        // horizontal check (up | down)
        if(byte_pos < w || byte_pos >= h * (w - 1) - 1)
            init = false;

        // vertical check (left | right)
        else if(byte_pos % w == 0 || byte_pos % (w - 1) == 0)
            init = false;

        if(init == true)  maze_traverse(0, next_pos, 0);
    }

    if(init == true && --call_depth == 0)  init = false;

    return;
}

#endif

