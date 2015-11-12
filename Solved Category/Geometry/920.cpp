#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

struct point
{
       long int x;
       long int y;
       
}a[105],c[105];

int n;

int comp(point a,point b)
{
    if(a.x<b.x)
    return 1;
    else
    return 0;
}

double get(int i,int j)
{
       double x1;
       x1 = (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y);
       return sqrt(x1);
}


int main(void)
{
    int t;
    scanf("%d",&t);
    int i,j,k;
    double dist;
    int temp;
    double a1,b1,c1;
    double x1,y1;
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0; i < n;i++)
        {
              scanf("%d %d",&a[i].x,&a[i].y);
        }
        //mergesort(0,n-1);
        sort(a,a+n,comp);
        dist = 0.0;
        if(a[n-2].y > a[n-1].y)
        {
                    dist += get(n-1,n-2);
                    temp = n-2;
        }
        else
        temp = n-1;
        for(i = n-3;i>= 0;i--)
        {
              if(a[temp].y < a[i].y)
              {
                   if(temp - i > 1)
                   {
                       a1 = (a[i].y - a[i+1].y);
                       b1 = -(a[i].x - a[i+1].x);
                       c1 = -a[i].x*(a[i].y - a[i+1].y) + a[i].y*(a[i].x - a[i+1].x);
                       y1 = a[temp].y;
                       x1 = (-c1-b1*y1)/a1;
                       dist += sqrt((a[i].x - x1)*(a[i].x - x1)+(a[i].y - y1)*(a[i].y - y1));
                   
                   }
                   else if(temp - i == 1)
                   {
                       dist += get(temp,i);
                   }
                   temp = i;
              }
        }
        
        printf("%.2lf\n",dist);
        
    }
    return 0;
}
