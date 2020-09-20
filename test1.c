#include <stdio.h>
#include <math.h>
#define pi 3.141592653
#define rho0 0.1693
#define R 6.38
#define a 0.535

int main()
{
	double r=0,rho;
	int i;
	FILE *fp=fopen("distribution_of_r.txt","w");
	for (i=0;i<2000;i++)
	{
		r+=0.01;
		rho=4*pi*r*r*rho0/(1+exp((r-R)/a));
		
		fprintf(fp,"%.4f\t%.4f\n",r,rho);
	}
	fclose(fp);
}
