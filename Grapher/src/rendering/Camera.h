#ifndef CAMERA
#define CAMERA

#include "Vector3D.h"
#include "Vector2D.h"

class Camera
{
public:
    Camera(float fov, Vector2D vw_size, Vector2D windowSize);

    Vector3D getPlanePoint();
    Vector3D get_vw_origin(); // Get virtual window origin

    void moveStraight(float disp);
    void rotateAround_z(float angle);

    Vector3D pos, direction;
    float planeDist;
    Vector2D vw_size, scaler; // Virtual window size, Projection scaler
    Vector3D virtual_x_axis;
    Vector3D virtual_y_axis;
};

#endif