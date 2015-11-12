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

using namespace std;

#define ma(a,b) a>= b?a:b
#define mi(a,b) a>= b?b:a

using namespace std;

    int main()
    {
        int Case = 1;
		int n,m,i,j,a,b,d,s,t,tou,k;
        while (true)
        {
            const int MAX = 110;
            const int INF = 999999999;
            int D[MAX][MAX] = { 0 };

			cin >> n >> m;

			if(!n && !m)
				break;
           
            for ( i = 0; i <= n; i++)
                for ( j = 0; j <= n; j++)
                   D[i][j] = 0;

            for (i = 1; i <= m; i++)
            {
               
					cin >> a >> b >> d;
               
					D[a][b] = d;
					D[b][a] = d;
             }
            
           
            for (k = 1; k <= n; k++)
                for ( i = 1; i <= n; i++)
                    for ( j = 1; j <= n; j++)
					{
						if(D[i][k] == 0 || D[k][j] == 0 || i == j)
							continue;
						int a = mi(D[i][k],D[k][j]);
                        D[i][j] = ma(D[i][j],a);
					}

			cin >> s >> t >> tou;
			if(s == t)
			{
				cout << "Scenario #" << Case++ << endl;
				cout << "Minimum Number of Trips = " << 1 << endl;
				continue;

			}

			//cout << D[s][t] << endl;

			cout << "Scenario #" << Case++ << endl;
			cout << "Minimum Number of Trips = " << ceil((tou*1.0)/ (D[s][t]-1)) << endl<< endl;
 
        }

       
        return 0;
 }
