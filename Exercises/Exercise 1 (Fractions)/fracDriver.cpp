// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "frac.h"
using namespace std;
int main()
{

	// ADDITION
	FractionType add1;
	FractionType add2;
	add1.Initialize(10, 12);
	add2.Initialize(5, 6);
	FractionType addRes = add1 + add2;
	cout << "10/12 + 5/6 = ";
	addRes.print();

	// SUBTRACTION
	FractionType subtract1;
	FractionType subtract2;
	subtract1.Initialize(10, 12);
	subtract2.Initialize(5, 6);
	FractionType subtractRes = subtract1 - subtract2;
	cout << "10/12 - 5/6 = ";
	subtractRes.print();

	// MULTIPLICATION
	FractionType multiply1;
	FractionType multiply2;
	multiply1.Initialize(10, 12);
	multiply2.Initialize(5, 6);
	FractionType multiplyRes = multiply1 * multiply2;
	cout << "10/12 * 5/6 = ";
	multiplyRes.print();

	// DIVISION
	FractionType divide1;
	FractionType divide2;
	divide1.Initialize(10, 12);
	divide2.Initialize(5, 6);
	FractionType divideRes = divide1 / divide2;
	cout << "10/12 / 5/6 = ";
	divideRes.print();


	// SIMPLEST FORM
	cout << endl << "In simplest form:" << endl;

	addRes.reduce();
	cout << "10/12 + 5/6 = ";
	addRes.print();

	subtractRes.reduce();
	cout << "10/12 - 5/6 = ";
	subtractRes.print();

	multiplyRes.reduce();
	cout << "10/12 * 5/6 = ";
	multiplyRes.print();

	divideRes.reduce();
	cout << "10/12 / 5/6 = ";
	divideRes.print();
}
