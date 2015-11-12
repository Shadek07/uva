#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
int n;
int a,b;
int x[1005];
int y[1005];


bool contains()
{
     int crossings = 0;
     int i;
     for(i = 0; i < n;i++)
     {
           double slope = (y[i+1] - y[i])/(x[i+1]-x[i]);
           bool cond1 = (x[i] <= a) && (a < x[i+1]);
           bool cond2  = (x[i+1] <= a) && (a < x[i]);
           bool above = (b < slope*(a-x[i]) + y[i]);
           if((cond1 || cond2) && above)
           crossings++;           
     }
     return (crossings%2 != 0);
}

int main(void)
{
    int i;
    bool c;
    while(cin >> n && n)
    {
        for(i = 0; i < n;i++)
        {
              cin >> x[i] >> y[i];
        } 
        
        cin >> a >> b; 
        c = contains();
        if(c == true)
        cout << "T\n";
        else
        cout << "F\n";    
    }
    return 0;
}
