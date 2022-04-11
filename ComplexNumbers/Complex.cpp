#include "Complex.h"

constexpr auto PI = 3.141567;
TComplex::TComplex(double _Re , double _Im)
{
	Re = _Re;
	Im = _Im;
	Angle = 0;
}

TComplex::TComplex(const TComplex& p)
{
	Re = p.Re;
	Im = p.Im;
	Angle = p.Angle;
}

double TComplex::GetRe()
{
	return Re;
}

double TComplex::GetIm()
{
	return Im;
}

double TComplex::GetAngle()
{
	if (Re == 0) throw "Exception!! Real part of complex numper = 0";
	else
	{
		if (Re > 0 && Im >= 0)
		{
			Angle = atan(Im/Re);
		}
		else if (Re < 0 && Im >= 0)
		{
			Angle = PI - atan(abs(Im / Re));
		}
		else if (Re < 0 && Im < 0)
		{
			Angle = PI + atan(abs(Im / Re));
		}
		else if (Re > 0 && Im < 0)
		{
			Angle = 2 * PI - atan(abs(Im / Re));
		}
	}
	return Angle;
}

double TComplex::GetAngle(const TComplex&p)
{
	double _Angle = 0;
	if (p.Re == 0) throw "Exceprion!! Real part of complex numper = 0";
	else
	{
		if (p.Re > 0 && p.Im >= 0)
		{
			_Angle = atan(p.Im / p.Re);
		}
		else if (p.Re < 0 && p.Im >= 0)
		{
			_Angle = PI - atan(abs(p.Im / p.Re));
		}
		else if (p.Re < 0 && p.Im < 0)
		{
			_Angle = PI + atan(abs(p.Im / p.Re));
		}
		else if (p.Re > 0 && p.Im < 0)
		{
			_Angle = 2 * PI - atan(abs(p.Im / p.Re));
		}
	}
	return _Angle;
}

double TComplex::GetAbs(const TComplex& num)
{
	 return sqrt(num.Re * num.Re + num.Im * num.Im);
}

double TComplex::GetAbs()
{
	return sqrt(Re * Re + Im * Im);
}

TComplex TComplex::PowNZ(int Numb)
{
	TComplex result(*this);
	
	result.Angle = result.GetAngle(*this) * Numb;
  double abs = sqrt(Re * Re + Im * Im);

	abs = pow(abs, Numb);

	result.Re = cos(result.Angle) * abs;
	result.Im = sin(result.Angle) * abs;
	return result;

}

TComplex TComplex::PowQ(int numerator, int denumerator)
{

	TComplex result(*this);

	result.Angle = result.GetAngle(*this) * numerator;
	double abs = sqrt(Re * Re + Im * Im);

	abs = pow(abs, numerator);

	result.Re = cos(result.Angle) * abs;
	result.Im = sin(result.Angle) * abs;

	double q = static_cast<double>(1) / denumerator;
  abs = exp(log(abs) * q);

	result.Angle = result.Angle / denumerator;

	result.Re = cos(result.Angle) * abs;
	result.Im = sin(result.Angle) * abs;

	return result;
 
}

void TComplex::GetTrigForm(const TComplex& num)
{
	Angle = this->GetAngle();
	std::cout << GetAbs(num) << "*(" << " cos(" << Angle << ") + i*sin(" << Angle << ") )" << std::endl;
}

void TComplex::GetTrigForm()
{
	
	Angle = this->GetAngle();
	std::cout << GetAbs(*this) << "*(" << " cos(" << Angle << ") + i * sin(" << Angle << "))" << std::endl;
}

void TComplex::SetRe(double _Re)
{
	Re = _Re;
}

void TComplex::SetIm(double _Im)
{
	Im = _Im;
}

void TComplex::SetAngle(double _Angle)
{
	Angle = _Angle;
}


