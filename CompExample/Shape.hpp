//
//  Shape.hpp
//  CompExample
//
//  Created by panqj on 4/13/24.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <iostream>

// Base class
class Shape {
public:
    virtual double area() const = 0; //Pure virtual function
    virtual void display() const = 0;
    virtual ~Shape() {}; //Virtual destructor for polymorphic behavior
};

//Derived class
class Circle: public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area () const override {
        return 3.14 * radius * radius;
    }
    void display() const override {
        std::cout << "Circle radius: " << radius << std::endl;
    }
};

//Derived class
class Rectangle: public Shape {
private:
    double width, length;
public:
    Rectangle(double w, double l) : width(w), length(l) {}
    double area() const override {
        return width * length;
    }
    void display() const override {
        std::cout << "Rectangle length and width: " << length << ", " << width << std::endl;
    }
};


#endif /* Shape_hpp */
