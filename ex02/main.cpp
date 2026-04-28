#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int randomNum = rand() % 3;

    if (randomNum == 0)
        return new A;
    else if (randomNum == 1)
        return new B;
    else 
        return new C;
}

void identify(Base* p) {
    if (!p)
        return;
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception& e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception& e) {} 
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return ;
    } catch (std::exception& e) {}
}

int main() {
    srand(time(0));

    Base *base_ptr = generate();
    Base &base_ref = *base_ptr;
    identify(base_ptr);
    identify(base_ref);
    delete base_ptr;

    return (0);
}