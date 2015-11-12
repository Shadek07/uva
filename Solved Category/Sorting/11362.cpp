#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<cctype>
#include <iterator>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;


vector<string> v;

char in[20];
int main(void)
{
	  int t,n,i,j,k,ch;
      string s1,s2,s3;
	  cin >> t;
	  getchar();
	  int len1,len2;
	  while(t--)
	  {
                cin >> n;
                getchar();
                for(i = 0; i < n;i++)
                {
                      gets(in);
                      v.push_back(in);
                }
                
                sort(v.begin(),v.end());
                ch = 1;
                for(i = 0; i <n-1;i++)
                {
                     s1 = v[i];
                     s2 = v[i+1];
                     len1 = s1.size();
                     len2 = s2.size();
                     if(len2 >= len1)
                     {
                         s3 = s2.substr(0,len1);
                         if(s1.compare(s3) == 0)
                         {
                             ch = 0;
                             break;
                         }    
                     }
                }
                
                if(ch)
                cout << "YES\n";
                else
                cout << "NO\n";
                v.clear();
                
      }

	 

	return 0;
}
