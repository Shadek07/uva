#include<iostream>

using namespace std;

int main(void)
{
    
    int road;
    int num;
    int c = 1;
    int min = 0;
    int sum = 0;
    
    while(1)
    {
            cin >> road >> num;
            if( road == 0 && num == 0) break;
            
            cout << "Case " << c++ << ": ";
            
            if( road <= num)
            {
                  cout << min << endl;
                  continue;           
            }
            
            sum = num;
            
            for(int i = 0 ; i < 26; i++)
            {
                    sum += num;
                    min++;
                    if( sum >= road)
                    {
                        cout << min << endl;
                        break;
                    }
            }
            
            if( sum < road )
            cout << "impossible\n";
            
            
            min = 0;
            sum = 0;
            
    }
    
    
    
    return 0;
}
