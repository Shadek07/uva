#include<iostream>
#include <stack>
#include<vector>
#include<algorithm>

using namespace std;

int pos[25];

vector<int> v;

int main(void)
{

	stack<int> s[25];
	stack<int> tmp;
	int n,i,j,k;
	int pos1,pos2;

	char com1[10],com2[10];
	int fir,sec;
	cin >> n;
	for( i = 0; i < n; i++)
	{
		s[i].push(i);
		pos[i] = i;
	}
	while(1)
	{
		cin >> com1;
		if(strcmp(com1,"quit") == 0)
			break;
		cin >> fir;
		cin >> com2;
		cin >> sec;
		//cout << com1 << " " << fir << " " << com2 << " " << sec << endl;
		if(fir<0 || fir>=n || sec<0 || sec>=n) continue; 
		pos1 = pos[fir];
		pos2 = pos[sec];

		if(pos1 == pos2)
			continue;
		
		if( strcmp(com1,"move")== 0 && strcmp(com2,"onto") == 0)
		{
              pos1 = pos[fir];
			  pos2 = pos[sec];

					  
				  while(s[pos1].top() != fir)
				  {
					  j = s[pos1].top();
					  while(!s[j].empty())
						  s[j].pop();
					  s[j].push(j);
					  pos[j] = j;
					  s[pos1].pop();
				  }
				  while(s[pos2].top() != sec)
				  {
					  j = s[pos2].top();
					  while(!s[j].empty())
						  s[j].pop();
					  s[j].push(j);
					  pos[j] = j;
					  s[pos2].pop();
				  }

				  s[pos1].pop();
				  s[pos2].push(fir);
				  pos[fir] = pos[sec];
				  //pos[pos1] = pos2;
			  
		}
		if( strcmp(com1,"move")== 0 && strcmp(com2,"over") == 0)
		{
			  pos1 = pos[fir];
			  pos2 = pos[sec];
			  
			  while(s[pos1].top() != fir)
			  {
				  j = s[pos1].top();
				  while(!s[j].empty())
						  s[j].pop();
				  s[j].push(j);
				  pos[j] = j;
				  s[pos1].pop();
			  }

			  s[pos1].pop();
			  s[pos2].push(fir);
			  pos[fir] = pos[sec];
			  //pos[pos1] = pos2;

		}
		if( strcmp(com1,"pile")== 0 && strcmp(com2,"onto") == 0)
		{
			  pos1 = pos[fir];
			  pos2 = pos[sec];
			  while(s[pos2].top() != sec)
			  {
				  j = s[pos2].top();
				  while(!s[j].empty())
						  s[j].pop();
				  s[j].push(j);
				  pos[j] = j;
				  s[pos2].pop();
			  }

			  while(!tmp.empty())
				  tmp.pop();

			  while(s[pos1].top() != fir)
			  {
				  j = s[pos1].top();
				  tmp.push(j);
				  pos[j] = pos2;
				  s[pos1].pop();
			  }

			  tmp.push(fir);
			  pos[fir] = pos[sec];
			  s[pos1].pop();

			  while(!tmp.empty())
			  {
				  j = tmp.top();
				  s[pos2].push(j);
				  tmp.pop();
			  }

			  //pos[fir] = pos[sec];

		}
		if( strcmp(com1,"pile")== 0 && strcmp(com2,"over") == 0)
		{
			  pos1 = pos[fir];
			  pos2 = pos[sec];
			  

			  while(s[pos1].top() != fir)
			  {
				  j = s[pos1].top();
				  tmp.push(j);
				  pos[j] = pos[sec];
				  s[pos1].pop();
			  }

			  s[pos1].pop();

			  tmp.push(fir);
			  pos[fir] = pos[sec];

			  while(!tmp.empty())
			  {
				  j = tmp.top();
				  s[pos2].push(j);
				  tmp.pop();
			  }

			  //pos[fir] = pos[sec];

		}
	}

	for( i = 0; i < n; i++)
	{
		cout << i << ":";
		while(!s[i].empty())
		{
			v.push_back(s[i].top());
			
			s[i].pop();
		}


		reverse(v.begin(),v.end());
		int l = v.size();
		for( j = 0; j < l; j++)
		{
			cout << " " << v[j];
		}
		cout << endl;
		v.clear();
	}

	return 0;
}