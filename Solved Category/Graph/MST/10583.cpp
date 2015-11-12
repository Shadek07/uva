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
	int a,b,a1;
	
	
	
	int n,m;
    
    while(1)
    {
          
            
            cin>>n>>m;
			if(!n && !m)
				break;
			
			for( i=1;i<=n;i++)
            makeset(i);
			a1  = n;
        
		
			i = 1;
            while(i<=m)
			{
			
				     scanf ("%d %d",&a,&b);
			
					if(findset(a)!=findset(b))
					{
						mergset(a,b);
						a1--;
					}
				
				i++;
				
			}
			
                  
           cout << "Case " << s++ << ": " << a1 << endl; 
          
            
		
		//if(k<t-1)
               //getchar();   
   
    }

	

	

	return 0;
    
} 
  
            
