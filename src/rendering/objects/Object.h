#ifndef OBJECT2D_H
#define OBJECT2D_H

#include<vector>

#include "LineSeg.h"
#include "Vector2D.h"
#include "Vector3D.h"

class Object2D
{
public:
    Object2D(){}
    void addLineSeg(LineSeg<Vector2D> lineSeg) { lineSegments.push_back(lineSeg); }
    std::vector<LineSeg<Vector2D>> lineSegments;
};

class Object3D
{
public:
    Object3D(){}
    void addLineSeg(LineSeg<Vector3D> lineSeg) { lineSegments.push_back(lineSeg); }
    std::vector<LineSeg<Vector3D>> lineSegments;
};

#endif