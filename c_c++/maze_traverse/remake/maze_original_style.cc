
bool mazeTraverse( char[12][12], char *const );

char gl_map[] = 
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


#include <cstring>

int main( void )
{
    char local[12][12];

    strncpy(*local, gl_map, strlen(gl_map));

    mazeTraverse(local, &local[4][11]);
    //mazeTraverse(local, &local[2][0]);
}


#include <iostream>

bool mazeTraverse(char map[12][12], char *const pCoord)
{
    if(*pCoord != '.')  return false;

    *pCoord = 'X';

    short control = + 1;
    char  endLoop = + 1;
    char  sense   = - 1;

    system("cls");

    for(unsigned short i = 0; i < 12; ++i)
        std::cout.write(map[i], 12).put('\n');

    do
    {
        while(control != 0)
        {
            if(sense == -1 && pCoord[ control ] == 'X')
            {
                endLoop = control;
                sense   = 1;
            }

            switch(control)
            {
            case +  1: control = sense * - 12;  break;
            case - 12: control = sense * -  1;  break;
            case -  1: control = sense * + 12;  break;
            case + 12: control = sense * +  1;  break;

            case 0: default:
                break;
            }

            if(sense == -1)
            {
                if(control == endLoop)  sense = 1;
            }

            else if(sense == 1 && pCoord[ control ] == '.')
            {
                bool bord = false;

                for(unsigned short i = 0; i < 12 && bord == false; i++)
                {
                    /* */if(pCoord + control == &map[0][i] || pCoord + control == &map[11][i]) 
                        bord = true;

                    else if(pCoord + control == &map[i][0] || pCoord + control == &map[i][11]) 
                        bord = true;
                }

                if(bord == false)  break;

                pCoord[control] = 'X';
                return true;
            }

            else if(control == endLoop)
                return false;
        }
    }
    while(!mazeTraverse(map, pCoord + control));

    return true;
}

