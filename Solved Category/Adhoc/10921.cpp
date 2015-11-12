#include<iostream>

using namespace std;

int main()
{
	   int value[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

	   char str[31];

	   int index = 0;

	   char ch;

       int check = 0;
	   while( (ch = getchar())!= EOF)
	   {
			  if( ch != '\n')
			  {
					 str[index++] = ch;
			  }


			  else
			  {
					 check = 1;

					 str[index] = '\0';
			  }

			  if( check == 1)
			  {
					 for(int i = 0; i< index;i++)
					 {
							if( str[i] == '-' || str[i] == '0' || str[i] == '1')
							{
								   cout << str[i];
							}

							else
							{
								   cout << value[ str[i] - 65];
							}
					 }

					 cout << endl;

					 check =  0;

					 index = 0;
			  }
	   }

	   return 0;
}





