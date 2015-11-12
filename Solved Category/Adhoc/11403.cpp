#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

int main(void)
{

	char first[35],second[35],res[65],zero[35];
	unsigned long a,b,c,d;
	int len,i,j,k,hyphen,len1,len2,space;
	int st = 1;
	while(cin >> first >> second)
	{

		
		//if(strcmp(first,"0") == 0 && strcmp(second,"0") == 0)
		//	break;
		a = 0;
		int val;

		/*if(st == 1)
			st = 0;
		else
			cout << endl;*/

		len = strlen(first);
		len1 = len;
		for(i = 0;i < len; i++)
		{
			val = first[i] - 48;
			a += val*pow(2.0,len-i-1);
		}

		//cout << a << endl;

		len = strlen(second);
		len2 = len;
		if(len1 > len2)
			hyphen = len1;
		else
			hyphen = len2;
		b = 0;
		for(i = 0; i < len; i++)
		{
			val = second[i] - 48;
			b += val*pow(2.0,len-i-1);
		}

		c = a*b;
		i = 0;
		d = c;
		while(d != 0)
		{
			res[i] = char(d%2+48);
			i++;
			d /= 2;
		}

		for(j = 0; j < len1; j++)
		{
			zero[j] = '0';
		}
		zero[len1] = '\0';
		len = i;
		int fi;
		if(len > hyphen)
			fi = len;
		else
			fi = hyphen;
		j = len - len1;
		for(k =0; k < j;k++)
			cout << " ";
		cout << first << endl;

		j = len - len2;
		for(k =0; k < j;k++)
			cout << " ";
		cout << second << endl;

		j = len - hyphen;
		for(k =0; k < j;k++)
			cout << " ";
		for(k = 0; k < hyphen; k++)
		{
			cout << "-";
		}
		cout << endl;
		space = len - len1;
		for(k = len2-1; k >= 0; k--)
		{
			for(j = 0; j < space; j++)
				cout << " ";
			if(second[k] == '0')
			{
				cout << zero << endl;
			}
			else
			{
				cout << first << endl;
			}

			space--;
		}

		for(j = 0; j < len; j++)
		{
			cout << "-";
		}
		cout << endl;

		j = fi - len;
		for(k = 0; k < j; k++)
			cout << " ";

		for(j = i-1; j >= 0; j--)
		{
			cout << res[j];
		}
		cout << endl;
		cout << endl;
		//cout << first << " " << second << endl;
	}
	return 0;
}