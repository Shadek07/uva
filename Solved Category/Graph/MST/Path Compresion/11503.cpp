#include<iostream>
#include<cmath>
#include<algorithm>
#include <iomanip>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

int rank[100005];
int p[100005];

int elem[100005];

void makeset(int x)
{
     p[x]=x;
     rank[x]=0;
	 elem[x] = 1;
     
}

int findset(int px)
{
     /*if(px!=p[px])
	 {
		return px=findset(p[px]);
	 }
     else
	 {
		return px;
	 }*/
	int arr[100005];
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
}

void mergset(int px,int py)
{
     int x=findset(px);
     int y=findset(py);

	 if(x != y)
	 {
     
		 if(rank[x]>rank[y])
		 {
			p[y]=x;
			elem[x] += elem[y];
		 }
		 else
		 {
			p[x]=y;
			elem[y] += elem[x];
		 }
     
		 if(rank[x]==rank[y])
			rank[y]=rank[y]+1;
	 }
}

int main()
{
    int i;
	int a,b,a1,a2;

	
	int t;
	
	int n;
	string s1,s2;
	map<string,int> mp;
	int ind = 1;
	cin >> t;
    
    while(t--)
    {
          
            
            cin >> n;
			
			ind = 1;
			
			for( i=1;i<=n;i++)
			{
				cin >> s1 >> s2;
				if(!mp[s1])
				{
					mp[s1] = ind++;
					makeset(ind-1);
				}
				if(!mp[s2])
				{
					mp[s2] = ind++;
					makeset(ind-1);
				}

				a = mp[s1];
				b = mp[s2];

			    mergset(a,b);
				a1 = findset(a);
				
				cout << elem[a1] << endl;
			}

			mp.clear();
       
    }	

	return 0;
    
} 
  
            