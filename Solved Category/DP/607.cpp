
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
#include<sstream>
#include<stack>
#include<list>
#include <bitset>
#include<iomanip>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

typedef pair<int,int> pa;

int dp[1001][501];
bool ch[1001][501];
//bool solved[1001][501];
//int memo[1001][501];
int L,C,n;
int topic[1001];
int ans1,ans2;
int need;
//Idea from Topcoder forum
int getDI(int t)
{
	return t==0?0:t<=10?-C:(t-10)*(t-10);
}

bool feasible(int ind,int rem,int lec)
{
	for(;ind<n;ind++)
	{
		if(rem-topic[ind]<0)
		{
			rem = L;
			lec++;
			ind--;
		}
		else
		{
			rem-= topic[ind];
		}
	}

	return lec+1==need;
}

int lectures()
{
	int i;
	int sum=0,cnt=0;
	for(i = 0;i<n;i++)
	{
		if(sum+topic[i]<=L)
			sum += topic[i];
		else
		{
			sum=0;
			cnt++;
			i--;
		}
	}

	return cnt+(sum>0);
}
int calc(int ind,int rem,int lec)  //rem is remaining rem left for a lecture
{
	if(ind==n && lec+1==need)
		return getDI(rem);
	if(!feasible(ind,rem,lec))
		return 1e9;
	if(ch[ind][rem])
		return dp[ind][rem];
	int t,t1;
	int ret = 1e9,a,b;
	if(rem - topic[ind] >= 0)
	{
		//filling up current lecture, increased by topic[ind]
		a = calc(ind+1,rem-topic[ind],lec); 
		
		b = 1e9;
		// start new lecture, lec is increased by 1 for previous lecture
		if(rem != 0)
		b = calc(ind,L,lec+1); 
		
 
		if( b < 1e9 )
			b += getDI(rem);
		if( a < 1e9 || b < 1e9 )
			ret = min(a,b);
	}
		
	else
	{
		a = calc(ind,L,lec+1);
		if(a < 1e9 )
			ret = a + getDI(rem);
		
	}

	ch[ind][rem] = true;
	return dp[ind][rem] = ret;

}



int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int ca=1;
	int i,j;
	pa p;
	C = 10;
	//cout << getDI(12) <<endl;
	while(cin >> n && n)
	{
		cin >> L >> C;
		for(i = 0;i<n;i++)
			cin >> topic[i];
		memset(ch,false,sizeof(ch));
		if(ca>1)
			cout << endl;
		cout << "Case " << ca++ << ":\n";
		for(i = 0;i<=n;i++)
		{
			for(j = 0;j<=L;j++)
			{
				ch[i][j] = false;
			}

		}
		i = lectures();
		need = i;
		cout << "Minimum number of lectures: " << i << endl;
		cout << "Total dissatisfaction index: " << calc(0,L,0) << endl;
	}
    
	return 0;
}