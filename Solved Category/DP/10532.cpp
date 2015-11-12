
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
#include<stack>
#include<list>
using namespace std;


int main() 
{ 
int m, n, data[51], r[50], i, j, k, counter, temp; 
unsigned long long tab[51][51]; 

counter = 1; 
while(true)
{ 
cin>>n>>m; 
if(n==0)break; 
for(i=0; i<=50; i++)data[i] = 0; 
	for(i=1; i<=n; i++)
	{ 
		cin>>temp; 
		data[temp]++; 
	} 

	for(j=0; j<m; j++) cin>>r[j]; 

	for(i=1; i<=n; i++) tab[0][i] = 0;
	
	for(i=0; i<=n; i++) tab[i][0] = 1; 

	for(i=1; i<=n; i++)
	{ 
		for(j=1; j<=n; j++)
		{ 
			tab[j][i] = tab[j-1][i]; 
			for(k=1; k<=min(i,data[j]); k++)
			{ 
				tab[j][i] += tab[j-1][i-k]; 
			} 
		} 
	}
	
	cout<<"Case "<<counter<<":\n"; 
	for(i=0; i<m; i++) cout<<tab[n][r[i]]<<endl; 
	counter++; 
} 
return 0;
}