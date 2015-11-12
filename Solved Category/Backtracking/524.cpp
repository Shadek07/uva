#include <iostream>
#include <vector>

using namespace std;

bool vis[17];
//0,1,2.....
int is_prime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
vector<int>res;

void dfs(int n,int curr)
{
	if(curr==n-1)
	{
		if(is_prime[res[curr]+1])
		{
			printf("1");
			for(int i=1;i<n;i++)
				printf(" %d",res[i]);
			printf("\n");
		}
		return;
	}

	int i;
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(is_prime[res[curr]+i])
			{
				res.push_back(i);
				vis[i] = true;
				dfs(n,curr+1);
				res.pop_back();
				vis[i] = false;
			}
		}
	}

}

int main()
{
	int n,i,j,k,z=0;

	while(cin>>n)
	{
		memset(vis,0,sizeof(vis));
		if(z) printf("\n");
		printf("Case %d:\n",++z);
		vis[1] = true;
		res.clear();
		res.push_back(1);
		dfs(n,0);
	}


	return 0;
}