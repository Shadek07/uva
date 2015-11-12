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
#include<stack>

using namespace std;

struct suffix
{
	char word[1001];
}s[1002];

bool comp(suffix a,suffix b)
{
	if(strcmp(a.word,b.word)<0)
		return true;
	else
		return false;
}

int main(void)
{
	string s1,s2,s3;
	int t;
	char in[1001],in1[1001];
	int i,j,len,k;
	cin >> t;
	getchar();
	
	while(t--)
	{
         gets(in);	
		 len = strlen(in);
		 if(len == 1)
		 {
			 cout << "No repetitions found!\n";
			 continue;
		 }
		 if(len == 2)
		 {
			 if(in[0] == in[1])
				 cout << in[0] << " " << 2 << endl;
			 else
				 cout << "No repetitions found!\n";
			 continue;

		 }
		 
		 char T[1002];
		 for(i = len-1,k=1;i>=0;i--,k++)
		 {
			 strncpy(T,in+i,k);
			 T[k] = '\0';
			 strcpy(s[k-1].word,T);
		 }

		 sort(s,s+k-1,comp);

		 //for(i = 0;i<len;i++)
		//	 cout << s[i].word << endl;

		 int len2,len3;
		 int len4=0;
		 int cnt;
		 T[0] = 'z';
		 T[1] = '\0';
		 char temp[1001];
		 k = 0;
		 for(i = 0;i<len-1;i++)
		 {
			 len2 = strlen(s[i].word);
			 len3 = strlen(s[i+1].word);
			 if(len2<len3)
				 k = len2;
			 else
				 k = len3;
			 j=0;
			 while(j<k)
			 {
				 strncpy(in,s[i].word,j+1);
				 in[j+1] = '\0';
				 strncpy(in1,s[i+1].word,j+1);
				 in1[j+1] = '\0';
				 if(strcmp(in,in1)!=0)
					 break;
				 j++;
			 }
			 char sub[1001];
			 strncpy(sub,s[i].word,j);
			 sub[j] = '\0';
			 if(len4 == 0 && j>0)
			 {
				 len4 = j;
				 strncpy(T,s[i].word,j);
				 T[j] = '\0';
			 }
			 else if(j>len4)
			 {
				 len4 = j;
				 strncpy(T,s[i].word,j);
				 T[j] = '\0';
			 }
			 else if(j==len4 && strcmp(sub,T)<0)
			 {
				 strcpy(T,sub);
			 }
			 
		 }

		 if(len4==0)
			 cout << "No repetitions found!\n";
		 else
		 {
			cnt = 0;
			for(i =0;i<len;i++)
			{
				strncpy(in,s[i].word,len4);
				in[len4] = '\0';
				if(strcmp(T,in)==0)
					cnt++;
			}
			cout << T << " " << cnt << endl;
		 }
	}
}