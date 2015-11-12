#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>

using namespace std;

map<char,int> mp;
map<char,int> dont;
void nine_space()
{
	int i;
	for(i = 0; i < 9;i++)
	{
		cout << " ";
	}
}
void specific_space(int n)
{
	int i;
	for(i = 0; i < n;i++)
		cout << " ";
}
int main(void)
{
	char in[30],c,later;
	char fir[70] = "NAME                     SOUNDEX CODE\n";
	int cnt,len,i,j;
	//C, S, K, G, J, Q, X, Z
	mp['B'] =1;
	mp['P'] =1;
	mp['F'] =1;
	mp['V'] =1;
	mp['S'] =2;
	mp['C'] =2;
	mp['K'] =2;
	mp['G'] =2;
	mp['J'] =2;
	mp['Q'] =2;
	mp['X'] =2;
	mp['Z'] =2;
	mp['D'] =3;
	mp['T'] =3;
	mp['L'] =4;
	mp['M'] =5;
	mp['N'] =5;
	mp['R'] =6;

	dont['A'] = 1;
	dont['E'] = 1;	
	dont['I'] = 1;
	dont['O'] = 1;
	dont['U'] = 1;
	dont['Y'] = 1;	
	dont['W'] = 1;
	dont['H'] = 1;

	nine_space();
	cout << "NAME";
	specific_space(21);
	cout << "SOUNDEX CODE\n";
	while(gets(in))//scanf("%s",in) == 1
	{
		nine_space();
		printf("%s",in);
		len = strlen(in);
		specific_space(34 - len - 9);
		cnt = 0;
		c = in[0];
		cout << in[0];
		for(i = 1; i < len;i++)
		{
			if(!dont[in[i]])
			{
				if(mp[in[i]] != mp[in[i-1]])
				{
					
							if(cnt < 3)
							{
								cout << mp[in[i]];
								cnt++;
							}
							else
								break;
						
					
				}
			}

			
			
		}

		if(cnt == 0)
		{
			cout << "000";
		}
		else if(cnt == 1)
			cout << "00";
		else if(cnt == 2)
			cout << "0";

		cout << endl;

	}
	specific_space(19);
	cout << "END OF OUTPUT";
	cout << endl;
	return 0;
}