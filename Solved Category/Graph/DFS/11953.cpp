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
using namespace std;

int dx [] = {-1, 0, 1, 0};
int dy [] = {0, 1, 0, -1};

using namespace std;

int n;
char mat [105] [105];

void dfs (int p, int q)
{
	int i;
    if ( p < 0 || p == n || q < 0 || q == n || mat [p] [q] == '.' )
		return;

    mat [p][q] = '.';

    for (i = 0; i < 4; i++ )
        dfs (p + dx [i], q + dy [i]);
}

int main ()
{
    int testCase; scanf ("%d", &testCase);
    int cases = 0;
    int i,j;
    while ( testCase-- ) {
        scanf ("%d", &n);

        for (i = 0; i < n; i++ ) scanf ("%s", mat [i]);

        int cnt = 0;

        for (i = 0; i < n; i++ ) {
            for (j = 0; j < n; j++ ) {
                if ( mat [i] [j] == 'x' ) { cnt++;  dfs (i, j); }
            }
        }

        printf ("Case %d: %d\n", ++cases, cnt);
    }

	return 0;
}


