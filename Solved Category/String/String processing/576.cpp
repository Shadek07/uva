#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char in[205];

int ch[30] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0};
int check(char c)
{
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||c == 'y')
		return 1;
	else
		return 0;
}
int main(void)
{
	
	int first,second,third;
	int i;
	while(1)
	{
		gets(in);
		if(strcmp(in,"e/o/i") == 0)
			break;
		i = 0;
		first = second = third = 0;
		if(check(in[0]))
			first++;
		i++;
		while(in[i] != '/')
		{
			if(in[i] != ' ' && ch[in[i]-'a'] &&  !ch[in[i-1]-'a'])
				first++;
			i++;
		}

		i++;
		if(check(in[i]))
			second++;
		i++;
		while(in[i] != '/')
		{
			if(in[i] != ' ' && ch[in[i]-'a'] &&  !ch[in[i-1]-'a'])
				second++;
			i++;
		}

		i++;
		if(check(in[i]))
			third++;
		i++;
		while(in[i] != '\0')
		{
			if(in[i] != ' ' && ch[in[i]-'a'] &&  !ch[in[i-1]-'a'])
				third++;
			i++;
		}

	

		if(first == 5 && second == 7 && third == 5)
				cout << "Y" << endl;

		else if(first != 5)
			cout << 1 << endl;
		else if(second != 7)
			cout << 2 << endl;
		else if(third != 5)
			cout << 3 << endl;
	}
	return 0;
}