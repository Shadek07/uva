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

struct place
{
       int index;
       int num;
};
vector<place> v;
set<int> mp[1001];

bool comp(place a,place b)
{
     if(a.num < b.num)
     return true;
     else if(a.num == b.num && a.index < b.index)
     return true;
     return false;
}
int main(void)
{
    int t;
    int i,j,k,p;
    cin >> t;
    getchar();
    char in[10000];
    char *p1;
    while(t--)
    {
              cin >> p;
              getchar();
              for(i = 0; i < p;i++)
              {
                    gets(in);
                    p1 = strtok(in,"      \t");
                    while(p1 != NULL)
                    {
                         int a = atoi(p1);
                         mp[i].insert(a);
                         p1 = strtok(NULL,"      \t");    
                    }
              }
              
              struct place pl;
              for(i = 0; i < p;i++)
              {
                    pl.index = i;
                    pl.num = mp[i].size();
                    v.push_back(pl);
              }
              
              sort(v.begin(),v.end(),comp);
              k = v[0].num;
              cout << v[0].index+1;
              j = v.size();
              for(i = 1;i < j;i++)
              {
                   if(v[i].num == k)
                   {
                               cout << " " << v[i].index+1;
                   } 
                   else
                   break;
              }
              cout << endl;
              v.clear();
              for(i = 0; i < p;i++)
              mp[i].clear();
    }
    
    return 0;
}
