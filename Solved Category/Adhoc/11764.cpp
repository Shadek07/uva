#include<iostream>

using namespace std;

int main(void)
{
    int t;
    int N;
    int h,h1;
    int cas = 1;
    int i,j = 0,k = 0;
    cin  >> t;
    
    while(t--)
    {
            
            
            cin >> N;
              
            cin >> h1;
            
            for( i= 1; i < N ; i++)
            {
                 cin >> h;
                 
                 if( h > h1)
                 j++;
                 else if( h1 > h)
                 k++;
                 
                 h1 = h;
                 
                 
                 
            }
            cout << "Case "<< cas++ <<": " << j << " " << k << endl;
            
            j = k = 0; 
            
    }
    
    
   
    
    return 0;
}
