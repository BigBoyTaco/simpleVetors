#pragma once

#include <cmath>

// A simple floating point vector 2 [Ex: sVector2 myVec2 = sVector2(2.0f, 3.0f);]
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

    // (a.x * a.x) + (a.y * a.y)
    static float dot(sVector2 a)
    {
        float product = (a.x * a.x) + (a.y * a.y);
        return product;
    }

    // (a.x * b.x) + (a.y * b.y)
    static float dot(sVector2 a, sVector2 b)
    {
        float product = (a.x * b.x) + (a.y * b.y);
        return product;
    }

    //distance between two points
    static float distance (sVector2 a, sVector2 b)
    {
        float horz = a.x - b.x;
        float vert = a.y - b.y;
        // solve for hypot
        return sqrt((horz * horz) + (vert * vert));
    }
};

//
// operators
//
sVector2 operator * (sVector2 a, sVector2 b)
{
    float x = a.x * b.x;
    float y = a.y * b.y;
    return {x, y};
}

sVector2 operator * (sVector2 a, float b)
{
    float x = a.x * b;
    float y = a.y * b;

    return {x, y};
}

sVector2 operator / (sVector2 a, float b)
{
    float x = a.x / b;
    float y = a.y / b;
    return {x, y};
}

sVector2 operator + (sVector2 a, sVector2 b)
{
    float x = a.x + b.x;
    float y = a.y + b.y;
    return {x, y};
}

sVector2 operator - (sVector2 a, sVector2 b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    return {x, y};
}

sVector2 operator - (sVector2 a)
{
    float x = -1.0f * a.x;
    float y = -1.0f * a.y;
    return {x, y};
}

bool operator == (sVector2 a, sVector2 b)
{
    if((double)a.x - b.x == 0.0 && (double)a.y - b.y == 0.0)
        return true;
    else
        return false;
}

bool operator != (sVector2 a, sVector2 b)
{
    return !(a == b);
}