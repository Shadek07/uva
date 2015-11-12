
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
map<string, int> verb;
map<string, int> noun;
bool verb_check(string s)
{
       int sz = s.size();
       if(verb[s])
           return true;
      if(s[sz-1] == 's')
           return verb_check(s.substr(0,sz-1));
      else
            return false;

}

bool article_check(string s)
{
      if(s.compare("a") == 0 || s.compare("the") == 0)
                  return true;
      else
                  return false;
}

bool noun_check(string s)
{
      if(noun[s])
          return true;
      else
          return false;
}

bool actor_check(string s)
{
      int sz = s.size();
      int i,ind=-1;
      int space_count = 0;
      for(i=0;i<=sz-1;i++)
      {
            if(s[i] == ' ')
            {
                  space_count++;
                  ind = i;

            }
            if(space_count >1)
                 return false;
      }

	  if(sz > 0 && ind == -1)
		  return noun_check(s);
	  if(ind == -1)
		  return false;

      return article_check(s.substr(0,ind)) && noun_check(s.substr(ind+1,sz));
}

bool active_list_check(string s)
{
      int sz = s.size();

      int i,j;
	  i = 0;
	  while(i<sz && (s[i] == ' ' || s[i] == '\t'))
		  i++;
	  j = sz-1;
	  while(j>= 0 && (s[j] == ' ' || s[j] == '\t'))
		  j--;
	  s = s.substr(i,j-i+1);
	  sz = s.size();
      for(i = sz-1; i>= 5; i--)
      {
            if(s[i] == ' ' && s[i-1] == 'd' && s[i-2] == 'n' && s[i-3] == 'a' && s[i-4] == ' ')
            {
                  return active_list_check(s.substr(0,i-4)) && actor_check(s.substr(i+1,sz));
            }
      }

      return actor_check(s);
}

bool action_check(string s)
{
      int i,j,sz;
      sz = s.size();
      bool ans = false;
      bool temp;
      for(i = 1;i<sz-1;i++)
      {
            if(s[i] == ' ')
            {
                  j = i+1;
                  while(j<sz-1 && s[j] != ' ')
                       j++;
                  if(j<sz-1)
                  {
                        temp = true;
                        temp = temp && active_list_check(s.substr(0,i));
                        temp = temp &&  verb_check(s.substr(i+1,j-i-1));
                        temp = temp && active_list_check(s.substr(j+1,sz));
                        ans |=  temp;
                        if(ans == true)
                            return true;
                  }
				  i = j-1;
            }
      }

      return false;
}

bool statement_check(string s)
{
      int sz,i;
      sz = s.size();
      for(i = sz-2; i>= 4; i--)
      {
            if(s[i] == ',')
            {
                  return statement_check(s.substr(0,i)) && action_check(s.substr(i+1,sz));
            }
      }

      return action_check(s);
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    verb["hate"] = 1;
    verb["love"] = 2;
    verb["know"] = 3;
    verb["like"] = 4;

    noun["tom"] = 1;
    noun["jerry"] = 2;
    noun["goofy"] = 3;
    noun["mickey"] = 4;
    noun["jimmy"] = 5;
    noun["dog"] = 6;
    noun["cat"] = 7;
    noun["mouse"] = 8;
    char in[1000];

    while(gets(in))
    {
          if(statement_check(in))
          {
                cout << "YES I WILL\n";
          }
          else
          {
                cout << "NO I WON'T\n";
          }
    }
    return 0;
}
