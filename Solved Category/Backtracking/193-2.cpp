#include <iostream>
#include <cstring>

using namespace std;

const int MAXNODE = 101;

bool edge[MAXNODE][MAXNODE];
int nNode,nEdge,n1,n2;

struct Color
{
	int nBlack,nWhite;
	int node[MAXNODE];// 0-not visited 1-white 2-black
}best;


void backtrace( int now,Color *color )
{
	if ( (color->nBlack + color->nWhite) >= nNode )
	{
		if ( color->nBlack > best.nBlack )
		best = *color;
		return ;
	}

	int i,j;

	for ( i=now;i<=nNode;i++ )
	{
		if ( color->node[i] == 0 )
		{
			Color c = *color;
			c.nBlack++;
			c.node[i] = 2;
			for ( j=1;j<=nNode;j++ )
			if ( edge[i][j] )
			{
				if ( c.node[j] == 2 )
				break;
				else if ( c.node[j] == 0 )
				{
				c.nWhite++;
				c.node[j] = 1;
				}
			}

			if ( j > nNode && (nNode - c.nWhite) > best.nBlack )
			backtrace( now+1,&c );
		}
	}
}


int main()
{

		int nGraph;
		int i;
		cin>>nGraph;

		while ( nGraph-- )
		{
			cin>>nNode>>nEdge;
			memset( edge,0,sizeof(edge) );
			memset( &best,0,sizeof(best) );
			Color c = best;
			for ( i=0;i<nEdge;i++ )
			{
				cin>>n1>>n2;
				edge[n1][n2] = true;
				edge[n2][n1] = true;
			}

			backtrace( 1,&c );

			cout<<best.nBlack<<endl;
			int cnt = 0;
			for (  i=1;i<=nNode;i++ )
			if ( best.node[i] == 2 )
			{
				cnt++;
				cout<<i;
				if ( cnt == best.nBlack ) cout<<endl;
				else cout<<" ";
			}
		}

		return 0;
}

