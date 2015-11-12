#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int points[51][2];

int css(int A[2], int B[2], int C[2])
{
         int * AB = new int[2];
         int * AC = new int[2];
        AB[0] = B[0]-A[0];
        AB[1] = B[1]-A[1];
        AC[0] = C[0]-A[0];
        AC[1] = C[1]-A[1];
        int cross = AB[0] * AC[1] - AB[1] * AC[0];
        if(cross < 0)
        return -1;
        else
        return 1;       
}

int main(void)
{
    int n,i,j,k;
    int plus,minus;
    int A[2],B[2],C[2];
    while(cin >> n && n)
    {
              for(i = 0; i < n;i++)
              {
                    cin >> points[i][0] >> points[i][1];
              }
              
              plus = minus = 0;
              
              for(i = 0; i < n;i++)
              {
                  j = (i+1)%n;
                  k = (i+2)%n;
                  A[0] = points[i][0];
                  A[1] = points[i][1];
                  
                  B[0] = points[j][0];
                  B[1] = points[j][1];
                  
                  C[0] = points[k][0];
                  C[1] = points[k][1];
                  int c1 = css(A, B, C); 
                  if(c1 == 1)
                  plus = 1;
                  else
                  minus = 1;
                   
              }
              
              if((plus == 1 && minus == 0)||(plus == 0 && minus == 1))
              {
                       cout << "No\n";
              }
              else
              cout << "Yes\n";
              
    }
    
    return 0;
}
