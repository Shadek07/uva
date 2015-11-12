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
#include<stack>

using namespace std;


struct window
{
	int XLL,YLL;
	int XUR,YUR;
}win[3];

bool comp(window a,window b)
{
	if(a.XLL < b.XLL)
		return true;
	else return false;
}

int main(void)
{
	int t,a,b,c,d;
	cin >> t;
	bool ch = false;
	while(t--)
	{
		cin >> a >> b >> c >> d;
		win[0].XLL = a;
		win[0].YLL = b;
		win[0].XUR = c;
		win[0].YUR = d;
		cin >> a >> b >> c >> d;
		win[1].XLL = a;
		win[1].YLL = b;
		win[1].XUR = c;
		win[1].YUR = d;
		sort(win,win+2,comp);
		if(ch)
			cout << endl;
		else
			ch = true;

		win[2].XLL = win[1].XLL;
		if((win[1].XLL >= win[0].XUR))
		{
			cout << "No Overlap\n";
			continue;
		}

		if(win[1].YLL > win[0].YLL && win[1].YLL < win[0].YUR)
		{
			win[2].YLL = win[1].YLL;
		}
		else
		{
			win[2].YLL = win[0].YLL;
		}

		if((win[1].YLL >= win[0].YUR) || (win[1].YUR <= win[0].YLL))
		{
			cout << "No Overlap\n";
			continue;
		}

		if(win[1].XUR >= win[0].XUR)
		{
			win[2].XUR = win[0].XUR;
		}
		else
		{
			win[2].XUR = win[1].XUR;
		}

		if(win[1].YUR >= win[0].YUR)
		{
			win[2].YUR = win[0].YUR;
		}
		else
		{
			win[2].YUR = win[1].YUR;
		}

		cout << win[2].XLL << " " << win[2].YLL << " " << win[2].XUR << " " << win[2].YUR << endl;


	}
	return 0;
}