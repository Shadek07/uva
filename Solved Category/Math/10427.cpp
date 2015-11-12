#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<cctype>
#include<cstring>
#include<string>
#include <sstream>
using namespace std;
char in[15];
long long int save[15];
int digit[15];

int main(void)
{
    long long int cnt,temp,curr;
    int i,j;
    double a,b;
    int low,high,mid;
    int n,h,cover;
    int l,len;
    
    string str;
    cnt = 1;
    temp = 9;
    save[0] = 0;
    save[1] = 9;
    digit[1] = 9;
    for(i = 2;;i++)
    {
          curr = 9*pow(10.0,i-1);
          digit[i] = digit[i-1] + (curr*i);
          save[i] = save[i-1]+curr;
          if(99999999<digit[i])
          break; 
          //cout << digit[i] << endl;        
    }
    //cout << i << endl;
    
    l = i;
    while(cin >> n)
    {
              low = 1;
              high = l;
              while(1)
              {
                      //if(low == high)
                      //break;
                      mid = (low+high)/2;
                      if(digit[mid-1]<=n && digit[mid] >= n)
                      {
                           h = mid;
                           break;
                      }
                      else if(digit[mid] > n)
                      {
                             high = mid-1;
                      }
                      else if(digit[mid] <= n)
                      {
                           low = mid+1;
                      }
                      
              } 
              
              //cout << h << endl;   
              cover = digit[h-1];
              int extra = n-cover;
              int s = pow(10.0,h-1);
              int a = extra/h;
              s += a-1;
              a = extra%h;
              if(a>0)
              s += 1;
              stringstream ss;
              ss << s;
              
              str = ss.str();
              strcpy(in,str.c_str());
              //cout << s << " " << in << " " << a << endl;
              len = strlen(in);
              if(a == 0)
              cout << in[len-1] << endl; 
              else
              cout << in[a-1]<<endl;  
              str.erase(str.begin(),str.end()); 
    }
    
    
    return 0;
}
