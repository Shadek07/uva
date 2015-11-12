#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
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
#include<queue>
#include<sstream>
#include<stack>
#include<list>

using namespace std;

vector<int> v;
bool ok;
char save[105][55]; //save[i] is the smallest number using i matches
int dp[105]; //dp[i] is number of digit used to make a smaller number using i matches
char ans[55];
int arr[] = {6,2,5,5,4,5,6,3,7,6}; //arr[i] is number of matches to write digit i

int customized_Strcmp(char fir[55],char sec[55])
{
    int len1,len2,i,j;
    int a,b;
    len1 = strlen(fir);
    len2 = strlen(sec);
    if(len1 < len2)
    return 1;
    else if(len1 > len2)
    return 0;
    else
    {
        for(i = 0;i<len1;i++)
        {
              a = fir[i]-'0';
              b = sec[i] -'0';
              if(a>b)
              return 0;
        }
    }
    return 1;
}

void dfs(int ind,int match_used,int n)
{
     int i,j,a,b;
     bool ch;
     if(match_used == n)
     {
            ans[ind+1] = '\0';
            if(ind+1 <= dp[n] && customized_Strcmp(ans,save[n]) )
            {
                  strcpy(save[n],ans);
                  
            }
            return;
     }
     
     for(i = 0;i<=9;i++)
     {
           ans[ind+1] = char(i+'0');
           ans[ind+2] = '\0';
           if(match_used+arr[i] <= n && ind+2 <= dp[match_used+arr[i]] && customized_Strcmp(ans,save[match_used+arr[i]]))
           {
                 dp[match_used+arr[i]] = ind+2;
                 dfs(ind+1,match_used+arr[i],n); 
                                                   
           }
           else
           {
               if(i == 1 && match_used+arr[i] > n)
               break;
               else if(i == 7 && match_used+arr[i] > n)
               break;
           }
     }    
	
}

int main(void)
{
	int t,n;
	cin >> t;
	int i,j;
	bool ch;
	char temp[51];
	for(i = 0;i<51;i++)
	{
          temp[i] = '1';
    }
    temp[51] = '\0';
    for(i = 2;i<=100;i++)
    {
        strcpy(save[i],temp);
    }
    i = 10;
    for(i = 2;i<=100;i++)
    {
          dp[i] = 60;
    }
    
    for(j = 8;j<=100;j++)
    {
          //strcpy(save[j],temp);
	      for(i = 1;i<= 9;i++)
	      {
              ans[0] = char(i+'0');
	          dfs(0,arr[i],j);	          
          }
    }
    
	while(t--)
	{
		cin >> n;
		
		if(n%2==1)//odd
		{
			if(n ==3)
			{
				cout << 7 << " " << 7 << endl;
				continue;
			}
			if(n == 5)
			{
				cout << 2 << " " << 71 << endl;
				continue;
			}
			if(n == 7)
			{
				cout << 8 << " " << 711<<endl;
				continue;
			}
			
			
			cout << save[n];
			cout << " ";
			cout << 7;
			for(i = 5;i<=n;i+=2)
				cout << 1;
			cout << endl;

		}
		else  //even
		{
			if(n ==2)
			{
				cout << 1 << " " << 1 << endl;
				continue;
			}
			if(n == 4)
			{
				cout << 4 << " " << 11 << endl;
				continue;
			}
			if(n == 6)
			{
				cout << "6 111"<<endl;
				continue;
			}
			
			
			cout << save[n];
            			
			cout << " ";
			j = n/2;
			for(i = 1;i<=j;i++)
				cout << 1;
			cout << endl;
		}
	}
	return 0;
}
