
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

int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	double avg;
	int c,s;
	int i,j;
	vector<int> v;
	int st = 1;
	int a;
	double sum;
	while(cin >> c >> s)
	{
		 sum = 0;
		 for(i = 0;i<s;i++)
		 {
			cin >> a;
			v.push_back(a);
			sum += a;
		 }
		 avg = sum/c;
		 //cout << avg << endl;
		 for(i = s+1;i<=2*c;i++)
			 v.push_back(0);
		 sort(v.begin(),v.end());
		 double imv = 0;
		 i = 0;
		 int k = 0;
		 j = 2*c-1;
		 cout << "Set #" << st++ << endl;
		 while(i<j)
		 {
			 if(v[i] == 0 && v[j] == 0)
			 {
				 cout << " " << k << ":\n";
				 imv += avg;
			 }
			 else if(v[i] == 0 && v[j] != 0)
			 {
				 cout <<" " <<  k << ": " << v[j] << endl;
				 if(v[j] > avg)
					 imv += v[j]*1.0 - avg;
				 else
					 imv += (avg-v[j]);
			 }
			 else
			 {
					cout <<" " <<  k << ": " << v[i] << " " << v[j] << endl;
					if(v[j] +v[i]> avg)
					 imv += (v[j]+v[i])*1.0 - avg;
				 else
					 imv += (avg-(v[j]+v[i]));
			 }
			 i++;
			 j--;
			 k++;
		 }
		 while(k<c-1)
		 {
			 imv += avg;
			 k++;
			 cout << " " << k << ":\n";
		 }
		 printf("IMBALANCE = %.5f\n\n",imv);
		 v.clear();
	}
    
	return 0;
}