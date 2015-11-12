#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

int target;

vector<int> res;

int opt;

int len[10005];

int req[10005]; //req[i] is how many step is neeeded for making 1 to i
int mark[10005];
int ans[10005];
int out[10005];
int check;
int finish;
int upper;

void minStep()
{
	int i;
	int total;
	int next;

	for(i = 2;i <= target;i++)
	{
		total = 0;
		next = 1;
		while(next <= target)
		{
			next *= 2;
			total++;
		}

		req[i] = total;

	}

}

int get(int start,int limit)
{
	int cnt = 0;
	while(start < limit)
	{
		start *= 2;
		cnt++;
	}
	return cnt;
}

void recur(int ind)
{

	int i,j,c;

	c = get(ans[ind],target);

	if(c + ind + 1 > upper)
	{
		//cout << "yea\n";
		return;
	}

	if(ans[ind] == target && upper > ind)
	{
		upper = ind;

		for ( j = 0; j < upper + 1; j++) 
		{
			out[j] = ans[j];

		}
	}


	for(i = ind; i >= 0; i--)
	{
		ans[ind+1] = ans[ind] + ans[i];
		if(ans[ind+1] <= target)
			recur(ind+1);
	}
}


int main(void)
{
	int i;
	
	req[1] = 1;
	minStep();

	while(1)
	{
		cin >> target;
		if(!target)
			break;

		if(target == 1)
		{
			cout << 1 << endl;
			continue;
		}
		if(target == 2)
		{
			cout << 1 << " " << 2 << endl;
			continue;
		}
		if(target == 3)
		{
			cout << 1 << " " << 2 << " " << 3 << endl;
			continue;
		}

		
		ans[0] = 1;
		upper = target;
		recur(0);
		

		cout << out[0];

		for(i = 1; i <= upper ;i++)
		{
			cout << " " << out[i];
		}

		cout << endl;
		
	}

	return 0;
}

