
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

using namespace std;

#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

unsigned long long int N;
unsigned long long int fact[21];

void facto()
{
	unsigned long long int a = 1;
	unsigned long long int i;
	fact[1] = 1;
	for(i = 2;i<21;i++)
	{
		fact[i] = fact[i-1]*i;
	}
}

string calc(string s, unsigned long long int step)
{
	sort(s.begin(),s.end());
	if(step == 0)
		return s;
	
	int sz = s.size();
	if(sz == 2 && step == 1)
	{
          reverse(s.begin(),s.end());
          return s;
    }
    if(sz == 2 && step == 0)
	{
          return s;
    }
	unsigned long long int a;
	int i = 0,j;
	a = 0;
	string ans = "";
	while(step != 0)
	{
        a = 0;
        i = 0;
        sz = s.size();
    	int k = step / fact[sz-1];
		unsigned long long int mod = step % fact[sz-1];
	
    	string s1;
        
        step = mod;
        
        ans  += s[k];
        s = s.substr(0,k) + s.substr(k+1, s.length()- k-1);
    }
    
    return ans + s;
}

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	int t,i,j;
	cin >> t;
	string s;
	facto();
	//cout << fact[20]  << endl;
	while(t--)
	{
		cin >> s;
		cin >> N;
		sort(s.begin(),s.end());
		s = calc(s,N);
		cout << s << endl;
	}
    
	return 0;
}
