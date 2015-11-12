#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<fstream>

using namespace std;

#define INF (1<<30)
#define mn(a,b) a<b?a:b

int main(void)
{
    int n,i,j,low,high,mid;
    long long int a;
    long long int I[10005];
    int L[10005];
    int L1[10005];
    long long int seq[10005];
    long long int seq1[10005];
    int len;
    a = INF;
   	//ifstream f1("1.txt");
	//ofstream f3("2.txt");
    //cout << a << endl;
    while(cin >> n)
    {
       for(i = 0; i<n;i++)
       {
             cin >> seq[i];
             seq1[n-i-1] = seq[i];
       }
       
       I[0] = -INF;
       for(i = 1;i<n+1;i++)
       I[i] = INF;
       len = 0;
       for(i = 0; i < n;i++)
       {
             high = len;
             low = 0;
             while(low<=high)
             {
                  mid = (low+high)/2;
                  if(I[mid] < seq[i])
                  low = mid+1;
                  else
                  high = mid-1;
             }
             
             I[low] = seq[i];
             L[i] = low;
             if(len < low)
             len = low;
       }
       
       //cout << len << endl;
       
       I[0] = -INF;
       for(i = 1;i<n+1;i++)
       I[i] = INF;
       len = 0;
       for(i = 0; i < n;i++)
       {
             high = len;
             low = 0;
             while(low<=high)
             {
                  mid = (low+high)/2;
                  if(I[mid] < seq1[i])
                  low = mid+1;
                  else
                  high = mid-1;
             }
             
             I[low] = seq1[i];
             L1[i] = low;
             if(len < low)
             len = low;
       }
       
       //cout << len << endl;
       int mx = 0;
       int ind;
       int m;
       for(i = 1;i<n-1;i++)
       {
             if(L[i] != 1)
             {
                     m = mn(L[i],L1[n-i-1]);
                     m = 2*m -1;
                     if(m > mx)
                     mx = m;
                     ind = i;
             }
       }
       
       if(mx == 0)
       mx = 1;
       cout << mx << endl;
       //f3 << ind << endl;
              
    }
    return 0;
}
