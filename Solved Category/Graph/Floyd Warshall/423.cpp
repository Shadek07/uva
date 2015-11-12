#include <iostream>
#include <algorithm>
#include <iomanip>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b

using namespace std;

    int main()
    {
        int Case = 0;
		int n;
		int i,j,k;
		char in[1000];
		char *p;
        while (cin >> n)
        {
			getchar();
            const int MAX = 20;
            const int INF = 999999999;
            int D[100][102] = { 0 };

			for ( i = 1; i <= n; i++)
                for ( j = 1; j <= n; j++)
                    if (i == j)
                        D[i][j] = 0;
                    else
                        D[i][j] = INF;

			for(i = 2; i <= n ; i++)
			{
				gets(in);
				j = 1;
				p = strtok(in," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");

				while( p != NULL)
				{

					if(strcmp(p,"x") == 0)
					{
						D[i][j] = INF;

					}
					else
					{
						int p1 = atoi(p); 
						D[i][j] = p1;
						D[j][i] = p1;
					}
					
					
					p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
					j++;
				}

			}
           
            

            
           
            for ( k = 1; k <= n; k++)
                for ( i = 1; i <= n; i++)
                    for ( j = 1; j <= n; j++)
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
           
           
		    int mini = 0;
		   for( i = 1; i <= n; ++i)
			  if(D[1][i] != INF && mini < D[1][i])
				 mini = D[1][i];

		   printf("%d\n", mini);

		
                
           
           
        }
       
        return 0;
    }

			
