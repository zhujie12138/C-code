//������������ָ���ֲ������ 
/*
f(x)=k*exp(-k*x);x>0
     0          ;x<0
F(x) is integral of f(x) from minus infinity to x
u=F(x)
x=F(-1)(u)=-log(1-frand())
*/
//�������������ָ���ֲ������������ȷ�� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//����������[min,max]�ֳ�N��С����������
#define N 1000 

//����[0,1)�������number�� 
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
	printf("д�����");
    }
	else{printf("δ���ļ�");}
	    
    return 0;
}
