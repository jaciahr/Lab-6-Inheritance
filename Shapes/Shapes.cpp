#include <math.h>
#include <iostream>
#include <string>
#include "Shapes.h"
using namespace std;

const float PI = 3.14159f;

//Shape
Shape::~Shape() {
}


// 1) Shape 2D
void Shape2D::ShowArea() const {
    cout << GetName2D() << endl;
    cout << Area() << endl;
}

bool Shape2D::operator>(const Shape2D& rhs) const {
    if (Area() > rhs.Area())
        return true;
    else
        return false;
}

bool Shape2D::operator<(const Shape2D& rhs) const {
    if (Area() < rhs.Area())
        return true;
    else
        return false;
}

bool Shape2D::operator==(const Shape2D& rhs) const {
    if (Area() == rhs.Area())
        return true;
    else
        return false;
}

// 1) a. Square
Square::Square() {
    this->s = 0;
}

Square::Square(float s) {
    this->s = s;
}

string Square::GetName2D() const {
    return name;
}

float Square::Area() const {
    float area;
    area = pow(s, 2);
    return area;
}

void Square::Scale(float scaleFactor) {
    s *= scaleFactor;
}

void Square::Display() const {
    cout << "The area of the Square is : " << Area() << endl;
    cout << "Length of a side: " << s << endl;
}

// 1) b. Triangle
Triangle::Triangle() {
    this->b = 0;
    this->h = 0;
}

Triangle::Triangle(float b, float h) {
    this->b = b;
    this->h = h;
}

string Triangle::GetName2D() const {
    return name;
}

float Triangle::Area() const {
    float area;
    area = 0.5 * b * h;
    return area;
}

void Triangle::Scale(float scaleFactor) {
    b *= scaleFactor;
    h *= scaleFactor;
}

void Triangle::Display() const {
    cout << "The area of the Triangle is : " << Area() << endl;
    cout << "Base: " << b << endl;
    cout << "Height: " << h << endl;
}

// 1) c. Circle
Circle::Circle() {
    this->r = 0;
}

Circle::Circle(float r) {
    this->r = r;
}

string Circle::GetName2D() const {
    return name;
}

float Circle::Area() const {
    float area;
    area = PI * r * r;
    return area;
}

void Circle::Scale(float scaleFactor) {
    r *= scaleFactor;
}

void Circle::Display() const {
    cout << "The area of the Circle is : " << Area() << endl;
    cout << "Radius: " << r << endl;
}

// 2) Shape 3D
void Shape3D::ShowVolume() const {
    cout << GetName3D() << endl;
    cout << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D& rhs) const {
    if (Volume() > rhs.Volume())
        return true;
    else
        return false;
}

bool Shape3D::operator<(const Shape3D& rhs) const {
    if (Volume() < rhs.Volume())
        return true;
    else
        return false;
}

bool Shape3D::operator==(const Shape3D& rhs) const {
    if (Volume() == rhs.Volume())
        return true;
    else
        return false;
}

// 2) a. Triangular pyramid
TriangularPyramid::TriangularPyramid() : Triangle(0, 0) {
    this->h = 0;
}

TriangularPyramid::TriangularPyramid(float h, float length, float base) : Triangle(length, base) {
    this->h = h;
}

string TriangularPyramid::GetName3D() const {
    return name;
}

float TriangularPyramid::Volume() const {
    float volume;
    volume = (1.0 / 3) * Triangle::Area() * h;
    return volume;
}

void TriangularPyramid::Scale(float scaleFactor) {
    h *= scaleFactor;
    Triangle::Scale(scaleFactor);
}

void TriangularPyramid::Display() const {
    cout << "The volume of the TriangularPyramid is : " << Volume() << endl;
    cout << "The height is: " << h << endl;
    Triangle::Display();
}

// 2) b. Cylinder
Cylinder::Cylinder() : Circle(0) {
    this->h = 0;
}

Cylinder::Cylinder(float h, float r) : Circle(r) {
    this->h = h;
}

string Cylinder::GetName3D() const {
    return name;
}

float Cylinder::Volume() const {
    float volume;
    volume = Circle::Area() * h;
    return volume;
}

void Cylinder::Scale(float scaleFactor) {
    h *= scaleFactor;
    Circle::Scale(scaleFactor);
}

void Cylinder::Display() const {
    cout << "The volume of the Cylinder is : " << Volume() << endl;
    cout << "The height is: " << h << endl;
    Circle::Display();

}

// 2) c. Sphere
Sphere::Sphere() : Circle(0) {
    this->r = 0;
}

Sphere::Sphere(float r) : Circle(r) {
    this->r = r;
}

string Sphere::GetName3D() const {
    return name;
}

float Sphere::Volume() const {
    float volume;
    volume = (4.0 / 3) * r * Circle::Area();
    return volume;
}

void Sphere::Scale(float scaleFactor) {
    Circle::Scale(scaleFactor);
}

void Sphere::Display() const {
    cout << "The volume of the Sphere is : " << Volume() << endl;
    Circle::Display();
}
