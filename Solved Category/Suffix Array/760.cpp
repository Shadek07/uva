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

//#define for(i,a,b) for(i=a;i<b;i++)
#define mn(a,b) a<b?a:b
struct fir
{
	char w[305];

}c[305],c1[305];

set<string> st;

int main(void)
{
	string s1,s2,s;
	int i,j,k,a,b;
	char in[305];
	char in1[305];
	char temp[305];
	int l,l1;
	bool ch = false;
	while(gets(in))
	{
		l = strlen(in);
		while(l ==0)
		{
			gets(in);
			l = strlen(in);
		}
		gets(in1);
		l1 = strlen(in1);
		for(i = l-1,k=1;i>=0;i--,k++)
		{
			strncpy(temp,in+i,k);
			temp[k] = '\0';
			strcpy(c[k-1].w,temp);
		}
		for(i = l1-1,k=1;i>=0;i--,k++)
		{
			strncpy(temp,in1+i,k);
			temp[k] = '\0';
			strcpy(c1[k-1].w,temp);
		}

		int mx = 0;
		for(i = 0; i<l;i++)
		{
			strcpy(in,c[i].w);
			for(j = 0;j<l1;j++)
			{
				strcpy(in1,c1[j].w);
				a = strlen(in);
				b = strlen(in1);
				a = mn(a,b);
				for(k = 0;k<a;k++)
				{
					if(in[k] == in1[k])
					{
						temp[k] = in[k];
					}
					else
						break;
				}
				if(k > 0 && k>=mx)
				{
					temp[k] = '\0';
					st.insert(temp);
					mx = k;
				}
				
			}
		}

		if(ch ==false)
			ch = true;
		else
			cout << endl;
		if(mx ==0)
		{
			cout << "No common sequence.\n"; 
			continue;
		}
		set<string>::iterator it;
		for(it = st.begin(); it != st.end(); it++)
		{
			strcpy(in,(*it).c_str());
			l = strlen(in);
			if(l == mx)
				cout << in << endl;
		}
		st.clear();

	}
	return 0;
}
