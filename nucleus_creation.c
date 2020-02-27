/*my program about the number of participants in a monte carlo event of Au-Au collisions
woods-saxon distribution:rho(r)=rho0/(1+exp((r-R)/a)),rh0;R;a;
so,distribution of r is 4*pi*r*r*rho(r);
   distribution of theta is 0.5*sin(theta);
   distribution of phi is 1/(2*pi)
rand() create a random in [0,RAND_MAX] 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define pi 3.1416
#define rho0 0.1693
#define R 6.38
#define a 0.535
#define f(r) 4*pi*r*r*rho0/(1+exp((r-R)/a))

#define N 197//Au nucleus

double frand();
double randr();
double randtheta();
double randphi();


int main()
{
	FILE *fp=fopen("nucleus_creation.txt","w");
	srand((unsigned)time(NULL));
	double r,theta,phi;
	double x,y;
	int i;
	for (i=0;i<N;i++)
	{
		r=randr();
		theta=randtheta();
		phi=randphi();
		x=r*sin(theta)*cos(phi);
		y=r*sin(theta)*sin(phi);
		fprintf(fp,"%.4f\t%.4f\n",x,y);
	} 
	fclose(fp);
	printf("ok");
}















double frand()
{
	return ((double)rand())/RAND_MAX;
}

double randr()//ARM
{
	double r,f;
	while(1)
	{
		r=frand()*15;
		f=frand()*54.2;
		if (f<=f(r))
		{return r;}
	}	
}

double randtheta()//ITM
{
	double f;
	f=frand();
	return acos(1-2*f);	
}

double randphi()
{
	return frand()*2*pi;
}



