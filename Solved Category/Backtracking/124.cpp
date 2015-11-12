#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
char in[500];
char constr[500];

vector<int> var;
vector<int> out;
vector<int> adj[30];
int indeg[30];
int ch[30];
int total;
int taken[30];
int before[30][30]; //before[i][j] is 1 if i should be in a position that is prior to the position of j
string s1;
int order[30];
int ind;
void solve()
{
	int i,j;
	int flag;
	int cnt = 0;
	/*for(i = 0; i < 26;i++)
	{
		if(taken[i] == 1 && ch[i])
			cnt++;
	}*/
	if(ind == total)
	{
		for(i = 0; i < total;i++)
		{
		
			cout << char(order[i]+'a');
		}

		cout << endl;
		return;
	}
	else
	{
		for(i = 0; i < 26;i++)
		{
			if(ch[i] && taken[i] == 0)
			{
				flag = 1;
				for(j = 0; j < 26;j++)
				{
					if(ch[j]  && i != j && taken[j] == 0 && before[j][i] == 1)
					{
						flag = 0;
						break;
					}
				}

				if(flag)
				{
					taken[i] = 1;
					//s1 += char(i+'a');
					order[ind++] = i;
					//out.push_back(i);
					solve();
					taken[i] = 0;
					ind--;
					//i++;
				}
				else
					continue;

			}
		}
	}

}


int main(void)
{
	int len,i,j,k,len1;
	int ca = 1;

	while(gets(in))
	{
		total = 0;
		gets(constr);
		len = strlen(in);
		memset(ch,0,sizeof(ch));
		memset(indeg,0,sizeof(indeg));

		for(i = 0; i < len;i++)
		{
			if(in[i] >= 'a' && in[i] <= 'z')
			{
				var.push_back(in[i]-'a');
				ch[in[i]-'a'] = 1;
				total++;
			}
		}

		sort(var.begin(),var.end());

		len1 = strlen(constr);

		memset(before,0,sizeof(before));

		for(i = 0; i < len1;i++)
		{
			if(constr[i] >= 'a' && constr[i] <= 'z')
			{
				j = i;
				i++;
				while(!(constr[i] >= 'a' && constr[i] <= 'z'))
				{
					i++;
				}

				k = i;
				
                before[constr[j]-'a'][constr[k]-'a'] = 1;
			}

		
		}

		

		if(ca == 1)
			ca = 0;
		else
			cout << endl;

		s1 = "";
		memset(taken,0,sizeof(taken));

	//	recur(0);
		ind = 0;
		solve();

		var.clear();

		
		
	}
	return 0;
}
