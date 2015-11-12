#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<fstream>

using namespace std;
int a[500001];
int n;
unsigned long long cnt;
int c[500001];
void merge(int i,int m,int j)
{
    int p,q,r;
    int total = m-i+1;
    p = i;
    q = m+1;
    r = i;
    int temp = p;
    while(p<=m && q<=j)
    {
          if(a[p] <= a[q])
          {
                  c[r] = a[p];
                  p = p+1;
          }
          else
          {
              cnt += total - p+temp;
              c[r] = a[q];
              q = q+1; 
          }
          r = r+1;
    }
    
    while(p<= m)
    {
              c[r] = a[p];
              p = p+1;
              r = r+1;
    }
    while(q <= j)
    {
            c[r] = a[q];
            q++;
            r = r+1;
    }
    
    for(r = i;r<=j;r++)
    a[r] = c[r];
}

void mergesort(int i,int j)
{
     if(i == j)
     return;
     int m;
     m = (i+j)/2;
     mergesort(i,m);
     mergesort(m+1,j);
     merge(i,m,j);
     
}
int main(void)
{
    int i,j,k;
   
    while(cin >> n && n)
    {
                
        for(i = 0;i<n;i++)
        cin >> a[i];
        cnt = 0;
        mergesort(0,n-1);
        //cout << a[0]<<endl;
        if(cnt%2 == 0)
        cout << "Carlos" << endl;  
        else
        cout << "Marcelo" << endl;
        
    }
    
    return 0;
}
