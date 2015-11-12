#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{

	char in[100];

	char output[1000][100];
	int row,col;



	int len;
	

	
	
	int go,back = 0,i,j;
	
	string s;

	row = col = 0;

	while(gets(in))
	{
		len = strlen(in);

		s = in;

		go = 0;
		

		if( len == 1 && in[0] == '#')
		{
            break;
		}
		else
		{
			if( in[len-1] == '-')
			{
				go = 1;
			}

			if(go)
			{
				
				for( i = len-2; isalpha(in[i]) ; i--)
					;
				j = 0;

				if(back)
				{
					while(!isalpha(in[j]))
						j++;
                     for(; isalpha(in[j]); j++)
					 {
					     output[row][col] = in[j];
						 col++;
					 }
					 //cout << endl;
					  output[row][col] = '\0';
					 back = 0;
					 col = 0;
					 row++;
				}

				for(; j <= i  ; j++)
					if((isalpha(in[j]) || in[j] == ' ' || in[j] == '\t'))
					{
                         output[row][col] = in[j];
						 col++;
					}
				//cout << endl;
                    output[row][col] = '\0';
					row++;
					col = 0;

				for(i = i+1; i < len-1;i++)
					if((isalpha(in[i]) || in[i] == ' ' || in[i] == '\t'))
					{
						 output[row][col] = in[i];
						 col++;
					     
					}


				back = 1;

				
			}
			else
			{
				j = 0;

				if(back)
				{
					while(!isalpha(in[j]))
						j++;
                     for(; isalpha(in[j]); j++)
					 {
						 output[row][col] = in[j];
						 col++;
					     
					 }

					 //cout << endl;
					 back = 0;
					 output[row][col] = '\0';
					 row++;
					 col = 0;
				}

				for(;j < len; j++)

					if((isalpha(in[j]) || in[j] == ' ' || in[j] == '\t'))
					{
						 output[row][col] = in[j];
						 col++;
					     
					 }
			        //cout << endl;
					 output[row][col] = '\0';
					 row++;
					 col = 0;

			}

		}
		
	}

	for( i = 0; i < row; i++)
	{
		cout << output[i] << endl;
	}


    
    

	return 0;
}
