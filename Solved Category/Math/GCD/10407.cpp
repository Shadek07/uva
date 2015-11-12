#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a,int b)
{
    int c;

	if( b == 0)
	{
		return a;
	}

    else return gcd(b,a%b);
}



int main(void)
{
    int a,b,i,j,k;
    int ind;
    int input[10000];
int val[10000];
    
    while(1)
    {
            cin >> a;
            if(!a)
              break;
              input[0] = a;
              i = 1;
              while(1)
              {
                      cin >> a;
                      if(!a)
                      break;
                      input[i++] = a;
                      //val[i-2] = abs(input[i-1] - input[i-2]);
              }
              
              for( j = 0; j < i; j++)
              {
                   val[j] = labs(input[j]-input[j+1]);
              }
              
              j = i-1;
              
              if( j == 1)
              {
                  k = gcd(input[0],input[1]);
                  cout << k << endl;
                  continue;
              }
              
              
              k = gcd(val[0],val[1]);
              
              if( j == 2)
              {
                  cout << k << endl;
                  continue;
              }
              else
              {
                  for(b = 2; b < j; b++)
                  {
                        
                        k = gcd(k,val[b]);
                  }
                  
                  cout << k << endl;
              }
              
    }
    
    return 0;
}
