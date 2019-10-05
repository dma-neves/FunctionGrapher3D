#ifndef PROJECTOR
#define PROJECTOR

#include <vector>

#include "Camera.h"
#include "Object2D.h"
#include "Object3D.h"

class Projector
{
public:
    static Object2D projectObject(Camera* camera, Object3D* obj3d);

private:
    static Vector3D projectPointSpatially(Camera* camera, Vector3D& pt);
    static Vector2D projectPointToWindow(Camera* camera, Vector3D& pt);
};

#endif