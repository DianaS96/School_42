#include "whatever.hpp"

int main(void) {
    std::cout << "-----------------GIVEN TESTS-----------------" << std::endl;    
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "-----------------TEST1(SWAP + MAX, int)-----------------" << std::endl;
    int a1 = 10;
    int b1 = 42;
    std::cout << "Before swap: a1 = " << a1 << "; b1 = " << b1 << std::endl;
    std::cout << "Min: " << min(a1, b1) << std::endl;
    std::cout << "Max: " << max(a1, b1) << std::endl;
    swap(a1, b1);
    std::cout << "After swap: a1 = " << a1 << "; b1 = " << b1 << std::endl;

    std::cout << "-----------------TEST2(SWAP + MIN, float)-----------------" << std::endl;
    float pi = 3.14159;
    float e = 2.71828;
    std::cout << "Before swap: pi = " << pi << "; e = " << e << std::endl;
    std::cout << "Min: " << min(pi, e) << std::endl;
    std::cout << "Max: " << max(pi, e) << std::endl;
    swap(pi, e);
    std::cout << "After swap: pi = " << pi << "; e = " << e << std::endl;

    std::cout << "-----------------TEST3(SWAP, str)-----------------" << std::endl;
    std::string smile = "Smile";
    std::string heart = "Heart";
    std::cout << "Before swap: smile = " << smile << "; heart = " << heart << std::endl;
    swap(smile, heart);
    std::cout << "After swap: smile = " << smile << "; heart = " << heart << std::endl;

    return (0);
}