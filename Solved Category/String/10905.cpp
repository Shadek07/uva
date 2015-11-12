#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>


using namespace std;

struct sor
{
	char in[50];

}st[55];

bool comp(string  a,string b)
{
	/*char fr[110],lt[110];
	strcpy(fr,a.in);
	strcat(fr,b.in);

	strcpy(lt,b.in);
	strcat(lt,a.in);
	if (strcmp(fr,lt) > 0) return true;
	else return false;*/
	string s1,s2;

	s1 = a+b;
	s2 = b+a;

	if( s1 > s2)
		return true;
	else
		return false;


}


int main(void)
{

	int t;

	char in[1000000];

	string s[51];

	int i,j,k;

	char *p;

	while(1)
	{
		cin >> t;

		if( t == 0)
			break;

		getchar();

		

		for(i = 0;i < t; i++)
		{
			cin >> s[i];
		}

	/*	  //p = strtok(in," ,.,!?&@#\"");
		p = strtok(in," ");
		    
			while( p != NULL)
			{
				
				strcpy(st[i++].in,p);
				
				
				p = strtok(NULL," ");
			}*/

			sort(s , s + t,comp);

			for(j = 0; j < i; j++)
			{
				cout << s[j];
			}

			cout << endl;
	}

	return 0;
}
