#include "Rational2.h"
Rational::Rational(float b)
{
	this->b = b;
}
int Rational::toInt()
{
	return int(this->b);
}