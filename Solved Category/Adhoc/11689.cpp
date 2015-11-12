#include<iostream>

using namespace std;

int main(void)
{
    
   /* int t;
    
    int e,f,c,count = 0,temp,res;
    
    cin >> t;
    
    while(t--)
    {
              cin >> e >> f >> c;
              
              res = (e+f)/c;
              count = res;
              
              temp = (e+f)%c;
              res += temp;
              
              while(res >= c)
              {
                    
                    
                    count += (res / c);
                    temp = res % c;
                    res += temp;
                    res /= c;
                    
                    
                     
                     
              }
              
              cout << count << endl;
              
              count = 0;
              
              
              
              
    }*/
    int t;
    int a,res,start,e,f,c;
    cin >> t;
    while(t--)
    {
            
            cin >> e >> f >> c;
              
            res=start=(e+f)/c;
            a=(e+f)%c;
            
            while(start)
            {
                int NumToBuy = (start+a)/c;
                res+= NumToBuy;
                a=(start+a)%c;
                start = NumToBuy;
            }
            
            cout << res << endl;
    }
    
    
    
    
    return 0;   
}
