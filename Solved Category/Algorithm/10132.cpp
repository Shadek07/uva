#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

vector<string> v[150];
char in[300][10000];
int main(void)
{
	int t;
	int t1 = 0;
	int i,j,len,k;
	char inp[10000];
	string s1,s2,s3;
	cin >> t;
	getchar();
	getchar();
	int sum;
	int file;
	int total;
	int size;
	while(t--)
	{
		i = 0;
		sum = 0;
		while(gets(inp))
		{
			len = strlen(inp);
			sum += len;
			if(len == 0)
				break;
			i++;
			strcpy(in[i],inp);
		}
		total = i;
		file = i/2;
		size = sum/file;
		if(t1 == 0)
			t1 = 1;
		else
			cout << endl;
		for(i = 0;i<total;i++)
		{
			s1 = in[i+1];
			for(j = 0;j<total;j++)
			{
				if(i!= j)
				{
					s2 = s1;
					s2 += in[j+1];
					v[i].push_back(s2);
					s2.erase(s2.begin(),s2.end());
				}
				else
				{
					v[i].push_back("abc");
				}
			}
		}

		int cnt;
		int ch = 0;
		for(i = 0; i < total;i++)
		{
			cnt = 0;
			s1 = v[0][i];
			if(s1.size()>size)
				continue;
			for(j = 0;j<total;j++)
			{
				for(k = 0;k<total;k++)
				{
					if(j != k)
					{
						s2 = v[j][k];
						if(s2.size()>size)
							continue;
						else if(s1.compare(s2) == 0)
							cnt++;
					}

				}
				if(cnt >= file)
				{
					cout << s1 << endl;
					i = total;
					ch = 1;
					break;
				}
			}
		}

		if(ch == 0)
		{
			//cout <<"here2"<<endl;
			for(i = 0; i < total;i++)
			{
				cnt = 0;
				s1 = v[i][0];
				if(s1.size()>size)
					continue;
				for(j = 0;j<total;j++)
				{
					for(k = 0;k<total;k++)
					{
						if(j!= k)
						{
							s2 = v[j][k];
							if(s2.size()>size)
								continue;
							else if(s1.compare(s2) == 0)
								cnt++;
						}

					}
					if(cnt >= file)
					{
						cout << s1 << endl;
						ch = 1;
						break;
					}
				}
			}

		}
		for(i = 0;i<=total;i++)
		{
			if(!v[i].empty())
				v[i].clear();
		}
	}

	return 0;
}