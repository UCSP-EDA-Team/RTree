#ifndef OBJECT_H
#define OBJECT_H

#include "config.h"

class Object
{
protected:

public:
    virtual double area();
    virtual double contain(Object);
};

#endif // OBJECT_H
