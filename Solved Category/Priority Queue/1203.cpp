
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
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define rep(i,a,b) for(int i = int(a);i<=int(b);i++)
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); } 

struct query
{
	int qnum;
	int time;
	int base;
	bool operator < ( const query& p ) const 
	{
		if(p.time< time)
			return true;
		else if(p.time==time && p.qnum<qnum)
			return true;
		return false;
	}
};
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int q,t;
	int k;
	char in[15];
	query qu;
	priority_queue<query> pq;
	while(true)
	{
		cin >> in;
		if(in[0] == '#')
			break;
		cin >> q >> t;
		qu.qnum = q;
		qu.time = t;
		qu.base = t;
		pq.push(qu);
	}

	cin >> k;
	while(k--)
	{
		qu = pq.top();
		pq.pop();
		cout << qu.qnum << endl;
		qu.time += qu.base;
		pq.push(qu);
	}
    return 0;
}