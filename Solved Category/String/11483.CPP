#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(void)
{

	char in[101],c;
	string s1,s2;

	int N,i,j,k,cn = 1;

	while(1)
	{
		cin >> N;
		getchar();
		if(!N)
			break;

		printf("Case %d:\n",cn++);

		printf("#include<string.h>\n");

		printf("#include<stdio.h>\n");

		printf("int main()\n{\n");

		for( i = 0; i < N; i++)
		{
			gets(in);

			printf("printf(\"");

			j = strlen(in);

			for( k = 0; k < j; k++)
			{
				if(in[k] == '\"' || in[k] == '\\')
					cout << "\\" << in[k];
				else
					cout << in[k];
			}
			printf("\\n\");");
			cout << endl;
		}


		printf("printf(\"\\n\");");

		printf("\n");

		printf("return 0;");

		printf("\n}");

		printf("\n");
	}


	return 0;
}