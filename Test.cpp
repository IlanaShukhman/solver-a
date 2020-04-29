#include <iostream>
#include <complex>
#include "doctest.h"
#include "solver.hpp"

using namespace std;
using namespace solver;


//7
TEST_CASE("operator + with realVariables"){
	RealVariable x;
	CHECK(solve(2+x == 10) == 8);
	CHECK(solve(x+2 == 10) == 8);
	CHECK(solve(10 == x+2) == 8);
	CHECK(solve(4+x+2 == 10) == 4);
	CHECK(solve(x+2+x == 4+x+5) == 7);
	CHECK(solve(x+(-1) == 2) == 3);
	
	CHECK_THROWS(solve(x+1 == x+2));
}

//7
TEST_CASE("operator + with complex"){
	ComplexVariable x;
	CHECK(solve(2+x == 10) == complex<double> (8,0));
	CHECK(solve(x+5i == 2*x+3i) == complex<double> (0,2));
	CHECK(solve(2+x+1i == 10) == complex<double> (8,-1));
	CHECK(solve(-10 == 1i+1i+1i+x-10) == -3i);
	CHECK(solve(4i+x+2 == 4i+x+x+2) == 0.0);
	CHECK(solve(x+(-1i) == 2 + 5i) == complex<double> (2,6));
	
	CHECK_THROWS(solve(2i+x+2 == 2i+x+3));

}


//9
TEST_CASE("operator - with realVariables"){
	RealVariable x;
	CHECK(solve(2 + x == 4 - x) == 1);
	CHECK(solve(-1+x == x-1+x) == 0); 
	CHECK(solve(x-x == x+2) == -2);
	CHECK(solve(x+x-2 == 3) == 2.5);
	CHECK(solve(-x == -5) == 5.0);
	CHECK(solve(5+x == 7-x) == 1);
	CHECK(solve(x-(-1) == x+ 5 -7 +x) == 3);
	CHECK(solve(-(-x) == 0 ) == 0 );
	
	CHECK_THROWS(solve(x-1 == x-2));




}
//8
TEST_CASE("operator - with complex"){
	ComplexVariable x;
	CHECK(solve(2-x+1i == x+5+6i-3) == -2.5i);
	CHECK(solve(2-x+2i == 0) == complex<double> (2,2));
	CHECK(solve(0 == 2-x+2i) == complex<double> (2,2));
	CHECK(solve(2-1i == x) == complex<double>(2,-1));
	CHECK(solve(x - 1 == 1i) == complex<double>(1,1));
	CHECK(solve(x-(-1i) == x+ 5 -7i + 8i +x) == -5.0);
	CHECK(solve(-(-x) == 0.0 ) == 0.0 );

	CHECK_THROWS(solve(x-1i == x-2i));


	
}
//10
TEST_CASE("operator * with realVariables"){
	RealVariable x;
	CHECK(solve(x*1 == 0) == 0);
	CHECK(solve(5*x == 0) == 0);
	CHECK(solve(2 + x == 4 - x) == 1);
	CHECK(solve(-1+x == x-1+x) == 0); 
	CHECK(solve(x-x == x+2) == -2);
	CHECK(solve(3*(-x-7)+1==8*x) == 2);
	CHECK(solve(2*(x+3) == 8*(2*x-6)) + 12 == 3);
	CHECK(solve(8*x-5*x == -6) == -2);

	CHECK_THROWS(solve(x*0 == 1));
	CHECK_THROWS(solve((x+1)*(x^2) ==0));
	CHECK_THROWS(solve((x+1)*(x+1)*(x+1) ==0));

}
//8
TEST_CASE("operator * with complex"){
	ComplexVariable x;
	
	CHECK(solve(x*1 == 1i+1) == complex<double> (1,1));
	CHECK(solve((2+1i)*2*x == 1) == complex<double> (0.25,-0.5));	
	CHECK(solve((1+1i)*(2*x+4i) == 4-4i) == 4.0);
	CHECK(solve((3+5i)*(x-5i) == 34) == 3.0);
	CHECK(solve((x+5i)*(x-5i) == 34) == 3.0);
	CHECK(solve((5+5i-2*x)*(3*x+2i) == complex<double> (-1,21)) == 1.0);

	CHECK_THROWS(solve((1i+x)*0 == 1));
	CHECK_THROWS(solve((x+1)*(x^2) ==0));

}

//8
TEST_CASE("operator / with realVariables"){
	RealVariable x;
	CHECK(solve(x/2 == 0.5) == 1);
	CHECK(solve(x/5 -1 == -1) == 0); 
	CHECK(solve(x/6 == x-5) == 6);
	CHECK(solve(2 + x/4 * 4 == 8) == 6);
	CHECK(solve((1/3)*x+(1/4)*x ==1) == 12/7);
	CHECK(solve(1/1 == x/1) == 1);
	CHECK(solve((x^2)/2+x/1 == 2) == 2);


	CHECK_THROWS(solve(x/0 == 0));
}

//8
TEST_CASE("operator / with complex"){
	ComplexVariable x;
	CHECK(solve((2*x-2i-5*x+3*x)/2 == x) == -1i);
	CHECK(solve((x+1i)/(2*x+2i) == x/2) == 1.0);
	CHECK(solve((5*x+5i)/(3+4i) == 2-1i) == 2.0);	
	CHECK(solve((x+1i)/(1i+x) == x) == 1.0);
	CHECK(solve((1/x) == 0.5) == 2.0);


	CHECK_THROWS(solve((x+1i)/(2*x+2i) == 1));
	CHECK_THROWS(solve((x+2i)/0 == 0));	
	CHECK_THROWS(solve(1/(x+1i) == 0));
	

}

//11
TEST_CASE("operator ^ with realVariables"){
	RealVariable x;
	CHECK(solve((x^2)==1) == 1);
	CHECK(solve((x^1)==5) == 5);
	CHECK(solve(5==(x^1)) == 5);
	CHECK(solve((x^2)-1 == 0) == 1);
	CHECK(solve(((x+1)^2) == 0 ) == -1);
	CHECK(solve(x*x == (x^2) +x) == 0);


	CHECK_THROWS(solve((x^0)==5));
	CHECK_THROWS(solve((x^4)==5));
	CHECK_THROWS(solve((x^2)==-16));
	CHECK_THROWS(solve((2^x)==1));
	CHECK_THROWS(solve((x^-1)==1));
	CHECK_THROWS(solve(((x+1)^3) ==0));
}
//8
TEST_CASE("operator ^ with complex"){
	ComplexVariable x;
	CHECK(solve((x+1i)^2 == 15+8i) == 4.0);
	CHECK(solve((x+1i)^1 == 2*x-1i) == 2i);
	CHECK(solve((x^2) == -16) == 4i);
	CHECK(solve(x*x == (x^2) +x) == 0.0);
		
	CHECK_THROWS(solve(((x+2i)^0)==5));
	CHECK_THROWS(solve(((x+1i)^4) == 0));
	CHECK_THROWS(solve(((x+1i)^-1) == 0));
	CHECK_THROWS(solve((2^x) == 1));

}
//14
TEST_CASE("General equations"){
	RealVariable x;
	ComplexVariable y;
	CHECK(solve(x^2 + 2*x + 1 == 0) == -1);
	CHECK(solve(x^2 -3*x == -2) == 1);
	CHECK(solve(((x+1)^2) + (x+1) == 0) ==-1);
	CHECK(solve(2*x+7-5*x-12 == -8*x+3) == 8/5);
	CHECK(solve(((1-2*x)^2) == (2*x-1)) == 0.5);	
	CHECK(solve(x+2*x/4 == 0) == 0);

	CHECK_THROWS(solve((x^2)+x+1 == 0));
	
	


	CHECK(solve((y+2i)*(1+1i) == 20+2*y+y*1i) == 4.0);
	CHECK(solve((y^2) == -3+4i) == complex<double>(1,2));
	CHECK(solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == 4.0);
	CHECK(solve((y^2) +4*y+2i == 2.0+4*y*1i +(y^2)) == 0.5);
	CHECK(solve(y+5i == 2*y+3i) == 2i);
	CHECK(solve((y+1i)*(y+2i) == -2.0) == 0.0);
	CHECK(solve((y^2)+1.0 ==0) == -1i);


}



