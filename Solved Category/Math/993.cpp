#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v1;

int main(void)
{
  
  int cas,n;
  int i,j,k=0;
  int ch;
 
  cin >> cas;
 
  while(cas--)
  {
	scanf("%d",&n);
	if(n == 0)
	{
    	cout << 0 << endl;
    	continue;
     }
     if(n == 1)
     {
          cout << 1 << endl;
          continue;
     }
     
     for(i = 9; i>=2;i--)
     {
          ch = 0;
          while(n%i== 0)
          {
                      ch = 1;
                      n /= i;
                      v1.push_back(i);
          }
          //if(ch)
           
     }
     
     if(v1.size() == 0 || n != 1)
     {
          cout << -1 << endl;
     }
     else
     {
         sort(v1.begin(),v1.end());
         int l = v1.size();
         for(i = 0;i<l;i++)
         cout << v1[i];
         cout << endl;
         
     }
     
     v1.clear();
   }
  return 0;
}
