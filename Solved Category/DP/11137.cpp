#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
#define MAXTOTAL 10000


unsigned long long int nway[MAXTOTAL+1];

// Assume we have 5 different coins here
int coin[22] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};

int main() 
{
  int i,j,v,c;
  int n;
  int index;

   

  while(scanf("%d",&n) == 1)
  {
	 

	  v = 21;
	  index = n;
	  nway[0] = 1;
	  for (i=0; i<v; i++) 
	  {
		c = coin[i];
		for (j=c; j<=n; j++)
		  nway[j] += nway[j-c];
	  }

	  cout << nway[n] << endl;

	  
        
	  memset(nway,0,sizeof(nway));
  }
  return 0;
}
