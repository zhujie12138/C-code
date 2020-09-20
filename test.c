/*for one Au-Au collison event(given impact parameter b), record positon for each nucleon*/

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)



//将所测区间[min,max]分成N个小区间来计数
#define N 1000
//生成均匀分布随机数number个 
#define number 10000*N 
double rand1();

int main(){
	double min=0,max=1;
	double interval=(max-min)/N;
    int i;
	int f[N]={0};
    
	srand((unsigned)time(NULL));
	
	for (i=0;i<number;i++)
	{
		f[(int)((rand1()-min)/interval)]++;
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

double rand1()  
{
    long random=-rand();
    long *idum=&random;
	int j;
	long k;
	static long iy = 0;
	static long iv[NTAB];
	double temp;

	if (*idum <= 0 || !iy)
	{
		if (-(*idum) < 1)
		{
			*idum = 1;
		}
		else
		{
			*idum = -(*idum);
		}
		for (j = NTAB + 7; j >= 0; j--)
		{
			k = (*idum) / IQ;
			*idum = IA * (*idum - k * IQ) - IR * k;
			if (*idum < 0)
			{
				*idum += IM;
			}
			if (j < NTAB)
			{
				iv[j] = *idum;
			}

		}

		iy = iv[0];
	}
	k = (*idum) / IQ;
	*idum = IA * (*idum - k * IQ) - IR * k;
	if (*idum < 0)
	{
		*idum += IM;
	}
	j = iy / NDIV;
	iy = iv[j];
	iv[j] = *idum;
	if ((temp = AM * iy) > RNMX)
	{
		return RNMX;
	}
	else
	{
		return temp;
	}
}

