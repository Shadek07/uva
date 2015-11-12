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
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) ((a>b?a:b))
#define min(a,b) ((a>b?b:a))

const int inf = 2000000000; // a large value as infinity

 

int n,q; // the number of items in the sequence

int Seq[10001]; // the sequence of integers

int L[10001]; // L[] as described in the algorithm

int I[10001]; // I[] as described in the algorithm

 
vector<int> ind;

int takeInput() 
{

    scanf("%d %d", &n,&q); // how many numbers in the sequence ?
	if(!n && !q)
		return 0;

    for( int i = 0; i < n; i++ ) // take the sequence
        scanf("%d", &Seq[n-i-1]);
	return 1;

}

 void find_index(int q)
 {
	 int i,j,k;
	 j = n-1;
	 k = q;
	 int prev;
	 for(;j>=0;j--)
	 {
		 if(k == q && L[j] >= k)
		 {
			 ind.push_back(j);
			 k--;
			 prev = Seq[j];
		 }
		 else if(L[j] >= k && Seq[j] > prev)
		 {
				k--;
				prev = Seq[j];
				ind.push_back(j);
		 }
	 }

}

int LisNlogK() 
{ // which runs the NlogK LIS algorithm

    int i; // auxilary variable for iteration

    I[0] = inf; // I[0] = -infinite

    for( i = 1; i <= n; i++ ) // observe that i <= n are given

        I[i] = -inf; // I[1 to n] = infinite

 

    int LisLength = 0; // keeps the maximum position where a data is inserted

 

    for( i = 0; i < n; i++ ) { // iterate left to right

        int low, high, mid; // variables to perform binary search

        low = 0; // minimum position where we to put data in I[]

        high = LisLength; // the maximum position

 

        while( low <= high ) { // binary search to find the correct position

            mid = ( low + high ) / 2;

            if( I[mid] > Seq[i])

                low = mid + 1;

            else

                high = mid - 1;

        }

        // observe the binary search carefully, when the binary search ends

        // low > high and we put our item in I[low]

        I[low] = Seq[i];
		L[i] = low;
        if( LisLength < low ) // LisLength contains the maximum position

            LisLength = low;

    }

    return LisLength; // return the result

}

int main() 
{

	int ca=1;
	int sub = 1;
	int i,j,m;
	//freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
	while(takeInput())
	{
		int result = LisNlogK();
		
		sub = 1;
		cout << "Set " << ca++ << ":\n";
		for(i = 0;i<q;i++)
		{
			cin >> m;
			cout << "  Subset " << sub++ << ":\n";
			if(m > result)
				cout << "    Impossible\n";
			else
			{
				ind.clear();
				find_index(m);
				cout << "    " << Seq[ind[0]];
				for(j = 1;j<m;j++)
				{
					cout << " " << Seq[ind[j]];
				}
				cout << endl;

			}

		}
		
	}

    return 0;

}
