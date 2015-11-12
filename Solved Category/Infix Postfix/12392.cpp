#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;
char post[100];
char in[100];
int value[6];
int perm[6];
stack<char> st;
stack<int> sc;
int ind;
int n,val;
int desired;
int got;
void evaluate()
{
     int i,j,k;
     k = 0;
     int x,y;
     char c;
     int res;
     for(i = 0;i<ind;i++)
     {
        if(post[i] >= 'a' && post[i] <= 'z')
        {
                   sc.push(value[perm[k]]);
                   k++;
        }   
        else
        {
            c = post[i];
            y = sc.top();
            sc.pop();
            x = sc.top();
            sc.pop();
            if(c == '+')
            sc.push(x+y);
            if(c == '-')
            sc.push(x-y);
            if(c == '*')
            sc.push(x*y);
            
        }
     }
     
     res = sc.top();
     sc.pop();
     if(res == desired)
     got = 1;
}
int main(void)
{
    int i,j;
    char c;
    int len;
    while(1)
    {
            cin >> n >> val;
            if(!n && !val)
            break;
            value[0] = val;
            for(i = 1;i < n;i++)
            {
                  cin >> value[i];
            }
            cin >> desired;
            getchar();
            gets(in);
        ind = 0;

        len = strlen(in);
        
        for(i = 0; i < len;i++)
        {
              if(in[i] >= 'a' && in[i] <='z')
              {
                       post[ind++] = in[i];
              }
              else if(in[i] == '(' || in[i] == '+' || in[i] == '-' || in[i] == '*')
              st.push(in[i]);
              else if(in[i] == ')')
              {
                   while(st.top() != '(')
                   {
                          c = st.top();
                          post[ind++] = c;
                          st.pop();      
                   }
                   st.pop();
              }
              
        }
        
        for(i = 0; i < n;i++)
        perm[i] = i;
        got = 0;
        do
        {
            evaluate();
            if(got == 1)
            {
                   //cout << "YES";
                   break;
            }    
        }
        while(next_permutation(perm,perm+n));
        if(got == 1)
        cout << "YES\n";
        else
        cout << "NO\n";
       
    }
    
    return 0;
}
