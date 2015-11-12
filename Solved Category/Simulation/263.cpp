#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector <int> v1,v2;

int main( void)

{
	

	vector <int> ::iterator it;

//	char descend[100],ascend[100];

	int num,a,b;

	int i,j;

	int des,ascen;

	int count = 0;

	while(1)
	{

		cin >> num;
		if( !num) break;

		cout << "Original number was " << num << endl;

		count = 0;

		a = num;

		i = 0;

		while(1)
		{

            i = 0;
			while(a)
			{
				b = a%10;
				a /= 10;
				i++;
				v1.push_back(b);
			}

			sort(v1.begin(),v1.end());

			ascen = 0;

			it = v1.begin();

			while(it != v1.end())
			{
				j = *it;

				ascen = ascen*10 + j;

				it++;
			}

			i--;

			des = 0;

			while(i >= 0)
			{
				j = v1[i];
				des = des*10 + j;
				i--;
			}

			count++;

			v1.clear();

			cout <<  des << " " << "- " << ascen << " = " << des- ascen << endl;
        
			it = find(v2.begin(),v2.end(),des-ascen);
			if( it != v2.end())
			{
				

				cout << "Chain length " << count << endl << endl;

				
				v2.clear();

				break;

			  
			}
			else
			{
				v2.push_back(des-ascen);
			    a = des-ascen;
				

			}
		}


	}

	

	return 0;



}