#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	
	int i,j,k,ind;

	int t,s;
	
    char in[100000],out[100000];

	cin >> t;

	getchar();
    
  while(t--)
  {

	  gets(in);
	  
	  
	  i = strlen(in);

	  cin >> s;

	  getchar();
	  
	  while(s--)
	  {

		  gets(out);

		  j = strlen(out);

		  ind = 0;

		  for(k = 0; k < j; k++)
		  {
			  if( out[ind] == in[k])
				  ind++;
		  }



		  if(ind == j)
		  cout << "y" << endl;
		  else
			  cout << "n" << endl;
	  }

  }
  

  // different member versions of find in the same order as above:
  

  return 0;
}