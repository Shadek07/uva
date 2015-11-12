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


int main(void)
{
    unsigned long long int N;
    unsigned long long low,high,mid,a,b,c,d,st,end;
    
    int row,col;
    while(1)
    {
        cin >> N;
        if(!N) break;
        if(N == 1)
        {
             cout << 1 << " " << 1 << endl;
             continue;
        }  
        if(N == 2)
        {
             cout << 1 << " " << 2 << endl;
             continue;
        }
        if(N == 3)
        {
             cout << 2 << " " << 2 << endl;
             continue;
        }
        if(N == 4)
        {
             cout << 2 << " " << 1 << endl;
             continue;
        }
        
        low = 1;
        high = 1000000001;
        while(1)
        {
              mid = (low+high)/2;
              
              b = 2+(mid-1)*2;
              b *= mid;
              b /= 2;
              
              long b1 = 1+(mid-1)*2;
              
              c = b1+2;
              d = 2+(mid-2)*2;
              d *= (mid-1);
              d /= 2;
              
              if(N <= b && N > d)
              {
                   a = mid;
                   break;
              }
              else if(b > N)
              {
                   high = mid;
              }
              else if(b < N)
              {
                   low = mid;
              }
                                         
        }
        
        //cout << a << endl; 
        b = 1+(a-1)*2;
        st = 2+(a-2)*2;
        st *= (a-1);
        st /= 2;
        st += 1;
        end = st + b-1;
        if(a%2)
        {
               if(N <= st + b/2)
               {
                    row = a;
                    col = (b/2 + 1) - (st + b/2 - N);
               }
               else
               {
                   col = a;
                   row =  1 + (end-N);
               }               
        }
        else
        {
               if(N <= st + b/2)
               {                    
                   col = a;
                   row = (b/2 + 1) - (st + b/2 - N);
               }
               else
               {
                   row = a;
                   col = 1 + (end-N);                  
               }           
        }
        cout << row << " " << col << endl;
    }
       
	return 0;
}
