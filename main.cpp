#include "Vector.h"

using namespace std;

double Vector::getMagnitude() const { return magnitude; }
double Vector::getAngle() const { return angle; }

void Vector::setMagnitude(double magnitude)
{
    if (magnitude >= 0.0)
    {
        this->magnitude = magnitude;
    }
    else
    {
        throw std::invalid_argument("Magnitude must be greater than zero");
    }
}

void Vector::setAngle(double angle)
{
    this->angle = angle;
}


pair<double, double> Vector::getTerminalPointCoordinates() const
{
    double x = magnitude * cos(angle * degreesToRadians);
    double y = magnitude * sin(angle * degreesToRadians);

    x = (abs(x) < 1e-10) ? 0 : x;
    y = (abs(y) < 1e-10) ? 0 : y;

    return {x, y};
}

Vector::Vector() : magnitude(0.0), angle(0.0) {}

Vector::Vector(double magnitude, double angle)
{
    if (magnitude >= 0.0)
    {
        this->magnitude = magnitude;
        this->angle = angle;
    }
    else
    {
        throw invalid_argument("Magnitude must be greater than zero");
    }
}

Vector::Vector(const Vector &other)
{
    this->magnitude = other.magnitude;
    this->angle = other.angle;
}

void printVectorInfo(const Vector &vector)
{
    cout << "\nLength of Vector: " << vector.getMagnitude() << endl;
    cout << "Angle of Vector: " << vector.getAngle() << endl;

    pair<double, double> coordinates = vector.getTerminalPointCoordinates();
    cout << "Coordinates of end points of the vector: " << endl;
    cout << "\tx: " << coordinates.first << endl;
    cout << "\ty: " << coordinates.second << endl;
}

int main()
{
    cout << fixed << setprecision(10);

    cout << "Constructor by default" << endl;
    Vector defaultVector;
    printVectorInfo(defaultVector);

    cout << "Constructor with parameters" << endl;
    cout << "Enter the length of the vector (real non-negative number): ";
    double vectorMagnitude;
    cin >> vectorMagnitude;

    cout << "Enter the angle of the vector (in polar system of degrees): ";
    double vectorAngle;
    cin >> vectorAngle;

    Vector paramVector(vectorMagnitude, vectorAngle);
    printVectorInfo(paramVector);

    cout << "Constructor of copying vector" << endl;
    Vector copyVector(paramVector);
    printVectorInfo(copyVector);

    return 0;
}
