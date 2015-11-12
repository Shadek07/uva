#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n;

long long int points[1005][2];

int gcd(long long int a,long long int b)
{    

	if( b == 0)
	{
		return a;
	}

    else return gcd(b,a%b);
}

long long int points_in_line_segment(long long int i,long long int j)
{
    int x = abs(points[i][0] - points[j][0]);
    int y = abs(points[i][1] - points[j][1]);
    if(x == 0 && y == 0)
    return 0;    
    if(x == 0) return y-1;
        
    if(y == 0) return x-1;
    
    return gcd(x,y) - 1;
}

long long points_in_edges()
{
     long long ans = n;
     int i;
     for(i = 0; i < n;i++)
     {
           ans += points_in_line_segment(i,(i+1)%n);
     }
     
     return ans;
}
int main(void)
{
    int i,j,k;
    long long int area;
    long long int ans;
    while(cin >> n)
    {
              if(!n)
              break;
              for(i = 0; i < n;i++)
              {
                    cin >> points[i][0] >> points[i][1];
              }
              
              points[n][0] = points[0][0];
              points[n][1] = points[0][1];
              
              area = 0;
              for(i = 1; i <= n; i++)
              {
                    area += points[i-1][0]*points[i][1] - points[i][0]*points[i-1][1];
              }
              
              //area /= 2;
              if(area < 0)
              area = -area;
              long long int boundary_points = points_in_edges();
              ans = (area - boundary_points + 2)/2;
              cout << ans << endl;
    }
    return 0;
}
