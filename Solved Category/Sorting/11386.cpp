
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
#include <fstream>
#include<ctime>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define MX 1000000

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }


unsigned long long int arr[5001];
int n;

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k;
    unsigned long long int prefix[5002];
    unsigned long long int suffix[5002];
    while(scanf("%d",&n) == 1)
	{
		
		forl(i,0,n)
		{
			scanf("%llu",&arr[i]);			
			
		}
		
		sort(arr,arr+n);
		prefix[0] = 1;
		forl(i,1,n)
		{
			if(arr[i] == arr[i-1])
				prefix[i] = prefix[i-1] + 1;
			else
				prefix[i] = 1;
		}
		
		suffix[n-1] = 1;
		for(i = n-2; i>= 0; i--)
		{
			if(arr[i] == arr[i+1])
				suffix[i] = suffix[i+1] + 1;
			else
				suffix[i] = 1;
		}
		
		unsigned long long int cnt = 0,t1,t2,t3;
		forl(k,2,n)
		{
			i = 0;
			j = k-1;
			while(i<j)
			{
				unsigned long long int sum = arr[i] + arr[j];
				if(sum < arr[k])
				{
					i++;
				}
				else if(sum > arr[k])
				{
					j--;
				}
				else
				{
					if(arr[i] == arr[j])
					{
						t1 = j - i + 1;
						cnt += (t1*(t1-1))/2;
						i = j;
					}
					else
					{
						t1 = suffix[i];
						t2 = prefix[j];
						cnt += (t1*t2);
						i += suffix[i];
						j -= prefix[j];
					}
				}
			}
		}
		//cout << cnt << endl;
		printf("%llu\n",cnt);
		
	}
    return 0;
}

