
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
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

int mx;

struct node
{
    bool endmark;
	int depth;
	int cnt; //number of words passing through this node
    node *next[2];
	
    node()
    {
        endmark=false;
		depth = 0;
		int i;
        for(i=0;i<2;i++) next[i]=NULL;
    }
}*root;
 
void insert(char *str,int len)
{
    node *curr=root;
	int i;
    for(i=0;i<len;i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
		{
            curr->next[id]=new node();
			curr->next[id]->cnt = 1;
			curr->next[id]->depth = curr->depth+1;
		}
		else
		{
			curr->next[id]->cnt++;
			int tmp = curr->next[id]->cnt;
			tmp *= curr->next[id]->depth;
			if(tmp > mx)
				mx = tmp;
		}
		
        curr=curr->next[id];
    }

    curr->endmark=true;
     
}

bool search(char *str,int len)
{
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(node *cur)
{
	int i;
      for(i=0;i<2;i++)
             if(cur->next[i])
                  del(cur->next[i]);
  
          
         delete(cur) ;
}


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	mx = -1;
	int t;
	cin >> t;
	int n;
	int i;
	char in[201];
	while(t--)
	{

		root=new node();
		cin >> n;
		getchar();
		mx = -1;

		for(i = 0;i<n;i++)
		{
			gets(in);
			int len = strlen(in);
			insert(in, len);
			if(len > mx)
				mx = len;
		}

		cout << mx << endl;
		del(root);
	}
    return 0;
}
