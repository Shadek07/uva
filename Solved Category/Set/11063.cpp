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

int val[101];
int main(void)
{
	int i,j,k,a,b;
	int n;
	set<int> st;
	int ca = 1;
	bool ch;
	while(cin >> n)
	{
		for(i = 0; i < n;i++)
		{
			cin >> val[i];
		}
		ch = true;

		if(val[0] < 1)
			ch = false;

		for(i = 0; i <= n-1 && ch;i++)
		{
			for(j = i;j<n;j++)
			{
				st.insert(val[i]+val[j]);
				if(j > i && val[j] <= val[i])
					ch = false;
			}
		}

		cout << "Case #" << ca++ << ": ";
		a = (n*n - n  + 2*n)/2;
		b = st.size();
		//cout << a << " " << b << endl;
		if(a == b && ch)
		{
			cout << "It is a B2-Sequence.\n\n";
		}
		else
			cout << "It is not a B2-Sequence.\n\n";
		st.clear();

	}
	return 0;
}