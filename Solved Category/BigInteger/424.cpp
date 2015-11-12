#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

//temp = input + final
//final = temp;

char final[1000];

int main(void)
{
	
	
	char temp[1000];
	char input[1000];
	
	long int i,j,a,b;
	long int check = 1;
	long int len;
	long int max = 0;
    long int sum = 0;
	long int carry = 0;
	i = 0;
    long int ind;
	
	long int save;
	memset(final,'0',sizeof(final));
	memset(temp,'0',sizeof(temp));
	while(check)
	{
		gets(input);

		len = strlen(input);

		if( len == 1 && input[0] == '0')
		{
            //reverse(final,final+save);
			check = 0; 
			final[save] = '\0';
            i = 0;
			while(final[i] == '0')
				i++;

			for(; i < save;i++)
			{
				cout << final[i];
			}
			cout << endl;

			break;
		}

		else
		{

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
           
		   
		}

	}

    
    return 0;

}