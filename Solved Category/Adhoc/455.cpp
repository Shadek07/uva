#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(void)
{

	int t,i,j,len,len1,check;

	string s1,s2,s3;

	char in[100];
	char str[100];

	cin >> t;

	getchar();
	getchar();

	while(t--)
	{
		gets(in);

		s1 = in;

		check = 0;

		len  = strlen(in);

		for(i = 0; i < len ; i++)
		{

			s2 = s1.substr(0,i+1);

			s3 = s2;

            len1 = s2.length();

			if( len%len1 == 0)
			{
				for(j = 0; j < (len/len1-1);j++)
				{
                    s2.append(s3);
				}

				// assign string s2 to a character array named str

				strcpy(str,s2.c_str());

				if( strcmp(str,in) == 0)
				{
					cout << len1 << endl;
					break;
					check = 1;
				}
			}
            
		}

		if( t)
			cout << endl;

		getchar();
	}


	return 0;
}
