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

using namespace std;

typedef set<int> inside;
set<inside> st;

inside peo[101];

char in[100];
int p,t;
int main(void)
{
    int t1,a,b,i,j,k;
    cin >> t1;
    getchar();
    getchar();
    int len;
    bool ch = false;
    char *p1;
    while(t1--)
    {
        cin >> p >> t; 
        getchar();
        /*if(!p || !t)
        {
              cout << 0 << endl;
              if(ch == false)
                ch = true;
                else
                cout << endl;
        }*/
        while( gets(in) && sscanf(in, "%d %d", &a, &b ) == 2 )
        {
            peo[a].insert(b);
                       
        }
        
        for(i = 1; i <= p;i++)
        {
              //if(!peo[i].empty())
              st.insert(peo[i]);
              peo[i].clear();
        }
        if(ch == false)
        ch = true;
        else
        cout << endl;
        cout << st.size() << endl;
        st.clear();
           
    }
}
