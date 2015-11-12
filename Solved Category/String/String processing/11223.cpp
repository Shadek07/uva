#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char in[10000];

char t1[][10] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

char t2[][10] = {"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

//char t3[][10] = {};

int main(void)
{

	int t;
	int ca = 1;

	char test[10];
	int i,j,k,len;

	int letter,digit;
	int separate = 0;

	cin >> t;
	getchar();

	while(t--)
	{
		gets(in);

		len = strlen(in);

		j = 0;

		if(ca > 1)
			cout << endl;

		cout << "Message #" << ca++<< endl;

		for(i = 0; i <= len ; i++)
		{
			if(i != len)
			{
				if(in[i] != ' ')
					test[j++] = in[i];

			}

			if(i == len || in[i] == ' ')
			{
				test[j] = '\0';
				j = 0;
				if(in[i] == ' ' && in[i+1] == ' ')
				{
					//cout << ' ';
					separate = 1;
					i++;
				}
				letter = digit = -1;
				for( k = 0; k < 26; k++)
				{
					if( strcmp(test,t1[k]) == 0)
					{
						letter = k;
						break;
					}
				}

				for( k = 0; k < 10 && letter == -1; k++)
				{
					if( strcmp(test,t2[k]) == 0)
					{
						digit = k;
						break;
					}
				}

				if( letter > -1)
				{
					cout << char('A' + letter);
				}
				else if( digit > - 1)
				{
					cout << char('0' + digit);

				}
				else
				{
					if( strcmp(test,".-.-.-") == 0)
						cout << ".";
					if( strcmp(test,"--..--") == 0)
						cout << ",";
					if( strcmp(test,"..--..") == 0)
						cout << "?";
					if( strcmp(test,".----.") == 0)
						cout << "\'";
						if( strcmp(test,"-.-.--") == 0)
						cout << "!";
					if( strcmp(test,"-..-.") == 0)
						cout << "/";
					if( strcmp(test,"-.--.") == 0)
						cout << "(";
					if( strcmp(test,"-.--.-") == 0)
						cout << ")";
					if( strcmp(test,".-...") == 0)
						cout << "&";
					if( strcmp(test,"---...") == 0)
						cout << ":";
						if( strcmp(test,"-.-.-.") == 0)
						cout << ";";
					if( strcmp(test,"-...-") == 0)
						cout << "=";
					if( strcmp(test,".-.-.") == 0)
						cout << "+";
					if( strcmp(test,"-....-") == 0)
						cout << "-";
					if( strcmp(test,"..--.-") == 0)
						cout << "_";
						if( strcmp(test,".-..-.") == 0)
						cout << "\"";
					if( strcmp(test,".--.-.") == 0)
						cout << "@";
					
					
				}

				if( separate == 1)
				{
					cout << " ";
					separate = 0;
				}

				test[0] = '\0';
			}
			
		}

		cout << endl;
	}


	return 0;
}