#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    double xStart;
    double xEnd;
    double yStart;
    double yEnd;

    double area()
    {
        return (xEnd - xStart)*(yEnd - yStart);
    }
};

#endif // RECTANGLE_H
