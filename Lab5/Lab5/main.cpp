#include "lab5.h"

int main() {
	Complex c1, c2, c3;
	c1.setReal(3.5);
	c1.setImaginary(2);
	c2.setReal(5.5);
	c2.setImaginary(7);
	c3 = c1.add(c2);
	c3 = add(c1, c2);
	c3 = c1 + c2;
	c3 = c1 - c2;
	std::cout << "Enter Complex number format a + bi" << std::endl;
	c1.read();
	std::cout << "Enter Complex number format a + bi" << std::endl;
	c2.read();
	std::cout << "Enter two Complex number format a + bi" << std::endl;
	std::cin >> c1 >> c2;
	c1.print();
	c2.print();
	c3.print();
	std::cout << c1 << c2 << c3;
	system("pause");
	return 0;
}