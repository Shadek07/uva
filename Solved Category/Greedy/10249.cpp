#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct team
{
       int num;
       int id;
};

struct table
{
       int capa;
       int id;
};
vector<team> v;
vector<table> v1;
vector<int> seat[71]; //atmost 70 teams
//seat[i] indicates the list of tables where the teams members of team i will sit
int capa[51];

int comp(team a,team b)
{
    if(a.num > b.num)
    return 1;
    else
    return 0;
}

int comp1(table a,table b)
{
    if(a.capa > b.capa)
    return 1;
    else
    return 0;
}
int main(void)
{
    int ch,m,n;
    int i,j;
    struct team te;
    struct table tab;
    int a,b;
    while(1)
    {
            cin >> m >> n;
            if(!m && !n)
            break;
            ch = 1;
            for(i = 0; i < m;i++)
            {
                  cin >> a;
                  if(a>n)
                  ch = 0;
                  te.num = a;
                  te.id = i+1;
                  v.push_back(te);
            }
            
            for(i = 0; i < n;i++)
            {
                  cin >> capa[i];//table capacity
                  tab.capa = capa[i];
                  tab.id = i+1;
                  v1.push_back(tab);                 
            }
            
            if(ch == 0)
            {
                  //cout << 0 << endl;
                  //continue;
				  goto nt;
			}
            
            
            sort(v.begin(),v.end(),comp);
            sort(v1.begin(),v1.end(),comp1);
            
            for(i = 0; i < m;i++)
            {
                  a = v[i].num; //no. of team members
                  b = v[i].id; //team id
                  int cnt = 0;
                  for(j = 0; cnt < a && j < n;j++)
                  {
                        tab.capa = v1[j].capa;
                        if(tab.capa <= 0)
                        continue;
                        else
                        {
                            seat[b].push_back(v1[j].id);
                            v1[j].capa--;
                            cnt++;
                        }
                  }
                  
                  if(cnt != a)
                  {
                         ch = 0;
                         break;
                  }
                  sort(v1.begin(),v1.end(),comp1);
            }
            
            //if(ch == 0)
            //cout << "0" << endl;
            //else
            //{
			if(ch != 0)
			{
                cout << 1 << endl;
                for(i = 1;i<=m;i++)
                sort(seat[i].begin(),seat[i].end());
                for(i = 1;i <= m;i++)
                {
                      cout << seat[i][0];
                      for(j = 1;j<seat[i].size();j++)
                      cout << " " << seat[i][j];
                      cout << endl;
                }
			}
                
                
            //}
nt:
            
			if(ch == 0)
				cout << 0 << endl;
            if(!v.empty())
            v.clear();
            if(!v1.empty())
            v1.clear();
            for(i = 1;i<=m;i++)
            if(!seat[i].empty())
            seat[i].clear();
            
            
    }
    
    return 0;
}
