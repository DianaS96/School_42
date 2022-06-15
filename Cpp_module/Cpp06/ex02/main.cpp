#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    Base *result = NULL;
    int iSecret;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 3: */
    iSecret = rand() % 3;
    std::cout << "Random value: " << iSecret << std::endl;
    switch (iSecret)
    {
    case 0:
        result = new A();
        break;
    case 1:
        result = new B();
        return (result);
        break;
    case 2:
        result = new C();
        break;
    default:
        std::cout << "Que es esto???" << std::endl;
        break;
    }
    return (result);
}

void identify(Base* p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "(ptr) p points to object A" << std::endl;
    if (dynamic_cast<B *>(p) != NULL)
        std::cout << "(ptr) p points to object B" << std::endl;
    if (dynamic_cast<C *>(p) != NULL)
        std::cout << "(ptr) p points to object C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "(ref) p points to object A" << std::endl;
    }
    catch (std::exception &e) {}
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "(ref) p points to object B" << std::endl;
    }
    catch (std::exception &e) {}
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "(ref) p points to object C" << std::endl;
    }
    catch (std::exception &e) {}
}

int main() {
    Base *pPTR = generate();
    identify(pPTR);
    if (pPTR)
    {
        Base &pREF = *pPTR;
        identify(pREF);
    }
    if (pPTR)
        delete pPTR;
    return (0);
}