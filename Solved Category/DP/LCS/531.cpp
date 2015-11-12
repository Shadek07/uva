#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
#define MAX 100
char com1[100][31];
char com2[100][31];
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

void printLCS(int i,int j) 
{
       if (i==0 || j==0) return;
       if (b[i][j]==1) 
	   {
			printLCS(i-1,j-1);
			if( coun > 1)
			{
			   printf("%s ",com1[i-1]);
			   coun--;
			}
			else
				printf("%s\n",com1[i-1]);

	   }
	   else if (b[i][j]==2)
	         printLCS(i-1,j);
	   else
			 printLCS(i,j-1);
}

int main()
{

	string s,s1,s2;
	int check = 1;
    
	int hash;
	char in[10000],tmp[100];
	int len,len1,len2;
	char c1;
	hash = 0;
	ind1 = ind2 = 0;

	while( gets(in) )
	{
		len = strlen(in);
		if( len == 1 && in[0] == '#')
		{
			hash++;
			check = 0;
		}
		else
		{
			check = 1;
		}
		if( hash == 0 && check)
		{
            s1  = in;
			istringstream sin(s1);
			for(;sin >> s1 ;)
			{
                strcpy(tmp,s1.c_str());
				strcpy(com1[ind1++],tmp);
			}
			check = 1;
               
		}
		if( hash == 1 && check)
		{
			s1 = in;
			istringstream sin(s1);
			for(;sin >> s1 ;)
			{
                strcpy(tmp,s1.c_str());
				strcpy(com2[ind2++],tmp);
			}

			check = 1;

		}
		if( hash == 2)
		{
			//LCS
			coun = LCSlength();
			printLCS(ind1,ind2);
			ind1 = ind2 = hash = 0;
		}

	}


        
             
         
		  
	         
			 
	
   return 0;
}