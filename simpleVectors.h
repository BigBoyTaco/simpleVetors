#pragma once

#include <cmath>

// Simple Vectors written by https://github.com/BigBoyTaco
// v1.0.3

/// CHANGELOG:
/// added distance() to all vector types
/// added someVec.clamp() (clamps all values between a range)
/// added someVec.max() (clamps max value)
/// added someVec.min() (clamps min value)
/// added someVec.normalize() and someVec.normalized() making it easier to normalize a vector
/// other code-cleanliness improvements

// A simple vector 2 [Ex: sVector2 myVec2 = sVector2(2.0f, 3.0f);]
struct sVector2
{
    float x, y;


    void set(float newX, float newY)
    {
        x = newX;
        y = newY;
    }
    void set(sVector2 vector)
    {
        x = vector.x;
        y = vector.y;
    }
    void set(float a)
    {
        x = a;
        y = a;
    }
    sVector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    sVector2()
    {
        this->x = 0;
        this->y = 0;
    }
    explicit sVector2(float a)
    {
        this->x = a;
        this->y = a;
    }
    [[nodiscard]] float magnitude() const
    {
        // square root of the sum of the squares
        float a = sqrt((x * x) + (y * y));
        return a;
    }
    // returns the normalized version of current vector
    [[nodiscard]] sVector2 normalized() const
    {
        sVector2 normal = sVector2(this->x, this->y);
        float mag = normal.magnitude();
        normal.x = normal.x / mag;
        normal.y = normal.y / mag;
        return normal;
    }
    // sets this vector to it's normalized self
    void normalize()
    {
        this->set(this->normalized());
    }
    void scale(float a)
    {
        this->x *= a;
        this->y *= a;
    }
    void clamp(float min, float max)
    {
        if (this->x < min)
            this->x = min;
        else if (this->x > max)
            this->x = max;
        
        if (this->y < min)
            this->y = min;
        else if (this->y > max)
            this->y = max;
    }
    void max(float max)
    {
        if (this->x > max)
            this->x = max;
        
        if (this->y > max)
            this->y = max;
    }
    void min(float min)
    {
        if (this->x < min)
            this->x = min;
        
        if (this->y < min)
            this->y = min;
    }
};

struct sVector3
{
    float x, y, z;

    void set(float newX, float newY, float newZ)
    {
        x = newX;
        y = newY;
        z = newZ;
    }
    void set(sVector3 vector)
    {
        x = vector.x;
        y = vector.y;
        z = vector.z;
    }
    void set(float a)
    {
        x = a;
        y = a;
        z = a;
    }
    sVector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    sVector3()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    explicit sVector3(float a)
    {
        this->x = a;
        this->y = a;
        this->z = a;
    }
    [[nodiscard]] float magnitude() const
    {
        // square root of the sum of the squares
        float a = sqrt((x * x) + (y * y) + (z * z));
        return a;
    }
    // returns the normalized version of this vector
    [[nodiscard]] sVector3 normalized() const
    {
        sVector3 normal = sVector3(this->x, this->y, this->z);
        float mag = normal.magnitude();
        normal.x = normal.x / mag;
        normal.y = normal.y / mag;
        normal.z = normal.z / mag;
        return normal;
    }
    // sets this vector to it's normalized self
    void normalize()
    {
        this->set(this->normalized());
    }
    void scale(float a)
    {
        this->x *= a;
        this->y *= a;
        this->z *= a;
    }
    void clamp(float min, float max)
    {
        if (this->x < min)
            this->x = min;
        else if (this->x > max)
            this->x = max;

        if (this->y < min)
            this->y = min;
        else if (this->y > max)
            this->y = max;
        
        if (this->z < min)
            this->z = min;
        else if(this->z > max)
            this->z = max;
    }
    void max(float max)
    {
        if (this->x > max)
            this->x = max;

        if (this->y > max)
            this->y = max;
        
        if (this->z > max)
            this->z = max;
    }
    void min(float min)
    {
        if (this->x < min)
            this->x = min;

        if (this->y < min)
            this->y = min;
        
        if (this->z < min)
            this->z = min;
    }
};

struct sVector4
{
    float x, y, z, w;

    void set(float newX, float newY, float newZ, float newW)
    {
        x = newX;
        y = newY;
        z = newZ;
        w = newW;
    }
    void set(float a)
    {
        x = a;
        y = a;
        z = a;
        w = a;
    }
    void set(sVector4 vector)
    {
        x = vector.x;
        y = vector.y;
        z = vector.z;
        w = vector.w;
    }
    sVector4(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
    sVector4()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }
    explicit sVector4(float a)
    {
        this->x = a;
        this->y = a;
        this->z = a;
        this->w = a;
    }
    [[nodiscard]] float magnitude() const
    {
        // square root of the sum of the squares
        float a = sqrt((x * x) + (y * y) + (z * z) + (w * w));
        return a;
    }
    // returns the normalized version of this vector
    [[nodiscard]] sVector4 normalized() const
    {
        sVector4 normal = sVector4(this->x, this->y, this->z, this->w);
        float mag = normal.magnitude();
        normal.x = normal.x / mag;
        normal.y = normal.y / mag;
        normal.z = normal.z / mag;
        normal.w = normal.w / mag;

        return normal;
    }
    // sets this vector to it's normalized self
    void normalize()
    {
        this->set(this->normalized());
    }
    void scale(float a)
    {
        this->x *= a;
        this->y *= a;
        this->z *= a;
        this->w *= a;
    }
    void clamp(float min, float max)
    {
        if (this->x < min)
            this->x = min;
        else if (this->x > max)
            this->x = max;

        if (this->y < min)
            this->y = min;
        else if (this->y > max)
            this->y = max;

        if (this->z < min)
            this->z = min;
        else if (this->z > max)
            this->z = max;
        
        if (this->w < min)
            this->w = min;
        else if (this->w > max)
            this->w = max;
    }
    void max(float max)
    {
        if (this->x > max)
            this->x = max;

        if (this->y > max)
            this->y = max;

        if (this->z > max)
            this->z = max;
        
        if (this->w > max)
            this->w = max;
    }
    void min(float min)
    {
        if (this->x < min)
            this->x = min;

        if (this->y < min)
            this->y = min;

        if (this->z < min)
            this->z = min;
        
        if (this->w < min)
            this->w = min;
    }
};
//
//operations
//
const sVector2& operator * (sVector2 a, sVector2 b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    return sVector2(x, y);
}

const sVector2& operator * (sVector2 a, float b)
{
    float x = a.x * b;
    float y = a.y * b;

    return sVector2(x, y);
}

const sVector2& operator / (sVector2 a, sVector2 b)
{
    float x = a.x / b.x;
    float y = a.y / b.y;
    return sVector2(x, y);
}

const sVector2& operator / (sVector2 a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    return sVector2(x, y);
}

const sVector2& operator + (sVector2 a, sVector2 b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    return sVector2(x, y);
}

const sVector2& operator - (sVector2 a, sVector2 b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    return sVector2(x, y);
}
const sVector2 &operator-(sVector2 a)
{
    float x = -1 * a.x;
    float y = -1 * a.y;
    return sVector2(x, y);
}

bool operator == (sVector2 a, sVector2 b)
{
    if(a.x - b.x == 0 && a.y - b.y == 0)
        return true;
    else
        return false;
}

bool operator != (sVector2 a, sVector2 b)
{
    return !(a == b);
}

const sVector3& operator * (sVector3 a, sVector3 b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    float z = a.z * b.z;
    return sVector3(x, y, z);
}

const sVector3& operator * (sVector3 a, float b)
{
    float x = a.x * b;
    float y = a.y * b;
    float z = a.z * b;
    return sVector3(x, y, z);
}

const sVector3& operator / (sVector3 a, sVector3 b)
{
    float x = a.x / b.x;
    float y = a.y / b.y;
    float z = a.z / b.z;
    return sVector3(x, y, z);
}

const sVector3& operator / (sVector3 a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    float z = a.z / b;
    return sVector3(x, y, z);
}

const sVector3& operator + (sVector3 a, sVector3 b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    float z = a.z + b.z;
    return sVector3(x, y, z);
}

const sVector3& operator - (sVector3 a, sVector3 b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;
    return sVector3(x, y, z);
}

const sVector3 &operator-(sVector3 a)
{
    float x = -1 * a.x;
    float y = -1 * a.y;
    float z = -1 * a.z;

    return sVector3(x, y, z);
}

bool operator == (sVector3 a, sVector3 b)
{
    if(a.x - b.x == 0 && a.y - b.y == 0 && a.z - b.z == 0)
        return true;
    else
        return false;
}

bool operator != (sVector3 a, sVector3 b)
{
    return !(a == b);
}

const sVector4& operator * (sVector4 a, sVector4 b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    float z = a.z * b.z;
    float w = a.w * b.w;
    return sVector4(x, y, z, w);
}

const sVector4& operator * (sVector4 a, float b)
{
    float x = a.x * b;
    float y = a.y * b;
    float z = a.z * b;
    float w = a.w * b;
    return sVector4(x, y, z, w);
}

const sVector4& operator / (sVector4 a, sVector4 b)
{
    float x = a.x / b.x;
    float y = a.y / b.y;
    float z = a.z / b.z;
    float w = a.w / b.w;
    return sVector4(x, y, z, w);
}

const sVector4& operator / (sVector4 a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    float z = a.z / b;
    float w = a.w / b;
    return sVector4(x, y, z, w);
}

const sVector4& operator + (sVector4 a, sVector4 b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    float z = a.z + b.z;
    float w = a.w + b.w;
    return sVector4(x, y, z, w);
}

const sVector4& operator - (sVector4 a, sVector4 b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;
    float w = a.w - b.w;
    return sVector4(x, y, z, w);
}

const sVector4 &operator-(sVector4 a)
{
    float x = -1 * a.x;
    float y = -1 * a.y;
    float z = -1 * a.z;
    float w = -1 * a.w;

    return sVector4(x, y, z, w);
}

bool operator == (sVector4 a, sVector4 b)
{
    if(a.x - b.x == 0 && a.y - b.y == 0 && a.z - b.z == 0 && a.w - b.w == 0)
        return true;
    else
        return false;
}

bool operator != (sVector4 a, sVector4 b)
{
    return !(a == b);
}

// (a.x * a.x) + (a.y * a.y)
float dot(sVector2 a)
{
    float product = (a.x * a.x) + (a.y * a.y);
    return product;
}
// (a.x * b.x) + (a.y * b.y)
float dot(sVector2 a, sVector2 b)
{
    float product = (a.x * b.x) + (a.y * b.y);
    return product;
}
// (a.x * a.x) + (a.y * a.y) + (a.z * a.z)
float dot(sVector3 a)
{
    float product = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
    return product;
}
// (a.x * b.x )+ (a.y * b.y) + (a.z + b.z)
float dot(sVector3 a, sVector3 b)
{
    float product = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    return product;
}
// (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w)
float dot(sVector4 a)
{
    float product = (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w);
    return product;
}
// (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w)
float dot(sVector4 a, sVector4 b)
{
    float product = (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
    return product;
}

sVector3 cross(sVector3 a, sVector3 b)
{
    sVector3 product = sVector3(
        a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    return product;
}

//distance between two points
float distance(sVector2 a, sVector2 b)
{
    float d1 = a.x - b.x;
    float d2 = a.y - b.y;
    return sqrt((d1 * d1) + (d2 * d2));
}

//distance between two points
float distance(sVector3 a, sVector3 b)
{
    float d1 = a.x - b.x;
    float d2 = a.y - b.y;
    float d3 = a.z - b.z;
    return sqrt((d1 * d1) + (d2 * d2) + (d3 * d3));
}

// distance between two points
float distance(sVector4 a, sVector4 b)
{
    float d1 = a.x - b.x;
    float d2 = a.y - b.y;
    float d3 = a.z - b.z;
    float d4 = a.w - b.w;
    return sqrt((d1 * d1) + (d2 * d2) + (d3 * d3) + (d4 * d4));
}