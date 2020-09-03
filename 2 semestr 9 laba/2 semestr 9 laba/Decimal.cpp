#include "Decimal.h"
Decimal::Decimal(float a, float b)
{
	this->a = a;
	this->b = b;
}
int Decimal::toInt()
{
	return (int((this->a) / (this->b)));
}