#pragma once
#include"Number2.h"
using namespace std;
class Decimal:Number
{
private:
	float a, b;
public:
	virtual int toInt();
	Decimal(float a, float b);
};

