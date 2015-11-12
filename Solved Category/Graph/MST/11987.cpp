
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)

int rank[200005];
int p[200005];
int id[200005];
int elem[200005];
unsigned long sum[200005];
int cnt;
void makeset(int x)
{
     p[x]=x;
     rank[x]=1;
	 elem[x] = 1;
	 sum[x] = x;
	 id[x] = x;
}

int findset(int px)
{
     
	int arr[200005];
	int i,j;

	i = 0;

	while(px != p[px])
	{
		arr[i++] = px; 
		px = p[px];
	}

	for(j = 0;j<i;j++)
	{
		p[arr[j]] = px;
	}
	return px;

	/*if(px!=p[px])
	 {
		return p[px]=findset(p[px]);
	 }
     else
	 {
		return px;
	 }*/
}

void mergset(int x,int y)
{
     //int x=findset(id[px]);
     //int y=findset(id[py]);

	 if(x != y)
	 {
     
		 if(elem[x]<elem[y])
		 {
			p[y]=x;
			elem[x] += elem[y];
			sum[x] += sum[y];
		 }
		 else
		 {
			p[x]=y;
			elem[y] += elem[x];
			sum[y] += sum[x];
		 }
     
		 //if(rank[x]==rank[y])
			//rank[y]=rank[y]+1;
	 }
}

void move(int px,int py)
{
	 int x=findset(id[px]);
     int y=findset(id[py]);

	 sum[x] -= px;
	 elem[x]--;


	 p[cnt] = cnt;
	id[px] = cnt;
	elem[cnt] = 1;
	sum[cnt] = px;

	cnt++;
	mergset(id[px],y);
	 

}

int main()
{
    int i;
	int a,b,a1,c;
	
	int n,m;
	int ind = 1;
    
    while(scanf("%d %d",&n,&m)==2)
    {
        for(i = 1;i<= n;i++)
		{
			makeset(i);
		}

		cnt = n+1;

		for(i = 1;i<=m;i++)
		{
			//cin >> a;
			scanf("%d",&a);
			if(a==3)
			{
				//cin >> b;
				scanf("%d",&b);
				a1 = findset(id[b]);
				cout << elem[a1] << " " << sum[a1] << endl;

			}
			else if(a==1 || a ==2)
			{
				//cin >> b >> c;
				scanf("%d %d",&b,&c);
				if(a == 1)
				{
					int x=findset(id[b]);
					int y=findset(id[c]);
					mergset(x,y);
				}
				if(a==2)
				{
					move(b,c);					
				}
			}
		}

       
    }	

	return 0;
    
} 
  
            