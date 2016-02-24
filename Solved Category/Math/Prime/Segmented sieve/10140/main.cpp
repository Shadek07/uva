
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


#define MAX 1000001
#define INF 9999999
#define PRIMESZ 46341 //sqrt of (2^31-1)
#define SZ (8*4)
ull bitarray[PRIMESZ/SZ + 1];

#define SETBIT(x) (bitarray[x/SZ] |= (1<<(x%SZ)))
#define RESETBIT(x) (bitarray[x/SZ] &= ~(1<<(x%SZ)))
#define GETBIT(x) ((bitarray[x/SZ] & (1<<(x%SZ)))?1:0)
vector<int> primes;

bool isPrime[MAX]; //isPrime[i] checks whether L+i is a prime 
//where L is lower bound of the input

void sieve(){
   int i,j;
   for(i=4;i<=PRIMESZ;i+=2){
        SETBIT(i);
   }
   
   for(i=3;i*i<=PRIMESZ; i+=2){
       if(GETBIT(i) == 0){ //if i is prime
           for(j=i*i; j<= PRIMESZ; j += (i<<1) ){
                SETBIT(j); //mark all multiple of i as non-prime
           }
       }
   }
   
   primes.pb(2);
   for(i=3;i<=PRIMESZ;i+=2){
      if(GETBIT(i) == 0){
           primes.pb(i);
      }
   } 
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    long long int i,j,k;
    int L,U;
    int sz = PRIMESZ/SZ;
    forl(i,0,sz+1){
        bitarray[i] = 0LLU;
    }
    sieve(); //get all primes within sqrt(2^31-1)
    sz = primes.size();
    
    int diff;
    while(scanf("%d %d",&L,&U) == 2){
        if(L == 1 && U == 2){
           printf("There are no adjacent primes.\n");
           continue; 
        }
        if(L==2 && U == 3){
            printf("%d,%d are closest, %d,%d are most distant.\n",L,U,L,U);
            continue;
        }
        diff = U-L+1;
        forl(i,0,diff){
            isPrime[i] = true; //L+i is prime initially
        }
        int close = 1000000;
        int distant = 0;
        int c1,c2,d1,d2;
        int prev=-1;
        if(L<=2){
            close = 1;
            c1 = 2;
            c2 = 3;
        }
        if(L<3){ //start from 3 if < 3
            L = 3;
        }
        if(L%2==0){ //start from an odd number
            L++;
        }
        forl(i,0,sz){
            if(primes[i] > U)
                break;
            int st = primes[i]*(L/primes[i]);
            
            //mark all multiples of i'th prime i.e primes[i] within range [L,U]
            for(j=st; j <= U;j += primes[i]){
                if(j < L || j == primes[i])
                    continue;
                isPrime[j-L] = false;
            }  
        }
        
        for(i=0;i<diff;i++){
            if(L+i <= 1)
                continue;
            if(isPrime[i] == true){
                if(prev == -1){
                    prev = i;
                }else{
                    if(i-prev < close && L+i <= U){
                        close = i-prev;
                        c1 = L+prev;
                        c2 = L+i;
                    }
                    if(i-prev > distant && L+i <= U){
                        distant = i-prev;
                        d1 = L+prev;
                        d2 = L+i;
                    }
                }
                prev = i;
            }
        }
        if(distant == 0){
            printf("There are no adjacent primes.\n");
        }else{
            printf("%d,%d are closest, %d,%d are most distant.\n",c1,c2,d1,d2);
        }
    }
    return 0;
}

