#include<iostream>

using namespace std;

#define INF 4294967295
int num;

void print(unsigned long s[20][20],int i,int j)
{
     if( i == j)
         printf("A%d",num++);
     else
     {
         printf("(");
         print(s,i,s[i][j]);
         printf(" x ");
         print(s,s[i][j]+1,j);
         printf(")");
     }
}

void matrix_chain(int *p,int n)
{
     unsigned long m[20][20] = {0};
     unsigned long s[20][20] = {0};
     unsigned int q;
     int l,j,i,k;
     for( l = 2; l<= n; l++)
     {
          for( i = 1; i <= n-l + 1; i++)
          {
               j = i+l-1;
               m[i][j] = INF;
               for( k = i; k < j;k++)
               {
                    q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if( q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
               }
          }
     }
     
     num = 1;
     print(s,1,n);

}

int main(void)
{
    
    int size,i,k,l,m,n,c = 1;
    int p[20] = {0};
    
     while(1)
     {
             cin >> n;
             if(!n) break;
             for(i = 1; i <= n; i++)
             {
                   scanf("%d %d",&p[i-1],&p[i]);

             }
              
              cout << "Case " << c++ << ": ";
              matrix_chain(p,n);
              putchar('\n');
     }


   
    
    return 0;
}
