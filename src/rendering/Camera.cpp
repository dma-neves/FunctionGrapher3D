#include "Camera.h"

Camera::Camera(float fov, Vector2D vw_size, Vector2D windowSize) : pos(pos), direction(direction), vw_size(vw_size)
{
    planeDist = vw_size.y / 2.0f / tan(M_PI*fov/180.0f);
    scaler.x = windowSize.x / vw_size.x;
    scaler.y = windowSize.y / vw_size.y;

    pos = Vector3D(20, 0, 0);
    direction = Vector3D(-1, 0, 0);
    virtual_y_axis = Vector3D(0, 0, -1);
    virtual_y_axis.setMagnitude(vw_size.x);
    virtual_x_axis = Vector3D(0, 1, 0);
    virtual_x_axis.setMagnitude(vw_size.y);
}

Vector3D Camera::getPlanePoint()
{
    Vector3D aux = direction;
    aux.setMagnitude(planeDist);
    return pos + aux;
}

Vector3D Camera::get_vw_origin()
{
    Vector3D aux = (virtual_x_axis * -0.5f) + (virtual_y_axis * -0.5f);
    return getPlanePoint() + aux;
}

void Camera::moveStraight(float disp)
{
    Vector3D aux = direction; aux.setMagnitude(disp);
    pos += aux;
}

void Camera::moveHorizontal(float disp)
{
    Vector3D aux = virtual_x_axis; aux.setMagnitude(disp);
    pos += aux;
}

void Camera::moveVertical(float disp)
{
    Vector3D aux = (virtual_y_axis * -1); aux.setMagnitude(disp);
    pos += aux;
}

void Camera::rotateVertically(float angle)
{
    pos.rotate(virtual_x_axis, angle);
    direction.rotate(virtual_x_axis, angle);
    virtual_y_axis.rotate(virtual_x_axis, angle);
}

void Camera::rotateHorizontally(float angle)
{
    pos.rotate(virtual_y_axis, angle);
    direction.rotate(virtual_y_axis, angle);
    virtual_x_axis.rotate(virtual_y_axis, angle);
}