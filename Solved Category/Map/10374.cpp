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

map<string,string> mp;
map<string,int> vote;
map<string,int> check;
set<string> st;
set<string>::iterator it;
int main(void)
{
	int t;
	cin >> t;
	cin.ignore(100, '\n');
	int n,m,i,j,k;
	char in[500];
	char in1[500];
	int ch = 0;
	while(t--)
	{
		cin >> n;
		cin.ignore(100, '\n');
		mp.clear();
		vote.clear();
		st.clear();
		check.clear();
		for(i = 0;i<n;i++)
		{
			gets(in);
			st.insert(in);
			gets(in1);
			mp[in] = in1;
			check[in] = i+1;
		}
		cin >> m;
		cin.ignore(100, '\n');
		for(i = 0;i<m;i++)
		{
			gets(in);
			if(check[in] && vote[in])
				vote[in]++;
			else if(check[in])
				vote[in] = 1;
		}
		//getchar();
		int mx = -1;		
		int cnt=-1;
		string s1;
		in1[0] = '\0';
		for(it = st.begin(); it != st.end();it++)
		{
         
			 s1 = *it;
			 strcpy(in,s1.c_str());
			 if(vote[in] > 0 && vote[in] > mx)
			 {             
				 s1 = mp[in];
				 strcpy(in1,s1.c_str());
				 mx = vote[in];
			 }
           
		}

		set<string> sec;

		for(it = st.begin(); it != st.end();it++)
		{
			 s1 = *it;
			 strcpy(in,s1.c_str());
			 if(vote[in] == mx)
			 {             
				 sec.insert(in);
			 }

		}

    
		if(ch==0)
			ch=1;
		else
			cout << endl;
		if(sec.size()>1 || in1[0] == '\0')
		{
			   cout << "tie\n";
		}
		else
		{
			cout << in1 << endl;
		}

		

		}

		return 0;
}
