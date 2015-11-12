#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int cnt[105];

int in[15];

set<int> s1;

vector<int> v,v1;

int tar;
int n;
int taken[15];
int cardinality[15];
int end;
int ch;
int modified[15];

struct small
{
	int val;
	int cnt;

}all[20];

bool comp(small a,small b)
{
	if(a.val > b.val)
		return 1;
	else
		return 0;
}

void solve(int add,int ind)
{
	int j,k;
	if(add == tar)
	{
		int a = 1;
		ch = 1;
		for(j = 0; j < end;j++)
		{
			if(taken[j])
			{
				for(k = 0; k < cardinality[j];k++)
				{
					if(a == 1)
					{
						cout << modified[j];
						a = 0;
					}
					else
						cout << "+" << modified[j];
				}
			}
		}

		cout << endl;
	}
	else
	{
		for(j = ind; j < end;j++)
		{
			if(taken[j] == 0)
			{
				for(k = v[j]; k >= 1;k--)
				{
					int b = add + modified[j]*k;
					if(b <= tar && b > add)
					{
						taken[j] = 1;
						cardinality[j] = k;
						solve(b,j+1);
						taken[j] = 0;
						//v[j]--;						
					}
				}
			}
		}
	}
}
int main(void)
{

	int i,a;

	set<int>::iterator it;

	while(1)
	{
		cin >> tar >> n;
		if(!n)
			break;

		memset(cnt,0,sizeof(cnt));

		for(i = 0; i < n;i++)
		{
			cin >> a;
			s1.insert(a);
			cnt[a]++;
		}

		i = 0;

		//sort(s1.begin(),s1.end());

		for ( it=s1.begin() ; it != s1.end(); it++ )
		{
				a = *it;
				all[i].val = a;
				all[i].cnt = cnt[a];
				i++;
		}

		end = s1.size();
		sort(all,all+end,comp);
		for(i =0; i < end;i++)
		{
			v.push_back(all[i].cnt);
			modified[i] = all[i].val;
		}

		memset(taken,0,sizeof(taken));
		ch = 0;
		cout << "Sums of " << tar << ":\n";
		solve(0,0);
		if(ch == 0)
			cout << "NONE\n";
		

		s1.clear();
		v.clear();
	}
	
	return 0;
}