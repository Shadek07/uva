#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>

using namespace std;
string s1;
long square(long n) 
{ 
	return ((n%131071)*(n%131071))%131071; 
}

long fastexp(long base,long power) 
{
	if (power == 0)
		return 1;
	else if (power%2 == 0)
		return square((fastexp(base,power/2))%131071);
	else
		return base * (fastexp(base,power-1))%131071;
}

int process()
{
	int len,i,j;
	int res;
	len = s1.size();
	res = 0;
	for(j = 0,i = len-1; i >= 0;i--,j++)
	{
		if(s1[j] == '1')
		{
			res += (fastexp(2,i)%131071); 
		}
		
	}

	res = res%131071;

	
	return res;
}

int main(void)
{
	string s2,s3;
	char in[110];
	int len,a;
	while(gets(in))
	{
		len = strlen(in);
		s1 = "";
		if(in[len-1] == '#')
		{
			in[len-1] = '\0';
			s1 = in;
			a = process();
			if(a == 0)
			{
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
		else
		{
			while(1)
			{
				gets(in);
				len = strlen(in);
				if(in[len-1] == '#')
				{
					in[len-1] = '\0';
					s1 += in;
					break;
				}
				else
				{
					s1 += in;
				}
			}

			a = process();

			if(a == 0)
			{
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}

	}

	return 0;
}