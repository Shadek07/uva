
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
char out[20][30];
int pos[20];

pair<int,int> find_position(string s1, string s2)
{
      int sz = s1.size();
      int sz2 = s2.size();
      int i,j;
      for(i = 0;i<sz;i++)
      {

            for(j = 0;j<sz2;j++)
            {
                  if(s1[i] == s2[j])
                       return make_pair(i,j);
            }
      }

      return make_pair(-1,-1);
}


int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int ca=1;
    char in[11], in1[11], in2[11], in3[11];
    pair<int,int> pa1, pa2;
    string s1,s2;
    int i,j;
    while(cin >> in)
    {
          if(in[0] == '#')
                  break;

         for(i = 0;i<20;i++)
         {
               memset(out[i], '\0', sizeof(out[i]));
         }

         cin >> in1 >> in2 >> in3;
         if(ca==1)
         ca=0;
         else
         cout << endl;

         s1 = in;
         s2 = in1;
         pa1 = find_position(s1,s2);
         if(pa1.first == -1)
         {
               cout << "Unable to make two crosses\n";
               continue;
         }

         s1 = in2;
         s2 = in3;
         pa2 = find_position(s1,s2);

         //cout << pa2.first << " " << pa2.second << endl;

         if(pa2.first == -1)
         {
               cout << "Unable to make two crosses\n";
               continue;
         }

         memset(pos, -1, sizeof(pos));

         strcpy(out[9], in);
         strcat(out[9], "   ");
         strcat(out[9], in2);

         pos[9] = strlen(in) + strlen(in2) + 2;

         int a,b;

         int k;
         a = pa1.first;
         b = pa1.second;
         i = 9 - b;

         for(j = i,k=0;j<i+strlen(in1);j++,k++)
         {
               out[j][a] = in1[k];
               if(pos[j] < a)
               pos[j] = a;
         }

         a = strlen(in) + 3 + pa2.first;
         b = pa2.second;
         i = 9 - b;

         for(j = i,k=0;j<i+strlen(in3);j++,k++)
         {
               out[j][a] = in3[k];
               if(pos[j] < a)
               pos[j] = a;
         }

         for(i = 0;i<20;i++)
         {
               if(pos[i] == -1)
               continue;
               else
               {
                     for(j = 0;j<=pos[i];j++)
                     {
                           if(isalpha(out[i][j]))
                           cout << out[i][j];
                           else
                           cout << " ";
                     }
                     cout << endl;
               }
         }
    }
    return 0;
}
