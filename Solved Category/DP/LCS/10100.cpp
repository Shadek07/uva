#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>

using namespace std;
#define MAX 1005
char com1[1005][100];
char com2[1005][100];
int ind1,ind2;
int m,n;
int coun;
int i,j,c[MAX][MAX],b[MAX][MAX];

int LCSlength() 
{
		m=ind1;
		n=ind2;

		for (i=1;i<=m;i++) 
			c[i][0]=0;
		for (j=0;j<=n;j++) 
			c[0][j]=0;
		for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
		{
			if (strcmp(com1[i-1],com2[j-1]) == 0) 
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1; /* from north west */
			}
			else if (c[i-1][j]>=c[i][j-1]) 
			{
					c[i][j]=c[i-1][j];
					b[i][j]=2; /* from north */
			}
			else 
			{
					c[i][j]=c[i][j-1];
					b[i][j]=3; /* from west */
			}
		}

		return c[m][n];
}

int main()
{

	string s,s1,s2;
	string t1,t2;
	int check = 0;
    int cn = 1;
	int hash;
	char in[10000],in1[10000];
	int len,len3;
	
	int j,k;
	hash = 0;
	ind1 = ind2 = 0;

	while( gets(in) && gets(in1) )
	{
		len = strlen(in);
		len3 = strlen(in1);
		char *p;

		if( len == 0 || len3 == 0)
		{			
			printf("%2d",cn++);
			cout  << ". Blank!\n";
			continue;
			check = 1;
		}
		
		else
		{
            s1  = in;
			j = 0;
			len = strlen(in);
			p = strtok(in," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			while( p != NULL)
			{

				strcpy(com1[ind1],p);

				ind1++;
				
				
				p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			}

		
		
			len = strlen(in1);
			

			j = 0;

			p = strtok(in1," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			while( p != NULL)
			{

				strcpy(com2[ind2],p);

				ind2++;
				
				
				p = strtok(NULL," !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~");
			}
			
			//LCS
			coun = LCSlength();

			printf("%2d",cn++);

			cout <<". Length of longest match: ";
			printf("%d\n", coun );
			
			ind1 = ind2 = hash = 0;			              
		}								

	}	 	
   return 0;
}