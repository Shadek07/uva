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

using namespace std;


#define min1(a,b) a < b?a:b
#define max1(a,b) a < b?b:a
typedef pair<int,int> pa;

unsigned long dist[105][105];


int main(void)
{
	int num;

	int i,j,k;

	int term = 1;

	int c,s,q;
    int a,b,d;
    
	
    bool ch = true;

	while(1)
	{

			    cin >> c >> s >> q;
				if(!c && !s && !q)
					break;
				for(i = 1; i <= c;i++)
				{
                      for(j = 1; j <=c;j++)
                      {
                            dist[i][j] = 99999999;
                      }
                }
				
				for(i = 0; i < s;i++)
				{
				   cin >> a >> b >> d;
                   dist[a][b] = d;
                   dist[b][a] = d;                     
                }
                
                for(k = 1;k<=c;k++)
                {
                      for(i = 1;i<=c;i++)
                      {
                            for(j = 1; j <=c;j++)
                            {
                                 a = dist[i][k];
                                 b = dist[k][j];
                                 a = max1(a,b);
                                 dist[i][j] = min1(dist[i][j],a);
                                  
                            }
                      }
                }

				if(ch)
					ch = false;
				else
					cout << endl;
				printf("Case #%d\n",term);

				for(i = 0;i<q;i++)
				{
					cin >> a >> b;
					if(dist[a][b] == 99999999)
						cout << "no path\n";
					else
						cout << dist[a][b]<<endl;
				}
				term++;
	}


	return 0;

}
