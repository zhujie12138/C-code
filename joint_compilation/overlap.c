#include "function.h"
#include <math.h>


#define rho0 0.1693
#define R 6.38
#define a 0.535
#define rho(s,z) rho0/(1+exp((sqrt(s*s+z*z)-R)/a))

#define cross_section 4.2 
#define accuracy 0.1
double overlap(double b)
{
	double xi=-10-b;
	double xf=10+b;
	double yi=-10;
	double yf=10;
	double overlap=0;
	double x,y;
	
	for (x=xi;x<xf;x+=accuracy)
	{
		for (y=yi;y<yf;y+=accuracy)
		{
			overlap+=T(sqrt(x*x+y*y))*T(sqrt((x-b)*(x-b)+y*y))*accuracy*accuracy;
			
		}
	}
	return overlap;
}


