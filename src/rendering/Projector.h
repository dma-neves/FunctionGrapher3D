#ifndef PROJECTOR
#define PROJECTOR

#include <vector>

#include "Camera.h"
#include "Object2D.h"
#include "Object3D.h"

class Projector
{
public:
    static Object2D projectObject(Camera* camera, Object3D* renderable);
};

#endif