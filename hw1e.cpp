#include <iostream>

// The static instances of these classes are declared in the order that spells out "Hello, world!". 
// When the program starts, these static instances are constructed in the order of their declaration 
// So it prints "Hello, world!" before entering the function main()

struct H { H() { std::cout << 'H'; } };
struct e { e() { std::cout << 'e'; } };
struct l { l() { std::cout << 'l'; } };
struct o { o() { std::cout << 'o'; } };
struct space { space() { std::cout << ' '; } };
struct w { w() { std::cout << 'w'; } };
struct r { r() { std::cout << 'r'; } };
struct d { d() { std::cout << 'd'; } };
struct exclamation { exclamation() { std::cout << '!'; } };

static H h;
static e e1;
static l l1;
static l l2;
static o o1;
static space s;
static w w1;
static o o2;
static r r1;
static l l3;
static d d1;
static exclamation ex;

int main() {
    return 0;
}
