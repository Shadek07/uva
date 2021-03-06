#include <iostream>
using namespace std;
#define MAXTOTAL 30006


long nway[MAXTOTAL+1];

// Assume we have 5 different coins here
int coin[5] = { 50,25,10,5,1 };

int main() 
{
  int i,j,n,v,c;

  while(scanf("%d",&n) == 1)
  {
	  v = 5;
	  nway[0] = 1;
	  for (i=0; i<v; i++) 
	  {
		c = coin[i];
		for (j=c; j<=n; j++)
		  nway[j] += nway[j-c];
	  }
	  if(nway[n] == 1)
	  cout << "There is only 1 way to produce " << n << " cents change.\n";
	  else
		  cout << "There are " << nway[n] <<" ways to produce " << n << " cents change.\n";

	  memset(nway,0,sizeof(nway));
  }
  return 0;
}