
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

using namespace std;

#define max1(a,b) a>b?a:b
#define min1(a,b) a>b?b:a

int n,r;
map<string,int> mp;

char in[50],in1[50];

int dist[201][201];

int main(void)
{
    int i,j,k,ind;
    int a,b,c,d;
    int cnt = 1;
    int weight;
    while(cin >> n >> r)
    {
              if(!n && !r)
              break;
              getchar();
              ind = 1;
              for(i = 1; i <= n;i++)
              {
                    for(j = 1; j <=n;j++)
                    {
                          dist[i][j] = -1;
                    }
              }
              for(i = 0; i < r;i++)
              {
                    cin >> in >> in1 >> weight;
                    if(!mp[in])
                    mp[in] = ind++;
                    if(!mp[in1])
                    mp[in1] = ind++;
                    a = mp[in];
                    b = mp[in1];
                    dist[a][b] = dist[b][a] = weight;
              }
              
              cin >> in >> in1;
              a = mp[in];
              b = mp[in1];
              
              for(k = 1; k <= n;k++)
              {
                      for(i = 1; i <= n;i++)
                      {
                            for(j = 1; j <= n;j++)
                            {
                                  c = dist[i][k];
                                  d = dist[k][j];
                                  c = min1(c,d);
                                  dist[i][j] = max1(dist[i][j],c);
                            }
                      }
              }
              
              cout << "Scenario #" << cnt++ << endl;
              cout << dist[a][b] << " tons\n\n";
              mp.clear();
              
              
    }
    
    return 0; 
}
