#ifndef CAMERA
#define CAMERA

#include "Vector2D.h"

class Camera
{
public:
    Camera(Vector2D pos, Vector2D direction) : pos(pos), direction(direction) {}

    Vector2D pos, direction;
};

#endif