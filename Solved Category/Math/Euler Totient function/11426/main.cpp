
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

#define MAX 4000001
#define INF 9999999

vector<int> divisors[MAX];
bool isPrime[MAX];

//Euler's totient function
//phi[n] = number of integers i (<n) such that gcd(i,n)=1
int phi[MAX];
long long int dp[MAX];

//sieve of eratosthenes
void sieve(){
    ms(isPrime,true);
    int i,j;
    for(i=4;i<MAX;i+=2)
        isPrime[i] = false;
    isPrime[1] = false;
    for(i=1;i<MAX;i++){
        //2 is a prime that is always present in prime factorization of a number
        //so divide it by 2 as for calculating phi
        if(i%2==0) 
            phi[i] = i/2;
        else
            phi[i] = i;
    }
    for(i=3;i<MAX;i+=2){
        if(isPrime[i]){
            //when i is prime, phi[i] equals i-1
            phi[i] = i-1;
            for(j=i+i;j<MAX;j+=i){
                isPrime[j] = false;
                phi[j] /= i;
                phi[j] *= (i-1); 
                //phi[n] = n*((p1-1)/p1)*((p2-1)/p2)....
                //n=(p1^a)x(p2^b)x(p3^c)....
            }
        }
    }
    
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i,j,k;
    for(i=2;i<MAX;i++){
        for(j=i+i;j<MAX;j+=i){
            divisors[j].pb(i);
            //divisors[n] stores all divisors of n excluding 1 and n
        }
    }
    sieve();
    dp[2] = 1;
    for(i=3;i<MAX;i++){
        int sz = divisors[i].size();
        dp[i] = dp[i-1];
        //dp(i)=dp(i-1)+S(i) 
        //where S(i) is the summation of gcd(x,i) where x runs from 1 to i-1
        for(j=0;j<sz;j++){
            dp[i] += divisors[i][j]*phi[i/divisors[i][j] ];
            
            //If d is divisor of i then there are phi[i/d] integers(x<i) such that gcd(x,i) = d
            
            /*Lemma: If d is a divisor of n, then there are Phi(n/d) numbers i <= n for which gcd(i,n)=d
              Proof: We can see an example which certainly generalizes. 
              Say, n=12 and we want to compute the number of numbers i <= 12 so that gcd(i,12)=3. 
              Let's do it by hand first. These i are 3,9. Now, we compute it by logic.
                First off, any such i must be divisible by 3. 
                So, assume i=3j. Then gcd(12,3j)=3*gcd(j,4). 
                Now, if gcd(4,j) is greater than 1, then our desired gcd will be greater than 3. 
                Therefore, we must have gcd(4,j)=1. How many such j are there? Phi(4). 
                So, the number of such i is the number of such j, i.e. Phi(4)=Phi(12/3). 
                You can check it with other examples. 
                And generally, it follows that for a divisor d, we would have such Phi(n/d) numbers.
            */
        }
        dp[i] += phi[i];
    }
    int n;
    while(cin >> n){
        if(n==0)
            break;
        cout << dp[n] << endl;
    }
    return 0;
}
