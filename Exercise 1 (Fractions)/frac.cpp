// Implementation file for class FractionType
#include <iostream>
#include "frac.h"
#include <stdlib.h>
using namespace std;
void FractionType::Initialize(int numerator, int denominator)
// Function: Initialize the fraction
// Pre:  None
// Post: numerator is stored in num; denominator is stored in 
//       denom
{
  num = numerator;
  denom = denominator;
}
int FractionType::NumeratorIs()
// Function: Returns the value of the numerator
// Pre:  Fraction has been initialized
// Post: numerator is returned
{
  return num;
}
int FractionType::DenominatorIs()
// Function: Returns the value of the denominator
// Pre:  Reaction has been initialized 
// Post: denominator is returned
{
  return denom;
}  

bool FractionType::IsZero()
// Function: Determines if fraction is zero
// Pre:  Fraction has been initialized
// Post: Returns true if numerator is zero
{
  return (num == 0);
}

bool FractionType::IsNotProper()
// Function: Determines if fraction is a proper fraction
// Pre:  Fraction has been initialized
// Post: Returns true if num is greater than or equal to denom
{
  return (abs(num) >= abs(denom));
}

int FractionType::ConvertToProper()
// Function: Converts the fraction to a whole number and a 
//       fractional part
// Pre:  Fraction has been initialized, is in reduced form, and
//       is not a proper fraction
// Post: Returns num divided by denom
//       num is original num % denom; denom is not changed
{
  int result;
  result = num / denom;
  num = num % denom;
  return result;
}
void FractionType::print(){
	cout << num << "/" << denom << endl;
}
int FractionType::findGCD(int a, int b){
	return b == 0 ? a : findGCD(b, a % b);
}
void FractionType::reduce(){
	int GCD = findGCD(num,denom);
	num = num/GCD;
	denom = denom/GCD;
}

FractionType FractionType::operator+(const FractionType& addend)
{
	FractionType frac;
	if(denom != addend.denom){
		frac.num = (num*addend.denom) + (addend.num*denom);
		frac.denom = denom*addend.denom;
	}
	else{
		frac.denom = denom;
		frac.num = num + addend.num;
	}
	return frac;
}

FractionType FractionType::operator-(const FractionType& subend){
	FractionType frac;
	if(denom != subend.denom){
		frac.num = (num*subend.denom) - (subend.num*denom);
		frac.denom = denom*subend.denom;
	}
	else{
		frac.denom = denom;
		frac.num = num - subend.num;
	}
	return frac;
}

FractionType FractionType::operator*(const FractionType& multiend){
	FractionType frac;
	frac.num = num*multiend.num;
	frac.denom = denom*multiend.denom;
	return frac;
}

FractionType FractionType::operator/(const FractionType& divend){
	FractionType frac;

	frac.num = num * divend.denom;
	frac.denom = denom*divend.num;
	return frac;
}


