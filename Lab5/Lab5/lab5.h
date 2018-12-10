#pragma once
#pragma warning(disable: 4996)
#include <iostream>

//Classes
class Complex {
public:
	//constructors and destructor
	Complex();
	Complex(Complex &copy);
	~Complex();
	//setters
	void setReal(double real);
	void setImaginary(double imaginary);
	//getters
	double getReal() const;
	double getImaginary() const;
	//Functions
	Complex add(Complex &rhs);
	void read();
	void print();

private:
	double mReal;
	double mImaginary;
};

//Functions
Complex add(Complex &lhs, Complex &rhs);
Complex operator+(const Complex &lhs, const Complex &rhs);
Complex operator-(const Complex &lhs, const Complex &rhs);
std::istream &operator>>(std::istream &lhs, Complex &rhs);
std::ostream &operator<<(std::ostream &lhs, Complex &rhs);