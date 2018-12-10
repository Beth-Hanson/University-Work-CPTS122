#include "lab5.h"

Complex::Complex(){
	mReal = 0.0;
	mImaginary = 0.0;
}

Complex::Complex(Complex &copy){
	mReal = copy.getReal();
	mImaginary = copy.getImaginary();
}

Complex::~Complex(){

	std::cout << "destructor" << std::endl;
}

void Complex::setReal(double real){
	mReal = real;
}

void Complex::setImaginary(double imaginary){
	mImaginary = imaginary;
}

double Complex::getReal() const {
	return mReal;
}

double Complex::getImaginary() const {
	return mImaginary;
}

Complex Complex::add(Complex &rhs){
	Complex sum;
	sum.setReal(mReal + rhs.getReal());
	sum.setImaginary(mImaginary + rhs.getImaginary());
	return sum;
}

void Complex::read(){
	char trash;
	std::cin >> mReal >> trash >> mImaginary >> trash;
}

void Complex::print(){
	std::cout << mReal << " + " << mImaginary << "i" << std::endl;
}

Complex add(Complex &lhs, Complex &rhs){
	Complex sum;
	sum = lhs.add(rhs);
	return sum;
}

Complex operator+(const Complex &lhs, const Complex &rhs){
	Complex sum;
	sum.setReal(lhs.getReal() + rhs.getReal());
	sum.setImaginary(lhs.getImaginary() + rhs.getImaginary());
	return sum;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
	Complex dif;
	dif.setReal(lhs.getReal() - rhs.getReal());
	dif.setImaginary(lhs.getImaginary() - rhs.getImaginary());
	return dif;
}

std::istream & operator>>(std::istream & lhs, Complex & rhs){
	double real = 0.0, fake = 0.0;
	char trash;
	lhs >> real >> trash >> fake >> trash;
	rhs.setReal(real);
	rhs.setImaginary(fake);
	return lhs;
}

std::ostream & operator<<(std::ostream & lhs, Complex & rhs)
{
	lhs << rhs.getReal() << " + " << rhs.getImaginary() << "i" << std::endl;
	return lhs;
}
