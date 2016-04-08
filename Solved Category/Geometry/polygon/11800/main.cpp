
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
typedef pair<long long int,long long int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999
vpii vp;

long long dist(pii p1, pii p2){
    long long int x = p1.first-p2.first;
    x *= x;
    long long int y = p1.second-p2.second;
    y *= y;
    return x+y;
}
pii getPair(long long int a, long long int b){
    if(a>=0 && b>=0)
    return {a,b};
    if(a<0 && b>=0)
    return {a,b};
    if(a>=0 && b<0 )
    return {-abs(a),abs(b)};
    else
    return {abs(a),abs(b)};
}
bool isPerpendicular(pii p1, pii p2, pii p3){
    if(p1.first == p2.first && p1.second == p3.second)
        return true;
    if(p1.second == p2.second && p1.first == p3.first)
        return true;
    long long int x1,y1,x2,y2;
    long long int gcd;
    x1 = p1.first-p2.first;
    y1 = p1.second-p2.second;
    gcd = __gcd(abs(x1),abs(y1));
    x1 /= gcd;
    y1 /= gcd;
    x2 = p1.first-p3.first;
    y2 = p1.second-p3.second;
    gcd = __gcd(abs(x2),abs(y2));
    x2 /= gcd;
    y2 /= gcd;
    if(abs(x1) != abs(y2))
        return false;
    if(abs(y1) != abs(x2))
        return false;
    y1 /= x2;
    y2 /= x1;
    if(y1*y2 == -1)
        return true;
    return false;
}

bool isParallel(pii p1, pii p2, pii p3, pii p4){
    if(p1.second == p2.second && p3.second == p4.second)
        return true;
    if(p1.first == p2.first && p3.first == p4.first)
        return true;
    long long int x1,y1,x2,y2;
    long long int gcd;
    x1 = p1.first-p2.first;
    y1 = p1.second-p2.second;
    gcd = __gcd(abs(x1),abs(y1));
    x1 /= gcd;
    y1 /= gcd;
    x2 = p4.first-p3.first;
    y2 = p4.second-p3.second;
    gcd = __gcd(abs(x2),abs(y2));
    x2 /= gcd;
    y2 /= gcd;
    pii p = getPair(x1,y1);
    x1 = p.first;
    y1 = p.second;
    p = getPair(x2,y2);
    x2 = p.first;
    y2 = p.second;
    if(x1 != x2)
        return false;
    if(y1 != y2)
        return false;
    return true;
}
bool isSquare(pii p1, pii p2, pii p3, pii p4){
    if(dist(p1,p2) != dist(p3,p4))
        return false;
    if(dist(p1,p4) != dist(p2,p3))
        return false;
    if(dist(p1,p2) != dist(p2,p3))
        return false;
    if(!isPerpendicular(p2,p1,p3)) //angle should be 90 degree
        return false;
    return true;
}
bool isRectangle(pii p1, pii p2, pii p3, pii p4){
    if(dist(p1,p2) != dist(p3,p4))
        return false;
    if(dist(p1,p4) != dist(p2,p3))
        return false;
    if(!isPerpendicular(p2,p1,p3)) //angle should be 90 degree
        return false;
    return true;
}
bool isRhombus(pii p1, pii p2, pii p3, pii p4){
    if(dist(p1,p2) != dist(p3,p4))
        return false;
    if(dist(p1,p4) != dist(p2,p3))
        return false;
    if(dist(p1,p2) != dist(p2,p3))
        return false;
    if(isPerpendicular(p2,p1,p3)) //angle should not be 90 degree
        return false;
    return true;
}
bool isParallelogram(pii p1, pii p2, pii p3, pii p4){
   if(dist(p1,p2) != dist(p3,p4))
        return false;
    if(dist(p1,p4) != dist(p2,p3))
        return false;
    if(isPerpendicular(p2,p1,p3)) //angle should not be 90 degree
        return false;
    return true; 
}
bool isTrapezoid(pii p1, pii p2, pii p3, pii p4){
    if(isParallel(p1,p4,p2,p3) && !isParallel(p1,p2,p3,p4))
        return true;
    if(!isParallel(p1,p4,p2,p3) && isParallel(p1,p2,p3,p4))
        return true;
    return false;
}
int calculate(pii p1, pii p2, pii p3, pii p4){
    if(isSquare(p1,p2,p3,p4)){
        return 0;
    }
    else if(isRectangle(p1,p2,p3,p4)){
        return 1;
    }else if(isRhombus(p1,p2,p3,p4)){
        return 2;
    }else if(isParallelogram(p1,p2,p3,p4)){
        return 3;
    }else if(isTrapezoid(p1,p2,p3,p4)){
        return 4;
    }else{
        return 5;
    }
}
bool isPositiveArea(pii p1, pii p2, pii p3, pii p4){
   long long int v = 0;
   v += p1.first*p2.second;
   v -= p1.second*p2.first;
   v += p2.first*p3.second;
   v -= p2.second*p3.first;
   v += p3.first*p4.second;
   v -= p3.second*p4.first;
   v += p4.first*p1.second;
   v -= p4.second*p1.first;
   v = abs(v);
   if(v>0)
        return true;
   return false;
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    string ans[] = {"Square", "Rectangle", "Rhombus", "Parallelogram", "Trapezium", "Ordinary Quadrilateral"};
    int n;
    cin >> n;
    int a,b,i;
    int ca=1;
    while(n){
        vp.clear();
        forl(i,0,4){
            cin >> a >> b;
            vp.pb({a,b});
        }
        int arr[] = {0,1,2};
        int mn = 10;
        //points may not be given in clockwise or anticlockwise order
        do{
           //check for clockwise or anti clockwise order
           if(isPositiveArea(vp[arr[0]], vp[arr[1]], vp[arr[2]], vp[3])){
               mn = min(mn, calculate(vp[arr[0]], vp[arr[1]], vp[arr[2]], vp[3]));
               break;
           }
               
        }while(next_permutation(arr,arr+3));
        cout << "Case " << ca++ << ": " << ans[mn] << endl;
        n--;
    }
    return 0;
}
