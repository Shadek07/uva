#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;



double search(double low,double high);

double s;
double x,y,c;

int main(void)
{

	
	double a,b,d,f,mn;
	while(cin >> x >> y >> c)
	{
		s = c;
		if(x < y)
		mn = x;
		else
		mn = y;
		d = search(0.0,mn);

		printf("%.3lf\n",d);

	}
}

double search(double low,double high)
{
	double mid,up,down,res,w;
    double wx,wy,hx,hy;
    
    w = (low+high)/2.0;
	hx = sqrt(x*x - w*w);
	wx = (c*w)/hx;
	hy = sqrt(y*y - w*w);
	wy = (c*w)/hy;
	
	if(wx + wy >= (w-0.00005) && (wx + wy) <= (w+0.00005))
    {
          return w;
    } 
    else if(wx + wy > w)
    {
       return  search(low,w);
    }
    else
    return search(w,high);
	

}
