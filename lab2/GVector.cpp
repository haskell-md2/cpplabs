#include "GVector.h"


GVector GVector::operator+(GVector b)
{
	return GVector(_x + b._x, _y + b._y);
}

GVector GVector::operator*(int scalar)
{
	return GVector(_x * scalar, _y * scalar);
}

