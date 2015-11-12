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

#define for(i,a,b) for(i=a;i<b;i++) 

map<string,int> gain;
vector<string> name;

int main(void)
{
	int n,i,j,k;
	char in[15];
	char in1[15];
	double cost,a,b;
	bool ch = 0;
	while(cin >> n)
	{
		getchar();
		for(i,0,n)
		{
			cin >> in;
			name.push_back(in);	
			gain[in] = 0;
		}
		
		for(i,0,n)
		{
			cin >> in >> cost >> k;
			if(k==0)
				continue;
			a = floor(cost/k);
			b = a;
			a *= k;
			gain[in] -= a;
			for(j,0,k)
			{
				cin >>in1;
				gain[in1] += b;
				//cout << in1 << " " << gain[in1] << endl;
			}
		}
		if(ch==0)
			ch = 1;
		else
			cout << endl;
		j = name.size();
		for(i,0,j)
		{
			cout << name[i] << " " << gain[name[i]] << endl;
		}
		name.clear();
		gain.clear();
	}
	return 0;
}