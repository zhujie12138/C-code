//�������ָ���ֲ������������ȷ�� 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//����������[min,max]�ֳ�N��С����������
#define N 1000 

//����[a,b]�ľ��ȷֲ������number�� 
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
    printf("д�����"); 
	}
	else{printf("δ���ļ�");}
	    
    return 0;
}
