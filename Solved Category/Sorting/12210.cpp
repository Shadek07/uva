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

struct bach
{
	int age;
	bool male;
}b[20001];

bool comp(bach a,bach b)
{
	if(a.age < b.age)
		return true;
	
	return false;
}

int main(void)
{
	int i,j,k,a;
	int m,n;
	struct bach p1;
	int ca=1;
	while(cin >> m >> n)
	{
		if(!m && !n)
			break;
		for(i = 0;i<m;i++)
		{
			cin >> a;
			p1.age = a;
			p1.male = true;
			b[i]=p1;
		}
		j = m;
		for(i =0;i<n;i++)
		{
			cin>> a;
			p1.age = a;
			p1.male = false;
			b[j] = p1;
			j++;
		}

		sort(b,b+m,comp);
		cout << "Case " << ca++ << ": ";
		if(n>=m)
		{
			cout << 0 <<endl;
		}
		else
		{
			cout << m-n << " " << b[0].age << endl;
		}
	}
	return 0;
}