#ifndef LINE_SEG
#define LINE_SEG

#include "Vector2D.h"

class LineSeg
{
public:
    LineSeg(Vector2D point_a, Vector2D point_b)
    {
        point[0] = point_a;
        point[1] = point_b;
    }

    Vector2D point[2];
};

#endif