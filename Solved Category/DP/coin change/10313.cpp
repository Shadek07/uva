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
#include<sstream>
using namespace std;

#define MAXTOTAL 7490



unsigned long long int nway[MAXTOTAL+1];

unsigned long long int coin[301][301]; //coin[i][j] is the number of ways to make 
                                       //amount i using j coins
                                       //coin[i][j]=0,if j>i,because we have least coin with value 1

int main() 
{
  int i,j,n,k,v,c;
  int inp[3];
  char in[100];
  

  for(i = 0;i<=300;i++)
  {
        for(j = 0;j<=300;j++)
        {
              coin[i][j] = 0;
        }
  }
  
  coin[0][0] = 1;
  for(i = 1; i<=300;i++) //i is a coin with value i
  {
        k = i;
        for(j = i;j<=300;j++)
        {
              for(n = 1;n<= j;n++)
              {
                    coin[j][n] += coin[j-k][n-1]; 
              }
        }
  }
  while(gets(in))
  {
       i = 0;    
       string s1;
       s1 = in;
       istringstream is(s1);
       while(is >> v)
       {
            inp[i] = v;
            i++;
       }
       unsigned long long int ans = 0;
	   if(i == 1)
	   {
            n = inp[0];
            for(j = 0;j<=n;j++)
            {
                  ans += coin[n][j];
            }
            cout << ans << endl;
       }
       else if(i == 2)
       {
            n = inp[0];
            v = inp[1];
            if(v > 300)
            v = 300;
            for(j = 0; j<= v;j++)
            ans += coin[n][j];
            cout << ans << endl;
       }
       else
       {
            n = inp[0];
            v = inp[1];
            c = inp[2];
            if(v>300)
            v = 300;
            if(c>300)
            c = 300;
            for(j = v; j<= c;j++)
            ans += coin[n][j];
            cout << ans << endl;
       }
  }
  return 0;
}
