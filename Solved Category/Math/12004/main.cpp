#include <iostream>

using namespace std;

int main()
{
    long long n,x;
    int t;
    cin >> t;
    int ca=1;
    while(t--){
        cin >> n;
        cout << "Case " << ca++ << ": ";
        /**
        number of swaps can be 0 to n*(n-1)/2
        let's say x = n*(n-1)/2
        so, total number of swaps = x*(x+1)/2
        number of different swap value = x+1
        average = total swaps/number of different swap value = x/2
        **/
        x = ((n)*(n-1))/2;
        if(x&1){
            cout << x << "/" << 2 << endl;
        }
        else{
            cout << x/2 << endl;
        }
    }
    return 0;
}
