#pragma once
#include <iostream>
#include <fstream>

using namespace std;


class Complex {

	
public:
	Complex();                                         
	Complex(const Complex &c);                         
	Complex(double _re, double _im);                   
	Complex(double d);                                 

	~Complex();                                        

	void output();                                     
	Complex Add(const Complex& c);                     

	
	Complex& operator=(const Complex& c);              

	bool operator==(const Complex& c);                 

	Complex operator+(const Complex& c);               
	Complex operator-(const Complex& c);              
	Complex operator*(const Complex& c);               
	Complex operator/(const Complex& c);               

	

private:
	double re;                                         
	double im;                                        

};                                                   

Complex::Complex() {
	re = 0.0;
	this->im = 0.0;
}


Complex::Complex(const Complex &c) {
	re = c.re;
	im = c.im;
}


Complex::Complex(double _re, double _im) : re(_re), im(_im) {  }


Complex::Complex(double _re) {
	re = _re;
	im = 0.0;
}


Complex::~Complex() {
	re = 0.0;
	im = 0.0;
}




Complex& Complex::operator=(const Complex& c) {
	(*this).re = c.re;
	im = c.im;
	return *this;
}


bool Complex::operator==(const Complex& c) {
	bool res;
	if ((c.re == re)&&(c.im == im)){
		res = true;
	} else { res = false; }
	return res;
}




Complex Complex::Add(const Complex& c) {
	Complex res;
	res.re = re + c.re;
	res.im = im + c.im;
	return res;
}


Complex Complex::operator+(const Complex& c) {
	Complex res;
	res.re = re + c.re;
	res.im = im + c.im;
	return res;
}


Complex Complex::operator-(const Complex& c) {
	Complex res;
	res.re = re - c.re;
	res.im = im - c.im;
	return res;
}


Complex Complex::operator*(const Complex& c) {
	Complex res;
	res.re = re * c.re - im * c.im;
	res.im = re * c.im + c.re*im;
	return res;
}


Complex Complex::operator/(const Complex& c) {
	Complex res;
	res.re = (re * c.re + im * c.im) / ((c.re*c.re)+(c.im*c.im));
	res.im = ((im*c.re) - (re*c.im)) / ((c.re*c.re) + (c.im*c.im));
	return res;
}




void Complex::output() {
	cout << re;
	if (im > 0) { cout << " + " << im << "i"; }
	else if (im < 0) { cout << " - " << -im << "i"; }
	cout << endl;
}