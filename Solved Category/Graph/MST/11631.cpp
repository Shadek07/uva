#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
#include<list>
using namespace std;

int rank[200001];
int p[200001];



struct node
{
       int s;
       int d;
       int w;
}nd[200001];

bool comp(const node &x1,const node &x2)
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
    int i,j;
    int s = 1;
	int a,b,a1;
	long sum,ans;	
	int n,m;
    
    while(1)
    {
          
            
            cin>>n>>m;
			if(!n && !m)
				break;

			sum = 0;
			
			for( i=0;i<=n;i++)
            makeset(i);
			a1  = n;
        
		
			i = 0;
            while(i<m)
			{			
				scanf ("%d %d %d",&a,&b,&a1);			
			    nd[i].s = a;
			    nd[i].w = a1;
			    nd[i].d = b;
                sum += a1;				
			    i++;				
			}
			
            sort(nd,nd+m,comp);
			i = 0;
			ans = 0;
			j=0;
			while(i<n-1)
			{
				if(findset(nd[j].s) != findset(nd[j].d))
				{
					i++;
					mergset(nd[j].s,nd[j].d);
					ans += nd[j].w;
				}
				j++;
			}
            
			//cout << 
			cout << sum - ans << endl;
             
   
    }
	return 0;
    
} 
  
            
