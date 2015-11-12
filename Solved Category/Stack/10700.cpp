#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
using namespace std;

char in[200];



stack<unsigned long long> st,st1;
unsigned long long num[15];
bool sign[15];
int main(void)
{
    int t;
    int i,j,k,len;
    unsigned long long a,b,c;
    int val;
    cin >> t;
    getchar();
    while(t--)
    {
         gets(in);
         i = 0;
         len = strlen(in);
         val = 0;
         memset(sign,false,sizeof(sign));
         for(j = 0;j<len+1;j++)
         {
               if(j == len || in[j] == '+' || in[j] == '*')
               {
                    num[i] = val;
                    val = 0;
                    i++;
                    if(in[j] == '+')
                    sign[i] = true;
                    if(i == 1)
                    {
                         st.push(num[0]);
                         st1.push(num[0]);
                    }
                    else
                    {
                        if(sign[i-1] == true)
                        {
                              c = st.top();
                              st.pop();
                              st.push(c+num[i-1]);
                              st1.push(num[i-1]);   
                        }
                        else
                        {
                            c = st1.top();
                            st1.pop();
                            st1.push(c*num[i-1]);
                            st.push(num[i-1]);
                        }
                    }
               }
               else
               {
                   val = val*10 + (in[j] - 48);
               }
         }
         
         a = 1;
         while(!st.empty())
         {
                a *= st.top();
                st.pop();         
         }
         
         b = 0;
         while(!st1.empty())
         {
                b += st1.top();
                st1.pop();         
         }
         
         cout << "The maximum and minimum are " << a << " and " << b << ".\n";
         
         
              
    }
    return 0;
}
