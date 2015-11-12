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
#include <sstream>

using namespace std;

vector<int> fir,sec;
set<int> s1,s2;

int main(void)
{

	int i,j,k;
	int ca,cb;
    string input;
    stringstream ss;
    int tmp;
	int len1,len2;

	while(getline(cin,input))
	{
		len1 = len2 = 0;
		
		ss.str(input);
		
		while(ss >> tmp)
		{
                 len1++;
                 fir.push_back(tmp);
        }
        
		//getchar();

		getline(cin,input);
        ss.clear();
		ss.str(input);
		
		while(ss >> tmp)
		{
                 len2++;
                 sec.push_back(tmp);
        }

		ss.clear();

		ca = cb = 0;

		for(i = 0; i < len1;i++)
		{
			for(j = 0; j < len2;j++)
			{
                  if(fir[i] == sec[j])
                  {
                            ca++;
                            //break;
                  }
            }
		}

		if(ca == len1 && ca == len2)
		{
			cout << "A equals B\n";
		}
		else if(ca ==len1)
		{
			cout << "A is a proper subset of B\n";
		}
		else if(ca == len2)
		{
			cout << "B is a proper subset of A\n";

		}
		else if(ca == 0)
		{
			cout << "A and B are disjoint\n";
			
		}
		else
		{
			cout << "I'm confused!\n";

		}
		
        fir.clear();
		sec.clear();
	}

	return 0;
}
