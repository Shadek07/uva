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
#define N 100000

bool mark [N];
vector <int> primeList;
vector <int> factors [1000 + 10];
typedef pair<int,int> pa;

void sieve ()
{
	memset (mark, true, sizeof (mark));

	mark [0] = mark [1] = false;

	int i,j;
	for ( i = 4; i < N; i += 2 ) mark [i] = false;

	for (  i = 3; i * i <= N; i += 2 ) {
		if ( mark [i] ) {
			for ( j = i * i; j < N; j += 2 * i ) mark [j] = false;
		}
	}

	primeList.clear ();
	primeList.push_back (2);

	for (i = 3; i < N; i += 2 ) 
	{
		if (mark [i]) 
			primeList.push_back (i);
	}

	//printf ("%d\n", primeList.size ());
}
int main(void)
{
	int num,i,j,k;
	char in[1000];
	char *p;
	int a,b;
	vector<pa> v;
	pa p2;
	sieve();
	while(gets(in))
	{
		num = 1;
		if(in[0] == '0')
			break;
		p = strtok(in," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
		while(p != NULL)
		{
			a = atoi(p);
			p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			b = atoi(p);
			for(i=0;i<b;i++)
				num *= a;
			p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
		}

		a = num-1;
		i=0;
		while(a>1)
		{
			bool ch=false;
			int cnt = 0;
			while(a%primeList[i]==0)
			{
				a /= primeList[i];
				ch = true;
				cnt++;
			}
			if(ch)
			{
				p2.first = primeList[i];
				p2.second = cnt;
				//p2 = make_pair(primeList[i],cnt);
				v.push_back(p2);
			}
			i++;
		}

		j = v.size();
		for(i = j-1;i>=0;i--)
		{
			if(i==j-1)
				cout << v[i].first << " " << v[i].second;
			else
				cout << " " << v[i].first << " " << v[i].second;
		}
		cout << endl;
		v.clear();
	}
	return 0;
}
