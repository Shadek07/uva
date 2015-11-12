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
set<string> project[101];
set<string> disqualified;   //deleted students from project
char names[101][101];
struct pro
{
	char name[101];
	int students;
};

vector<pro> v;

bool comp(pro a, pro b)
{
	if(a.students > b.students)
		return true;
	else if(a.students == b.students && strcmp(a.name,b.name) < 0)
		return true;
	else
		return false;
}
int main(void)
{
	int i,j,k,len;
	char in[500];
	while(1)
	{
		gets(in);
		if(strcmp(in,"0") == 0)
			break;
		i = 0;
		strcpy(names[i],in);
		while(1)
		{
			gets(in);
			if(strcmp(in,"1") == 0)
			break;
			len = strlen(in);
			bool ch = false;
			for(j = 0; j < len;j++)
			{
                  if(in[j] >='a' && in[j] <= 'z')
				  {
					  ch = true;
					  break;
				  }
			}

			if(ch == true)
			{
				int del = 0;
				for(k = 0; k < i; k++)
				{
					if(project[k].count(in) == 1)
					{
						project[k].erase(in);
						disqualified.insert(in);
						del = 1;
					}
				}
				if(del==0 && disqualified.count(in) == 0)
				project[i].insert(in);
			}
			else
			{
				i++;
				strcpy(names[i],in);
			}


		}

		struct pro a;
		
		for(k = 0; k <= i; k++)
		{
			strcpy(a.name,names[k]);
			a.students = project[k].size();
			v.push_back(a);
		}

		sort(v.begin(),v.end(),comp);

		for(k = 0; k <= i;k++)
		{
			cout << v[k].name << " " << v[k].students << endl;
		}
		v.clear();
		disqualified.clear();
		for(k = 0; k <= i; k++)
			project[k].clear();


	}
	return 0;
}