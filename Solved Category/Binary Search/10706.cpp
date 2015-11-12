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

long long int digit[10],f[10],la[10];
char in[15];
long long int save[15];
int dig[15];
int n1;
void calculate()
{
     long long int cnt,temp,curr;
    int i,j;
    //double a,b;
    int low,high,mid;
    int n,h,cover;
    int l,len;
    
    string str;
    cnt = 1;
    temp = 9;
    save[0] = 0;
    save[1] = 9;
    dig[1] = 9;
    for(i = 2;;i++)
    {
          curr = 9*pow(10.0,i-1);
          dig[i] = dig[i-1] + (curr*i);
          save[i] = save[i-1]+curr;
          if(99999999<dig[i])
          break; 
          //cout << digit[i] << endl;        
    }
    //cout << i << endl;
    
    l = i;
    n = n1;
   
              low = 1;
              high = l;
              while(1)
              {
                      //if(low == high)
                      //break;
                      mid = (low+high)/2;
                      if(dig[mid-1]<=n && dig[mid] >= n)
                      {
                           h = mid;
                           break;
                      }
                      else if(dig[mid] > n)
                      {
                             high = mid-1;
                      }
                      else if(dig[mid] <= n)
                      {
                           low = mid+1;
                      }
                      
              } 
              
              //cout << h << endl;   
              cover = dig[h-1];
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
              {
               cout << in[len-1] << endl; 
               //cout << "h1\n";
              }
              else
              {
              cout << in[a-1]<<endl;  
              //cout << "h2\n";
              }
              str.erase(str.begin(),str.end()); 
    
    
 }
int main(void)
{
    long long int cnt,temp,curr;
    int i,j,t,h,low,high,mid;
    double a,b;
    int cover,extra;
    cnt = 1;
    temp = 1;
    digit[0] = 0;
    digit[1] = 45;
    f[1] = 1;
    unsigned long int prev_last,first,last;
    double sum = 0.0;
    int n,l;
    prev_last = 9;
    for(i = 2;;i++)
    {
        first = prev_last+i;
        n = 9*pow(10.0,i-1);
        last =  first+(n-1)*i;
        sum = n/2;
        sum *= (2*first + (n-1)*i);
        digit[i] = digit[i-1]+sum;
        f[i] = first;
        la[i] = last;
        //cout << digit[i]<<endl;
        if(digit[i]>2147483647)
        break;
        sum = 0;
        prev_last = last;     
    }
    cin >> t;
    while(t--)
    {
              cin >> n;
              low = 1;
              high = 5;
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
                      
                      //cout << "abc\n";
                      
              }
              
              cover = digit[h-1];
              //cout << cover << endl;
              low = 1;
              high = 9*pow(10.0,h-1);
              int total = high;
              int ex = n-cover;
              n = ex;
              int f1 = f[h];
              int l1 = la[h];
              
              while(1)
              {
                      mid = (low+high)/2;
                      sum = mid*1.0/2;
                      sum *= (2*f1+(mid-1)*h);
                      if(sum <= n && n<= (sum+f1+mid*h))
                      {
                             int temp = n;
                             n = n-sum;
                             if(n == 0)
                             {
                                  //cout << "mid " << mid << endl;
                                  sum = (mid-1)*1.0/2;
                                  sum *= (2*f1+(mid-2)*h);
                                  n = temp-sum;
                             }
                             //cout << sum << endl;
                             break;
                      }
                      else if(sum > n)
                      {
                           high = mid-1;
                      }
                      else if(sum < n)
                      {
                           low = mid+1;
                       }
                       //cout << "abc\n";
              }
              
              //if(n != 0) 
              n1 = n;
              //else
              //n1 = sum;
              //cout << "n1 " << n1 << endl;
              calculate();
    }
    

    
    return 0;
}
