#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std ;

bool check[1001];
int ind[1001];

struct s
{
	int c;

	int frequency;

}ascii[300];

int compare(s a, s b)
{
	if( a.frequency != b.frequency)
	return a.frequency < b.frequency;
	else
	return a.c > b.c;
}




int main(void)
{

      char in[1001];
	  int i,j;
	  int ch = 0;

	  int count[1000];

	  memset(count,0,sizeof(count));
	  

	  while(gets(in) != NULL)
	  {
		  i = strlen(in);

		  memset(ascii,0,sizeof(ascii));
		  memset(check,false,sizeof(check));
		  memset(ind,-1,sizeof(ind));

		  int st = 0;

		  if( ch == 1)
			  cout << "\n";
		  else
			  ch = 1;

		  for( j = 0; j < i; j++)
		  {
              //count[(int)in[j]]++;
			  int a = int(in[j]);
			  if( check[a] == false)
			  {
				  ascii[st].c = int(in[j]);
				  ascii[st].frequency = 1;
				  ind[a] = st;
				  check[a] = true;
				  st++;
			  }
			  else
			  {
				  int b = ind[a];
			      ascii[b].frequency++;
			  }
			  
		  }

		  sort(ascii,ascii+st,compare);

		  for(j = 0; j < st; j++)
		  {
			  cout << ascii[j].c << " " << ascii[j].frequency << endl;
		  }

		  //cout << endl;
          
	  }

		


	

	return 0;
}