//to calculate double integral on a square area
#include <stdio.h>
#include <math.h>

#define accuracy 0.01

#define f(x,y) (x)*(y)

 

int main(){
	double xi=0;
	double xf=1;
	double yi=0;
	double yf=1;
	double integral=0;
	double x,y;
	
	for (x=xi;x<xf;x+=accuracy)
	{
		for (y=yi;y<yf;y+=accuracy)
		{
			integral+=f(x+accuracy/2,y+accuracy/2)*accuracy*accuracy;
		}
	}
	
	printf("%.4f",integral);

    return 0;
}
