#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int in[50002];
int wrt,n;
int find_short(int low,int high)
{
	int mid,i;

	if(low == high - 1 && low == 0 && in[0] < wrt)
	{
		return 0;
	}

	if(low == high - 1 && low == 0 && in[0] >= wrt)
	{
		return -1;
	}

	if(low == high -1 && low != 0 && in[low] < wrt && wrt <= in[high] )
	{
		return low;
	}

	if(low == high -1 && low != 0 && in[high] < wrt )
	{
		return high;

	}

	if(low == high)
	{
		if(low == 0 && in[0] >= wrt)
			return -1;
		else
			return low;

	}

	mid = (low+high)/2;

	if(in[mid] >= wrt)
	{
		i = find_short(low,mid);
		return i;

	}
	if(in[mid] < wrt)
	{
		i = find_short(mid,high);
		return i;
	}

}

int find_high(int low,int high)
{

	int mid,i;

	if(low == high - 1 && high == n-1 && in[high] <= wrt)
	{
		return -1;
	}

	if(low == high - 1 && high == n-1 && in[high] > wrt)
	{
		return high;
	}

	if(low == high -1 && high != n-1 && in[low] <= wrt && wrt < in[high] )
	{
		return high;
	}

	if(low == high -1 && high != n-1 && in[low] > wrt )
	{
		return low;

	}

	if(low == high)
	{
		if(low == n-1 && in[n-1] <= wrt)
			return -1;
		else
			return low;

	}

	mid = (low+high)/2;

	if(in[mid] > wrt)
	{
		i = find_high(low,mid);
		return i;

	}
	if(in[mid] <= wrt)
	{
		i = find_high(mid,high);
		return i;
	}


}
int main(void)
{
	int i,j,k,t,b;
	cin >> n;
	for(i = 0; i < n;i++)
	{
		scanf("%d",&in[i]);
	}

	cin >> t;

	for(i = 0; i < t;i++)
	{
		scanf("%d",&k);
		wrt = k;
		j = find_short(0,n-1);
		if(j == -1)
			cout << "X ";
		else
			cout << in[j] << " ";

		b = find_high(0,n-1);

		if(b == -1)
			cout << "X\n";
		else
			cout << in[b] << endl;

	}
	return 0;
}