#include <cmath>

inline double linearDist( const double p1, const double p2 );

inline void distance( const bool, double[3], const double[][3], unsigned );
void        distance( double[2][3], const double[][3], unsigned );

int main( void )
{
    int screen_size[2] = { 10, 10 };
    int& height = screen_size[0];
    int& width  = screen_size[1];

    // W = Width  H = Height  D = Depth
    // v = vertices d = dimentions
    /*  Ex.: (v = 2, d = 3)

        <type> form[v][d] = {
            { W, H, D }, 
            { W, H, D }
        };
    */
    // <type> = any variable type

    double   map_origin[3] = {  0.0,  0.0,  0.0  };
    double light_origin[3] = {  1.0, -1.0, -1.0  };

    double square[8][3] = {
        { -1.0,  1.0, -1.0  }, 
        { -1.0,  1.0,  1.0  }, 
        {  1.0,  1.0,  1.0  }, 
        {  1.0,  1.0, -1.0  }, 
        { -1.0, -1.0, -1.0  }, 
        { -1.0, -1.0,  1.0  }, 
        {  1.0, -1.0,  1.0  }, 
        {  1.0, -1.0, -1.0  }
    };
}


inline double linearDist(const double p1, const double p2) {
    return (abs( p1 ) + abs( p2 )) / 2.0;
}

inline void distance(const bool rather, double dist[3], const double point[][3], unsigned vertices) {
    for(int i = 0; i < 3; i++)
        dist[i] = point[0][i];

    while(--vertices > 0)
        for(unsigned short index = 0; index < 3; index++)
            if( ( rather == true  && dist[index] < point[vertices][index] ) || 
                ( rather == false && dist[index] > point[vertices][index] ) )

                dist[index] = point[vertices][index]
            ;
}

void distance(double dist[2][3], const double point[][3], unsigned vertices)
{
    distance(true , dist[0], point, vertices);
    distance(false, dist[1], point, vertices);
}

