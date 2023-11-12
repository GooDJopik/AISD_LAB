#include "Matrix.h"
#include<iostream>
using namespace std;
using namespace matrix;

int main() {
	setlocale(LC_ALL, "rus");
	Matrix<complex<double>> a1(3, 3, complex<double>(1.0, 1.0));
	Matrix<int>a2(3, 3, 4, 1);
	/*Matrix<complex<double>> b2(1, 3, complex<double>(2.0, 2.0));
	Matrix<complex<double>> c3(1, 3, complex<double>(3.0, 3.0));*/
	cout << a2<<"\n";
	cout << a2.trace()<<"\n" << "\n";
	Matrix<float>a(1, 3, 1.2);
	Matrix<float>b(1, 3, 2.4);
	Matrix<float>c(1, 3, 3.5);
	cout << a;
	cout << b;
	cout << c<< "\n";
	cout<<a1.trace()<< "\n" << "\n";
	bool coplanar = checking_for_coplanarity(a, b, c);
	cout << coplanar;
	a = a * 2.0f;
	a = 2.0f *a ;
	return 0;
}