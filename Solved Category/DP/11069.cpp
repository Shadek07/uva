#include<iostream>
#include<cstdio>
#include<cstdio>

using namespace std;
int ans[78][2];
int main(void)
{
    int i,j,k,n;
    ans[1][0] = 1;
    ans[1][1]=  1;
    ans[2][0] = 2;
    ans[2][1] = 1;
    ans[3][0] = 2;
    ans[3][1] = 1;
    
    for(i = 4;i<=76;i++)
    {
          ans[i][1] = ans[i-2][1]+ans[i-3][1];
          ans[i][0] = ans[i][1]+ans[i-1][1];
    }
    
    while(cin >> n)
    {
              cout << ans[n][0]<<endl;
    }
    return 0;
}
