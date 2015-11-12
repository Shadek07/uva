#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main(void)
{
    
    int t;
    char one[22];
    char two[22];
    
    int c = 0;
    
    int l1,l2;
    
    cin >> t;
    getchar();
    
    while(t--)
    {
        gets(one);
        gets(two); 
       // getchar();
        
        l1 =  strlen(one);
        l2 = strlen(two);
        if(l1 != l2)
        {
              
            cout << "No\n";
            continue;
        }
        
        for(int i = 0; i < l1; i++)
        {
                if( one[i] != two[i] )
                {
                    if( !((one[i]== 'a'||one[i]== 'e'||one[i]== 'i'||one[i]== 'o'||one[i]== 'u')&&(two[i]== 'a'||two[i]== 'e'||two[i]== 'i'||two[i]== 'o'||two[i]== 'u')))
                    {
                        cout << "No\n";
                        c = 1;
                        break;
                    }
                }
                
        }
        
        if( c != 1)
        {
            cout << "Yes\n";
        }
        
        c = 0;
           
              
    }
        
    return 0;   
}
