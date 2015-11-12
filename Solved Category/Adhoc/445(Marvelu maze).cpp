#include<stdio.h>

int main(void)
{

	char input[140];

	char k,k1;

	int f,e;

	int i = 0 ,i1; 

	int digit_sum = 0 ; 

	while( (k = getchar() ) != EOF )
	{
            
		    input[i++] = k;
               

	        i1 = i - 1;

			input[i] = '\0' ;

			if( input[i1] == '\n')
			{


					for(  f = 0 ; f < i ; f++)
					{

							k = input[f] ;

							if( k >= '0' && k<= '9' )
							{
								digit_sum += k - 48;
								
								while(input[++f] >= '0' && input[f] <= '9' )
								{
									digit_sum += input[f] - 48 ;
								}

							}

							k1 = input[f] ;

							if(  ( k1 >= 'A' && k1 <= 'Z' ) || ( k1 == 'b' ) || ( k1 == '*') || (k1 == '\n'))
							{
								if( digit_sum != 0 )
								{

									for(  e = 1; e <= digit_sum ; e++)
									{

										/*if( k1 != 'b')

										printf("%c", k1);

										
                                        else
											printf(" ");*/

										if( k1 == 'b')

											printf(" ");

										if( k1 == '\n')

											printf("\n");

										if( k1 == '*')

											printf("*");

										if( k1 == '!')

											printf("\n");

										else

											printf("%c",k1);
									}
								}
							}

							
							
							
							

							digit_sum = 0;
					}

					

					i = 0;
			}
					

	}


    return 0 ;


}
