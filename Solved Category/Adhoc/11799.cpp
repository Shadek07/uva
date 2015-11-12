#include<iostream>

using namespace std;
int main(void)
{
    int t,n,a;
    int i;
    int max,c = 1;
    cin >> t;
    
    while(t--)
    {
       cin >> n;
       cin >> max;
       
       for( i = 0; i < n-1; i++)
       {
            cin >> a;
            
            if(a > max) max = a; 
       }
       
       cout << "Case " << c++ << ": " <<  max << endl;       
    }
         
    return 0;
}
