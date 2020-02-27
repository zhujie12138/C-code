//计算定积分 y=sqrt(x)
#include <stdio.h>
#include <math.h>

#define accuracy 0.00001
#define f(x) sqrt(x)

 

int main(){
	double a=0;
	double b=1;
	double x;
	double integral=0;
	for (x=a;x<b;x+=accuracy)
	{
		integral+=(f(x)*accuracy);
	}
	printf("%.4f",integral);

    return 0;
}
