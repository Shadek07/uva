#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
vector<int> v;
class degree
{
	int deg;
public:
	degree(int a)
	{
		deg = a;

	}

	int get_deg() const
	{
		return deg;
	}
};

bool operator<(const degree &a, const degree &b)
{
  return a.get_deg() < b.get_deg();
}

int main(void)
{
	priority_queue<degree> mypq;

	int n;
	int ch,i,j,k,a,b;
	while(1)
	{
		cin >> n;
		if(!n)
			break;
		ch  =1;

		for(i = 0; i < n; i++)
		{
			cin >> a;
			mypq.push(degree(a));

		}

		while(mypq.size() > 1)
		{
			b = mypq.top().get_deg();
			if(b < 0)
			{
				ch = 0;
				break;
			}

			mypq.pop();

			if(!v.empty())
				v.clear();

			for(i = 1; i <= b;i++)
			{
				j = mypq.top().get_deg();
				if(j - 1 < 0)
				{
					ch = 0;
					goto nt;
				}

				mypq.pop();
				v.push_back(j-1);
			}

			for(i = 0; i < b;i++)
			{
				k = v[i];
				mypq.push(degree(k));

			}
		}

nt:

		if(ch == 0)
		{
			cout << "Not possible\n";
		}
		else
		{
			a = mypq.top().get_deg();
			if(a == 0)
			{
				cout << "Possible\n";
			}
			else
			{
				cout <<  "Not possible\n";
			}
		}
		while(!mypq.size())
		{
			mypq.pop();
		}

		

	}
	return 0;
}