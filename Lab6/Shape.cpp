#include <sstream>
#include <array>
#include "Shape.h"


Shape::Shape() {

}

Shape::~Shape() {

}

// one line constructor definition
Circle::Circle(double x, double y, double r): x(x), y(y), r(r) {}

Circle::~Circle() {

}

double Circle::getX() const {
    return this->x;
}

double Circle::getY() const {
    return this->y;
}

double Circle::getR() const {
    return this->r;
}

std::string Circle::to_string() const {
    std::stringstream ss;
    ss << "Circle centered at " << "(" << this->getX() << ", " << this->getY() 
        << ") with radius " << this->getR();

    return ss.str();    
}

void Circle::centre_at(double x, double y) {
    this->x = x;
    this->y = y;
}

Rectangle::Rectangle(double x0, double x1, double y0, double y1) 
    : x0(x0), x1(x1), y0(y0), y1(y1) {}

Rectangle::~Rectangle(){}    

std::string Rectangle::to_string() const {
    double width = std::abs(x1 - x0);
    double height = std::abs(y1 - y0);

    std::ostringstream ss;
    ss << "Rectangle at [(" << x1 << ", " << y0 << "), (" 
       << x0 << ", " << y1 << ")] with width " << width << ", height " << height;

    return ss.str();
}



void Rectangle::centre_at(double x, double y) {
    double width = x1 - x0;
    double height = y1 - y0;
    
    double new_x0 = x - width / 2;
    double new_y0 = y - height / 2;
    double new_x1 = x + width / 2;
    double new_y1 = y + height / 2;
    
    x0 = new_x0;
    y0 = new_y0;
    x1 = new_x1;
    y1 = new_y1;
}

Triangle::Triangle(double x0, double x1, double x2, double y0, double y1, double y2)
                : x0(x0), x1(x1), x2(x2), y0(y0), y1(y1), y2(y2) {
    // ...
}

Triangle::~Triangle(){}

std::string Triangle::to_string() const {
    std::array<double, 3> sideLengths = this->calculateSideLengths();
    std::ostringstream ss;
    
    ss << "Triangle at [(" << this->x0 << this->y0 << "), (" << this->x1 << this->y1
        << "), " << this->x2 << this->y2 << ")] with side lengths " << sideLengths[0] 
        << ", " << sideLengths[1] << ", " << sideLengths[2];

    return ss.str();    
}

Point Triangle::centroid() {
    return { (this->x0 + this->x1 + this->x2) / 3.0,
     (this->y0 + this->y1 + this->y2) / 3.0 };

}

void Triangle::centre_at(double x, double y) {
    Point centroid = this->centroid();
    double xTrans = centroid.x - x;
    double yTrans = centroid.y - y;

    this->x0 -= xTrans;
    this->x1 -= xTrans;
    this->x2 -= xTrans;

    this->y0 -= yTrans;
    this->y1 -= yTrans;
    this->y2 -= yTrans;
}


std::array<double,3> Triangle::calculateSideLengths() const {
    std::array<double, 3> sideLengths;

    sideLengths[0] = std::sqrt(( this->x1 -  this->x0) * ( this->x1 -  this->x0) +
        ( this->y1 -  this->y0) * ( this->y1 -  this->y0));

    sideLengths[1] = std::sqrt(( this->x2 -  this->x1) * ( this->x2 -  this->x1) +
        ( this->y2 -  this->y1) * ( this->y2 -  this->y1));

    sideLengths[2] = std::sqrt(( this->x0 -  this->x2) * ( this->x0 -  this->x2) +
        ( this->y0 -  this->y2) * ( this->y0 -  this->y2));

    return sideLengths;    
}

