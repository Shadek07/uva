#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
long int val[10000];

int main(void)
{
    int n;
    int i;
    long long res;
    while(1)
    {
            cin >> n;
            if(!n)
            break;
            
            for(i = 0; i < n;i++)
            cin >> val[i];
            if(n == 1)
            {
                 cout << "Yes\n";
                 continue;
            }
            
            res = val[0] ^ val[1];
            for(i = 2; i < n;i++)
            {
                  res ^= val[i];
            }
            
            if(res == 0)
            cout << "No\n";
            else
            cout << "Yes\n";
    }
    return 0;
}
