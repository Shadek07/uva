
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
#include <bitset>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

int dist[101][101];
double lat[101][2];
map<string,int> mp;
int n,m,q;
double rad = 6378;
double PI = 3.141592653589793;


double  greatCircleDistance(double  pLat,  double pLong, 
                                        double qLat, double qLong)
{ 
             pLat  *= PI / 180;  pLong  *= PI / 180; 
             qLat  *= PI / 180;  qLong  *= PI / 180; 
			 double x;
             x =   rad * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong)    + 
                                    cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong)   + 
                                    sin(pLat)*sin(qLat));
			 return floor(x+0.5);
}
 
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int i,j,k,ind;
	char in[30],in1[30];
	int ca=1;
	while(cin >> n >> m >> q)
	{
		if(!n && !m && !q)
			break;
		for(i = 0;i<n;i++)
		{
			cin >> in >> lat[i+1][0] >> lat[i+1][1];
			mp[in] = i+1;
		}
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=n;j++)
			{
				dist[i][j] = 9999999;
			}
		}


		for(i = 0;i<m;i++)
		{
			cin >> in >> in1;
			j = mp[in];
			k = mp[in1];
			dist[j][k]=greatCircleDistance(lat[j][0],lat[j][1],lat[k][0],lat[k][1]);                                       
		}

		for(k = 1;k<=n;k++)
		{
			for(i = 1;i<=n;i++)
			{
				for(j = 1;j<=n;j++)
				{
					if(k != i && k != j && i != j)
					{
						if(dist[i][k] != 999999 && dist[k][j] != 9999999)
						dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
					}
				}
			}
		}

		if(ca>1)
			cout << endl;
		cout << "Case #" << ca++ << endl;
		while(q--)
		{
			cin >> in >> in1;
			i = mp[in];
			j = mp[in1];
			if(dist[i][j] == 9999999)
				cout << "no route exists\n";
			else
				cout << dist[i][j] << " km\n";
		}

	}
    return 0;
}