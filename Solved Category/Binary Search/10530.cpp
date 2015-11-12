#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

vector<int> low,high;
char in[10];
int main(void)
{
    int n,i,j;
    int val;
    while(cin >> n && n)
    {
         getchar();
         gets(in);
         while(1)
         {
                 
                 if(strcmp(in,"right on") == 0)
                 {
                     val = n;
                     break;                
                 }
                 else if(strcmp(in,"too low") == 0)
                 {
                      low.push_back(n);
                 }
                 else
                 high.push_back(n);
                 
                 cin >> n;
                 getchar();
                 gets(in);
                 
         }
         
         j = low.size();
         int ch = 1;
         for(i = 0; i < j;i++)
         {
               if(low[i] >= val)
               {
                         ch = 0;
                         break;
               }
         }
         j = high.size();
         for(i = 0; i < j;i++)
         {
               if(high[i] <= val)
               {
                    ch = 0;
                    break;
               }
         }
         
         if(ch == 0)
         cout << "Stan is dishonest\n";
         else
         cout << "Stan may be honest\n";
         
         low.clear();
         high.clear();  
    }
    return 0;
}
