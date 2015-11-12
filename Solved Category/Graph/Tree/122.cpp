
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

using namespace std;

int node[100000];
bool ch[100000];
bool stop;
bool complete;
int mx;
vector<int> num;
map<int,string> mp; //map index to path like "LLRL"
queue<int> pq;
vector<int> ans;
void process(char in[100000])
{
	char *p;
	int ind;
	int value,k,i;
	int len;
	char path[100000];
	p = strtok(in," \		");
	while(p != NULL)
	{
		len = strlen(p);
		if(strcmp(p,"()")==0)
		{
			stop = true;
		}
		else
		{
			ind = 1;
			value = 0;
			for(i = 1;p[i] != ',';i++)
				value = value*10 + (p[i]-'0');
			i++;
			k = 0;
			for(;i<len-1;i++,k++)
			{
				if(p[i] == 'L')
					ind = 2*ind;
				else
					ind = 2*ind + 1;
				path[k] = p[i];
			}
			path[k] = '\0';
			mp[ind] = path;
			if(ch[ind] == true)
				complete = false;
			else
			{
				ch[ind] = true;
				node[ind] = value; //save node value
				num.push_back(ind);
				if(ind > mx)
					mx = ind;
			}
		}
		p = strtok(NULL," \		");
	}

}
int main(void)
{
	char in[100000];
	char *p;
	int i,j,k,len,a,b;

	while(gets(in))
	{
		stop = false;
		memset(ch,false,sizeof(ch));
		complete = true;
		mx = 0;
		process(in);
		while(stop == false)
		{
			gets(in);
			process(in);
		}
		if(complete == false)
		{
			cout << "not complete\n";
		}
		else
		{
			len = num.size();
			if(len == 0)//no root
			{
				cout << "not complete\n";
				goto nt;
			}
			for(i = 0;i<len;i++)
			{
				j = num[i];
				strcpy(in,mp[j].c_str());
				k = 1;
				int l = 0;
				while(k != j)
				{
					if(ch[k] == false)
					{
						complete = false;
						break;
					}
					if(in[l] == 'L')
						k = 2*k;
					else
						k = 2*k + 1;
					l++;
				}
			}
			if(complete == false)
				cout << "not complete\n";
			else
			{
				pq.push(1);
				while(!pq.empty())
				{
					j = pq.front();
					ans.push_back(node[j]);
					pq.pop();
					if(ch[2*j] == true)
						pq.push(2*j);
					if(ch[2*j+1] == true)
						pq.push(2*j+1);
				}
				len = ans.size();
				if(len == 0)
					cout << "not complete\n";
				else
				{
					cout << ans[0];					
					for(j = 1;j<len;j++)
						cout << " " << ans[j];
					cout << endl;
				}
			}
		}

nt:
		ans.clear();
		mp.clear();
		num.clear();
	}
	return 0;
}

