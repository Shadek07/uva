#include<iostream>
#include<cstring>

using namespace std;
char f[10000];
char fact[1010][10000];
void multiply(int k)
{
     int in,sum,i;
     int len = strlen(f);
     in = 0; 
     i = 0;
     while( i < len)
     {
            sum = in+(f[i]-'0')*k;
            f[i] = (sum%10)+'0';
            i++;
            in = sum/10;
     }
     while(in >0)
     {
              f[i++] = (in%10)+'0';
              in /= 10;
              
     }
     f[i] = '\0';
     for(int j = 0;j < i;j++)
     {
          fact[k][j] = f[j];
             
     }
     
     fact[k][i] = '\0';
     
     
}

void fac()
{
     int k;
     strcpy(f,"1");
     for(k = 2; k <= 1000; k++)
     
     multiply(k);
     
}
void print(int n)
{
     int i;
     int len = strlen(fact[n]);
     printf("%d!\n",n);
     for( i = len-1;i>=0; i--)
     {
          printf("%c",fact[n][i]);
          
     }
     printf("\n");
}

int main(void)
{
    int n;
    fact[0][0] = '1';
    fact[1][0] = '1';
    fac();
    while(scanf("%d",&n)==1)
    {
           print(n);
    }
    
    fflush(stdin);
    getchar();
    
    
    return 0;
}
