#pragma once

#include <iostream>
using std::istream;
using std::ostream;

class Vector {
private:
    friend istream& operator >> (istream& cin, Vector& v) { return cin >> v.x >> v.y; }
    friend ostream& operator << (ostream& out, const Vector& v) { return out << "x=" << v.x << " y=" << v.y; }
    friend Vector operator+(Vector v1, Vector v2) { return Vector(v1.x + v2.x, v1.y + v2.y); }
    friend Vector operator*(double k, Vector v) { return Vector(v.x * k, v.y * k); }
    friend Vector operator*(Vector v, double k) { return operator*(k, v); }
    friend double operator*(Vector v1, Vector v2) { return v1.x * v2.x + v1.y * v2.y; }
    double x, y;

public:
    Vector() { x = y = 0; }
    Vector(double x, double y) { this->x = x; this->y = y; }
    double getX() { return x; }
    void setX(double x) { this->x = x; }
    double getY() { return y; }
    void setY(double y) { this->y = y; }
};