#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

const int INF = 2000000000;

int main(int argc, char *argv[])
{
    long long humble[5842];
    humble[0] = 1;
    for(int i = 1; i < 5842; i++)
    {
        humble[i] = INF;

        for(int j = 0; j < i; j++)
        {
            if(humble[j] * 2 > humble[i-1])
            {
                if(humble[j] * 2 < humble[i])
                    humble[i] = humble[j] * 2;
            }
            else if(humble[j] * 3 > humble[i-1])
            {
                if(humble[j] * 3 < humble[i])
                    humble[i] = humble[j] * 3;
            }
            else if(humble[j] * 5 > humble[i-1])
            {
                if(humble[j] * 5 < humble[i])
                    humble[i] = humble[j] * 5;
            }
            else if(humble[j] * 7 > humble[i-1])
            {
                if(humble[j] * 7 < humble[i])
                    humble[i] = humble[j] * 7;
            }
        }
    }
                  
    int n;

    while(cin >> n)
    {
        if(n == 0)
            break;
        if(n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
            cout << "The " << n << "th humble number is " << humble[n-1] << ".\n";
        else if(n % 10 == 1)
            cout << "The " << n << "st humble number is " << humble[n-1] << ".\n";
        else if(n % 10 == 2)
            cout << "The " << n << "nd humble number is " << humble[n-1] << ".\n";
        else if(n % 10 == 3)
            cout << "The " << n << "rd humble number is " << humble[n-1] << ".\n";
        else
            cout << "The " << n << "th humble number is " << humble[n-1] << ".\n";
    }
    
    return 0;
}