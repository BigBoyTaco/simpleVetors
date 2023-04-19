#pragma once

#include <cmath>

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

    // (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w)
    static float dot(sVector4 a)
    {
        float product = (a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w);
        return product;
    }

    // (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w)
    static float dot(sVector4 a, sVector4 b)
    {
        float product = (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
        return product;
    }

    // distance between two points
    static float distance(sVector4 a, sVector4 b)
    {
        float x = a.x - b.x;
        float y = a.y - b.y;
        float z = a.z - b.z;
        float w = a.w - b.w;

        return sqrt((x * x) + (y * y) + (z * z) + (w * w));
    }
};

sVector4 operator * (sVector4 a, sVector4 b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    float z = a.z * b.z;
    float w = a.w * b.w;

    return {x, y, z, w};
}

sVector4 operator * (sVector4 a, float b)
{
    float x = a.x * b;
    float y = a.y * b;
    float z = a.z * b;
    float w = a.w * b;

    return {x, y, z, w};
}

sVector4 operator / (sVector4 a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    float z = a.z / b;
    float w = a.w / b;

    return {x, y, z, w};
}

sVector4 operator + (sVector4 a, sVector4 b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    float z = a.z + b.z;
    float w = a.w + b.w;

    return {x, y, z, w};
}

sVector4 operator - (sVector4 a, sVector4 b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;
    float w = a.w - b.w;

    return {x, y, z, w};
}

sVector4 operator - (sVector4 a)
{
    float x = -1 * a.x;
    float y = -1 * a.y;
    float z = -1 * a.z;
    float w = -1 * a.w;

    return {x, y, z, w};
}

bool operator == (sVector4 a, sVector4 b)
{
    if(a.x - b.x == 0 && a.y - b.y == 0 && a.z - b.z == 0 && a.w - b.w == 0)
        return true;
    else
        return false;
}

bool operator != (sVector4 a, sVector4 b) { return !(a == b); }