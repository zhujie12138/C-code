//检测生成指定分布的随机数的正确性 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//将所测区间[min,max]分成N个小区间来计数
#define N 1000 

//生成[a,b]的均匀分布随机数number个 
#define a 10
#define b 100
#define frand() (a+(b-a)*((double)rand())/RAND_MAX)
#define number 10000*N 


int main(){
	double min=a,max=b;
	double interval=(max-min)/N;
    int i;
	int f[N]={0};
    
	srand((unsigned)time(NULL));
	
	for (i=0;i<number;i++)
	{
		f[(int)((frand()-min)/interval)]++;
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
