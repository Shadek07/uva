#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<map>

using namespace std;
string fir;
string last;
map<string,bool> mp;
map<string,bool> used;
map<string,string> par;



queue< pair<string,int> > pq;
pair<string,int> st,temp;
int ind;

int main(void)
{
    int t;
    int a,b,d,i,j,forbid;
    int ans;
    char in[10];
    //struct state st,temp;
    char c;
    string s,s1,s2,s3;
    int ch = 0;
    //cin >> a >> b;
    cin >> t;
    getchar();
    while(t--)
    {
          gets(in);
          fir = in;
          gets(in);
          last = in;
          cin >> forbid;
          getchar();
          for(i = 1; i <= forbid;i++)
          {
                gets(in);
                mp[in] = true;
          }
          if(t>0)
                 getchar();
          if(fir.compare(last) == 0)
          {
                cout << 0 << endl;
                continue;
          }
          
          ind = 1;
          st.first = fir;
          //par[first] = first;
          used[st.first] = true;
          st.second = 0;
          ch = 0;
          
          pq.push (pair<string,int> (fir, 0));
          while(!pq.empty())
          {
                st = pq.front();
                pq.pop();
                //cout << "here?\n";
                if(st.first.compare(last) == 0)
                {
                      ch = st.second;
                      break;
                }
                //cout << st.second<< endl;
                s = st.first;
                s1 = s;
                s2 = s;
                //change first digit
                for(i = 0;i <7;i+=2)
                {
                    s1 = s;
                    s2 = s;
                    c = s.at(i);
                    a = c-'0';
                    b = a+1;
                    d = a-1;
                    if(b==10)
                    b = 0;
                    if(d == -1)
                    d =9;
                    
                    s3 = "a";
                    s3 += char(b+'0');
                    s3.erase(0,1);
                    s1.replace(i,1,s3);
                    if(!mp[s1] && !used[s1])
                    {
                            
                            used[s1] = true;
                            pq.push (pair<string,int> (s1, st.second+1));
                    }
                    
                    s3.clear();
                    s3 = "a";
                    s3 += char(d+'0');
                    s3.erase(0,1);
                    s2.replace(i,1,s3);
                    if(!mp[s2] && !used[s2])
                    {
                            
                            used[s2] = true;
                            pq.push (pair<string,int> (s2, st.second+1));
                    }
                }
          }
          if(!mp.empty())
          mp.clear();
          if(used.empty())
          used.clear();
          while(!pq.empty())
                pq.pop();
          if(ch)
                cout << ch << endl;
          else
              cout << -1 << endl;
          
    }
    
    return 0;
}
