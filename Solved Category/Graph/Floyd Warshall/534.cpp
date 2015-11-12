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

#define min1(a,b) a < b?a:b
#define max1(a,b) a < b?b:a
typedef pair<int,int> pa;

pa cor[201];

double dist[201][201];

double measure(int i,int j)
{
       double a;
       a = (cor[i].first - cor[j].first)*(cor[i].first - cor[j].first) + (cor[i].second - cor[j].second)*(cor[i].second - cor[j].second);
       a = sqrt(a);
       return a;
}
int main(void)
{
	int num;

	int i,j,k;

	int term = 1;

	double min,m,a,b;
   
    scanf("%d",&num);

	while(num)
	{

				for( i = 0 ; i < num; i++)
				{
					scanf("%d %d",&cor[i].first,&cor[i].second);
				}
				
				for(i = 0; i < num;i++)
				{
                      for(j = 0; j < num;j++)
                      {
                            dist[i][j] = 99999999.0;
                      }
                }
				
				for(i = 0; i < num-1;i++)
				{
                      for(j = i+1; j < num;j++)
                      {
                            m = measure(i,j);
                            dist[i][j] = m;
                            dist[j][i] = m;
                      }
                }
                
                for(k = 0;k<num;k++)
                {
                      for(i = 0;i<num;i++)
                      {
                            for(j = 0; j < num;j++)
                            {
                                 a = dist[i][k];
                                 b = dist[k][j];
                                 a = max1(a,b);
                                 dist[i][j] = min1(dist[i][j],a);
                                  
                            }
                      }
                }

				printf("Scenario #%d\n",term);

				printf("Frog Distance = ");
				printf("%.3f\n\n",dist[0][1]);
                scanf("%d",&num);
				term++;
	}


	return 0;

}
