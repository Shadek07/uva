#include<iostream>

using namespace std;

unsigned  long long m[1000001];

int main(void)
{

unsigned  long long	int n;
unsigned  long long	int i,j,k;

unsigned  long long	int inc;
	


	m[3] = 0;
	//m[4] = 1;
	//m[5] = 3;
	i = 1;
	j = 0;
	inc = 1;
	k = 2;
unsigned  long long	int cnt = 0;
   
	for( i = 4; i <=1000000; i++,k++)
	{
		
		cnt++;
	
			
		
		
        j = j + inc;
		
	   	m[i] = m[i-1] + j;
		if(cnt == 2)
		{
		  inc++;
		  cnt = 0;
		}
		

	}

	while(cin >> n && n>=3)
	{
		cout << m[n] << endl;

	}


	return 0;
}