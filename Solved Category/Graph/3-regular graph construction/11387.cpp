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

int main(void)
{
	int n,i,j,a,b;
	bool ch[101];
	while(cin >> n && n)
	{
		if(n%2 || n==2)
		{
			cout << "Impossible\n";
			continue;
		}

		cout << n*3/2 << endl;
		for(i = 1;i<=n;i++)
		{
			a = (i+1)%n;
			if(a==0)
				a = n;
			cout << i << " " << a <<endl;
		}
		memset(ch,false,sizeof(ch));
		for(i = 1;i<= n-3;i+=2)
		{			
			cout << i << " " <<i+3<<endl;				
		}
		cout << n-1 << " " << 2 << endl;
		
	}
	return 0;
}