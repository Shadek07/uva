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
map<string,int> mp;
map<string,string> out;
int main(void)
{
	int ind=1;
	char in[20];
	mp["HELLO"] = ind++;
	out["HELLO"] = "ENGLISH";
	mp["HOLA"] = ind++;
	out["HOLA"] = "SPANISH";
	mp["HALLO"] = ind++;
	out["HALLO"] = "GERMAN";
	mp["BONJOUR"] = ind++;
	out["BONJOUR"] = "FRENCH";
	mp["CIAO"] = ind++;
	out["CIAO"] = "ITALIAN";
	mp["ZDRAVSTVUJTE"] = ind++;
	out["ZDRAVSTVUJTE"] = "RUSSIAN";
	int ca=1;
	while(gets(in))
	{
		if(strcmp(in,"#")==0)
			break;
		cout << "Case " << ca++ <<": ";
		if(mp[in])
		{
			cout << out[in]<<endl;
		}
		else
			cout << "UNKNOWN\n";
	}
	return 0;
}