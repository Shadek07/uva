#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cctype>
#include <cstdlib>
#include<algorithm>

using namespace std;
char *p;
char in[10000];
vector<int> v,v1,v3;
int arr[40];
int main(void)
{
    int a,b,i,j;
    int current;
    while(gets(in))
    {
            p = strtok(in," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			while( p != NULL)
			{
				a = atoi(p);
				v.push_back(a);		
				p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			}
			for(i = 0;i<v.size();i++)
			{
                  v1.push_back(v[i]);
                  v3.push_back(v[i]);
            }
            
            sort(v3.begin(),v3.end());
            reverse(v3.begin(),v3.end());
            reverse(v.begin(),v.end());
            int ch = 0;
            cout << v1[0];
            for(i = 1;i<v1.size();i++)
            {
                  cout << " " << v1[i];
            }
            cout << endl;
            for(i = 0; i < v3.size();i++)
            {
                  a = v3[i];
                  if(v[i] != a)
                  {
                        for(j = i;j < v.size();j++)
                        {
                              if(v[j] == a && j != v.size()-1)
                              {
                                   if(ch == 0)
                                    {
                                          cout << j+1;
                                          ch = 1;
                                    } 
                                    else
                                    cout << " " << j+1;
                                    reverse(v.begin()+j,v.end());
                                    break;
                              }
                        }
                        if(ch == 0)
                        {
                              cout << i+1;
                              ch = 1;
                        } 
                        else
                        cout << " " << i+1;
                        reverse(v.begin()+i,v.end());
                  }
            }
            
            if(ch == 1)
            cout << " " << 0 << endl; 
            else
            cout << 0 << endl;
            v.clear();
            v1.clear();
            v3.clear(); 
    }
    return 0;
}
