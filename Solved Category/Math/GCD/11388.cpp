#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>

using namespace std;

typedef pair<int,int> pa;

class GCDLCM 
{ 
    //Euclid's method to get the gcd of two numbers
    public:
    long gcd(long a, long b)
    {
        while (b != 0) 
        {
            long c = b;
            b = a % b;
            a = c;
        }
        return a;
    }
    pa get(long G, long L) 
    { 
        
        long res = -1; 
        long ab = L/G; 
        // divisors of ab 
        // For each pair (a,b) such that a*b == ab,
        // at least one of the (a,b) will be <= sqrt(ab)
        for(long a=1; a <= ab/a; a++) 
        { 
            if (ab % a == 0) 
            { 
                //try all pairs (a,b) 
                long b = ab / a; 
                if (gcd(a,b) == 1) 
                {  
                    
                    long fir = a*G;
                    long sec = b*G;
                    pa p3 = pa(fir,sec);
                    return p3;
                    break;
                }               
               
            } 
        } 
        
    } 
    
};

int main(void)
{
    int t;
    
    int G,L;
    
    cin >> t;
    GCDLCM gd;
    pa p2;
    while(t--)
    {
        cin >> G >>  L;        
        if( L%G == 0)
        {
            p2 = gd.get(G,L);
            cout << p2.first << " " << p2.second << endl;
        }
        else cout << "-1" << endl;        
    }
        
    return 0;
}
