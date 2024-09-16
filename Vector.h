#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

class Vector
{
private:
    double magnitude;
    double angle;

    const double degreesToRadians = M_PI / 180.0;

public:
    double getMagnitude() const;
    double getAngle() const;

    void setMagnitude(double magnitude);
    void setAngle(double angle);

    std::pair<double, double> getTerminalPointCoordinates() const;

    Vector();
    Vector(double magnitude, double angle);
    Vector(const Vector &other);
};

void printVectorInfo(const Vector &vector);

#endif
