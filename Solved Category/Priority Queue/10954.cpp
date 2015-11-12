// priority_queue::push/pop
#include <iostream>
#include <queue>
using namespace std;

class Thread {
  int priority;
  
public:
  Thread()
  { 
     
     priority = 0; 
  }
  Thread( int p) 
  { 
      
     priority = p; 
  }

 
  int getpriority() const 
  { 
     return priority; 
  }
};

// Determine priority.
bool operator<(const Thread &a, const Thread &b)
{
  return a.getpriority() > b.getpriority();
}


int main ()
{
  priority_queue<Thread> mypq;

  
  int n,i,a,b,c;
  int cost;

  while(1)
  {
	  cin  >> n;
	  if(!n)
		  break;

	  for( i = 0; i < n; i++)
	  {
		  cin >> a;
          mypq.push(Thread(a));
	  }

	  cost = 0;

	  while (!mypq.empty())
	  {
		 b =  mypq.top().getpriority();
		 mypq.pop();
		 c = mypq.top().getpriority();
		 mypq.pop();

		 cost += (b+c);
		 if(!mypq.empty())
		 mypq.push(Thread(b+c));

	  }

      cout << cost << endl;


  }
  

  return 0;
}