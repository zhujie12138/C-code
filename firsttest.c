//�������ָ���ֲ������������ȷ�� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//����������[min,max]�ֳ�N��С����������
#define N 50 

//���������number��
#define number 70*N 

#define rho0 10.0 

double rho(double r)
{
    return(rho0/(1+exp((r-6.38)/0.535)));
}

double frand(double a,double b)
{
	return (a+(b-a)*((double)rand())/RAND_MAX);//����[a,b]����ȷֲ������ 
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
    printf("д�����"); 
	}
	else{printf("δ���ļ�");}
	    
    return 0;
}
