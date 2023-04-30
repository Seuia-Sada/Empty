
bool mazeTraverse( char[12][12], char *const );

const char map[145]
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

    strncpy(*local, ::map, strlen(::map));

    mazeTraverse(local, &local[4][11]);
    //mazeTraverse(local, &local[2][0]);

    return 0;
}


#include <iostream>
using std::cout;

bool mazeTraverse(char map[12][12], char *const pCoord)
{
    if(*pCoord != '.')
        return false;

    *pCoord = 'X';

    enum directions {
        IDLE = 0, 
        LEFT = -1 , RIGHT = 1, 
        UP   = -12, DOWN  = 12

    } control{ RIGHT }, endLoop{ RIGHT };

    int sense{ -1 };

    system("cls");

    for(unsigned j, i = 0; i < 12; ++i)
    {
        for(j = 0; j < 12; ++j)
            cout.put(map[i][j]).put(' ');

        cout.put('\n');
    }

    do
    {
        while(control != IDLE)
        {
            if(sense == -1 && *(pCoord + control) == 'X')
                endLoop = control, 
                sense   = 1;

            switch(control)
            {
            case RIGHT: control = static_cast< directions >( UP    * (sense) );  break;
            case UP   : control = static_cast< directions >( LEFT  * (sense) );  break;
            case LEFT : control = static_cast< directions >( DOWN  * (sense) );  break;
            case DOWN : control = static_cast< directions >( RIGHT * (sense) );  break;

            case IDLE:
            default:
                break;
            }

            if(sense == -1)
            {
                if(control == endLoop)
                    sense = 1;

                continue;
            }

            // check if pCoord is any of the border positions
            if(sense == 1 && *(pCoord + control) == '.')
            {
                bool bord{ false };

                for(unsigned i = 0; bord == false && i < 12; ++i)
                {
                    // vertical
                    /* */if(pCoord + control == &map[i][0] || pCoord + control == &map[i][11])
                        bord = true;

                    // horizontal
                    else if(pCoord + control == &map[0][i] || pCoord + control == &map[11][i])
                        bord = true;
                }

                if(bord == true)
                {
                    pCoord[control] = 'X';

                    return true;
                }
                else
                    break;
            }
            else if(control == endLoop)
                return false;
        }
    }
    while(!mazeTraverse(map, pCoord + control));

    return true;
}

