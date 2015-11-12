#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

int N,M;



/*class num
{
public:
	int n;

	num(){}
      num(long int val)
      {
         n = val;
         
      }
};*/

//vector <num> info;

vector <int> info;


/*bool compare(num a,num b)
{
	if(a.n%M != b.n%M)
		return a.n%M < b.n%M;

	if(a.n%M == b.n%M)
	{
		if( a.n%2 == 1 && b.n%2 == 0)
		{
			return a.n%2 > b.n%2;
		}
		if( a.n%2 == 1 && b.n%2 == 1)
		{
			return a.n > b.n;
		}
		if( a.n%2 == 0 && b.n%2 == 0)
		{
			return a.n < b.n;
		}
	}
}*/
bool odd (int x)
{
	    if ( x < 0 ) x *= -1;
	    if ( x % 2 ) return true;
	    return false;
}
	 
bool even (int x)
{
	    if ( x < 0 ) x *= -1;
	    if ( x % 2 == 0 ) return true;
	    return false;
}

bool compare(int a,int b)
{
	if(a%M < b%M)
		return true;

	if(a%M == b%M)
	{
		
		if( odd(a) && even(b))
		{
			
				return true;
		}
		if( odd(a) && odd(b))
		{
			if(a > b)
			return true;
			else
				return false;
		}
		if( even(a) && even(b))
		{
			if( a < b)
				return true;
			else
				return false;
		}
	}

	return false;
}

int main(void)
{
	long int i,a;
	int inf[10003];

	while(1)
	{
		cin >> N >> M;
		if( !N && !M)
		{
			cout << N << " " << M << endl;
			break;
		}

		for( i = 0; i < N; i++)
		{
			 cin >> a;
			 //info.push_back(a);
			 inf[i] = a;
		}

		sort(inf, inf+N, compare);

		cout << N << " " << M << endl;

		for(i = 0; i < N; i++)
		{
			cout << inf[i] << endl;
		}
	}

	return 0;
}