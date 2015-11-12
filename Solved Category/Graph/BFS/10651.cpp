#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<queue>

using namespace std;
char in[20];
int peb;

struct state
{
       string s;
       int cnt;
};

queue<state> pq;
map <string,int> m1;
int main(void)
{
    string s1,s2,s3;
    int t;
    cin >> t;
    getchar();
    int i,j,k,len;
    struct state tmp,st;
    int ind;
    int get;
    while(t--)
    {
        gets(in); 
        len = 12;
        for(i = 0; i < len;i++)
        {
              if(in[i] == 'o')
              peb++;
        }
        
        st.s = in;
        st.cnt = 0;
        pq.push(st);
        ind = 0;
        m1[in] = ind++;
        get = -1;
        while(!pq.empty())
        {
              tmp = pq.front();
              pq.pop();
              s1 = tmp.s;
              if(tmp.cnt>get)
              {
                  get = tmp.cnt;          
              }
              for(i = 0;i<len-1;i++)
              {
                    if(s1[i] == 'o' && s1[i+1] == 'o')
                    {
                             if(i-1 >= 0 && s1[i-1] == '-')
                             {
                                    s2 = s1;
                                    s2[i]  = '-';
                                    s2[i-1] = 'o';
                                    s2[i+1] = '-';
                                    if(!m1[s2])
                                    {
                                               m1[s2] = ind++;
                                               st.s = s2;
                                               st.cnt = tmp.cnt+1;
                                               pq.push(st);
                                    }
                             }
                             
                             if(i+2 < 12 && s1[i+2] == '-')
                             {
                                    s2 = s1;
                                    s2[i]  = '-';
                                    s2[i+1] = '-';
                                    s2[i+2] = 'o';
                                    if(!m1[s2])
                                    {
                                               m1[s2] = ind++;
                                               st.s = s2;
                                               st.cnt = tmp.cnt+1; 
                                               pq.push(st);
                                    }
                             }
                    }
              }
              
              
              
        } 
        cout << peb-get << endl;
        m1.clear();
        peb = 0;
    }
    
    return 0;
}
