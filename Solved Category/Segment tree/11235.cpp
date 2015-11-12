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
#include<stack>

using namespace std;
#define MX(a,b) a>b?a:b

int M[1000001];
int A[100001];
int N;
int ans;
void initialize(int node, int b, int e) 
{ 
		int i,j,k;
		int value;
        if (b == e) 
             M[node] = 1; 
        else 
          { 
			 //compute the values in the left and right subtrees 
             initialize(2 * node, b, (b + e)/2); 
             initialize(2 * node + 1, (b + e) / 2 + 1,e); 
			 
             if (M[2 * node] > M[2 * node + 1]) 
                  M[node] = M[2 * node]; 
             else 
                  M[node] = M[2 * node + 1]; 
			 k = (b+e)/2;
			 j= 1;
			 value = A[k];
			 while(k+1 <= e && A[k+1] == value)
			 {
				 j++;
				 k++;
			 }
			 k = (b+e)/2;
			 while(k-1 >=b && A[k-1] == value)
			 {
				 j++;
				 k--;
			 }
			 M[node] = MX(M[node],j);

        } 
}

int query(int node, int b, int e,int i, int j) 
{
        int p1, p2; 
		int j1,k,value;
   //if the current interval doesn't intersect 
   //the query interval return -1 
        if (i > e || j < b) 
             return -1; 

   //if the current interval is included in 
   //the query interval return M[node] 
        if (b >= i && e <= j) 
             return M[node]; 

 
        p1 = query(2 * node, b, (b + e) / 2,i,j); 
        p2 = query(2 * node + 1, (b + e)/2 + 1, e,i,j); 

   
        if (p1 == -1) 
             return  p2; 
        if (p2 == -1) 
             return  p1; 
        ans = p1;
		if(ans < p2)
			ans = p2;

		k = (b+e)/2;
		j1 = 1;
		value = A[k];
		while(k+1 <= j && A[k+1] == value)
		{
			j1++;
			k++;
		}
		k = (b+e)/2;
		while(k-1 >=i && A[k-1] == value)
		{
			j1++;
			k--;
		}
		if(j1>ans)
			ans = j1;

		k = (b+e)/2+1;
		j1 = 1;
		value = A[k];
		while(k+1 <= j && A[k+1] == value)
		{
			j1++;
			k++;
		}
		k = (b+e)/2+1;
		while(k-1 >=i && A[k-1] == value)
		{
			j1++;
			k--;
		}
		if(j1>ans)
			ans = j1;
		return ans;
		

}
 
int main(void)
{
	int i,j,k,q;
	int a;
	while(cin >> N && N)
	{
		cin >> q;
		for(i = 0;i<N;i++)
			cin >> A[i];
		memset(M,-1,sizeof(M));
		initialize(1, 0, N-1);
		//cout << M[15] << endl;
		for(i = 0;i<q;i++)
		{
			cin >> j >> k;
			ans = -1;
			a = query(1,0,N-1,j-1,k-1); 
			cout << a << endl;
		}

	}
	return 0;
}
