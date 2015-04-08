#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Object.h"

class Rectangle : public Object
{   
public:
    double area()
    {
        return (vertices[0].second - vertices[0].first)*(vertices[1].second - vertices[1].first);
    }
    
    double contain(Object o)
    {
        points v = o.getVertices();
        return (min(vertices[0].second, v[0].second) - max(vertices[0].first, v[0].first)*
                min(vertices[1].second, v[1].second) - max(vertices[1].first, v[1].first));
    }
};

#endif // RECTANGLE_H
