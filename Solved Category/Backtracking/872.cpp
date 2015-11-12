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
int fl;

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

		cout << char(order[i]+'A');
		for(i = 1; i < total;i++)
		{
		
			cout << " " << char(order[i]+'A');
		}

		cout << endl;
		fl = 1;
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
					//s1 += char(i+'A');
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
	int t;
	cin >> t;
	getchar();
	getchar();

	while(t--)
	{
		gets(in);
		total = 0;
		gets(constr);
		if(t > 0)
			getchar();
		len = strlen(in);
		memset(ch,0,sizeof(ch));
		memset(indeg,0,sizeof(indeg));

		for(i = 0; i < len;i++)
		{
			if(in[i] >= 'A' && in[i] <= 'Z')
			{
				var.push_back(in[i]-'A');
				ch[in[i]-'A'] = 1;
				total++;
			}
		}

		sort(var.begin(),var.end());

		len1 = strlen(constr);

		memset(before,0,sizeof(before));

		for(i = 0; i < len1;i++)
		{
			if(constr[i] >= 'A' && constr[i] <= 'Z')
			{
				j = i;
				i++;
				while(!(constr[i] >= 'A' && constr[i] <= 'Z'))
				{
					i++;
				}

				k = i;
				
                before[constr[j]-'A'][constr[k]-'A'] = 1;
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
		fl = 0;
		solve();
		if(fl == 0)
			cout << "NO\n";

		var.clear();

		
		
	}
	return 0;
}
