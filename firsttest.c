//检测生成指定分布的随机数的正确性 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//将所测区间[min,max]分成N个小区间来计数
#define N 50 

//生成随机数number个
#define number 70*N 

#define rho0 10.0 

double rho(double r)
{
    return(rho0/(1+exp((r-6.38)/0.535)));
}

double frand(double a,double b)
{
	return (a+(b-a)*((double)rand())/RAND_MAX);//产生[a,b]间均匀分布随机数 
}

double myrand()
{
	double x,y,z;
	while (1)
	{
		x=frand(0,100);
		y=frand(0,rho0);
		z=rho(x);
		if (y<=z)
		{
			return x;
		}
	}
}

int main(){
	double min=0,max=10;
	double interval=(max-min)/N;
    int i;
	int f[N]={0};
	srand((unsigned)time(NULL));
	
	for (i=0;i<number;i++)
	{
		f[(int)((myrand()-min)/interval)]++;
	}
	
	
	FILE *fp=fopen("distribution.txt","w");
	if (fp){
	for (i=0;i<N;i++)
	{
		fprintf(fp,"%.4f\t%d\n",min+interval*(i+0.5),f[i]);
	}
	fclose(fp);
    printf("写入完毕"); 
	}
	else{printf("未打开文件");}
	    
    return 0;
}
