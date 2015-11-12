#include<iostream>
#include<cstring>

using namespace std;


int main(void)
{

	int info[26];

	char solution[1000];
	char guess[1000];

	bool wrong[26];
	bool wrong1[26];

	int r,i,j,k,count;

	int check;
	int not_win;
	int prev = 0;

	while(1)
	{
		cin >> r;
		getchar();
		if( r == -1)
			break;

		memset(info,0,sizeof(info));
		memset(wrong,false,sizeof(wrong));
		memset(wrong1,false,sizeof(wrong1));

		count = 0;

		gets(solution);
		gets(guess);

		cout << "Round " << r << endl;

		not_win = 0;
		prev = 1;

		i = strlen(solution);

		for( j = 0; j < i ; j++)
		{
			info[int(solution[j])-97]++;
		}

		i = strlen(guess);

		check = 0;

		for( j = 0 ; j < i ; j++)
		{
			if( wrong1[int(guess[j])-97] == false)
			{
				wrong1[int(guess[j])-97] = true;

				if( info[int(guess[j])-97] == 0)
				{
					if( wrong[int(guess[j])-97] == false )
					{
					   count++;
					   wrong[int(guess[j])-97] = true;
					}

					


					if( count == 7)
					{
						check = 1;   //lose
						//
						//break;
					}
				}
				if( info[int(guess[j])-97] > 0)
				{
					info[int(guess[j])-97] = 0;
				}
			}

			if( count < 7)
			{
						prev = 1;
						for( k = 0; k < 26 ; k++)
						{
                             if( info[k] != 0)
								 prev = 0;

						}
			}
		}

		
		
			for( i = 0; i < 26 ; i++)
			{
				if( info[i] != 0 )
				{
					 not_win = 1;
					 
					 break;
				}
			}

			

			if( not_win == 0 && prev == 1)
			{
				    cout << "You win.\n";
					
			}
			else if( count >= 7 )
			{
				cout << "You lose.\n";

			}
			else
			{
				cout << "You chickened out.\n";
			}
		
		
	}


	return 0;
}
