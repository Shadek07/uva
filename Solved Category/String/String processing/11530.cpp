#include<iostream>

using namespace std;

int main()

{
	int num_of_line;

	int save[] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };

	char str[103];

	int index = 0;

	int cas = 1;

	char ch;

	char p;

	int count = 0;

	cin >> num_of_line;

	int num = num_of_line;

	p = getchar();

	while(num_of_line)
	{
		
		while( (ch = getchar())!= '\n')
		{
			str[index++] = ch;
		}

		for(int a = 0; a<index;a++)
		{

			int n = str[a] - 97;


		    
			
				
			if( n>= 0 && n < 26)	


			count += save[n];

			else

				count += 1;

	
			
			
		}


		cout << "Case #" << cas << ":" << " " ;
		
		cout << count << endl;

		count = 0;

        cas++;

		index = 0;

		str[0] ='\0';

		num_of_line--;
	}
	
	
	
    return 0;


	
}

