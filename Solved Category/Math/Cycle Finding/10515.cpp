
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
 
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	    int data[10][5];
		char in[105],in1[105];
		
		data[0][0] = 0;
		data[1][0] = 1;
		
		data[2][0] = 6;
		data[2][1] = 2;
		data[2][2] = 4;
		data[2][3] = 8;
		
		
		data[3][1] = 3;
		data[3][2] = 9;
		data[3][3] = 7;
		data[3][0] = 1;
		
		data[4][1] = 4;
		data[4][0] = 6;
		
		data[5][0] = 5;
		
		data[6][1] = 6;
		
		data[7][1] = 7;
		data[7][2] = 9;
		data[7][3] = 3;
		data[7][0] = 1;
		
		data[8][1] = 8;
		data[8][2] = 4;
		data[8][3] = 2;
		data[8][0] = 6;
		
		data[9][1] = 9;
		data[9][0] = 1;
		while(true)
		{
		
		
		     cin >> in >> in1;
		     int l1,l2;
			 l1 = strlen(in);
			 l2 = strlen(in1);

		     
			if(l1 == l2 && l1== 1 && in[0] == '0' && in1[0] == '0')
		     		break;
		     if(in1[0] == '0')
		     {
		     	cout << 1 << endl;
		     	continue;
		     }
		     

		     int a1 = in[l1-1]-'0';

		     int b1;
		     if(l2==1)
		       b1 = in1[l2-1]-'0';
		     else
		     {
		     	b1 = in1[l2-2]-'0';
		     	b1 = b1*10 + in1[l2-1]-'0';
		       	
		     }
		     
		     int ans;
		     //b1--;
		     if(a1==0 || a1== 1 || a1== 5 || a1 ==6)
		     	ans = data[a1][0];
		     else if(a1==4 || a1 == 9)
		     	ans = data[a1][b1%2];
		     else
		     {
		     	ans = data[a1][b1%4];
		     }
		     cout << ans << endl;
        }
    return 0;
}