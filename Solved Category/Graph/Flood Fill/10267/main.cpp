
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
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
#include <fstream>
#include<ctime>
#include<climits>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define MID(a, b) (a + ((b - a) >> 1))
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999

char grid[302][302];
int n,m;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char in[10001];
    int len;
    char c1,c2;
    int a,b,c,d,e,x,y,y1,y2,x1,x2;
    char name[10001];
    int i,j;
    while(gets(in)){
        len = strlen(in);
        if(len == 1 && in[0] == 'X')
            break;
        
        if(in[0] == 'I'){
            sscanf(in,"%c %d %d",&c1,&m,&n);    
            ms(grid, 'O');
        }else if(in[0] == 'C'){
            ms(grid,'O');
        }else if(in[0] == 'L'){
            sscanf(in,"%c %d %d %c",&c1,&y,&x, &c2);
            grid[x][y] = c2;
        }else if(in[0] == 'V'){
            sscanf(in,"%c %d %d %d %c",&c1,&x,&y1,&y2, &c2);
            if(y1>y2)
                swap(y1,y2);
            fore(i,y1,y2){
               grid[i][x] = c2; 
            } 
        }else if(in[0] == 'H'){
            sscanf(in,"%c %d %d %d %c",&c1,&y1,&y2,&x, &c2);
            if(y1>y2)
                swap(y1,y2);
            fore(i,y1,y2){
               grid[x][i] = c2; 
            } 
        }else if(in[0] == 'K'){
            sscanf(in,"%c %d %d %d %d %c",&c1,&y1,&x1, &y2,&x2,&c2);
            fore(i,x1,x2){
                fore(j,y1,y2){
                    grid[i][j] = c2;
                }
                
            } 
        }else if(in[0] == 'S'){
            sscanf(in,"%c %s",&c1,&name);
            cout << name << endl;
            fore(i,1,n){
                fore(j,1,m){
                    cout << grid[i][j];
                }
                cout << endl;
            }
        }else if(in[0] == 'F'){
            sscanf(in,"%c %d %d %c",&c1,&y, &x, &c2);
            char curr = grid[x][y];
            if(curr == c2)
                continue;
            stack<int> st;
            
            st.push(y);
            st.push(x);
            while(!st.empty()){
                x = st.top();
                st.pop();
                y = st.top();
                st.pop();
                grid[x][y] = c2;
                forl(i,0,4){
                    x1 = x+dx[i];
                    y1 = y+dy[i];
                    if(x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && grid[x1][y1] == curr){
                        st.push(y1);
                        st.push(x1);
                    }
                }
            }
        }
    }
    return 0;
}

