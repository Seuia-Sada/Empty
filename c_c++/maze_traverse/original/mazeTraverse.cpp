#include <iostream>

bool mazeTraverse(char map[12][12], char * const pCoord)
{
    if(*pCoord != '.')  return false;

    *pCoord = 'X';

    enum directions {
        IDLE = 0, 
        LEFT = -1 , RIGHT = 1, 
        UP   = -12, DOWN  = 12

    } control{ RIGHT }, endLoop{ RIGHT };

    unsigned short i, j;
    short sense{ -1 };

    system("cls");

    for(i = 0, j; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
            std::cout<<map[i][j]<<' ';

        std::cout<<'\n';
    }

    do  while(control != IDLE)
        {
            if(sense == -1 && *(pCoord + control) == 'X')
            {
                endLoop = control;
                sense = 1;
            }

            switch(control)
            {
                case RIGHT: control = (directions)( UP    * (sense) ); break;
                case UP   : control = (directions)( LEFT  * (sense) ); break;
                case LEFT : control = (directions)( DOWN  * (sense) ); break;
                case DOWN : control = (directions)( RIGHT * (sense) ); break;
            }

            if(sense == -1)
            {
                if(control == endLoop)  sense = 1;
                continue;
            }

            if(sense == 1 && *(pCoord + control) == '.')
            {
                bool bord{ false };

                for(i = 0; i < 12 && bord == false; i++)
                    for(j = 0; j < 12 && bord == false; j++)
                    {
                        if( (pCoord + control == &map[i][0] ) || (pCoord + control == &map[i][11]) || 
                            (pCoord + control == &map[0][j] ) || (pCoord + control == &map[11][j]) 
                        ) { bord = true; }
                    }

                if(bord == true) {
                    pCoord[control] = 'X';
                    return true;

                } else break;

            } else if(control == endLoop)  return false;
        }
    while(!mazeTraverse(map, pCoord + control));

    return true;
}

int main()
{
    char map[12][12] {
        '#','#','#','#','#','#','#','#','#','#','#','#', 
        '#','.','.','.','#','.','.','.','.','.','.','#', 
        '.','.','#','.','#','.','#','#','#','#','.','#', 
        '#','#','#','.','#','.','.','.','.','#','.','#', 
        '#','.','.','.','.','#','#','#','.','#','.','.', 
        '#','#','#','#','.','#','.','#','.','#','.','#', 
        '#','.','.','#','.','#','.','#','.','#','.','#', 
        '#','#','.','#','.','#','.','#','.','#','.','#', 
        '#','.','.','.','.','.','.','.','.','#','.','#', 
        '#','#','#','#','#','#','.','#','#','#','.','#', 
        '#','.','.','.','.','.','.','#','.','.','.','#', 
        '#','#','#','#','#','#','#','#','#','#','#','#' 
    };

    mazeTraverse(map, &map[4][11]);
    //mazeTraverse(map, &map[2][0]);

    return 0;
}
    
