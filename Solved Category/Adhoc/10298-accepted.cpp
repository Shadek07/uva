#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>


using namespace std;

int main(void)
{
	string s1,s2,s3;
	int i,j,len;
	while(cin >> s1)
	{
		if(s1.compare(".") == 0)
			break;

		len = s1.size();

		for(i = 1; i <= len; i++)
		{
			if(len%i != 0)
				continue;
			s2 = s1.substr(0,i);
			s3 = "";
			for(j = 1; j <= len/i; j++)
				s3 += s2;
			if(s3.compare(s1) == 0)
			{
				cout << len/i << endl;
				break;
			}
		}
	}

	return 0;
}