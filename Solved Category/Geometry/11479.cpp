#include<iostream>
#include<cmath>
using namespace std;


int main()
{
       int t;
      long long int a,b,c;
       int y = 1;
       
       cin >> t;
       
       while(t--)
       {
            cin >> a >> b >> c;
            
            cout <<"Case " << y++ << ": ";
            
            if( a <= 0 || b <= 0 || c <= 0 ||((a+b) <= c) || ((a+c) <= b) ||((c+b) <= a) )
            {
                cout << "Invalid\n";
            }
            else
            {
                if( (a == b)&& ( b == c)&&(a == c))
                cout << "Equilateral\n";
                if( ((a == b) && c != a) || ((a == c) && b != a) || ((c == b) && a != c))
                {
                    cout << "Isosceles\n";
                }
                if( (a != b) && (c != b) && (a != c) )
                cout << "Scalene\n";
                
                
            }
                 
                 
                 
       }
    
       	return 0;
}
