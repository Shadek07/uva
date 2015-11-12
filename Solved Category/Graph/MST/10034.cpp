#include<iostream>
#include<cmath>
#include<algorithm>
#include <iomanip>
using namespace std;
int rank[100000];
int p[100000];


struct node
{
       int s;
       int d;
       float w;
};

bool operator <(const node &x1,const node &x2)
{
     if(x1.w<x2.w)
     return true;
     
     return false;
}

void makeset(int x)
{
           p[x]=x;
           rank[x]=0;
     
}

int findset(int px)
{
     if(px!=p[px])
     return px=findset(p[px]);
     else
     return px;
}

void mergset(int px,int py)
{
     int x=findset(px);
     int y=findset(py);
     
     if(rank[x]>rank[y])
     p[y]=x;
     
     else
     p[x]=y;
     
     if(rank[x]==rank[y])
     rank[y]=rank[y]+1;
}

int main()
{
    int t,i;
    int s = 0;
    cin>>t;
	getchar();
	getchar();
    for(int k=0;k<t;k++)
    {
          
            int n;
            cin>>n;
            float ans=0.0;
            float a[1000][2];
            node x[1001];
           
            for( i=0;i<n;i++)
            {
                    cin>>a[i][0]>>a[i][1]; 
            }
			
getchar();
            int c=0;
           
            for( i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                         float xx=a[i][0]-a[j][0];
                         float yy=a[i][1]-a[j][1];
                         
                         xx=xx*xx;
                         yy=yy*yy;
                         
                         xx=sqrt(xx+yy);
                           
                         x[c].s=i;
                         x[c].d=j;
                         x[c].w=xx;
                         c++;
                           
                    }
                }
           }
         
           for( i=0;i<c;i++)
           makeset(i);
   
           sort(x,x+c);
           
   
           for( i=0;i<c;i++)
           {
                   if(findset(x[i].s)!=findset(x[i].d))
                   {
                         ans+=x[i].w;
                         mergset(x[i].s,x[i].d);                           
                   }
            }
            
            if(s == 0)
                 s = 1;
		else
			cout << "\n";
            //
            printf("%.2lf\n",ans);
           // else
           // printf("%.2lf\n",ans);
		if(k<t-1)
               getchar();   
   
    }
    
} 
  
            