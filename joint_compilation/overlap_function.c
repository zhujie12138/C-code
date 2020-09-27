//绘制重叠函数函数
#include <stdio.h>
#include <math.h>



#define accuracy 0.1

#define rho0 0.1693
#define R 6.38
#define a 0.535
#define rho(s,z) rho0/(1+exp((sqrt(s*s+z*z)-R)/a))
#define cross_section 4.2 

double T(double s);
double overlap(double b);





int main()
{
	FILE *fp1=fopen("overlap.txt","w");
	FILE *fp2=fopen("num_of_coll.txt","w");
	double b;
	for (b=0;b<20;b+=0.2)
	{
		fprintf(fp1,"%.4f\t%.4f\n",b,overlap(b));
		fprintf(fp2,"%.4f\t%.4f\n",b,cross_section*overlap(b));
	}
	fclose(fp1);
	fclose(fp2);
	printf("ok");
	return 0;
}

