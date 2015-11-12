/* p392 */

/* Polynomial Showdown */

#include<iostream>

using namespace std;

int main(void)
{
   int pol[12], i, j, flag, flag_1st, sum;

   //freopen("input.in", "r", stdin);

   
   while(scanf("%d%d%d%d%d%d%d%d%d", &pol[0], &pol[1], &pol[2], &pol[3], &pol[4], &pol[5], &pol[6], &pol[7], &pol[8]) == 9 )
   {
         
      flag = 0; flag_1st = 0; sum = 0;
      
      for( i = 0, j = 8; i < 9; i++, j--)
      {
         if(pol[i] < 0)
            sum = sum + (pol[i] * (-1));
         else
            sum = sum + pol[i];
         if(pol[i] != 0) 
         {
            flag_1st++;

            if( pol[i] < 0)
            {
				if( flag == 1)
					printf(" ");
               printf("-");
               if( flag == 1 )
                  printf(" ");
   
               pol[i] = pol[i] * -1;
               flag_1st++; 
            }
            else if( pol[i] > 0 )
            {
               if(flag_1st != 1)
               {
                  printf(" + ");
               }
            }
            
            
            flag_1st++;   
            if( pol[i] == 1)
            {
               if( i == 7 )
                  printf("x");
               else if( i == 8 )
                  printf("1");
               else
                  printf("x^%d", j);
               
               flag = 1;
            }
            else if( pol[i] > 1 )
            {
               if( i == 7 )
                  printf("%dx", pol[i]);
               else if( i == 8 )
                  printf("%d", pol[i]);
               else
                  printf("%dx^%d", pol[i], j);
   
               flag = 1;
            }
   
   
            
         }
         if(i == 8 && sum == 0)
            printf("0");
   
         
      }//end for
      
      printf("\n");
   }//end while
   
         
   return 0;
}//end main