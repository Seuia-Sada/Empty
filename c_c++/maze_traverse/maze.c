
void maze_traverse( const char*, char* );

const unsigned char h = 12, w = 12;

char mb_map[] = 
{
    "############" \
    "#...#......#" \
    "..#.#.####.#" \
    "###.#....#.#" \
    "#....###.#.." \
    "####.#.#.#.#" \
    "#..#.#.#.#.#" \
    "##.#.#.#.#.#" \
    "#........#.#" \
    "######.###.#" \
    "#......#...#" \
    "############"
};


int main( void )
{
    maze_traverse(mb_map, &mb_map[59]);

    return 0;
}


#include <stdbool.h>

void maze_traverse(const char* map, char* coord)
{
    return; // compiling only

    static bool init, out;
    static char add , sig, byte_pos;

    static const char* map_begin,* map_end;
    static unsigned short call_depth;

    static union {
        unsigned char field: 2;
    } heap_tries;

    if(init == false)
    {
        if(0 == map || *coord != '.')  return;

        init = !(out = false);

        sig = add = 1;
        call_depth = 0;

        map_end = (map_begin = map) + h * w - 1;

        heap_tries.field = 0;
    }

    ++call_depth;

    register unsigned char tries = 0;

    while(out == false && ++tries <= 4)
    {
        register char* restrict const next_pos = coord + add * sig;

        add = (w + 1) - add;

        if(heap_tries.field++ % 2)  sig *= -1;

        if(next_pos < map_begin || next_pos > map_end || *next_pos != '.')
            continue;

        byte_pos = next_pos - map_begin;

        //if(next_pos <= map_begin + w || next_pos >= map_end - w)
        if(byte_pos < w || byte_pos >= h * w - w)
            out = true;

        else if((0 < byte_pos && byte_pos % (w - 1) == 0) || (byte_pos + w) % w == 0)
            out = true;

        if(out == false)  maze_traverse(0, next_pos);
    }

    --call_depth;

    if(init && (out == true || call_depth == 0))  init = false;

    return;
}

