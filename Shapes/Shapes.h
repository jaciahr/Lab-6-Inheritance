#pragma once
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape() = 0;
};

class Shape2D : virtual public Shape {
public:
    virtual float Area() const = 0;
    virtual string GetName2D() const = 0;
    void ShowArea() const;
    bool operator>(const Shape2D& rhs) const;
    bool operator<(const Shape2D& rhs) const;
    bool operator==(const Shape2D& rhs) const;
};

class Square : virtual public Shape2D {
    float s;
    string name = "The area of the Square is : ";
public:
    Square();
    Square(float s);
    string GetName2D() const;
    float Area() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Triangle : virtual public Shape2D {
    float b;
    float h;
    string name = "The area of the Triangle is : ";
public:
    Triangle();
    Triangle(float b, float h);
    string GetName2D() const;
    float Area() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Circle : virtual public Shape2D {
    float r;
    string name = "The area of the Circle is : ";
public:
    Circle();
    Circle(float r);
    string GetName2D() const;
    float Area() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Shape3D : virtual public Shape {
public:
    virtual float Volume() const = 0;
    virtual string GetName3D() const = 0;
    void ShowVolume() const;
    bool operator>(const Shape3D& rhs) const;
    bool operator<(const Shape3D& rhs) const;
    bool operator==(const Shape3D& rhs) const;
};

class TriangularPyramid : virtual public Shape3D, private Triangle {
    float h;
    string name = "The volume of the TriangularPyramid is : ";
public:
    TriangularPyramid();
    TriangularPyramid(float h, float length, float base);
    string GetName3D() const;
    float Volume() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Cylinder : virtual public Shape3D, private Circle {
    float h;
    string name = "The volume of the Cylinder is : ";
public:
    Cylinder();
    Cylinder(float h, float r);
    string GetName3D() const;
    float Volume() const;
    void Scale(float scaleFactor);
    void Display() const;
};

class Sphere : virtual public Shape3D, private Circle {
    float r;
    string name = "The volume of the Sphere is : ";
public:
    Sphere();
    Sphere(float r);
    string GetName3D() const;
    float Volume() const;
    void Scale(float scaleFactor);
    void Display() const;
};