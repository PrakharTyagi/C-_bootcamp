#include <iostream>

class A {
public:
    //virtual void f() = 0;
    /*virtual*/ ~A() { 
        std::cout << "doing nothing!" << std::endl;
    }
};
class B : public A {
    char *p = new char();
    //void f(){}
public:
    ~B(){ 
            std::cout << "cleaning up!" << std::endl;
            delete p; 
        }
};
int main() {
    A *pA= new B;
    delete pA;
    std::cout << " ----- " << std::endl;
    B b;
    return 0;
}


