

#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
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

int total;
int m;
stack<int> st[3];

void transfer(stack<int> &tmp, int index){
    while(!st[index].empty()){
        tmp.push(st[index].top());
        st[index].pop();
    }
}
void print_stack(stack<int> &tmp, int index){
    if(!tmp.empty())
        cout << "  ";
    while(!tmp.empty()){
        cout << " " << tmp.top();
        st[index].push(tmp.top());
        tmp.pop();
    }
    cout << endl;
}
void TowerOfHanoi( int cnt, int src, int via, int dest){
    stack<int> tmp;
    if(cnt == 1 && total < m){
        //cout << "move " << mx << " from "<< src << " to " << dest << endl;
        
        st[dest].push(st[src].top());
        st[src].pop();
        cout << "A=>";
        transfer(tmp,0);
        print_stack(tmp,0);
        cout << "B=>";
        transfer(tmp,1);
        print_stack(tmp,1);
        cout << "C=>";
        transfer(tmp,2);
        print_stack(tmp,2);
        cout << endl;
        total++;
        return;
    }
    if(total < m)
        TowerOfHanoi(cnt-1, src,dest,via);
    if(total < m)
        TowerOfHanoi(1,src,via,dest);
    if(total < m)
        TowerOfHanoi(cnt-1,via,src,dest);
    
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int n;
    int i;
    int ca=1;
    while( cin >> n >> m){
        if(n == 0 && m ==0){
            break;
        }
            
        total=0;
        forl(i,0,3){
            while(!st[i].empty()){
                st[i].pop();
            }
        }
        cout << "Problem #" << ca++ << endl << endl;
        for(i=n;i>=1;i--){
            st[0].push(i); //initially all disks in first peg
        }
        cout << "A=>  ";
        for(i=n;i>=1;i--){
            cout << " " << i;
        }
        cout << endl;
        cout << "B=>\n";
        cout << "C=>\n\n";
        TowerOfHanoi(n,0,1,2);
    }
    return 0;
}
