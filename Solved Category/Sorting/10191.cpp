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
#include<algorithm>

using namespace std;
char in[1000];  
int n;
struct schedule
{
       int s_hour;
       int s_minute;
       int e_hour;
       int e_minute;
}s[105];

bool comp(schedule a, schedule b)
{
    if(a.s_hour < b.s_hour)
    {
         return true;
    }
    else if(a.s_hour == b.s_hour && a.s_minute < b.s_minute)
    return true;
    else if(a.s_hour == b.s_hour && a.s_minute > b.s_minute)
    return false;
    else if(a.e_hour < b.s_hour)
    return true;
    else if(a.e_hour == b.s_hour && a.e_minute < b.s_minute)
    return true;
    return 0;
}
int main(void)
{
    int a,i,b,j;
    char *p;
    int day = 1;
    while(cin >> n)
    {
        getchar();
        for(i = 0;i < n;i++)
        {
              gets(in);
              p = strtok(in,",:      ");
              a = atoi(p);
              s[i].s_hour = a;
              p = strtok(NULL,",:      ");
              a = atoi(p);
              s[i].s_minute = a;
              p = strtok(NULL,",:      ");
              a = atoi(p);
              s[i].e_hour = a;
              p = strtok(NULL,",:     ");
              a = atoi(p);
              s[i].e_minute = a;
              
        }  
        
        sort(s,s+n,comp);
        
        int nap = -1; //minutes
        int temp;
        int starth,startm;
        if((s[0].s_hour == 10 && s[0].s_minute > 0) || (s[0].s_hour > 10))
        {
               nap = (s[0].s_hour - 10)*60 + s[0].s_minute;  
               starth = 10;
               startm = 0;      
        }
        /*for(i = 0; i < n;i++)
        {
              cout << s[i].s_hour << " " << s[i].s_minute << endl;
        }*/
        for(i = 1; i < n;i++)
        {
              if(s[i-1].e_minute >= 0 && s[i-1].e_hour < s[i].s_hour)
              {
                    temp = 60 -  s[i-1].e_minute;
                    temp += (s[i].s_hour - s[i-1].e_hour - 1)*60;
                    temp += s[i].s_minute;
                    if(temp > nap)
                    {
                            nap = temp;
                            starth = s[i-1].e_hour;
                            startm = s[i-1].e_minute;
                    }            
              }
              if(s[i-1].e_hour == s[i].s_hour)
              {
                    temp = s[i].s_minute - s[i-1].e_minute;
                    
                    if(temp > nap)
                    {
                            nap = temp;
                            starth = s[i-1].e_hour;
                            startm = s[i-1].e_minute;
                    }            
              }
              
        }  
        if((s[n-1].e_hour < 18)||(s[n-1].e_hour == 18 && s[n-1].e_minute < 60))
        {
                 temp = 60 -  s[n-1].e_minute;
                 temp += (18 -  s[n-1].e_hour-1)*60; 
                 if(temp > nap)
                 {
                    nap = temp;
                    starth = s[n-1].e_hour;
                    startm = s[n-1].e_minute;
                 }      
        }
        cout << "Day #" << day++ << ": the longest nap starts at ";
        cout << starth << ":";
        if(startm < 10)
        cout << "0";
        cout << startm;
        cout <<" and will last for ";
        if(nap >= 60)
        {
               cout << nap/60 << " hours and " << nap%60 << " minutes.\n";
        }
        else
        {
            cout << nap << " minutes.\n";
        }
         
    }
    
    return 0;
}
