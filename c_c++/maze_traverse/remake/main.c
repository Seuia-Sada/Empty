
#include "maze_header.c"

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
    "##########.#"
};


int main( void )
{
    maze_traverse(mb_map, &mb_map[59], 12);

    return 0;
}

