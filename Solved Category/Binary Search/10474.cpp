#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int main()
{
      int s[10000];
      int search[10000];
      int N,Q;
      int c = 1;
      int i,k,m,n,p,q;
      int count = 1,check = 0;
      while(1)
      {
              cin >> N >> Q;
              if( N == 0 && Q == 0)
              break;
              for( i = 0 ; i < N; i++)
              {
                   cin >> s[i];
                   
              
              }
              
              for(i = 0 ; i< Q;i++)
              {
                    cin >> search[i];
              }
              cout << "CASE# " << c++<<":\n";
              
              for( m = 0 ; m < Q;m++)
              {
                   p = search[m];
                       
                  for( i = 0 ; i < N; i++)
                  {
                       if(s[i] < p)
                       count++;
                       if(s[i] == p)
                       check = 1;
                  }
                  
                  
                  
                  
                  
                       
                       
                  if( check == 1)
                  {
                     cout <<  p <<" found at " << count << endl;
     
                   }
                   else
                   {
                           cout << p << " not found\n";
                   }
                  
                   check = 0;
                   count = 1;
                   
              }
     
      }
      
      return 0;
}


    
    
    

