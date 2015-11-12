
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<limits>
#include<map>
#include<string>

using namespace std;

#define LLU long long unsigned int
#define LLD long long double
#define FOR(i,N) for(int i=0;i<(N);i++)
#define MIN_INT numeric_limits<int>::min()

char input[1000];
string str;
vector<int> inp;
vector<int> lis;

void calc_ans(vector<int> &inp,vector<int> &lis)
{
    vector<int> cnt(inp.size(),1);
    vector<int> child(inp.size(),-1);
    for(size_t i1=0;i1<inp.size();i1++)
    {
        for(size_t j=0;j<i1;j++)
        {
            if(inp[j]<inp[i1] && cnt[j]+1>cnt[i1])
            {
                child[i1]=j;
                cnt[i1]=cnt[j]+1;
            }
        }
    }
    int MAX=*max_element(cnt.begin(),cnt.end());
    int i=cnt.size()-1;
    while(i>=0)
    {
        if(cnt[i]==MAX)
        break;
        i--;
    }
    while(child[i]!=-1)
    {
        lis.push_back(inp[i]);
        i=child[i];
    }
    lis.push_back(inp[i]);
    reverse(lis.begin(),lis.end());
}
int getnum(string str)
{

    int ret=0,i=0;
    if(str.length()==0) return MIN_INT;
    while(str[i]==' '&& i<str.length())
    {
        i++;
    }
    while(str[i]>='0' && str[i]<='9' && i<str.length())
    {
        ret=ret*10+(str[i]-'0');
        i++;
    }
    return ret;
}
int main()
{
    int cases,temp;
    getline(cin,str);
    int NO=1;
    cases=getnum(str);
    getline(cin,str);
    while(cases--)
    {
        getline(cin,str);
        inp.clear();
        lis.clear();
        while(str!="")
        {
            inp.push_back(getnum(str));
            getline(cin,str);
        }
        calc_ans(inp,lis);
        if(NO++>1) printf("\n");
        printf("Max hits: %d\n",lis.size());
        for(size_t i=0;i<lis.size();i++)
        printf("%d\n",lis[i]);
    }
}