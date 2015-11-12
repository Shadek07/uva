#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int arr[3];
void cal(int a,int b)
{
	int p,q,r;
	if(b == 0)
	{
		arr[0] = 1;
		arr[1] = 0;
		arr[2] = a;
		return;
	}
	else
	{
		cal(b,a%b);
		p = arr[0];
		q = arr[1];
		r = arr[2];

		arr[0] = q;
		arr[1] = p - floor(a*1.0/b)*q;
		arr[2] = r;
	}

}
int main(void)
{

	int a,b;

	while(cin >> a >> b)
	{
		cal(a,b);
		cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

	}
	return 0;
}