#include "Base.hpp"

Base::~Base() {}

Base *generate(void) {

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int i = std::rand() % 3;
    Base *base ;

    if (i == 0) {
        base = dynamic_cast<Base*>(new A);
    }
    else if (i == 1) {
        base = dynamic_cast<Base*>(new B);
    }
    else {
        base = dynamic_cast<Base*>(new C);
    }
    return base;
}

void identify(Base* p) {

    if (dynamic_cast<A*>(p)) {
        std::cout << "It's A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "It's B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "It's C" << std::endl;
    }
}

void identify(Base& p) {
        try 
        {
            A &a = dynamic_cast<A&>(p);
            std::cout << "It's A" << std::endl;
            (void)a;
        }
        catch (std::exception &e) 
        {
            try {
                B &b = dynamic_cast<B&>(p);
                std::cout << "It's B" << std::endl;
                (void)b;
            }
            catch (std::exception &e) {
                try {
                    C &c = dynamic_cast<C&>(p);
                    std::cout << "It's C" << std::endl;
                    (void)c;
                }
                catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
}

