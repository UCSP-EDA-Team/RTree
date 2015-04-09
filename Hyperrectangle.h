#ifndef HYPERRECTANGLE_H
#define HYPERRECTANGLE_H

#include "vector"

class Hyperrectangle
{   
private:
    points vertices;
public:
    points getVertices()
    {
        return this->vertices;
    }

    Hyperrectangle(points vertices)
    {
        this->vertices = vertices;
    }

    double area()
    {
        double tmp = 1;
        for(pair<double,double> dimension : this->vertices)
            tmp *= dimension.second - dimension.first;

        return tmp;
    }
    
    double contain(Hyperrectangle o)
    {
        points v = o.getVertices();

        double tmp = 1; int i=0;
        for(pair<double,double> dimension : this->vertices){
            tmp *= (min(dimension.second, v[i].second) - max(dimension.first, v[i].first));
            i++;
        }

        return tmp;
    }
};

#endif // HYPERRECTANGLE_H
