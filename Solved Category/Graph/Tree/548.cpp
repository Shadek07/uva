#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

vector<int> leaf,leaf_num;

int in[10005],post[10005];
int size;
int root;
int ind;
int cost[10005];
int parent[10002];
int par;
int mi;
int sin;
struct se
{
	int cost;
	int leaf;

}lf[10005];

int comp(se a, se b)
{
	if(a.cost < b.cost)
		return 1;
	else if(a.cost == b.cost)
	{
		if(a.leaf < a.leaf)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void build_tree(int r,int low,int high)
{
	int root_index,i,mid;
	
	if(low == high)
	{
		//cout << r << " ";
		
		lf[sin].cost = cost[in[low]];
		lf[sin].leaf = in[low];
		sin++;
		
		return;
	}

	for( i = 0; i < size; i++)
	{
		if(in[i] == r)
		{
			root_index = i;
			mid = i;
			break;
		}
	}



	if(high > mid)
	{
		ind--;
		cost[post[ind]] += post[ind] + cost[r];
		build_tree(post[ind],mid+1,high);
	}

	if(low < mid)
	{
		ind--;
		cost[post[ind]] += post[ind] + cost[r];
		build_tree(post[ind],low,mid-1);
	}


	//cout << r;

}

int main(void)
{
	int i,j;
	int t;
	char c;
	i = j = 0;

	while(cin >> t)
	{
		i = j = 0;
		in[i++] = t;
		c = getchar();
		while(c != '\n')
		{
			cin >> t;
			c = getchar();
			in[i++] = t;
		}

		size = i;

		cin >> t;
		post[j++] = t;
		c = getchar();
		while(c != '\n')
		{
			cin >> t;
			c = getchar();
			post[j++] = t;
		}

		if(i == 1)
		{
			cout << in[0] << endl;
			continue;
		}

		cost[post[j-1]] = post[j-1];
		par = post[j-1];
		ind = i-1;
		memset(cost,0,sizeof(sizeof(int)*i));
		mi = 100008;
		sin = 0;
		build_tree(post[j-1],0,j-1);

		sort(lf,lf+sin,comp);

		cout << lf[0].leaf << endl;

		//leaf.clear();

		memset(cost,0,sizeof(sizeof(int)*i));

		for(i = 0; i < size; i++)
		{
			 cost[in[i]] = 0;
		}

		/*for(i = 0; i < size; i++)
		{
			cout << cost[in[i]]  << " ";
		}*/

		//cout << endl;

	}

	return 0;

}