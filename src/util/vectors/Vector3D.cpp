#include "Vector3D.h"

Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3D Vector3D::operator+(Vector3D vec)
{
    return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

Vector3D Vector3D::operator-(Vector3D vec)
{
    return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

Vector3D Vector3D::operator*(float scaler)
{
    return Vector3D(x * scaler, y * scaler, z * scaler);
}

Vector3D Vector3D::operator/(float scaler)
{
    return Vector3D(x / scaler, y / scaler, z / scaler);
}

void Vector3D::operator+=(Vector3D vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
}

void Vector3D::operator-=(Vector3D vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}

void Vector3D::operator*=(float scaler)
{
    x *= scaler;
    y *= scaler;
    z *= scaler;
}

void Vector3D::operator/=(float scaler)
{
    x /= scaler;
    y /= scaler;
    z /= scaler;
}

void Vector3D::operator=(float num)
{
    if(num == 0)
    {
        x = 0;
        y = 0;
    }
    else std::cout << "Error: Invalid Vector3D operation: Vector3D = " << num << std::endl;
}

float Vector3D::magnitude()
{
    return sqrt( pow(x,2) + pow(y,2) + pow(z,2) );
}

bool Vector3D::null()
{
   return (x == 0 && y == 0 && z == 0);
}
