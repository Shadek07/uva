#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main(void)
{
     int   m[50100]; 
     int t;
     cin >> t;
     int i,j,k;
     int n;
     int a[105];
     int sum;
     int M;
          
     while(t--)
     {
               cin >> n;
               sum = 0;
               for(i = 0; i < n;i++)
               {
                   cin >> a[i];
                   sum += a[i];
               }
               
              M=sum;
              for(i=0;i<M+10;i++)      
              m[i]=0; 
              m[0]=1; 
              for(i=0;i<n;i++) 
                  for(j=M;j>=a[i];j--) 
                      m[j]  |=  m[j-a[i]];
              
              int M1 = M/2;
              for(i = M1;i>=0;i--)
              {
                    if(m[i] == 1)
                    {
                         cout << abs((i-(sum-i))*1.0) << endl;
                         //cout << M1 << " " << i << endl;
                         break;
                    }
              } 
      }
                    
      return 0;
}
