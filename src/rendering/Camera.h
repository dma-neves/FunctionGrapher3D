#ifndef CAMERA
#define CAMERA

#include "Vector3D.h"
#include "Vector2D.h"

class Camera
{
public:
    Camera(Vector3D pos, float fov, Vector2D vw_size, Vector2D windowSize) : pos(pos), direction(direction), vw_size(vw_size)
    {
        planeDist = vw_size.y / 2.0f / tan(M_PI*fov/180.0f);
        scaler.x = windowSize.x / vw_size.x;
        scaler.y = windowSize.y / vw_size.y;

        // Todo: dynamic axis and direction initialization
        direction = Vector3D(-1, 0, 0);
        virtual_y_axis = Vector3D(0, 0, -1);
        virtual_y_axis.setMagnitude(vw_size.x);
        virtual_x_axis = Vector3D(0, 1, 0);
        virtual_x_axis.setMagnitude(vw_size.y);
    }

    Vector3D getPlanePoint()
    {
        Vector3D aux = direction;
        aux.setMagnitude(planeDist);
        return pos + aux;
    }

    // Get virtual window origin
    Vector3D get_vw_origin()
    {
        Vector3D aux = (virtual_x_axis * -0.5f) + (virtual_y_axis * -0.5f);
        return getPlanePoint() + aux;
    }

    Vector3D pos, direction;
    float planeDist;
    Vector2D vw_size, scaler; // Virtual window size, Projection scaler
    Vector3D virtual_x_axis;
    Vector3D virtual_y_axis;
};

#endif