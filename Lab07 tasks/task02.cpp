#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    private:
    string position;
    string color;
    float borderThickness;

    public:
    Shape(string p, string c, float bt) : position(p), color(c), borderThickness(bt) {};

    virtual void draw() {
        cout << "Drawing Shape." << endl;
    }
    virtual double calculateArea() {
        cout << "Area is inconclusive!" << endl;
    }
    virtual double calculatePerimeter() {
        cout << "Perimeter is inconclusive!" << endl;
    }

};

class Rectangle : public Shape {
    private:
    double length;
    double width;

    public:
    Rectangle (string p, string c, float bt, int l, int w)
    : Shape (p,c,bt), length(l), width(w) {}

    void draw() override {
        cout << "Drawing Rectangle." << endl;
    }
    double calculateArea() override {
        return length*width;
    }
    double calculatePerimeter() override {
        return 2*(length + width);
    }

};

class Circle : public Shape {
    private:
    double radius;
    const double pi = 3.14;

    public:
    Circle (string p, string c, float bt, double r)
    : Shape (p, c, bt), radius(r) {}; 

    void draw() override {
        cout << "Drawing Circle." << endl;
    }
    double calculateArea() override {
        return pi*radius*radius;
    }
    double calculatePerimeter() override {
        return 2*pi*radius;
    }


};

class Triangle : public Shape {
    private:
    double a,b,c; 

    public:
    Triangle (string p, string c, float bt, double s1, double s2, double s3)
    : Shape (p, c, bt), a(s1), b(s2), c(s3)  {};

    void draw() override {
        cout << "Drawing Triangle." << endl;
    }
    double calculateArea() override {
        double s = (a+b+c)/2;
        return sqrt( s * (s-a) * (s-b) * (s-c) );
    }
    double calculatePerimeter() override {
        return a+b+c;
    }

}; 

int main() {
     
    Rectangle rectangle("Top-left-corner", "Blue", 2.0, 5, 3);
    Circle circle("Center", "Red", 1.5, 4);
    Triangle triangle("Bottom-right", "Green", 2.5, 3, 4, 5);
 
    // Rectangle
    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << endl;
    cout << endl;
 
    // Circle
    circle.draw();
    cout << "Circle Area: " <<  circle.calculateArea() << endl;
    cout << "Circle Perimeter: " <<  circle.calculatePerimeter() << endl;
    cout << endl;
 
    // Triangle 
    triangle.draw();
    cout << "Triangle Area: " << triangle.calculateArea() << endl;
    cout << "Triangle Perimeter: " << triangle.calculatePerimeter() << endl;
    cout << endl;
    return 0;
     
}