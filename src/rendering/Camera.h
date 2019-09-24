#ifndef CAMERA
#define CAMERA

#include "Vector3D.h"

class Camera
{
public:
    Camera(Vector3D pos, Vector3D direction) : pos(pos), direction(direction) {}

    Vector3D pos, direction;
};

#endif