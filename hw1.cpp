#include <iostream>

class HelloWorldPrinter {
public:
    HelloWorldPrinter() {
        std::cout << "Hello, ";
    }
};

class WorldPrinter {
public:
    WorldPrinter() {
        std::cout << "world!" << std::endl;
    }
};

// Global objects
HelloWorldPrinter helloPrinter;
WorldPrinter worldPrinter;

int main() {
    return 0;
}
