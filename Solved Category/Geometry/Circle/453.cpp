#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#define eps 1e-9
#define eps1 1e-5
using namespace std;

typedef pair<double,double> pa;

set<pa> st;

set<pa>::iterator it;

#define max1(a,b) a>b?a:b
#define min1(a,b) a>b?b:a
double get_x(double a, double b, double c,double y)
{
	double x;
	return x = (-c-b*y)/a;
}

bool dy(double x,double y)  {   return x > y + eps;} // x > y   
bool xy(double x,double y)  {   return x < y - eps;} // x < y  
bool dyd(double x,double y)	{ 	return x > y - eps;}	// x >= y 
bool xyd(double x,double y)	{	return x < y + eps;} 	// x <= y
bool eq1(double x,double y) {   return fabs( x - y ) < eps;} //x==y
bool eq(double x,double y) {   return fabs( x - y ) < eps1;} //x==y

int main(void)
{

	double x1[3],x2[3];
	double a2;
    double r1,r2;
	double mn,mx;
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	double sq;
	while(scanf("%lf %lf %lf",&x1[0],&x1[1],&x1[2]) == 3)
	{
		scanf("%lf %lf %lf",&x2[0],&x2[1],&x2[2]);

		a2 = (x1[0]-x2[0])*(x1[0]-x2[0]) + (x1[1]-x2[1])*(x1[1]-x2[1]);	
		//cout << a2 << endl;
		a2 = sqrt(a2);
		//cout << a2 << endl;
		//cout << x1[2] + x2[2] << endl;
		r1 = x1[2];
		r2 = x2[2];
		mn = min1(r1,r2);
		mx = max1(r1,r2);

		if(fabs(x1[0]-x2[0]) <= 1e-7 && fabs(x1[1]-x2[1]) <= 1e-7)
		{
			if(x1[2] == 0 ||dy(x1[2],x2[2])||xy(x1[2],x2[2]))
			{

				printf("(%.3lf,%.3lf)\n",x1[0],x1[1]);
			}
			else
			cout <<"THE CIRCLES ARE THE SAME\n";
			continue;
		}

		if( dy(a2,x1[2] + x2[2]) ||xy(a2,mx-mn))
		{
			cout <<"NO INTERSECTION\n";
			continue;
		}


		double h1,k1,h2,k2;
		double x,y,a,b,c,p,a1,b1,c3;
		double g1,g2,f1,f2,c1,c2;

		g1 = -2*x1[0];
		//cout << g1 << endl;
		g2 = -2*x2[0];
		f1 = -2*x1[1];
		f2 = -2*x2[1];
		h1 = x1[0];
		k1 = x1[1];
		h2 = x2[0];
		k2 = x2[1];
		c1 = h1*h1 + k1*k1 - r1*r1;
		c2 = h2*h2 + k2*k2 - r2*r2;

		a = g1 - g2;
		b = f1-f2;
		c = c1-c2;
		pa p2;
		double y5;
		if( fabs(a-0.0) <= 1e-7)
		{
			a1 = 1.0;
			b1 = g1;
		    y5 = -(c/b);
			c3 = y5*y5 + f1*y5 + c1;
			
			if(b1*b1 > 4*a1*c3)
			sq = sqrt(b1*b1 - 4*a1*c3);
			else
				sq=0;
			x = -b1;
			x += sq;
			x /= (2*a1);
			//if(xy(y5,0) && xy(fabs(y5),eps1))
				//y5=0;
			p2 = pa(x,y5);
			st.insert(p2);

			if(!eq1(a2,r1+r2))
			{
				x = -b1;
				x -= sq;
				x /= (2*a1);
				p2 = pa(x,y5);
				st.insert(p2);
			}
			goto nt;
		}
		else if(fabs(b-0.0) <= 1e-7)
		{
			a1 = 1.0;
			b1 = f1;
		    y5 = -(c/a);
			c3 = y5*y5 + g1*y5 + c1;

			if(b1*b1 > 4*a1*c3)
			sq = sqrt(b1*b1 - 4*a1*c3);
			else
				sq=0;

			x = (-b1 +sq)/(2*a1);
			//if(xy(y5,0) && xy(fabs(y5),eps1))
				//y5=0;
			p2 = pa(y5,x);
			
			st.insert(p2);

			if(!eq1(a2,r1+r2))
			{
				x = (-b1 -sq)/(2*a1);
				//if(xy(y5,0) && xy(fabs(y5),eps1))
					//y5=0;
				p2 = pa(y5,x);
				st.insert(p2);
			}

			goto nt;
		}
		//x = (-c-b*y)/a;
		p = -c-a*h1;
		a1 = b*b + a*a;
		b1 = -(2*p*b + 2*a*a*k1);
		c3 = p*p + a*a*(k1*k1-r1*r1);
		if(b1*b1 > 4*a1*c3)
			sq = sqrt(b1*b1 - 4*a1*c3);
		else
			sq=0;
		y = (-b1 +sq)/(2*a1);
		x = get_x(a,b,c,y);

		//if(xy(y,0) && xy(fabs(y),eps1))
			//y=0;
		p2 = pa(x,y);
		st.insert(p2);
		
		if(!eq1(a2,r1+r2))
		{
			y = (-b1 -sq)/(2*a1);
			x = get_x(a,b,c,y);
			p2 = pa(x,y);
			st.insert(p2);
		}
nt:
		if(st.size() > 1)
		{
			it = st.begin();

			a = (*it).first;
			b = (*it).second;
			if(fabs(a) < 0.001) 
				a=0;
			if(fabs(b) < 0.001) 
				b=0;
			printf("(%.3lf,%.3lf)",a,b);
			double s1=a,s2=b;

			it++;
			a = (*it).first;
			b = (*it).second;
			if(!(eq(s1,a)&&eq(s2,b)))
			{
				if(fabs(a) < 0.001) 
					a=0;
				if(fabs(b) < 0.001) 
					b=0;
				printf("(%.3lf,%.3lf)\n",a,b);
			}
			else
				cout << endl;
		}
		else
		{
			it = st.begin();
			a = (*it).first;
			b = (*it).second;
			if(fabs(a) < 0.001) 
				a=0;
			if(fabs(b) < 0.001) 
				b=0;
			printf("(%.3lf,%.3lf)\n",a,b);
		}

		st.clear();
		
        
	}

	return 0;
}