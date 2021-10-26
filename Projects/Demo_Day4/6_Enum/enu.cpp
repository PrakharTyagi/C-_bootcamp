#include <iostream>

enum Mode {INT, DBL};
enum Type {A, B};

enum class MODE {INT, DBL};
enum class TYPE {A,B};

void printMode (Mode _m ){
    std::cout << "Mode is: " << _m << std::endl;
}

void printMode (MODE _m ){
    std::cout << "Mode is: " <<
    static_cast<std::underlying_type<MODE>::type>(_m) << std::endl;
}

int main () {
#define ENUM_CLASS 1
#if ENUM_CLASS
    MODE m = MODE::INT;
    TYPE t = TYPE::A;
#else
    Mode m = Mode::DBL;
    Type t = Type::B;
#endif

    printMode(m);

#if !ENUM_CLASS    
    if (m == t) { }
    switch (t) {
    case Mode::DBL:
        printMode(Mode::DBL);        
        break;
    case Mode::INT:
        printMode(Mode::INT);        
        break;    
    default:
        std::cout << "Nothing" << std::endl;
        break;
    }
#endif

    return 0;
}