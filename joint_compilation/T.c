
double T(double s)
{
	double c=-15;
	double d=15;
	double z;
	double T;
	T=0;
	for (z=c;z<d;z+=accuracy)
	{
		T+=(rho(s,z)*accuracy);
	}
	
    return T;
}



