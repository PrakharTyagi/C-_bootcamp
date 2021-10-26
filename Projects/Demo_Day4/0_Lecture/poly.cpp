#include <iostream>

class Polygon {
    protected:
        int width, height;
    public:
        void setValues(int x, int y) {
            width=x;
            height =y;
        }
        virtual int area() {
            return -1;
        }
};

class Rectangle : public Polygon {
    public:
        int area() {
            return width * height;
        }
};

class Triangle : public Polygon {
    public:
        int area() {
            return width * height / 2;
        }
};

int main () {
    Rectangle rect;
    Triangle tria;
    Polygon *pPoly = new Polygon;

    pPoly->setValues(5,8);
    std::cout << typeid(*pPoly).name() << ": " << pPoly->area() << std::endl;
    delete pPoly;

    pPoly=&rect;
    pPoly->setValues(10,10);
    std::cout << typeid(*pPoly).name() << ": " << pPoly->area() << std::endl;
    
    pPoly=&tria;
    pPoly->setValues(8,8);
    std::cout << typeid(*pPoly).name() << ": " << pPoly->area() << std::endl;
}