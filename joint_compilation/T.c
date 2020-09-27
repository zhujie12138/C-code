#include "function.h"


#define rho0 0.1693
#define R 6.38
#define a 0.535
#define rho(s,z) rho0/(1+exp((sqrt(s*s+z*z)-R)/a))

#define cross_section 4.2 
#define accuracy 0.1
double T(double s)
{
	double c=-15;
	double d=15;
	double z;
	double T;
	T=0;
	for (z=c;z<d;z+=accuracy)
	{
		T+=(rho(s,z)*accuracy);
	}
	
    return T;
}


 
