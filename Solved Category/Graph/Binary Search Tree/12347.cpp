#pragma comment(linker, "/STACK:16777216")
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int n;

int in[10005];

void recur(int root,int start,int last)
{
	int index;
	int k;
	if(start + 1 == last)
	{
		if(in[start] < root && root < in[last])
			cout << in[start] << endl << in[last] << endl;
		else if(in[last] <root && root < in[start])
			cout << in[last] << endl << in[start] << endl; 
		else if(root < in[start] && in[start] < in[last])
			cout << in[last] << endl << in[start] << endl;
		else if(root > in[start] && in[start] > in[last])
			cout << in[last] << endl << in[start] << endl;
		else if(root < in[start] && in[start] > in[last])
			cout << in[last] << endl << in[start] << endl;
		else if(root > in[start] && in[start] < in[last])
			cout << in[last] << endl << in[start] << endl;
		cout << root << endl;
		return;
	}

	index = last+1;

	for(k = start; k <= last;k++)
	{
		if(in[k] > root)
		{
			index = k;
			break;
		}
	}

	if(index == start)  //only right subtree
	{
		
		recur(in[start],start+1,last);
		//else
			//cout << in[start] << endl;
		cout << root << endl;
	}
	else if(index == last+1) //only left subtree
	{
		//if(start+1 < last)
		recur(in[start],start+1,last);
		//else if(start+1
			//cout << in[start] << endl;
		cout << root << endl;
	}
	else
	{
		if(start+1<index-1) ///left subtree
			recur(in[start],start+1,index-1);
		else if(start == index-1)
			cout << in[start] << endl;
		else if(start+1 == index-1)
		{
			cout << in[index-1] << endl << in[start] << endl;
		}
		
		if(index+1<last)  //right subtree
			recur(in[index],index+1,last);
		else if(index == last)
			cout << in[index] << endl;
		else if(index+1 == last)
		{
			cout << in[last] << endl << in[index] << endl;
		}
		cout << root << endl;
	}
	

}

int main(void)
{
	int i,j;
	j = 0;
	while(scanf("%d",&i) == 1)
	{
		in[j++] = i;
	}

	recur(in[0],1,j-1);

	return 0;
}