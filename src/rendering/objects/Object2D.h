#ifndef OBJECT2D_H
#define OBJECT2D_H

#include<vector>

#include "Vector2D.h"

class Object2D
{
public:
    Object2D() {}

    void addLineSeg(std::pair<Vector2D, Vector2D> lineSeg) { lineSegments.push_back(lineSeg); }

    std::vector<std::pair<Vector2D, Vector2D>> lineSegments;
};

#endif