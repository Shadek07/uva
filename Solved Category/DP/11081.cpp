
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
#include<list>
using namespace std;

#define MAXN 65

int n;
char s1[MAXN], s2[MAXN], s3[MAXN];
int f1[MAXN][MAXN][MAXN], f2[MAXN][MAXN][MAXN], f[MAXN][MAXN][MAXN];

void solve()
{
    int len1 = strlen(s1+1);
    int len2 = strlen(s2+1);
    int len3 = strlen(s3+1);
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(f,0,sizeof(f));
	int i,j,k;
    for( i = 0; i <= len1; i ++)
        for( j = 0; j <= len2; j ++)
            f[i][j][0] = 1, f1[i][j][0] = 1, f2[i][j][0] = 1;
        for( k = 1; k <= len3; k ++)
        {
            for( i = 0; i <= len1; i ++)
            {
                for( j = 0; j <= len2; j ++)
                {
                    if(i) 
                    {
                        f1[i][j][k] = f1[i-1][j][k];
                        if(s1[i] == s3[k]) 
                            f1[i][j][k] += f[i-1][j][k-1];
                            f1[i][j][k] %= 10007;
                    }
                    if(j)
                    {
                        f2[i][j][k] = f2[i][j-1][k];
                        if(s2[j] == s3[k])
                            f2[i][j][k] += f[i][j-1][k-1];
                            f2[i][j][k] %= 10007;
                    } 
                    f[i][j][k] = (f1[i][j][k] + f2[i][j][k])%10007;
                }
            }
        }

        printf("%d\n",f[len1][len2][len3]);
}
void init()
{   
   scanf("%s%s%s", s1+1,s2+1,s3+1);
   solve();  
}
int main()
{
    int t;
	cin >> t;
	getchar();
	while(t--)
	{
		init();
	}
    return 0;
}