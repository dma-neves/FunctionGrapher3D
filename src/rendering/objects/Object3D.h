#ifndef OBJECT3D_H
#define OBJECT3D_H

#include<vector>

#include "Vector3D.h"

class Object3D
{
public:
    Object3D() {}

    void addLineSeg(std::pair<Vector3D, Vector3D> lineSeg) { lineSegments.push_back(lineSeg); }

    std::vector<std::pair<Vector3D, Vector3D>> lineSegments;
};

#endif