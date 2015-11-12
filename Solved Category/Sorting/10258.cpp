
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
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)

struct score
{
	int solved; //number of solved problems
	int penalty;
	int id; //contestant's id
}team[103];

struct rank
{
	int solved;
	int penalty;
	int id;
}rnk[101];

bool join[101];//join[i] is true if contestant with id i have submitted any problem
bool cor[101][10]; //cor[i][j] is true if contestant i have solved problem number j
int cnt[101][10]; //cnt[i][j] is number of incorrect submissions for problem j of contestant i prior to correct submission

int comp(rank p1,rank q1)
{
	if(p1.solved > q1.solved)
		return 1;
	else if(p1.solved == q1.solved)
	{
		if(p1.penalty < q1.penalty)
			return 1;
		else if(p1.penalty == q1.penalty)
		{
			if(p1.id < q1.id)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}
int main(void)
{
	int t,i,j,k;
	char in[100];
	cin >> t;
	getchar();
	getchar();
	string s1;
	int a,problem,time,d;
	char temp[5];
	bool ch = false;
	int mx;
	while(t--)
	{
		memset(join,false,sizeof(join));
		memset(cor,false,sizeof(cor));
		memset(cnt,0,sizeof(cnt));
		for(i = 0;i<=99;i++)
		{
			team[i].id = i;
			team[i].solved = 0;
			team[i].penalty = 0;
		}

		mx = -1;
		while(gets(in))
		{
			if(strlen(in)==0)
				break;
			s1 = in;
			istringstream is(s1);
			is >> a;
			is >> problem;
			is >> time;
			is >> temp;
			if(a > mx)
				mx = a;
			join[a-1] = true;

			if(strcmp(temp,"I") == 0)
			{
				cnt[a-1][problem]++;
			}
			else if(strcmp(temp,"C") == 0 && cor[a-1][problem] == false)
			{
				team[a-1].solved++;
				team[a-1].penalty += (time + 20*cnt[a-1][problem]);
				cor[a-1][problem] = true;
			}
		}

		if(ch==false)
			ch = true;
		else
			cout << endl;


		j = 0;
		k = 0;
		for(i = 0;i< mx;i++)
		{
			if(join[i]==true)
			{
				rnk[j].id = team[i].id+1;
				rnk[j].penalty = team[i].penalty;
				rnk[j].solved = team[i].solved;
				j++;
			}
		}
		sort(rnk,rnk+j,comp);
		for(i = 0;i<j;i++)
		{
			cout << rnk[i].id << " " << rnk[i].solved << " " << rnk[i].penalty<<endl;
		}
		//cout << join[0] << " " << join[1] << " " << join[2] << endl;
	}
	return 0;
}