#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v1;

int main(void)
{

	int num,i,j,a;

    i = 0;
	while(cin >> num)
	{
		i++;

		v1.push_back(num);

		sort(v1.begin(),v1.end());

        a = i-1;
		if( a == 0)
			j = v1[0];
        if( a > 0)
		{
           if( a%2 == 1)
		   j = (v1[(a+1)/2] + v1[(a-1)/2])/2;
		   else
			   j = v1[a/2];
		}
		

			
			

		cout << j << endl;
	}


	return 0;
}