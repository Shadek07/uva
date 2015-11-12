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
    int t,i,k;
    int s = 0;
	int a,b;
	char c;
	char in[10000];
	int success,uns;
	int n;
    cin>>t;
	getchar();
	getchar();
    for( k=0;k<t-1;k++)
    {
          
            
            cin>>n;
			getchar();
			for( i=1;i<=n;i++)
            makeset(i);
            float ans=0.0;
            
           
           
			success = 0;
			uns = 0;
            while(1)
			{
				gets(in);
				if(strlen(in) == 0)
				//if(in[0]!='q'&&in[0]!='c')//break;
					break;
				sscanf (in,"%c %d %d",&c,&a,&b);
				if(c == 'c')
				{
					mergset(a,b);

				}
				else
				{
					if(findset(a)!=findset(b))
						uns++;
					else
						success++;
				}
				
			}
			
                  
            
            if(s == 0)
                 s = 1;
		else
			cout << "\n";
            
		cout << success << "," << uns << endl;
		//if(k<t-1)
               //getchar();   
   
    }

	for(;k<t;k++)
	{
		    cin>>n;
			getchar();
			for( i=1;i<=n;i++)
            makeset(i);
            float ans=0.0;
            
           
           
			success = 0;
			uns = 0;
            while(gets(in))
			{
				
			
				sscanf (in,"%c %d %d",&c,&a,&b);
				if(c == 'c')
				{
					mergset(a,b);

				}
				else
				{
					if(findset(a)!=findset(b))
						uns++;
					else
						success++;
				}
				
			}
			
                  
            
            if(s == 0)
                 s = 1;
		else
			cout << "\n";
            
		cout << success << "," << uns << endl;
		//if(k<t-1)
               //getchar();   
   
    }


	

	return 0;
    
} 
  
            