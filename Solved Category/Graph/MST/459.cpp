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
    int i;
    int s = 1;
	int a1;
	char a,b;
	int a2,b1;

	

	char in[10];
	
	int t;

	cin >> t;

	getchar();
	getchar();
	
	int n,m;

	char c,c1;
    
    while(t--)
    {
          
           
		    c = getchar();
			getchar();
           // cin>>n>>m;
			n = c - 64;
			
			
			for( i=1;i<=n;i++)
            makeset(i);
			a1  = n;
        
		
			i = 1;
            while(gets(in))
			{
			
				     //gets(in);

					 //if(strlen(in) == 0)
						// break;
				if(!strcmp(in,"\n") || !strcmp(in,"\0") || !strcmp(in," "))
            break;

					 a2 = in[0] - 64;
					 b1 = in[1] - 64;
			
					if(findset(a2)!=findset(b1))
					{
						mergset(a2,b1);
						a1--;
					}
				
				i++;
				
			}
			
            if(s == 1)
				s = 0;
			else
				cout << "\n";
           cout << a1 << endl; 
          
            
		
		   
   
    }

	

	

	return 0;
    
} 
  
            