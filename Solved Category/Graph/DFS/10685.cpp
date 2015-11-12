#include<iostream>
#include<vector>
#include<cstring>
#include <map>
#include<cmath>

using namespace std;

#define SIZE 30005

vector <int> adj[SIZE];



bool visited[SIZE];
int v;

//char in[25][26];
int cnt = 0;
const int LineMax = 1000;

const int NULLCHAR = '\0';

typedef char LineType[LineMax];



class LineClass
   {
   private:
      LineType Info;
   public:
      LineClass(void);
      LineClass(LineType Str);
      void GetLine(LineType Line) const;
   };

class frequen
{
private:
	int cnt;
public:
	frequen(int a)
	{
		cnt = a;
	}
	void inc()
	{
		cnt++;
	}
	int get()
	{
		return cnt;
	}
};



LineClass::LineClass(void)
   {
        Info[0] = NULLCHAR;
   }



LineClass::LineClass(LineType Str)
   {
		strcpy(Info, Str);
   }



void LineClass::GetLine(LineType Line) const
   {
		strcpy(Line, Info);
		
   }



bool operator<(LineClass LHS, LineClass RHS)
   {

	   LineType Left, Right;

	    LHS.GetLine(Left);
	    RHS.GetLine(Right);

	   if (strcmp(Left, Right) < 0)
		  return true;
	   else
		  return false;
   }

void visit(int u)
{
	int i;
	visited[u] = true;
	for(i=1;i<=adj[u].size();i++)
	if(!visited[adj[u][i-1]])
	{
	   cnt++;
	   visit(adj[u][i-1]);
	}
}

int DFS(int d)
{
	int i,ncomp=0;
	
	int max = 0;
	int k;
		for( k = 1; k <= d; k++)
		{
			
			if(!visited[k])
			{
				cnt = 1;
				ncomp++;
				visit(k);
				if(cnt > max)
					max = cnt;

			}
		}

	return max;
}

int main(void)
{
	
	int d,i,j;

    int image = 1;
	
	int t,m,n;
	int a1,b1;

	map<LineClass,frequen> Dictionary;
    LineType Target;
	map<LineClass,frequen>::iterator it,it1,it2;
	pair<map<LineClass, frequen>::iterator,bool> ret;


	char in[1000],a2[1000],b2[1000];

	while(1)
	{
		cin >> m >> n;

		if(!m && !n)
			break;

		j = 1;
		getchar();
		for( i = 0; i < m; i++)
		{
			gets(in);
			ret = Dictionary.insert(pair<LineClass,frequen>(LineClass(in),
				  frequen(j++)));
		}
		for(i = 0; i < n; i++)
		{
			int ind1,ind2;

			cin >> a2 >> b2;

			it1 = Dictionary.find(a2);
			it2 = Dictionary.find(b2);

			ind1 = it1->second.get();
			ind2 = it2->second.get();

			adj[ind1].push_back(ind2);
			adj[ind2].push_back(ind1);
			
		}


		int a = DFS(m);

		if(n>0)
		getchar();
		getchar();

	    cout << a  << endl;

		memset(visited,false,sizeof(visited));

		for( i = 1; i <= m; i++)
		{
			if(!adj[i].empty())
				adj[i].clear();
		}

		
	}

	


	return 0;
}
