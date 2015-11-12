#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cctype>

using namespace std;


void strip_newline( char *str, int size )
{
    int i;

    /* remove the null terminator */
    for (  i = 0; i < size; ++i )
    {
        if ( str[i] == '\n' )
        {
            str[i] = '\0';

            /* we're done, so just exit the function by returning */
            return;   
        }
    }
    /* if we get all the way to here, there must not have been a newline! */
}


int check_hyphen( char *str, int size)
{
    int i;

    
    for (  i = 0; i < size; ++i )
    {
        if ( str[i] == '-' || str[i] == '\'' )
        {                    
            return 1;   
        }
    }

	return 0;
    
}


int main(void)
{
	int ca = 1;
	char in1[10000],in2[10000];
	char input[10000],c1;
	char tmp[100];
	string s1[20];
	string s2[20];
	int m,n,i,j,k;
	int attach = 0;
	int count[31];

	input[0] = '\0'; 

	while(fgets(tmp,100,stdin))
	{
		
		
		strip_newline( tmp,100);

		int l1 = strlen(tmp);

		if( l1 == 1 && tmp[0] == '#')
		{

			   memset(count,0,sizeof(count));
			   
			   char *p;
				
			    s1[0] = input;
				int l11 = strlen(input);
				//cout << l11 << endl;
				strcpy(in1,s1[0].c_str());
				p = strtok(in1," ,.,!?");
				
				while( p != NULL)
				{
					
                    j = strlen(p);

					int y = check_hyphen( p, j);

					if( y == 1)
						j = j-1;

								

					count[j]++;

				
					
					p = strtok(NULL," ,.,!?");
				}
				
				for( i = 1; i < 31; i++)
				{
					if(count[i] > 0)
					{
						cout << i << " " << count[i] << endl;
						count[i] = 0;
					}
				}

			     
				input[0] = '\0';

				cout << endl;
		}
		else
		{
			

			if( attach == 1)
			{

				
				s2[0] = tmp;
				strcat(input,s2[0].c_str());
				attach = 0;
			}
			else
			{
				strcat(input," ");
				s2[0] = tmp;
				strcat(input,s2[0].c_str());
			}
			if( tmp[l1-1] == '-')
			{
				attach = 1;
			}

		}

		

	    

	}
	return 0;
}