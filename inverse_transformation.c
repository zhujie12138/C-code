//反函数法生成指数分布随机数 
/*
f(x)=k*exp(-k*x);x>0
     0          ;x<0
F(x) is integral of f(x) from minus infinity to x
u=F(x)
x=F(-1)(u)=-log(1-frand())
*/
//下面测试下生成指定分布的随机数的正确性 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//将所测区间[min,max]分成N个小区间来计数
#define N 1000 

//生成[0,1)的随机数number个 
#define frand() ((double) rand()/(RAND_MAX+1))
#define number 1000*N 


int main(){
	double min=0,max=30;
	double interval=(max-min)/N;
    int i;
	int f[N]={0};
    
	srand((unsigned)time(NULL));
	
	for (i=0;i<number;i++)
	{
		f[(int)((-log(1-frand())-min)/interval)]++;
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
