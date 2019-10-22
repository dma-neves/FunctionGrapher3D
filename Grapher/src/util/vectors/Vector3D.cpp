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

Vector3D Vector3D::unitVector()
{
    Vector3D vec = *this;
    vec.setMagnitude(1);
    return vec;
}

Vector3D Vector3D::rotate(Vector3D axis, float angle)
{
    Quaternion q1(0,x, y, z);
    Quaternion q2(cos(angle/2), axis.x*sin(angle/2), axis.y*sin(angle/2), axis.z*sin(angle/2));
    Quaternion q3 = q2 * q1 * q2.conjugate();
    x = q3.x; y = q3.y; z = q3.z;
}

float Vector3D::angle(Vector3D vec)
{
    float c = dot(vec) / (magnitude() * vec.magnitude());

    if(c >= -1.0f and c <= 1.0f) return acos(c);

    //else std::cout << "Error: Invalid cos value: " << c << std::endl;
    return 0;
}