#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>

using namespace std;

int main(void)
{
	int ca = 1;
	char in[500],in1[500],in2[500];
	string s1[20];
	string s2[20];
	int m,n,i,j,k;
	int count[20];
	while(cin >> m >> n)
	{
		getchar();

		for( i = 0; i < m; i++)
		{
			gets(in);
			s1[i] = in;
		    //getline(cin,s1[i]);
		}

		for( i = 0; i < n; i++)
		{
			gets(in);
			s2[i] = in;
		   
		}

		memset(count,0,sizeof(count));
        char *p;

		for( j = 0; j < n; j++)
		{
			strcpy(in1,s2[j].c_str());
            p = strtok(in1," ,.,!?&@#\"");
		    
			while( p != NULL)
			{
				
				for( i = 0; i < m; i++)
				{
					strcpy(in2,s1[i].c_str());
					int len1,len2;
					len1 = strlen(p);
					len2 = strlen(in2);
					for( k = 0; k < len1 || k < len2; k++)
					{
						if( k < len1)
							p[k] = toupper(p[k]);
						if( k < len2)
							in2[k] = toupper(in2[k]);
					}
					if( strcmp(p,in2) == 0)
						count[j]++;
				}
				p = strtok(NULL," ,.,!?&@#\"");
			}
		}

		int b = *max_element(count,count+n);

		//cout << b << endl;

		cout << "Excuse Set #" << ca++ << endl;

		for( i = 0; i < n ; i++)
		{
			if( count[i] == b)
			{
				cout << s2[i] << endl;
			}
		}

		cout << endl;

	    

	}
	return 0;
}