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

using namespace std;

bool all[27];

vector<int> adj[27];
vector<int> wake;
int slept;
int m;
char in[4];


int main(void)
{
    int ind;
    int i,j;
    int day;
    int temp;
	int mx;
	bool ch;
    while(cin >> slept >> m)
    {
              getchar();
              gets(in);
              memset(all,false,sizeof(all));
              mx = 0;
              all[in[0]-'A'] = all[in[1]-'A'] = all[in[2]-'A'] = true; 
			  if(in[0]-'A' > mx)
				  mx = in[0]-'A';
			  if(in[1]-'A'>mx)
				  mx = in[1]-'A';
              slept -= 3;
              ch = true;
              for(i = 0;i<m;i++)
			  {
				  gets(in);
				  adj[in[0]-'A'].push_back(in[1]-'A');
				  adj[in[1]-'A'].push_back(in[0]-'A');
				  if(in[0]-'A' > mx)
					mx = in[0]-'A';
				  if(in[1]-'A'>mx)
					mx = in[1]-'A';
			  }
			  day = 0;
			  while(1)
			  {
				  wake.clear();
				  if(slept == 0)
					  break;
				  for(i = 0;i<=mx;i++)
				  {
					  if(all[i] == false)
					  {
						  ind = adj[i].size();
						  temp = 0;
						  for(j = 0;j<ind;j++)
						  {
							  if(all[adj[i][j]]==true)
								  temp++;
						  }
						  if(temp>=3)
							  wake.push_back(i);
					  }
				  }
				  ind = wake.size();
				  if(slept > 0 && ind == 0)
				  {
					  ch = false;
					  goto nt;
				  }
				  slept -= ind;
				  for(j = 0;j<ind;j++)
				  {
					   all[wake[j]]=true;
				  }
				  day++;
					
			  }
nt:
              if(!ch)
              cout << "THIS BRAIN NEVER WAKES UP\n";
              else
              cout << "WAKE UP IN, " << day << ", YEARS\n";
			  for(i = 0;i<=mx;i++)
			  {
				  if(!adj[i].empty())
					  adj[i].clear();
			  }
              
    }
    
    return 0;
}
