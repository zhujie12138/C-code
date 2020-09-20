#include <stdio.h>
#include <math.h>
#define pi 3.141592653

int main()
{
	double x[100],y[100];
	int i;
	FILE *fp=fopen("cosine","w");
	for (i=0;i<100;i++)
	{
		x[i]=2*pi/99*i;
		y[i]=sin(x[i]);
		fprintf(fp,"%.4f\t%.4f\n",x[i],y[i]);
	}
	fclose(fp);
}
