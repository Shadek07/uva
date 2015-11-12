
#include<iostream.h>
#include<math.h>

int main()
{

unsigned long int n;

while(cin>>n)
{
long double a=1;
unsigned long int t=0;

while(fmod(a,n)!=0)
{
a=(a*10)+1;
a=fmod(a,n);
t++;
}

cout << (t+1) << endl;
n=0;
}

return 0;
}
