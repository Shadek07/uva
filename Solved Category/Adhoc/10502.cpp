
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
int m,n;
int RL[101][101];
int DU[101][101];
char in[101][101];
int main(void)
{
    int i,j,k;
    int a,b,c,d;
    int x,y,z;
    unsigned long long sum;
    while(cin >> m && m)
    {
            cin >> n;
            getchar();
            for(i = 0;i<m;i++)
                    gets(in[i]);
            sum = 0;
            for(i = 0;i<m;i++)
            {
                for(j = 0;j<n;j++)
                {
                    for(x = i;x<m;x++)
                    {
                        for(y = j;y<n;y++)
                        {
                            bool ch = true;
                            for(a = i;a<=x;a++)
                            {
                                for(b = j;b<=y;b++)
                                if(in[a][b] == '0')
                                {
                                    a = x+1;
                                    ch = false;
                                    break;
                                }
                            }
                            if(ch)
                            sum++;
                        }
                    }
                }
            }
            cout << sum << endl;
    }    
    
	return 0;
}
