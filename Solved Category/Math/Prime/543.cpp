#include<iostream>
#include<cmath>
using namespace std;

int prime(int n)
{
    
    if( n == 1) return 0;
    if( n %2 == 0) return 0;
    int r = sqrt(n);
    for(int i = 3; i <= r; i+= 2)
    if( n%i == 0 ) return 0;
    
    return 1;       
}

int main(void)
{
    
    int num;
    int max = 0,i,m;
    int a,b;
    int check = 0;
    
    while(1)
    {
            cin >> num;
            if( num == 0) break;
            
            for( i = 3; i <= num/2; i+= 2)
            {
                 if( prime(i) && prime(num-i))
                 {
                     /*if( (num-2*i) > max)
                     {
                         a = i;
                         b = num-i;
                         check = 1;
                     } */
                     a = i;
                     b = num - i;
                     check = 1;
                     break;
                 }
            }
            
            if( check == 1)
            cout << num << " = " << a << " + " << b << endl;
            else
            cout << "Goldbach's conjecture is wrong.\n";
                       
            max = 0;
            check = 0;
    }
    
    
    
    
    return 0;   
}
