#ifndef QUATERNION
#define QUATERNION

class Quaternion
{
public:
    float w, x, y, z;

    Quaternion(float w, float x, float y, float z)
    {
        this->w = w;
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /*Quaternion(Quaternion& quaternion)
    {
        this->w = quaternion.w;
        this->x = quaternion.x;
        this->y = quaternion.y;
        this->z = quaternion.z;
    }*/

    Quaternion operator + (Quaternion& q) { return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z); }
    Quaternion operator - (Quaternion& q) { return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z); }
    Quaternion operator * (Quaternion q) 
    { 
        return Quaternion(
        w*q.w - x*q.x - y*q.y - z*q.z, 
        w*q.x + x*q.w + y*q.z - z*q.y,                          
        w*q.y + y*q.w + z*q.x - x*q.z,
        w*q.z + z*q.w + x*q.y - y*q.x); 
    }
    Quaternion operator / (Quaternion& q) { return ((*this) * (q.inverse())); }

    void operator += (Quaternion& q) { (*this) = (*this) + q; }
    void operator -= (Quaternion& q) { (*this) = (*this) - q; }
    void operator *= (Quaternion& q) { (*this) = (*this) * q; }
    void operator /= (Quaternion& q) { (*this) = (*this) / q; }

    bool operator == (Quaternion& q) { return w == q.w && x == q.x && y == q.y && z == q.z; }
    bool operator != (Quaternion& q) { return !( (*this) == q ); }

    Quaternion conjugate() { return Quaternion(w, -x, -y, -z); }
    Quaternion inverse() { return conjugate().scale(1/norm()); }

    Quaternion scale(float s) { return Quaternion(w*s, x*s, y*s, z*s); }
    float norm() { return (w*w + x*x + y*y + z*z); }
};

#endif