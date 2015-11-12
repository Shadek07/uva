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
	 int count[10];
     int len = strlen(fact[n]);
	 memset(count,0,sizeof(count));
     printf("%d! --\n",n);
     for( i = len-1;i>=0; i--)
     {
          count[fact[n][i]-48]++;
          
     }
	 //space should be maintained properly
	 printf("   (0)");
	 printf("%5d",count[0]);
	 printf("    (1)");
	 printf("%5d",count[1]);
	 printf("    (2)");
	 printf("%5d",count[2]);
	 printf("    (3)");
	 printf("%5d",count[3]);
	 printf("    (4)");
	 printf("%5d",count[4]);
	 cout << endl;
	 printf("   (5)");
	 printf("%5d",count[5]);
	 printf("    (6)");
	 printf("%5d",count[6]);

	 printf("    (7)");
	 printf("%5d",count[7]);
	 printf("    (8)");
	 printf("%5d",count[8]);
	 printf("    (9)");
	 printf("%5d",count[9]);
	 

     printf("\n");
}

int main(void)
{
    int n;
    fact[0][0] = '1';
    fact[1][0] = '1';
    fac();
    while(1)
    {
		   cin >> n;
		   if(!n) break;
           print(n);
    }
    
   
    
    
    return 0;
}
