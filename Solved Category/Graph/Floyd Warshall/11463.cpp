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

long dist[105][105];

#define INF 999999
int main(void)
{
	int num;

	int i,j,k,n;

	int term = 1;

	int c,s,q;
    int a,b,d;
    
	int t;
	cin >> t;
    bool ch = true;
	int mx;
	while(t--)
	{

			    cin >> n >> s;
				
				for(i = 0; i <n;i++)
				{
                      for(j = 0; j <n;j++)
                      {
                            if(i == j)
                            dist[i][j] = 0;
                            else
                            dist[i][j] = INF;
                      }
                }
				
				for(i = 0; i < s;i++)
				{
				   cin >> a >> b;
                   dist[a][b] = 1;
                   dist[b][a] = 1;                     
                }

				cin >> a >> b;
                
                for(k = 0;k<n;k++)
                {
                      for(i = 0;i<n;i++)
                      {
                            for(j = 0; j <n;j++)
                            {
								
								dist[i][j] = min1(dist[i][j],dist[i][k]+dist[k][j]);								
                                  
                            }
                      }
                }

				mx = -1;
				for(i = 0; i<n;i++)
				{
					 //if(i != a && i != b)
					 //{
							if(dist[a][i] + dist[i][b] > mx)
								mx = dist[a][i] + dist[i][b];
					 //}
				}
				//cout << dist[0][2] << " " << dist[2][3] << endl;
				if(mx == -1)
					mx = dist[a][b];
				cout << "Case " << term++ << ": " << mx << endl;
				
	}


	return 0;

}
