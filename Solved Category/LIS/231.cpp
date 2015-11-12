#include<iostream>
#include <vector>
using namespace std;
 
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
template<typename T> vector<int> find_lis(vector<T> &a)
{
	vector<int> b, p(a.size());
	int u, v;
 
	if (a.size() < 1) return b;
 
	b.push_back(0);
 
	for (int i = 1; i < (int)a.size(); i++) {
		if (a[b.back()] >= a[i]) {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] >= a[i])
				u=c+1; 
			else v=c;
		}
 
		if (a[i] >= a[b[u]]) {
			if (u > 0) 
				p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}
 
/* Example of usage: */

int main()
{
	int a[100000];
	int n,t = 1;
	unsigned long i;
	int size;
	int check = 0;
	
	i = 0;

    while(1)
	{
		i = 0;
		cin >> n;
		if( n == -1)
			break;
		else
		{
			a[i] = n;
		    i++;
		}
		
		while(1)
		{
		   cin >> n;
		   if( n == -1)
			   break;
		   a[i] = n;
		   i++;
		}

		//cout << "i: "<< i << endl;
		size = sizeof(a[0])*i;
		//vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
		vector<int> seq(a, a+size/sizeof(a[0]));
		vector<int> lis = find_lis(seq);
 
		int a1 = lis.size();
		
		if(check == 1)
			cout << "\n";
		else
			check = 1;
		cout << "Test #" << t++ << ":\n";
		cout << "  " << "maximum possible interceptions: "<< a1 << endl;

		seq.clear();
		lis.clear();
	}
 
	return 0;
}