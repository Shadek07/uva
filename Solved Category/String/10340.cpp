#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
	
	int i,j,k,ind;
	
    char in[100000],out[100000];
    
  while(scanf("%s %s",in,out)==2)
  {
	  
	  
	  i = strlen(in);

	  j = strlen(out);

	  ind = 0;

	  for(k = 0; k < j; k++)
	  {
		  if( in[ind] == out[k])
			  ind++;
	  }



	  if(ind == i)
      cout << "Yes" << endl;
	  else
		  cout << "No" << endl;

  }
  

  // different member versions of find in the same order as above:
  

  return 0;
}