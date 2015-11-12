#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void)
{
    
    int T,S,A,F,a,b;
    
    int i,k,m,n;
    
    long  double min,total = 0;
    
    int in[2][50000];
    
    int street,avenue;
    
    cin >> T;
    
    while(T--)
    {
        cin >> A >> S >> F;
        
        total = 0;
        min = 3802000000;
        
        for(  i = 0; i < F; i++)
        {
             cin >> a >> b;
             
             in[0][i] = a;
             
             in[1][i] = b;
        }
        
        sort(in[0],in[0]+F);
		sort(in[1],in[1]+F);
		if(F%2)
        cout << "(Street: " << in[0][F/2] << ", Avenue: " << in[1][F/2] << ")\n";
		else
			cout << "(Street: " << in[0][(F-1)/2] << ", Avenue: " << in[1][(F-1)/2] << ")\n";

        
    }
    
    
    
    return 0;
}
