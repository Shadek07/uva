#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

char in[1000];

stack<char> st;
vector<char> v1;

int main(void)
{
    int t;
    cin >> t;
    cin.ignore(100, '\n');
    char c;
    int ind = 0;
    int c1 = 0;
    int i,j;
    char k1;
    while(t--)
    {
              ind = 0;
              cin.ignore(100, '\n');
              while(cin.peek() != '\n' && cin.peek() != -1)
              {
                      cin >> c;
                      cin.ignore(100, '\n');                                         
                      in[ind++] = c;
              }
              
              in[ind] = '\0';
              if(c1 == 0)
              c1 = 1;
              else
              cout << endl;
              
              for(i = 0; i<ind;i++)
              {
                    if(in[i] == '(')
                    st.push(in[i]);
                    else if(in[i] == ')')
                    {
                             while(st.top() != '(')
                             {
                                   v1.push_back(st.top());
                                   st.pop();
                             }
                             st.pop();
                    }
                    else if(in[i] >= '0' && in[i] <= '9')
                    {
                         v1.push_back(in[i]);
                    }
                    
                    else if(in[i] == '+' ||  in[i] == '-')
                    {
                         while(!st.empty() && st.top() != '(')
                         {
                                 k1 = st.top();                             
                                 if(k1 == '+' || k1 == '-' || k1 == '*' || k1 == '/')
                                 {
                                       v1.push_back(k1);
                                       st.pop();
                                       continue;
                                 }
                                 else
                                 break;
                         }
                         st.push(in[i]);
                    }
                    else if(in[i] == '*' ||  in[i] == '/')
                    {
                         while(!st.empty()&& st.top() != '(')
                         {
                                 k1 = st.top();                             
                                 if(k1 == '*' || k1 == '/')
                                 {
                                       v1.push_back(k1);
                                       st.pop();
                                       continue;
                                 }                                 
                                 else
                                 break;
                         }
                         st.push(in[i]);
                    }
              }
              
              while(!st.empty())
              {
                                v1.push_back(st.top());
                                st.pop();
              }
              
              int i1 = v1.size();
              
              for(i = 0; i < i1; i++)
              {
                    cout << v1[i];
              }
              cout << endl;
              v1.clear();
              
    }
    
    return 0;
}
