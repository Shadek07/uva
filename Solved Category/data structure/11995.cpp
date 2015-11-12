#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<stack>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>

using namespace std;


class Thread1 {
  int priority;
  
public:
  Thread1()
  { 
     
     priority = 0; 
  }
  Thread1( int p) 
  { 
      
     priority = p; 
  }

 
  int getpriority() const 
  { 
     return priority; 
  }
};

// Determine priority.
bool operator<(const Thread1 &a, const Thread1 &b)
{
  return a.getpriority() < b.getpriority();
}

int n;
int main(void)
{
	priority_queue<Thread1> sec;
	stack<int> st;
	queue<int> que;
    int i,j,k,a,b,c;
	int s,s1,q,q1,pq,pqi,pqd;
    while(cin >> n)
	{
		s = q = pq = 0;
		s1 = q1  = pqd = 1;
		for(i = 0;i<n;i++)
		{
			cin >> a >> b;
			if(a == 1)
			{
				if(s1) //stack
				{
					st.push(b);
				}
				if(q1)
				{
					que.push(b);
				}
				if(pqd)
				{
				    sec.push(Thread1(b));
				}
			}
			if(a == 2)
			{
				if(s1)
				{
					if(st.size() > 0)
					{
						c = st.top();
						if(c != b)
							s1 = 0;
						else
							st.pop();
					}
					else
						s1 = 0;
				}
				if(q1)
				{
					if(que.size() > 0)
					{
						c = que.front();
						if(c != b)
							q1 = 0;
						else
							que.pop();
					}
					else
						q1 = 0;
				}
				if(pqd)
				{
					if(sec.size()>0)
					{
						c = sec.top().getpriority();
						if(c != b)
						{
							pqd = 0;
						}
						else
							sec.pop();
					}
					else
						pqd = 0;

				}
			}
		}

		if((s1 && q1)||(q1&&pqd) ||(s1 && pqd))
		{
			cout << "not sure\n";
			
		}
		else if(s1 == 1 && q1 == 0 && pqd ==0)
			cout << "stack\n";
		else if(s1 == 0 && q1 == 1 && pqd ==0)
			cout << "queue\n";
		else if(s1 == 0 && q1 == 0 && pqd ==1)
			cout << "priority queue\n";
		else
			cout << "impossible\n";
			

		while(!st.empty())
			st.pop();
		while(!que.empty())
			que.pop();
		while(!sec.empty())
			sec.pop();

	}
	return 0;
}