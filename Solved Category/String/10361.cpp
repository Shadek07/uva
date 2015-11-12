#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main( void)
{
	int test;

	int arr[4];

	string str1,str2;

    string str3,str4;

	char f[105];

	char c;

	int i,j = 0;

	size_t found;


	cin >> test;

	c = getchar();

	for( i = 0; i< test; i++)
	{
		gets(f);

		str1 = f;

		gets(f);

		str2 = f;

		
	    str3 = str1;

        found = str1.find_first_of("<");

		arr[0] = int( found);

		found = str1.find_first_of(">");

		arr[1] = int(found);

		found = str1.find_last_of("<");

		arr[2] = int(found);

		found = str1.find_last_of(">");

		arr[3] = int(found);

	//	cout << arr[0] << "  " << arr[1] << " " << arr[2] << " " << arr[3] << "\n";

		j = str3.find("<");

		


		str3.erase(j,1);

		j = str3.find(">");



		str3.erase(j,1);

		j = str3.find("<");

		

	

		str3.erase(j,1);

		j = str3.find(">");

	

		str3.erase(j,1);



	   	

	

		

		j = str2.find(".");

		str4 = str2.substr(0,j);

        //str = str1.substr(arr[2] + 1 , arr[3] -1 )

        str4.append(str1.substr(arr[2] + 1 , arr[3] - arr[2] - 1 ));

		str4.append(str1.substr(arr[1] + 1 , arr[2] - arr[1] - 1 ));

		str4.append(str1.substr(arr[0] + 1 , arr[1] - arr[0] - 1 ));

		str4.append(str1.substr(arr[3] + 1 , str1.size() - arr[3] - 1 ));


        cout << str3 << "\n";

		cout << str4 << "\n";



		
	}


	return 0;
}