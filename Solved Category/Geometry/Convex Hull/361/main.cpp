
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

//hull_cops will store convex hull points from all cops points
//same to robbers
vpii cops, robbers, hull_cops, hull_robbers;
int c,r;
pii lowest_pnt;
int position_sort(pii p1, pii p2){
    if(p1.first < p2.first)
        return 1;
    else if(p1.first == p2.first && p1.second < p2.second)
        return 1;
    return 0;
}
int cross_product(pii root, pii p1, pii p2){
    int ux = p1.first-root.first;
    int uy = p1.second-root.second;
    int vx=p2.first-root.first;
    int vy=p2.second-root.second;
    int v = ux*vy-uy*vx;
    if(v>0)
        return 1;
    else if(v<0)
        return -1;
    else
        return 0;
}
int dist(pii p1, pii p2){
    int a = p1.first-p2.first;
    a*=a;
    int b=p1.second-p2.second;
    b*=b;
    return a+b;
}
int angle_sort(pii p1, pii p2){
    int cross_prod = cross_product(lowest_pnt, p1,p2);
    if(cross_prod == 0){
        return dist(lowest_pnt, p1) < dist(lowest_pnt,p2);
    }
    return cross_prod>0;
}

bool isOnLineSegment(pii pnt, pii p1, pii p2){
    int mnx = min(p1.first,p2.first);
    int mxx = max(p1.first,p2.first);
    int mny = min(p1.second,p2.second);
    int mxy = max(p1.second,p2.second);
    return cross_product(pnt,p1,p2) == 0 && (mnx<=pnt.first && pnt.first <= mxx) && (mny<=pnt.second && pnt.second <= mxy);
}

bool DoesTwoSegmentIntersect(pii p1, pii p2, pii p3, pii p4){
    int d1 = cross_product(p1,p2,p3);
    int d2 = cross_product(p1,p2,p4);
    int d3 = cross_product(p3,p4,p1);
    int d4 = cross_product(p3,p4,p2);
    if(d1*d2 < 0 && d3*d4 < 0)
        return true;
    if(d1 == 0 && isOnLineSegment(p3,p1,p2))
        return true;
    if(d2 == 0 && isOnLineSegment(p4,p1,p2))
        return true;
    if(d3 == 0 && isOnLineSegment(p1,p3,p4))
        return true;
    if(d4 == 0 && isOnLineSegment(p2,p3,p4))
        return true;
    return false;
}
bool is_insideOrInBoundary(pii pnt, vpii hull){
    bool antiClockwise=false;
    bool clockwise=false;
    vpii::iterator it;
    hull.pb(hull[0]);
    int sz=hull.size();
    it = find(all(hull),  pnt);
    if(it != hull.end()){
        return true;
    }
    int i;
    int a=0,b=0;
    pii distant;
    distant.first = 100000;
    distant.second = pnt.second; //an imaginary line segment between pnt and distant
    int cnt=0;
    forl(i,0,sz-1){
        if(isOnLineSegment(pnt, hull[i], hull[i+1])){
            return true;
        }
        if(hull[i].second == hull[i+1].second)
            continue;
        int tmp = -1;  
        if(isOnLineSegment(hull[i], pnt, distant) )  
            tmp = i;  
        else if( isOnLineSegment(hull[i+1], pnt, distant) )  
                tmp = i+1;  
        if(tmp != -1 && (hull[tmp].second == max(hull[i].second,hull[i+1].second)) )  
            cnt++;  
        else if( tmp == -1 && DoesTwoSegmentIntersect(pnt, distant, hull[i], hull[i+1]) )  
                cnt++;
    }
    return (cnt%2)==1;
}

//convex hull algorithm
vpii Graham_scan(vpii pnts){
    //sort(all(pnts), position_sort);
    int tmp = 0;  
    int sz = pnts.size();
    int i;
    for(i=1; i<sz; i++)
    	if( (pnts[i].first<pnts[tmp].first) || (pnts[i].first == pnts[tmp].first && pnts[i].second < pnts[tmp].second) )
    		tmp = i;
    swap(pnts[0],pnts[tmp]);
    lowest_pnt = pnts[0];
    sort(pnts.begin()+1,pnts.end(), angle_sort); 
    int m=0;
    
    vpii hull_pnts;
    forl(i,0,sz){
        while(m>=2 && cross_product(hull_pnts[m-2], hull_pnts[m-1], pnts[i]) <= 0){
            m--;
            hull_pnts.pop_back();
        }
        m++;
        hull_pnts.pb(pnts[i]);
    }
    return hull_pnts;  
}

#define normal 1

int main(void)
{
    int n,i,j,k;
    #ifdef normal
         //freopen("1.txt", "r", stdin);
         //freopen("2.txt", "w", stdout);
    #else
        c = 150,r=150,n=5;
        freopen("1.txt", "w", stdout);
        cout << c << " " << r << " " << n << endl;
        forl(i,0,c){
            cout << -100+rand()%201 << " " << -100+rand()%201 << endl;
        }
        forl(i,0,r){
            cout << -100+rand()%201 << " " << -100+rand()%201 << endl;
        }
        forl(i,0,n){
            cout << -100+rand()%201 << " " << -100+rand()%201 << endl;
        }
        cout << "0 0 0\n";
        return 0;
    #endif 
    
    int dataset=1;
    int a,b;
    vpii data_pnts;
    while(cin >> c >> r >> n){
        if(c==0 && r == 0 && n == 0)
            break;
        cops.clear();
        robbers.clear();
        hull_cops.clear();
        hull_robbers.clear();
        vpii::iterator it;
        forl(i,0,c){
            cin >> a >> b;
            cops.pb({a,b});
        }
        forl(i,0,r){
            cin >> a >> b;
            robbers.pb({a,b});
        }
        
        c = cops.size();
        r = robbers.size();
        if(c >= 3){
            hull_cops = Graham_scan(cops);
        }
        if(r>=3){
            hull_robbers = Graham_scan(robbers);
        }
        
        cout << "Data set " <<dataset++ << ":\n";
        forl(i,0,n){
            cin >> a >> b;
            pii pnt = make_pair(a,b);
            
            cout <<  "     Citizen at (" << pnt.first << "," << pnt.second;
            if( !(hull_cops.size()<3 && c<3)&& is_insideOrInBoundary(pnt, hull_cops)){
                cout<<  ") is safe.\n";
            }else if(!(hull_robbers.size()<3 && r<3) && is_insideOrInBoundary(pnt, hull_robbers)){
                cout<< ") is robbed.\n";
            }else{
                cout << ") is neither.\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
