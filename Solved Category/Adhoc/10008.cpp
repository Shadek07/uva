#include<iostream>

#include<cstring>


using namespace std;

int main()
{
	int arr[26];//to save frequency

	char letter[27]; //to show output

	char c;

	int max = 0;

	int index;

	int total_line;

	int check = 1;

	int secondVariable = 1;

	c = 'A';

	for(int l = 0;l<=25;l++)
	{
		letter[l] = c;

		c++;
	}

	for(int k = 0;k<=25;k++)
	{
		arr[k] = 0;
	}

	cin >> total_line;

	while(total_line + 1)
	{


		while((c = getchar())!='\n')
		{
			if(c>= 'a' && c<= 'z')
			{
				arr[ c  - 'a' ]++;
			}

			if(c >= 'A' && c<='Z')
			{
				arr[ c - 65]++;
			}
		}

		if( c =='\n')
		{
			total_line--;
		}
	}


	while(check)
	{


		for(int j = 0;j<= 25;j++)
		{
			if(arr[j]> max)

			{
				max = arr[j];

				index = j;
			}

		}
		if(max != 0)
		{

		
		  cout << letter[index] << " "<< max << endl;
		}

	/*	for(int m = 0;m<=25;m++)

		{
			if(arr[m] != 0)  //if there are any non-jero value

				secondVariable = 0;
			
			
		}*/

		/*if(!secondVariable)
		{
			check = 1;
		}

		else
			check = 0;*/

		if(max == 0 )
		{
			check = 0;
		}

		arr[index] = 0; // make jero in such index value where we have got max value for making easy to find next max

		max = 0;  // for initialization to use in next iteration
	}

	

	return 0;
}






