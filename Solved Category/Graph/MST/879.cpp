
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

char in[1048577];

int rank[1048577];

int p[1048577];


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
	/*int arr[1999999];
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
	return px;*/
}

void mergset(int x,int y)
{
     
     if(rank[x]>rank[y])
     p[y]=x;
     
     else
     p[x]=y;
     
     if(rank[x]==rank[y])
     rank[y]=rank[y]+1;
}

int main(void)
{
    int t;
    int ch = 0;
    cin >> t;
    char *p;
    int i,j,k,n;
    getchar();
    getchar();
    int res;
    int a,b;
	string s1;
	int save[1048577];
	int a1,b1;
    while(gets(in))
    {
		  t--;
		  s1= in;
		  istringstream is(s1);
		  is >> n;
          res = n;
		  i = 0;
		  while(is>>a)
		  {
			  save[i] = a;
			  i++;
		  }

          
          while(gets(in))
          {
               if(strlen(in) == 0)
               break;
               s1 = in;
               istringstream is(s1);
			   while(is>>a)
			  {
				  save[i] = a;
				  i++;
			  }              
                 
          } 
          
		  b = i;

		  for(i =1; i <= n;i++)
              makeset(i);

		  for(j = 0;j<b;j+=2)
		  {
			  a1 = findset(save[j]);
			  b1 = findset(save[j+1]);
			  if(a1 != b1)
              {
                  mergset(a1,b1);  
                  res--;      
              }
		  }
          if(ch == 0)
          ch = 1;
          else
          cout << endl;
          cout << res << endl;  
		  if(t==0)
			  break;
    }
    return 0;
}
