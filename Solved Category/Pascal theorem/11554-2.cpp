#include<iostream>
#include<cstring>
using namespace std;

#define MAXTRI 1000001
long long  pas[MAXTRI][4],re[MAXTRI];
void pascals(int n)
{
	register int i,j;
	pas[0][0]=1;
	pas[1][0]=pas[1][1]=1;
	//re[3]=0;
	re[4]=1;
	for(i=2;i<=n;i++)
	{
		pas[i][0]=1;
		for(j=1;j<4;j++)
		{
			pas[i][j]= pas[i-1][j-1]+pas[i-1][j];
		}
		if(i<4) continue;
		re[i+1]=pas[i][3]-re[i];

		//pas[i][j]=1;
	}
}

int main()
{
	pascals(1000001);
	int n,t,zero=0;
	cin>>t;
	while(t--)
	{
        cin>>n;
        if(n==3) cout<<zero<<endl;

		else
		    cout<<re[n]<<endl;
		    //cout<<pas[n][3];
	}

	return 0;
}
