#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> coll;
    
    vector<int>::iterator pos;
    
    int a,b,c,ca = 1;
    int t;
    
    cin >> t;
    
    while(t--)
    {
              
            cin >> a >> b >> c;
            
            coll.push_back(a);
            coll.push_back(b);
            coll.push_back(c);
           
            cout << "Case " << ca++ << ": ";
            
            
            pos = min_element (coll.begin(), coll.end());
            coll.erase(pos);
            pos = max_element (coll.begin(), coll.end());
            coll.erase(pos);
            
            cout << coll[0] << endl;
            coll.clear();
     }
     
    fflush(stdin);
    getchar();
    return 0;
}
