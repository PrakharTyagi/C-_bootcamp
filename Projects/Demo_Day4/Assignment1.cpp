#include <iostream>

class Shape {
protected:
        double width, height;
public:    
    virtual void print() = 0;
    virtual double perimeter() {
        return 1;
    }
    virtual double area()
    {
        return 1;
    }
    void setValues(int x, int y) {
            width=x;
            height =y;
        }
};

class Circle : public Shape {
public:
    Circle() = default;
    void print() {
        std::cout << "Circle is here" << std::endl;
    } 
   
};

class Triangle : public Shape {
public:
    Triangle() = default;
    void print() {
        std::cout << "Triangle is here" << std::endl;
    } 
    double area() {
            return width * height / 2;
        }
   
};


class Rectangle : public Shape {
public:
    Rectangle() = default;
    virtual void print() {
        std::cout << "Rectangle is here" << std::endl;
    }
     double area() {
            return width * height;
        }
};

class Square :  public Rectangle{
public:
    Square() = default;
    void print() {
        std::cout << "Square is here" << std::endl;
    }
    double area() {
            return width * height;
        }
};


}
