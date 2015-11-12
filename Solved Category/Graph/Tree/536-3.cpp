#include<iostream>
#include<cstring>

using namespace std;

char pre[30],in[30];
int size;
char root;
int ind;

void post(char r,int low,int high)
{
	int root_index,i,j,k,mid;

	if(low == high)
	{
		cout << r;
		return;
	}

	for( i = 0; i < size; i++)
	{
		if(in[i] == r)
		{
			root_index = i;
			mid = i;
			//ind++;
			break;
		}
	}

	if(low < mid)
	{
		ind++;
		post(pre[ind],low,mid-1);
	}
	if(high > mid)
	{
		ind++;
		post(pre[ind],mid+1,high);
	}

	cout << r;

}

int main(void)
{
	int len,i,j,k;

	while(cin >> pre >> in)
	{
		ind = 0;
		len = strlen(pre);
		size = len;
		root = pre[ind];
		post(root,0,len-1);
		cout << endl;

	}

}