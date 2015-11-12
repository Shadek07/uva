#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<vector>
#include<cstdio>

using namespace std;

#define maxi(a,b) a>b?a:b

int indegree[101];
bool taken[101];
bool used[30];
bool check[101][101];
char in[1000];
int cost[50];
long int val[30];

vector<int> v[30];

int main(void)
{
	int m,n,i,j,k,a,b;

	int count;
	int estimate = -1;
	int lst;
    int sz;
	int t;
    int ch = 0;
	cin >> t;

	getchar();
	getchar();
	char *str;

	while(t--)
	{

		memset(indegree,0,sizeof(indegree));
		memset(taken,false,sizeof(taken));
		memset(check,false,sizeof(check));
		memset(cost,0,sizeof(cost));
		memset(val,0,sizeof(val));
		memset(used,false,sizeof(used));

		count = 0;
		m = 0;
		while(gets(in))
		{
			if(strlen(in) == 0)
				break;

			str = strtok(in," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			m++;

			a = str[0] - 65;
            used[a] = true;
			str = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");

			int tra = atoi(str);

			cost[a] = tra;
            //val[a] = cost[a];
			str = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");

			int len;
			if(str != NULL)
				 len = strlen(str);
			else
				len = 0;

			for(i = 0; i < len; i++)
			{

				b = str[i] - 65;

				check[a][b] = true;

				indegree[a]++;
				v[b].push_back(a);

			}


		}

		estimate = -1;

		while(count != m)
		{
			for(i = 0; i < 26; i++)
			{
				if(used[i] == true && indegree[i] == 0 && taken[i] == false)
				{
					
                    lst = i;
					count++;
					taken[i] = true;
					sz = v[i].size();
					if(sz == 0)
					{
                          if(cost[i] > estimate)
                               estimate = cost[i];
                    }
                    
					for(j = 0; j < sz; j++)
					{
                        b = v[i][j];
                        
                        if(check[b][i] == true)
						{
                            val[b] = maxi(val[b],val[i] + cost[i]);
                            if(val[b] > estimate)
                            estimate = val[b];
							indegree[b]--;
							if(indegree[b] == 0 && v[b].size() == 0)
							{
                                val[b] = val[b] + cost[b];
                                if(val[b] > estimate)
                                estimate = val[b];           
                            }
							check[b][i] = false;
						}
					}
				}
			}
		}

        if(ch == 0)
        ch = 1;
        else
        cout << endl;
		cout << estimate << endl;
		
		for(i = 0; i < 26;i++)
        {
              if(!v[i].empty())
              v[i].clear();
        }

	}

	return 0;
}
