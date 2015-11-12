#include<iostream>

#include<cstring>

using namespace std;

int main()
{
	int capital[53] = { 0};

	//int small[27] = {0};

	char ch,c1 = 'a',c2 = 'A';

	int max1 = 0,max2 = 0;

	int i,j;

	int save1,save2;

	while( (ch = getchar())!= EOF)
	{
		if( ch != '\n')
		{
			if( ch >= 'a' && ch <= 'z')
			{
				capital[ (int)ch - 97]++;  // from index 0 to 25
			}

			if( ch >='A' && ch <= 'Z')
			{
				capital[(int) ch - 65 + 26]++;  // from index 26 to 51
			}
		}

		if( ch == '\n')
		{
			for( i= 0; i<= 25; i++)
			{
				if( capital[ i] >= max1)
				{
					max1 = capital [i];

					save1 = i;


				}
			}

			for( j = 26; j<= 51; j++)
			{
				if( capital[j] >= max2)
				{
					max2 = capital [j];

					save2 = j;
				}
			}

			if( max1 < max2)
			{

				for( int g = 26; g <= save2 ; g++)
				{
					if( capital[g] == max2)

			        cout << char(c2 + g - 26);
				}

				cout << " " << max2 << endl;
			}

			if( max1 > max2)
			{

				for( int h = 0; h <= save1 ; h++)
				{
					if( capital[h] == max1)

			        cout << char(c1 + h);
				}

				cout << " " <<  max1 << endl;
			}


			if( max1 == max2)
			{
				
				for( int x = 26; x <= save2 ; x++)
				{
					if( capital[x] == max2)

			        cout << char(c2 + x  - 26);
				}


				for( int y = 0; y <= save1 ; y++)
				{
					if( capital[y] == max1)

			        cout << char(c1 + y);
				}

				cout << " " << max1 << endl;
			}

			max1 = 0;

			max2 = 0;

			for( int q = 0; q <= 51 ;q++)
			{
				capital[q] = 0;
			}



				
		}
	}

	return 0;
}


