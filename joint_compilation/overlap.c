
double overlap(double b)
{
	double xi=-10-b;
	double xf=10+b;
	double yi=-10;
	double yf=10;
	double overlap=0;
	double x,y;
	
	for (x=xi;x<xf;x+=accuracy)
	{
		for (y=yi;y<yf;y+=accuracy)
		{
			overlap+=T(sqrt(x*x+y*y))*T(sqrt((x-b)*(x-b)+y*y))*accuracy*accuracy;
			
		}
	}
	return overlap;
}


