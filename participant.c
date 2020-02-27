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
#define d0 sqrt(4.2/pi)

double frand();
double randr();
double randtheta();
double randphi();
int num_of_part(double b);


int main()
{
	srand((unsigned)time(NULL));
	FILE *fp=fopen("participant.txt","w");
	double b;
	double participant;
	int i;
	for (b=0.0;b<20.0;b++)
	{
		participant=0.0;
		for (i=0;i<5000;i++)
		{
			participant+=num_of_part(b);
		}
		fprintf(fp,"%.2f\t%.2f\n",b,participant/i);
	}
	fclose(fp);
	
	return 0;
}





int num_of_part(double b)
{
	double xA[N],yA[N],xB[N],yB[N];
	int i,j;
	double r,theta,phi;
	//creat two nuclei
	for (i=0;i<N;i++)
	{
		r=randr();
		theta=randtheta();
		phi=randphi();
		xA[i]=r*sin(theta)*cos(phi);
		yA[i]=r*sin(theta)*sin(phi);
	}	
	for (j=0;j<N;j++)
	{
		r=randr();
		theta=randtheta();
		phi=randphi();
		xB[j]=r*sin(theta)*cos(phi)+b;
		yB[j]=r*sin(theta)*sin(phi);
	}
	//count the participants
	int participant=0;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if ((xA[i]-xB[j])*(xA[i]-xB[j])+(yA[i]-yB[j])*(yA[i]-yB[j])<d0*d0)
			{
				participant++;
				break;
			}
			
		}
	}
	
	for (j=0;j<N;j++)
	{
		for (i=0;i<N;i++)
		{
			if ((xA[i]-xB[j])*(xA[i]-xB[j])+(yA[i]-yB[j])*(yA[i]-yB[j])<d0*d0)
			{
				participant++;
				break;
			}
			
		}
	}
	return participant;
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



