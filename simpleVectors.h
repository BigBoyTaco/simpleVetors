#pragma once
//Simple Vectors written by https://github.com/BigBoyTaco

//A simple vector 2 [Ex: sVector2 myVec2 = sVector2(2.0f, 3.0f);]
struct sVector2
{
    float x, y;

    void set(float newX, float newY)
    {
        x = newX;
        y = newY;
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
};

sVector2 newVec2(float x, float y)
{
    return {x, y};
}

sVector3 newVec3(float x, float y, float z)
{
    return {x, y, z};
}

sVector4 newVec4(float x, float y, float z, float w)
{
    return {x, y, z, w};
}
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
    float x = a.x / b;
    float y =a.x / b;

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

bool operator == (sVector4 a, sVector4 b)
{
    if(a.x - b.x == 0 && a.y - b.y == 0 && a.z - b.z == 0 && a.w - b.w ==0)
        return true;
    else
        return false;
}

bool operator != (sVector4 a, sVector4 b)
{
    return !(a == b);
}
