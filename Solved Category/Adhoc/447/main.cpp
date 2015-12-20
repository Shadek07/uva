
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
#include <fstream>
#include<ctime>

using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int getCount(int a,int b, char in[20][21]){
    int i;
    int cnt=0;
    forl(i,0,8){
        int x = a+dx[i];
        int y=b+dy[i];
        if(x>=0&&x<20&&y>=0&&y<20 && in[x][y]=='O'){
            cnt++;
        }
    }
    return cnt;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    char grid[20][21];
    char tmp[20][21];
    int t;
    cin >> t;
    int year;
    char in[50];
    int c=0;
    int a,b;
    int i,j,k;
    while(t--){
        cin >> year;
        getchar();
        if(c)
            cout << endl;
        ms(grid,' ');
        while(gets(in)){
            int len = strlen(in);
            if(len == 0)
                break;
            sscanf(in,"%d %d",&a,&b);
            a--,b--;
            grid[a][b] = 'O';
        }
        forl(i,0,20){
            grid[i][20] = '\0';
        }
        cout << "********************\n";
        int g;
        forl(a,0,year){
            if(a)
                cout << "********************\n";
            forl(i,0,20){
                cout << grid[i] << endl;
            }
            forl(i,0,20){
                if(i == 5){
                    int a = 4;
                }
                forl(j,0,20){
                    g = getCount(i,j,grid);
                    if(grid[i][j] == 'O'){
                        if(g<=1 || g >=4){
                            tmp[i][j] = ' ';
                        }else if(g==2 || g == 3){
                            tmp[i][j] = 'O';
                        }
                    }else{
                        if(g==3){
                            tmp[i][j] = 'O';
                        }else{
                            tmp[i][j] = ' ';
                        } 
                    }
                }
                tmp[i][20] = '\0';
                //cout << "--" << tmp[i] << endl;
            }
            forl(i,0,20){
                strcpy(grid[i],tmp[i]);
            }
            //grid = tmp;
        }
        cout << "********************\n";
        c++;
    }
    return 0;
}
