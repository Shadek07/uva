#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAX INT_MAX*(1.0)

struct point
{

	int x;
	int y;


}p[10];

bool compare(point a, point b)
{
	if( a.x < b.x)
		return 1;
	if(a.y < b.y)
		return 1;
}

int main(void)
{

	int n,i,j,k,net = 1;

	double min = MAX;

	double a,b,c,d,e,f;

	int test[8] = {0,1,2,3,4,5,6,7};
	int save[8];

	double distance[7];

	while(1)
	{
		cin >> n;
		if(!n)
			break;
		for( i = 0; i < n; i++)
		{
			cin >> j >> k;

			p[i].x = j;
			p[i].y = k;
		}

		//sort(p,p+n,compare);

		   min = MAX;

	    	do 
        	{
        		
				    
				    e = 0.0;
			    
					for( i = 0; i < n-1; i++)
					{
						b = abs(p[test[i]].x - p[test[i+1]].x);
						b *= b;
						c = abs(p[test[i]].y - p[test[i+1]].y);
						c *= c;
						a = sqrt(b+c);

						a += 16.0;
						
						e += a;
					}

                 	if( e < min)
					{

						min = e;

						for( j = 0; j < n; j++)
						{
							save[j] = test[j];
						}
					}
        		
                		
        	}while(next_permutation(test,test+n));

		cout << "**********************************************************\n";
		cout << "Network #" << net++ << endl;

		e = 0.0;
		
		for( i = 0; i < n-1; i++)
		{
			cout << "Cable requirement to connect (" << p[save[i]].x <<"," << p[save[i]].y << ") to (" << p[save[i+1]].x << "," << p[save[i+1]].y << ") is ";
			
			b = abs(p[save[i]].x - p[save[i+1]].x);
			b *= b;
			c = abs(p[save[i]].y - p[save[i+1]].y);
			c *= c;
			a = sqrt(b+c);

			printf("%.2f feet.\n",a+16.0);
			//e += a;
		}

		cout << "Number of feet of cable required is ";

		printf("%.2f.\n",min);


	}


	return 0;
}