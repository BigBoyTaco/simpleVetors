#pragma once

#include <cmath>

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

    // (a.x * a.x) + (a.y * a.y) + (a.z * a.z)
    static float dot(sVector3 a)
    {
        float product = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
        return product;
    }

    // (a.x * b.x )+ (a.y * b.y) + (a.z + b.z)
    static float dot(sVector3 a, sVector3 b)
    {
        float product = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
        return product;
    }

    static sVector3 cross(sVector3 a, sVector3 b)
    {
        sVector3 product = sVector3(
                a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
        return product;
    }

    //distance between two points
    static float distance(sVector3 a, sVector3 b)
    {
        float horz = a.x - b.x;
        float vert = a.y - b.y;
        float depth = a.z - b.z;

        return sqrt((horz * horz) + (vert * vert) + (depth * depth));
    }
};

sVector3 operator * (sVector3 a, sVector3 b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    float z = a.z * b.z;

    return {x, y, z};
}

sVector3 operator * (sVector3 a, float b)
{
    float x = a.x * b;
    float y = a.y * b;
    float z = a.z * b;

    return {x, y, z};
}

sVector3 operator / (sVector3 a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    float z = a.z / b;

    return {x, y, z};
}

sVector3 operator + (sVector3 a, sVector3 b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    float z = a.z + b.z;

    return {x, y, z};
}

sVector3 operator - (sVector3 a, sVector3 b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;

    return {x, y, z};
}

sVector3 operator - (sVector3 a)
{
    float x = -1 * a.x;
    float y = -1 * a.y;
    float z = -1 * a.z;

    return {x, y, z};
}

bool operator == (sVector3 a, sVector3 b)
{
    if((double)a.x - b.x == 0 && (double)a.y - b.y == 0 && (double)a.z - b.z == 0)
        return true;
    else
        return false;
}

bool operator != (sVector3 a, sVector3 b) { return !(a == b); }