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
    long long sum;
	int n;
	int ch,i,j,k,a,b;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		sum = 0;
		if(n == 0)
		{
             cout << "Yes\n";
             continue;
        }
		ch  =1;

		for(i = 0; i < n; i++)
		{
			cin >> a;
			sum += a;
			mypq.push(degree(a));
		}

        if(sum%2)
        {
              cout << "No\n";
              while(!mypq.empty())
   		      {
     			  mypq.pop();
      		  }
              continue;   
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
			cout << "No\n";
		}
		else
		{
			a = mypq.top().get_deg();
			if(a == 0)
			{
				cout << "Yes\n";
			}
			else
			{
				cout <<  "No\n";
			}
		}
		
		while(!mypq.empty())
		{
			mypq.pop();
		}

	}
	
	return 0;
}
