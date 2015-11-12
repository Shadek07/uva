#include<iostream>
#include<algorithm>
#include<vector>
#define max 50

using namespace std ; 

struct path
{
	int i,j,co ;
};

bool check(path const *a , path const *b)
{
	return ( a -> co < b -> co );
}

int V,E ; 

vector <path*> edges ;

vector <path*> mst ;

vector <path*> answer;

vector<int>weight;

bool present[1000][1000];
bool taken[1000][1000];

int circles[max] ; 

int main()
{
	int out[10][2] ; 

	int num,d,w,i , c = 1;

	path *e ; 

	d = 1 ;

	while(true)
	{

		edges.clear() ; 

		mst.clear() ;

		answer.clear();

		memset(present,false,sizeof(present));
		memset(taken,false,sizeof(taken));

		cin >> V >> E ; 

		

		if( !V && !E ) break ;

		for( i = 0 ; i < E ; i++ )
		{
			e = new path ; 

			cin >> e -> i >> e -> j >> e -> co ;

			present[e->i][e->j] = true;


			edges.push_back(e) ; 

		}

		sort( edges.begin() , edges.end() , check ) ;

		for( i = 0 ; i < V ; i++ )

			circles[i] = i ; 

		while( mst.size() < (V-1) && edges.size() )
		{
			if( circles[edges[0] -> i ] != circles[edges[0] -> j ] )
			{

				num = circles[edges[0] -> j ] ;

				for( i = 0 ; i < V ; i++ )
				{
					if( circles[i] == num )

						circles[i] = circles[edges[0] -> i] ;
				}

				mst.push_back(edges[0]) ;
			}
			else
			{
				answer.push_back(edges[0]);

			}

            edges.erase( edges.begin() , edges.begin() + 1) ;
		}

		w = 0 ;

		

		while(edges.size())
		{
             answer.push_back(edges[0]);
			 edges.erase( edges.begin() , edges.begin() + 1) ;
		}

		int a = answer.size();

		if( a == 0)
		{

			cout << "forest\n";
			continue;
		}

		for( i = 0 ; i < answer.size() ; i++ )
		{
			if( i < answer.size() - 1)
				cout << answer[i]->co << " ";
			else
				cout << answer[i]->co << "\n";
		}


	

	
	}


		return 0;
}






