#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;
char in[1000];

#define INF 9999999
#define min1(a,b) a<b?a:b
int deg[26];
int cost[26][26];
long long int all_pair[26][26];

vector<int> adj[26];
int odd[2];
int main(void)
{
    int i,j,k,len;
    int ind;
    long long int total;
    while(gets(in))
    {
         total = 0;
         memset(deg,0,sizeof(deg));
         for(i = 0; i < 26;i++)
         {
               for(j = 0; j < 26;j++)
               {
                    all_pair[i][j] = 99999999; 
               }
         }
         len = strlen(in);
         total += len;
         cost[in[0]-'a'][in[len-1]-'a'] = len;
         cost[in[len-1]-'a'][in[0]-'a'] = len;
         all_pair[in[0]-'a'][in[len-1]-'a'] = len;
         all_pair[in[len-1]-'a'][in[0]-'a'] = len;
         deg[in[0]-'a']++;
         deg[in[len-1]-'a']++;
         while(1)
         {    
             gets(in);     
             if(strcmp(in,"deadend") == 0)
             break;
             
             len = strlen(in);
             cost[in[0]-'a'][in[len-1]-'a'] = len;
             cost[in[len-1]-'a'][in[0]-'a'] = len;
             all_pair[in[0]-'a'][in[len-1]-'a'] = len;
             all_pair[in[len-1]-'a'][in[0]-'a'] = len;
             deg[in[0]-'a']++;
             deg[in[len-1]-'a']++;
             total += len;
         }
                  
         ind = 0; 
         for(i = 0; i < 26;i++)
         {
             if(deg[i] != 0 && deg[i]%2 == 1)
             {
                       odd[ind++] = i;
             }  
         }
         if(ind == 0)
         {
                cout << total << endl;
         }
         else
         {
               
               for(k = 0; k < 26;k++)
               {
                     for(i = 0; i < 26;i++)
                     {
                           for(j = 0; j < 26;j++)
                           {
                                 all_pair[i][j] = min1(all_pair[i][j],all_pair[i][k] + all_pair[k][j]);
                           } 
                     }
               }
               
               cout << total + all_pair[odd[0]][odd[1]] << endl;
         }        
    }
    return 0;
}
