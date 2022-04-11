#pragma once
#include "Complex.h"


TComplex TComplex::operator * (const TComplex& num)
{
	TComplex result(*this);
	result.Re = Re * num.Re - Im * num.Im;
	result.Im = Re * num.Im + num.Re * Im;
	return result;
}

TComplex TComplex::operator + (const TComplex& num)
{
	TComplex result(*this);
	result.Re = Re + num.Re;
	result.Im = Im + num.Im;
	return result;
}

TComplex TComplex::operator-(const TComplex& num)
{
	TComplex result(*this);
	result.Re = Re - num.Re;
	result.Im = Im - num.Im;
	return result;
}

TComplex TComplex::operator / (const TComplex& num)
{
	TComplex result(*this);
	if (num.Im == 0 && num.Re == 0) throw "This problem was called by operator / Division by zero";
	result.Re = (Re * num.Re + Im * num.Im) / (num.Re * num.Re + num.Im * num.Im);
	result.Im = (num.Re * Im - Re * num.Im) / (num.Re * num.Re + num.Im * num.Im);

	return result;
}
TComplex& TComplex::operator=(const TComplex& num)
{
	this->Re = num.Re;
	this->Im = num.Im;
	return *this;

}

bool TComplex::operator==(const TComplex& num)
{
	if (this->Re == num.Re && this->Im == num.Im) return true;
	else return false;
}



std::ostream& operator<<(std::ostream& stream, const TComplex& num)
{
	stream << num.Re << ' ' << '+' << ' ' << num.Im << " * i";
	return stream;
}

std::istream& operator>>(std::istream& stream, TComplex& num)
{
	stream >> num.Re;
	stream >> num.Im;
	return stream;
}
