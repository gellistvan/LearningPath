#include <iostream>
#include <string>

// Class using delegating constructors
class Widget {
public:
    // Default constructor delegates to the main constructor
    Widget() : Widget(0, "default") {
        std::cout << "Widget default initialized with id = " << id
                  << " and name = " << name << std::endl;
    }

    // Parameterized constructor
    Widget(int id, std::string name) : id(id), name(name) {
        std::cout << "Widget initialized with id = " << id
                  << " and name = " << name << std::endl;
    }

private:
    int id;
    std::string name;
};

// Base class with multiple constructors
class Base {
public:
    Base(int x) : value(x) {
        std::cout << "Base initialized with int: " << value << std::endl;
    }

    Base(std::string str) : value(std::stoi(str)) {
        std::cout << "Base initialized with string: " << value << std::endl;
    }

protected:
    int value;
};

// Derived class inheriting constructors from Base
class Derived : public Base {
public:
    using Base::Base;  // Inherits all constructors from Base

    void display() const {
        std::cout << "Derived value: " << value << std::endl;
    }
};

int main() {
    // Testing delegating constructors
    Widget w1;       // Uses default constructor which delegates
    Widget w2(2, "Advanced Widget");

    // Testing inherited constructors
    Derived d1(10);  // Uses Base(int)
    d1.display();

    Derived d2("42");  // Uses Base(std::string)
    d2.display();

    return 0;
}
