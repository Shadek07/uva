#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int d1;

vector<int> v;

struct info
{
	int value[10];
	int index;
}in[50];

int dist[35];
int from[35];
int ind;
void path(int a);

/*bool comp(info a,info b)
{
	int i;

	for( i = 0; i < d; i++)
	{
		if( a.value[i] <= b.value[i])
			return false;
		//else  return (a.value[i] < b.value[i]);
	}
	return true;

}*/
bool comp (int x, int y)
{
    for ( int i = 0; i < d1; i++ ) 
    {
        if ( in [x].value [i] <= in [y].value [i] )
            return false;
    }
    return true;
}

void print_path (int x)
{
    if ( x == from [x] )
        return ;
    print_path (from [x]);
    v.push_back (in [from [x]].index);
}

int main(void)
{
	int total,dim;
	int i,j,k;
	int check;

	while(cin >> total >> dim)
	{
		for( i = 0; i < total; i++)
		{
			for( j = 0; j < dim; j++)
			{
				cin >> in[i].value[j];
			}

			in[i].index = i;
		}

		for( i = 0; i < total; i++)
		{
			sort(in[i].value,in[i].value+dim);
		}

		d1 = dim;
			 

		//sort(in,in+total,comp);
		for ( i = 0; i < total; i++ )
        {
            for (  j = i + 1; j < total; j++ )
            {
                    if ( comp (i, j) )
                        swap (in [i], in [j]);
			}
		}

		//v.push_back(in[0].index);

		k = 0;

		dist[0] = 1;

		memset(from,-1,sizeof(from));

	

		for (  i = 0; i < total; i++ )
		{
			dist [i] = 1;
			from [i] = i;
		} 

		int max,index;

			for(i = 1; i < total; i++)
			{
				check = 1;
				
				max = -1;
				for( j = 0; j < i; j++)
				{
					if( comp(i,j) && dist[j] + 1 > dist[i] )
					{
						dist[i] = dist[j] + 1;
						from[i] = j;
						//index = in[j].index;
					}
				}

				
			
			}

			max = 0;

			for( i = 0; i < total; i++)
			{
				if( dist[i] > max)
				{
					max = dist[i];
					index = i;
				}

			}

			//cout << max << endl;

			ind = index;

			print_path(ind);
			v.push_back(in[index].index);

		cout << v.size() << endl;

		cout << v[0] + 1;

		for( i = 1; i < v.size(); i++)
		{
			cout << " " << v[i] + 1 ;
			
		}

		cout << endl;

		v.clear();
	}
	return 0;
}

