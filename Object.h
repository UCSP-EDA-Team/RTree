#ifndef OBJECT_H
#define OBJECT_H

#include "config.h"

class Object
{
protected:
    points vertices;
public:
    Object(points vertices)
    {
        this->vertices = vertices;
    }

    points getVertices()
    {
        return this->vertices;
    }

    virtual double area();
    virtual double contain(Object);
};

#endif // OBJECT_H
