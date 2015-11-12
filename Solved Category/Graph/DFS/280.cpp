#include<iostream>
#include<vector>
#include<list>

using namespace std ;

void DFS( int u );

int info[101][101] = {0} ;

bool color[101] = {false};

int node_degree[101] = {0};

vector<int> pr;
vector<int>::const_iterator pi;

int main (void)
{
	int vert,count;	




	int v;

	int neigh;

	int a,i,k,l;

    cin >> vert ;

	while(vert)
	{
         
		cin >> v ; 


        while (v)
		{
		    

			cin >> neigh;

			while (neigh)
			{
				node_degree[v]++ ;

				info[v][ node_degree[v] ] = neigh;

				cin >> neigh;
			}

			cin >> v;
		}

		 cin >> count ;

         vector <int> vec ;

         while ( count-- )
		 {
			 cin >> a ;

			 vec.push_back(a);
		 }

		 vector<int>::const_iterator e;

		 

		 for(  e = vec.begin(); e != vec.end(); e++ )
		 {
                 
                  i =  *e;

				  DFS(i);

				  for( k = 1; k <= vert; k++ )
				  {
					  if( color[k] == false )
					  {
                           
						   pr.push_back(k);

					  }
				  }

				  

                  pi = pr.begin();
				  cout << pr.size()  ;

				  while( pi != pr.end() )
				  {
					  cout << " " << *pi;

					  pi++;
				  }

				  cout << "\n";

				  pr.clear();

				  memset(color,false,sizeof(color));
				  
		 }

         vec.clear();  

         cin >> vert;
		 memset(node_degree,0,sizeof(node_degree));
	}




  return 0;
}


void DFS(int u)
{
	int v ;

	for( v = 1; v <= node_degree[u] ; v++ )
	{
		if( !color[ info[u][v] ] )
		{
			color[ info[u][v] ] = true;

			DFS( info[u][v]) ;
		}
	}



}
