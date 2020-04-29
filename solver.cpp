#include <iostream>
#include <complex>
#include <cmath>
#include "solver.hpp"


using namespace std;
namespace solver{

	double solve(RealVariable r){
		double a=r.a, b=r.b, c=r.c;
		double ans;
		//cout << a <<" , " << b << " , " << c <<endl;
		if(a!=0){
			double b2= pow(b,2);
			if((b2)-4*a*c < 0){
				throw runtime_error("answer not a real number!");
			}
			else if((b2)-4*a*c == 0)
				return (-b/2*a);
			else{
				double delta =sqrt( (b2)-4*a*c );
				ans = (-b-delta)/2*a;

			}
		}
		else
			ans = -c/b;
		r.a=0;	
		r.b=1;
		r.c=0;
		
		return ans;
	}
	

	complex<double> solve(ComplexVariable c){
		return complex<double>(0,0);
	}
	
	//--------------------RealVariables--------------------
	//--------------------Operator + ----------------------
	RealVariable operator + (RealVariable r1, RealVariable r2){
		RealVariable x;
		x.a=r1.a+r2.a;
		x.b=r1.b+r2.b;
		x.c=r1.c+r2.c;
		return x;
	}
	RealVariable operator + (double r1, RealVariable r2){
		RealVariable x;
		x.a=r2.a;
		x.b=r2.b;
		x.c=r1+r2.c;
		return x;
	}
	RealVariable operator + (RealVariable r1, double r2){
		return r2+r1;
	}


	//--------------------Operator - ----------------------
	RealVariable operator - (RealVariable r1, RealVariable r2){
		RealVariable x;
		x.a=r1.a-r2.a;
		x.b=r1.b-r2.b;
		x.c=r1.c-r2.c;
		return x;
	}
	RealVariable operator - (double r1, RealVariable r2){
		RealVariable x;
		x.a=-r2.a;
		x.b=-r2.b;
		x.c=r1-r2.c;
		
		return x;
	}
	RealVariable operator - (RealVariable r1, double r2){
		RealVariable x;
		x.a=r1.a;
		x.b=r1.b;
		x.c=r1.c-r2;
		return x;
	}
	RealVariable operator - (RealVariable r1){
		RealVariable x;
		x.a=-r1.a;
		x.b=-r1.b;
		x.c=-r1.c;
		return x;
	}

	//--------------------Operator * ----------------------
	RealVariable operator * (RealVariable r1, RealVariable r2){
		if((r1.a>0 && (r2.a>0 || r2.b>0)) || (r2.a>0 && (r1.a>0 ||r1.b>0)))
			throw runtime_error("Cannot be more than x^2");
		RealVariable x;
		x.a=r1.a*r2.c + r1.b*r2.b + r1.c*r2.a;
		x.b=r1.b*r2.c + r2.b*r1.c;
		x.c=r1.c*r2.c;
		return x;
	}
	RealVariable operator * (double r1, RealVariable r2){
		RealVariable x;
		x.a=r1*r2.a;
		x.b=r1*r2.b;
		x.c=r1*r2.c;
		
		return x;
	}
	RealVariable operator * (RealVariable r1, double r2){
		return r2*r1;
	}


	//--------------------Operator / ----------------------
	RealVariable operator / (RealVariable r1, RealVariable r2){
		RealVariable x;
		x.a = r1.a;
		x.b = r1.b;
		x.c = r1.c;	
		
		/*x.d = r2.a;
		x.e = r2.b;
		x.f = r2.c;*/
		return x;
	}
	RealVariable operator / (double r1, RealVariable r2){
		RealVariable x;
		x.a = 0;
		x.b = 0;
		x.c = r1;
	
		/*x.d = r2.a;
		x.e = r2.b;
		x.f = r2.c;*/
		return x;
	}
	RealVariable operator / (RealVariable r1, double r2){
		RealVariable x;
		x.a = r1.a/r2;
		x.b = r1.b/r2;
		x.c = r1.c/r2;
		return x;
	}

	//--------------------Operator ^ ----------------------
	RealVariable operator ^ (RealVariable r1, RealVariable r2){
		if(r2.a > 0 || r2.b > 0 || r1.a > 0 || r2.c < 0 || r2.c > 2)
			throw runtime_error("not legal input!");
		RealVariable x;
		if(r2.c == 0){
			x.a=0;
			x.b=0;
			x.c=1;	
		}
		else if(r2.c == 1){
			return r1;
		}
		else{
			x.a = pow(r1.b,2);
			x.b = 2*r1.b*r1.c;
			x.c = pow(r1.c,2);
		}
		return x;
	}
	RealVariable operator ^ (double r1, RealVariable r2){
		if(r2.a>0 || r2.b>0)
			throw runtime_error("Not a legal input!");
		RealVariable x;
		x.a=0;
		x.b=0;
		x.c=r1;	
		return r1^r2;
	}
	RealVariable operator ^ (RealVariable r1, double r2){
		RealVariable x;
		x.a=0;
		x.b=0;
		x.c=r2;	
		return r1^x;
	}


	//--------------------Operator == ----------------------
	RealVariable operator == (RealVariable r1, RealVariable r2){
		/*if(r1.d != 0 || r1.e != 0 || r1.f != 1){
			RealVariable x;
			x.a=r1.d;
			x.b=r1.e;
			x.c=r1.f;
			r2*x;
			r1.d=0;
			r1.e=0;	
			r1.f=1;
		}
		if(r2.d != 0 || r2.e != 0 || r2.f != 1){
			RealVariable x;
			x.a=r2.d;
			x.b=r2.e;
			x.c=r2.f;
			r1*x;
			r2.d=0;
			r2.e=0;	
			r2.f=1;
		}*/
		return r2 - r1;
	}
	RealVariable operator == (double r1, RealVariable r2){
		return r2 - r1;
	}
	RealVariable operator == (RealVariable r1, double r2){
		return r2 - r1;
	}

	//---------------------------------ComplexVariables--------------------
	//--------------------Operator + ----------------------	
	ComplexVariable operator + (ComplexVariable c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (double c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (ComplexVariable c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (complex<double> c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (ComplexVariable c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (complex<double> c1, int c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (int c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (complex<double> c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator + (double c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}



	//--------------------Operator - ----------------------
	ComplexVariable operator - (ComplexVariable c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (double c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (ComplexVariable c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (complex<double> c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (ComplexVariable c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (complex<double> c1, int c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (int c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (complex<double> c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (double c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator - (ComplexVariable c1){
		ComplexVariable y;
		return y;
	}







	//--------------------Operator * ----------------------
	ComplexVariable operator * (ComplexVariable c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (double c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (ComplexVariable c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (complex<double> c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (ComplexVariable c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (complex<double> c1, int c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (int c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (complex<double> c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator * (double c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}










	//--------------------Operator / ----------------------
	ComplexVariable operator / (ComplexVariable c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (double c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (ComplexVariable c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (complex<double> c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (ComplexVariable c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (complex<double> c1, int c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (int c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (complex<double> c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator / (double c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}








	//--------------------Operator ^ ----------------------
	ComplexVariable operator ^ (ComplexVariable c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (double c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (ComplexVariable c1, int c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (complex<double> c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (ComplexVariable c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (complex<double> c1, int c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (int c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (complex<double> c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator ^ (double c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}








	//--------------------Operator == ----------------------
	ComplexVariable operator == (ComplexVariable c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator == (double c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator == (ComplexVariable c1, double c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator == (complex<double> c1, ComplexVariable c2){
		ComplexVariable y;
		return y;
	}
	ComplexVariable operator == (ComplexVariable c1, complex<double> c2){
		ComplexVariable y;
		return y;
	}



	bool operator == (complex<double> c1, complex<double> c2){
		return (real(c1) == real(c2) && imag(c1) == imag(c2));
	}
	bool operator == (double c1, complex<double> c2){
		return (c1 == real(c2));
	}
	bool operator == (complex<double> c1, double c2){
		return (c2 == real(c1));
	}
	bool operator == (int c1, complex<double> c2){
		return (c1 == real(c2));
	}
	bool operator == (complex<double> c1, int c2){
		return (c2 == real(c1));
	}




}
