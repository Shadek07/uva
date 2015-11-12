#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cctype>
#include<set>
#include<cmath>
using namespace std;
char in[1000];

vector<int> v[27],v1,sol;
set<int> s1;
set<int>::iterator it;
int total;
int dist;
int order[10];
int out[10];
int taken[30];

int get_dist(int ind)
{
    int mx = 0;
    int temp,i,j,src,dest,k,k1;
    for(i = 0;i<=ind;i++)
    {
         src = order[i];
         temp = 0;
         for( j = 0; j<v[src].size();j++)
         {
              dest = v[src][j];
              for(k = 0;k<=ind;k++)
              {
                    if(order[k] == dest)
                    {
                        k1 = abs(i-k);
                        if(k1 > temp)
                        temp = k1;
                    }                        
              }
         }
         
         if(temp > mx)
         mx = temp;
    }
    
    return mx;
}
void recur(int ind)
{
    int i,j;
    
    //if(a > dist)    //pruning
      //  return;
    if(ind == total-1)
    {
           int a  =get_dist(ind);
           if(a < dist)
           dist = a;
           else return;
           for(i = 0;i <=ind;i++)
           {
                 out[i] = order[i];
           }
    }
    
    for(i = 0;i<total;i++)
    {
          if(taken[v1[i]] == 0)
          {
                 taken[v1[i]] = 1;
                 order[ind+1] = v1[i];
                 recur(ind+1);
                 taken[v1[i]] = 0;
          }
    }
}
int main(void)
{
    int i,j,len;
    char *p,c;
    while(gets(in))
    {
         len = strlen(in);
         if(len == 1 && in[0] == '#')
              break;
         p = strtok(in,";");
         while( p != NULL)
         {
                c = p[0];
                s1.insert(c-'A');
                len = strlen(p);
                for(i = 2;i<len;i++)
                {
                      v[c-'A'].push_back(p[i]-'A');
                      s1.insert(p[i]-'A');
                }
                p = strtok(NULL,";");
         } 
         
         for(it=s1.begin(); it != s1.end();it++)
               v1.push_back(*it);
               
         total = v1.size();
         dist = total;
         order[0] = v1[0];
         memset(taken,0,sizeof(taken));
         taken[v1[0]] = 1;
         recur(0);
         cout << char(out[0] + 'A');
         for(i = 1;i<total;i++)
         {
               cout << " " << char(out[i]+'A');
         }
         cout << " -> " << dist << endl;
         for(i = 0;i<26;i++)
         if(!v[i].empty())
         v[i].clear();
         v1.clear();
         s1.clear();
    }
    return 0;
}
