#include "Point.hpp"

int main( void ) {
	std::cout << "----------------------Test1----------------------" << std::endl;
	Point A(0, 0), B(0, 10), C(5, 0);
	Point const p1(0, 3);

	std::cout << "Triangle: " << \
	"A(" << A.getX() << ", " << A.getY() << "), " \
	"B(" << B.getX() << ", " << B.getY() << "), " \
	"C(" << C.getX() << ", " << C.getY() << ")" << std::endl;

	std::cout << "Point(" << p1.getX() << ", " << p1.getY() << ")" << std::endl; 
	if (bsp(A, B, C, p1) == true)
		std::cout << "Ok, the point is inside (or on the side of) the triangle" << std::endl;
	else
		std::cout << "No, the point is outside the triangle" << std::endl;

	std::cout << "----------------------Test2----------------------" << std::endl;
	Point A2(0, 0), B2(0, 10), C2(5, 0);
	Point const p2(2, 2);

	std::cout << "Triangle: " << \
	"A(" << A2.getX() << ", " << A2.getY() << "), " \
	"B(" << B2.getX() << ", " << B2.getY() << "), " \
	"C(" << C2.getX() << ", " << C2.getY() << ")" << std::endl;

	std::cout << "Point(" << p2.getX() << ", " << p2.getY() << ")" << std::endl; 
	if (bsp(A2, B2, C2, p2) == true)
		std::cout << "Ok, the point is inside (or on the side of) the triangle" << std::endl;
	else
		std::cout << "No, the point is outside the triangle" << std::endl;

	std::cout << "----------------------Test3----------------------" << std::endl;
	Point A3(1, 1.55), B3(2, 2), C3(3, 1.55);
	Point const p3(2, 1.545);

	std::cout << "Triangle: " << \
	"A(" << A3.getX() << ", " << A3.getY() << "), " \
	"B(" << B3.getX() << ", " << B3.getY() << "), " \
	"C(" << C3.getX() << ", " << C3.getY() << ")" << std::endl;

	std::cout << "Point(" << p3.getX() << ", " << p3.getY() << ")" << std::endl; 
	if (bsp(A3, B3, C3, p3) == true)
		std::cout << "Ok, the point is inside (or on the side of) the triangle" << std::endl;
	else
		std::cout << "No, the point is outside the triangle" << std::endl;

	std::cout << "----------------------Test4----------------------" << std::endl;
	Point A4(1, 1.55), B4(2, 2), C4(3, 1.55);
	Point const p4(2, 1.55);

	std::cout << "Triangle: " << \
	"A(" << A4.getX() << ", " << A4.getY() << "), " \
	"B(" << B4.getX() << ", " << B4.getY() << "), " \
	"C(" << C4.getX() << ", " << C4.getY() << ")" << std::endl;

	std::cout << "Point(" << p4.getX() << ", " << p4.getY() << ")" << std::endl; 
	if (bsp(A4, B4, C4, p4) == true)
		std::cout << "Ok, the point is inside (or on the side of) the triangle" << std::endl;
	else
		std::cout << "No, the point is outside the triangle" << std::endl;
	
	std::cout << "----------------------Test5----------------------" << std::endl;
	Point A5(1, 1.55), B5(1, 1.55), C5(3, 1.55);
	Point const p5(2, 1.55);

	std::cout << "Triangle: " << \
	"A(" << A5.getX() << ", " << A5.getY() << "), " \
	"B(" << B5.getX() << ", " << B5.getY() << "), " \
	"C(" << C5.getX() << ", " << C5.getY() << ")" << std::endl;

	std::cout << "Point(" << p5.getX() << ", " << p5.getY() << ")" << std::endl; 
	if (bsp(A5, B5, C5, p5) == true)
		std::cout << "Ok, the point is inside (or on the side of) the triangle" << std::endl;
	else
		std::cout << "No, the point is outside the triangle" << std::endl;
	
	return 0;
}