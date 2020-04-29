#pragma once

#include <iostream>
#include <complex>


using namespace std;

namespace solver{

	class RealVariable{
		public:
		double a;
		double b;	
		double c;
		
		/*double d;
		double e;
		double f;*/
		RealVariable(){
			a=0;
			b=1;
			c=0;
			/*d=0;
			e=0;
			f=1;*/
		}
	};
	class ComplexVariable{
		double re;
		double im;
	};

	double solve(RealVariable r);

	complex<double> solve(ComplexVariable c);

	//-------------------RealVariables------------

	RealVariable operator + (RealVariable r1, RealVariable r2);
	RealVariable operator + (double r1, RealVariable r2);
	RealVariable operator + (RealVariable r1, double r2);

	RealVariable operator - (RealVariable r1, RealVariable r2);
	RealVariable operator - (double r1, RealVariable r2);
	RealVariable operator - (RealVariable r1, double r2);
	RealVariable operator - (RealVariable r1);


	RealVariable operator * (RealVariable r1, RealVariable r2);
	RealVariable operator * (double r1, RealVariable r2);
	RealVariable operator * (RealVariable r1, double r2);


	RealVariable operator / (RealVariable r1, RealVariable r2);
	RealVariable operator / (double r1, RealVariable r2);
	RealVariable operator / (RealVariable r1, double r2);


	RealVariable operator ^ (RealVariable r1, RealVariable r2);
	RealVariable operator ^ (double r1, RealVariable r2);
	RealVariable operator ^ (RealVariable r1, double r2);

	RealVariable operator == (RealVariable r1, RealVariable r2);
	RealVariable operator == (double r1, RealVariable r2);
	RealVariable operator == (RealVariable r1, double r2);

	//-----------------------ComplexVariables-----------------

	ComplexVariable operator + (ComplexVariable c1, ComplexVariable c2);
	ComplexVariable operator + (double c1, ComplexVariable c2);
	ComplexVariable operator + (ComplexVariable c1, double c2);
	ComplexVariable operator + (complex<double> c1, ComplexVariable c2);
	ComplexVariable operator + (ComplexVariable c1, std::complex<double> c2);
	ComplexVariable operator + (complex<double> c1, int c2);
	ComplexVariable operator + (int c1, complex<double> c2);
	ComplexVariable operator + (complex<double> c1, double c2);
	ComplexVariable operator + (double c1, complex<double> c2);

	ComplexVariable operator - (ComplexVariable c1, ComplexVariable c2);
	ComplexVariable operator - (double c1, ComplexVariable c2);
	ComplexVariable operator - (ComplexVariable c1, double c2);
	ComplexVariable operator - (complex<double> c1, ComplexVariable c2);
	ComplexVariable operator - (ComplexVariable c1, complex<double> c2);
	ComplexVariable operator - (complex<double> c1, int c2);
	ComplexVariable operator - (int c1, complex<double> c2);
	ComplexVariable operator - (complex<double> c1, double c2);
	ComplexVariable operator - (double c1, complex<double> c2);
	ComplexVariable operator - (ComplexVariable c1);

	ComplexVariable operator * (ComplexVariable c1, ComplexVariable c2);
	ComplexVariable operator * (double c1, ComplexVariable c2);
	ComplexVariable operator * (ComplexVariable c1, double c2);
	ComplexVariable operator * (complex<double> c1, ComplexVariable c2);
	ComplexVariable operator * (ComplexVariable c1, complex<double> c2);
	ComplexVariable operator * (complex<double> c1, int c2);
	ComplexVariable operator * (int c1, complex<double> c2);
	ComplexVariable operator * (complex<double> c1, double c2);
	ComplexVariable operator * (double c1, complex<double> c2);

	ComplexVariable operator / (ComplexVariable c1, ComplexVariable c2);
	ComplexVariable operator / (double c1, ComplexVariable c2);
	ComplexVariable operator / (ComplexVariable c1, double c2);
	ComplexVariable operator / (complex<double> c1, ComplexVariable c2);
	ComplexVariable operator / (ComplexVariable c1, complex<double> c2);
	ComplexVariable operator / (complex<double> c1, int c2);
	ComplexVariable operator / (int c1, complex<double> c2);
	ComplexVariable operator / (complex<double> c1, double c2);
	ComplexVariable operator / (double c1, complex<double> c2);

	ComplexVariable operator ^ (ComplexVariable c1, ComplexVariable c2);
	ComplexVariable operator ^ (double c1, ComplexVariable c2);
	ComplexVariable operator ^ (ComplexVariable c1, int c2);
	ComplexVariable operator ^ (complex<double> c1, ComplexVariable c2);
	ComplexVariable operator ^ (ComplexVariable c1,complex<double> c2);
	

	ComplexVariable operator == (ComplexVariable c1, ComplexVariable c2);
	ComplexVariable operator == (double c1, ComplexVariable c2);
	ComplexVariable operator == (ComplexVariable c1, double c2);
	ComplexVariable operator == (complex<double> c1, ComplexVariable c2);
	ComplexVariable operator == (ComplexVariable c1, complex<double> c2);

	bool operator == (complex<double> c1, complex<double> c2);
	bool operator == (double c1, complex<double> c2);
	bool operator == (int c1, complex<double> c2);
	bool operator == (complex<double> c1, double c2);
	bool operator == (complex<double> c1, int c2);
	
	

}
