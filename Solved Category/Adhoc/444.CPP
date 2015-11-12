#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{

	char in[100000],out[100000];

	int i,k,len,len1,d,a,b;

	

	while(gets(in))
	{
		len = strlen(in);

		if( len != 0)
		{

				k = 0;

				if( isdigit(in[0]))
				{
					 reverse(in,in+len);
             
					 for( i = 0; i < len;i++)
					 {
						 d = 0;
						 if( in[i] == '1')
						 {
							 d = d*10 + (in[i] - 48);
							 i++;
							 d = d*10 + (in[i] - 48);
							 i++;
							 d = d*10 + (in[i] - 48);

							 out[k++] = char(d);

						 }
						 else
						 {
							 d = d*10 + (in[i] - 48);
							 i++;
							 d = d*10 + (in[i] - 48);
							 
							 out[k++] = char(d);

						 }
					 }

					 out[k] = '\0';

					 cout << out;
				}
				else
				{
					
					
					
					for(i = 0; i < len ; i++)
					{
						  d = int(in[i]);
						  
						  if( d < 100)
						  {
							  a = d/10;
							  b = d%10;
							  out[k++] = char(a+48);
							  out[k++] = char(b+48);
						  }
						  else
						  {
							  out[k++] = char(49);   //1+48
							  d = d%100;
							  a = d/10;
							  b = d%10;
							  out[k++] = char(a+48);
							  out[k++] = char(b+48);
						  }
					}

					out[k] = '\0';

					len1 = strlen(out);

					reverse(out,out+len1);

					cout << out;

				}
		}

		cout << endl;
	}


	return 0;
}