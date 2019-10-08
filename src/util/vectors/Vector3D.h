#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>

#include "Quaternion.h"

class Vector3D
{
public:
    Vector3D(float x = 0, float y = 0, float z = 0);

    float x, y, z;

    Vector3D operator+(Vector3D vec);
    Vector3D operator-(Vector3D vec);
    Vector3D operator*(float scaler);
    Vector3D operator/(float scaler);

    void operator+=(Vector3D vec);
    void operator-=(Vector3D vec);
    void operator*=(float scaler);
    void operator/=(float scaler);
    void operator=(float num);

    bool operator==(Vector3D vec) { return (x == vec.x && y == vec.y && z == vec.z); }
    bool operator!=(Vector3D vec) { return !(*this==vec); }

    void setMagnitude(float mag) { *this *= (mag / magnitude()); }
    float magnitude();
    bool null();
    Vector3D unitVector();

    float dot(Vector3D vec) { return x * vec.x + y * vec.y + z * vec.z; }

    Vector3D rotate(Vector3D axis, float angle);
};

#endif // Vector3D_H
