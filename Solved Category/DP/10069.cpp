#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//int m[100][10001];
char root[10001],check[101];

vector<string> v[101][10001];

void add(char s1[],char s2[],char sav[])
{
	    int a,b,i,j,ind;
		char temp[10001];
		char final[10001];
		char input[10001];
		
		 int save;
		strcpy(final,s1);
		strcpy(input,s2);
	       

	        a = strlen(final);
            b = strlen(input);

			reverse(final,final + a);
			reverse(input,input + b);

			a--;
			b--;

			i = a;
			j = b;

			int c = 0;
			int t;
			
			ind = 0;
			a = 0;
			b = 0;

			while( a <= i || b <= j || c != 0)
			{
                t = c;
				c = 0;
				if( a <= i)
				{
					t += final[a] - 48;
					a++;
				}
				if( b <= j)
				{
					t += input[b] - 48;
					b++;
				}

				c = t/10;
				t = t%10;
				temp[ind++] = t+48;
			}

			temp[ind] = '\0';

			reverse(temp,temp+ind);

			final[ind] = '\0';

			save = ind;

			strcpy(final,temp);

			final[ind] = '\0';

			strcpy(sav,final);
	        //return final;

}

int main(void)
{
	int t;
	int i,j;
	int len1,len2;
	char res[10001];
	char in[10001],in1[10001];

	string s1,s2,s3,s4,s5;

	cin >> t;

	getchar();
	while(t--)
	{
		gets(root);
		gets(check);
		len1 = strlen(root);
		len2 = strlen(check);

		s1 = "0";
		s2 = "1";
		for( i = 0; i <= len1; i++)
		{
			//m[0][i] = 0;
			
			v[0][i].push_back(s1);

		}
		for( i = 1; i <= len2; i++)
		{
			//m[i][0] = 0;
			v[i][0].push_back(s1);
		}

		for(i = 1; i <= len1; i++)
		{
			if(check[0] == root[i-1])
			{
				//m[1][i] = m[1][i-1] + 1;
				char a1[10];
				a1[0] = '1';
				a1[1] = '\0';
				s3 = v[1][i-1][0];
				strcpy(in,s3.c_str());
				add(in,a1,res);
				v[1][i].push_back(res);
			}
			else
			{
				//m[1][i] = m[1][i-1];
				v[1][i].push_back(v[1][i-1][0]);
			}
		}

		for( i = 2; i <= len2; i++)
		{
			for( j = 1; j <= len1; j++)
			{
				if(root[j-1] == check[i-1])
				{
					//m[i][j] = m[i][j-1] + m[i-1][j-1];
					s3 = v[i][j-1][0];
					s4 = v[i-1][j-1][0];
					strcpy(in,s3.c_str());
					strcpy(in1,s4.c_str());
					add(in,in1,res);
					v[i][j].push_back(res);
				}
				else
				{
					//m[i][j] = m[i][j-1];
					v[i][j].push_back(v[i][j-1][0]);
				}
			}
		}

		cout << v[len2][len1][0] << endl;

		for( i = 0; i <= 100; i++)
		{
			for( j = 0; j <= 10000; j++)
			{
				v[i][j].clear();
			}
		}

	}

	return 0;
}