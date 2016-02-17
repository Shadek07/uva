
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

#define MAX 10
#define INF 9999999

#define MAXBITS 100000000
#define USIZE (8*4)

ull bitarray[MAXBITS/USIZE];

#define SETBIT(X)    (bitarray[X/USIZE]|=1<<(X%USIZE))
#define RESETBIT(X)  (bitarray[X/USIZE]&=~(1<<(X%USIZE)))
#define GETBIT(X)    ((bitarray[X/USIZE]&(1<<(X%USIZE)))?1:0)

void setBit(int x){
    int a = x/USIZE;
    int b = 1<<(x%USIZE);
    bitarray[a] |= 1<<(x%USIZE);
}

vector<int> primes;

void sieve(){
    int i,j;
    //RESETBIT(2);
    //RESETBIT(3);
    for(i = 4; i<= MAXBITS; i += 2){
        SETBIT(i);
    }
    for(i=3;i*i <= MAXBITS; i += 2){
        if(GETBIT(i) == 0){ //if prime
            for(j=i*i;j<= MAXBITS; j += (i<<1)){
                SETBIT(j); //set bit to mark as composite
                //setBit(j);
            }
        }
    }
    primes.pb(2);
    for(i=3;i<MAXBITS;i+=2){
        if(GETBIT(i) == 0){
            primes.pb(i);
        }
    }
}

int main()
{
    //cout << "Hello world!" << endl;
    //cout << sizeof(ull) << endl;
    //ms(bitarray,0);
    //cout << sizeof(long long int) << endl;
    int i,j;
    int n;
    int mx = MAXBITS/USIZE;
    for(i=0;i<=mx;i++){
        bitarray[i] = 0LLU;
    }
    //cout << bitarray[0] << endl;
    sieve();
    bool found;
    
    RESETBIT(3);
    //cout << bitarray[0] << endl;
    //cout << GETBIT(7) << endl;
    //cout << GETBIT(3) << endl;
    int x,y;
    while(cin >> n){
        if(n<5){
            printf("%d is not the sum of two primes!\n",n);
            continue;
        }
        if(n&1){
            //cout << GETBIT(3) << endl;
            y = n-2;
            x =GETBIT(y); 
            if(x == 0){
                printf("%d is the sum of %d and %d.\n",n,2,n-2);
            }else{
                printf("%d is not the sum of two primes!\n",n);
            }
            //cout << GETBIT(3) << endl;
        }else{
            j = n/2;
            if((j&1) == 0)
            j--;
            int p = (int)(upper_bound(all(primes),j)-primes.begin());
            if(primes[p] > j)
                p--;
            found = false;
            for(;p>=0;p--){
                j = primes[p];
                x = n-j;
                if(j == x)
                    continue;
                int a = GETBIT(j);
                int b = GETBIT(x);
                if(a == 0 && b == 0){
                    if(j>x)
                        swap(j,x);
                    printf("%d is the sum of %d and %d.\n",n,j,x);
                    found = true;
                    break;
                }
            }
            if(!found){
                printf("%d is not the sum of two primes!\n",n);
            }
        }
    }
    return 0;
}
