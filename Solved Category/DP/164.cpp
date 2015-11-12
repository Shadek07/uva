
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
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)
#define max(a,b) a>a?a:b
#define min(a,b) a>b?b:a

int dp[50][50];
int main (void) 
{
	string w1, w2;
	int i,j;
	int len1,len2;
	while (cin >> w1) 
	{
		if (w1 == "#") break;
		cin >> w2;
		
		
		
		// Levenshtein Distance - dynamic programming
		len1 = w1.size();
		len2 = w2.size();
		for ( i = 0; i <= len1; i++) 
			dp[i][0] = i;
		for (i = 0; i <= len2; i++) 
			dp[0][i] = i;
		
		for ( i = 1; i <= len1; i++) 
		{
			for (j = 1; j <= len2; j++) 
			{
				int cost;
				if (w1[i-1] == w2[j-1]) 
					cost = 0;
				else cost = 1;

				dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + cost));
			}
		}
		// Levenshtein Distance end
		
		// surfing through the matrix to find the commands we need
		// to execute in order to get the best(minimum) result
		i = len1;
		j = len2;
		
		char buf[25];
		vector <string > commands;
		while(i>0 && j>0)
		{ 
		      if(dp[i-1][j] + 1 == dp[i][j])
			  { 
		         sprintf(buf,"D%c%02d",w1[i-1],j+1); 
		         i--; 
		      } 
		      else if(dp[i][j-1]+1 == dp[i][j])
			  { 
		         sprintf(buf,"I%c%02d",w2[j-1],j); 
		         j--; 
		      } 
		      else
			  { 
		         if(w1[--i] != w2[--j])sprintf(buf,"C%c%02d",w2[j],j+1); 
		         else  
					 continue; 
		      } 

		      commands.push_back(string(buf)); 
		   } 
		   while(i>0)
		   { 
		      sprintf(buf,"D%c%02d",w1[--i],1); 
		      commands.push_back(string(buf)); 
		   } 
		   while(j>0)
		   { 
		      sprintf(buf,"I%c%02d",w2[j-1],j); 
		      commands.push_back(string(buf)); 
		      j--; 
		   } 
		   string instr = ""; 
		   for(int k = commands.size()-1;k >= 0;k--) 
		      instr += commands[k]; 
		   instr += 'E';
		
		cout << instr;
		cout << endl;
	}	
	return 0;
}
