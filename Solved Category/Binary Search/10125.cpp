
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
using namespace std;

int n;
int arr[1001];

struct sum
{
	int x;
	int y;
	long int s;

}sm[1000001];

bool comp(sum p,sum q)
{
	if(p.s < q.s)
		return true;
	else
		return false;
}

int main(void)
{
	int i,j,k;
	struct sum s1,s2;
	long int a,b;
	while(cin >> n && n)
	{
		for(i = 0;i<n;i++)
		{
			cin >> arr[i];
		}

		sort(arr,arr+n);
		int cnt = 0;
		for(i = 0;i<n-1;i++)
		{
			for(j = i+1;j<n;j++)
			{
				s1.x = i;
				s1.y = j;
				s1.s = arr[i] + arr[j];
				sm[cnt] = s1;
				cnt++;
			}	
		}
		
		sort(sm,sm+cnt,comp);
		bool ch = false;
		for(i = n-1;i>= 0;i--)
		{
			for(j = n-1;j>=0;j--)
			{
                  if(i != j)
                  {
        				a = arr[i] - arr[j];
        				int low,high,mid;
        				low = 0;
        				high = cnt-1;
        				while(low <= high)
        				{
        					mid = (low+high)>>1;
        					//cout << low << " " << high << endl; 
        					if(sm[mid].s == a && !(sm[mid].x == i || sm[mid].x == j) && !(sm[mid].y == i || sm[mid].y == j))
        					{
        						cout << arr[i] << endl;
        						ch = true;
        						i = 0;
        						j = 0;
        						break;
        					}
        					else if(sm[mid].s < a)
        					{
        						low = mid+1;
        					}
        					else
        						high = mid-1;
        				}
                    }
			}
		}

		if(!ch)
			cout << "no solution\n";

	}
	return 0;
}
