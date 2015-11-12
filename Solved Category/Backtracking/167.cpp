#include<iostream>
#include<vector>



using namespace std;

vector<int> v;
vector<int>:: iterator it;

void backtrack(int a[], int k, int input);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
bool is_a_solution(int a[], int k, int n);
void nqueens(int n);
#define NMAX 100
#define MAXCANDIDATES 100

int solution_count;

int a[NMAX];

int input[10][10];

int output = 1;

int x,y;
int max1;

bool finished = false; /* found all solutions yet? */
void backtrack(int a[], int k, int input)
 {
	int c[MAXCANDIDATES]; /* candidates for next position */
	int ncandidates; /* next position candidate count */
	int i; /* counter */
	if (is_a_solution(a,k,input))
	process_solution(a,k);
	else 
	{
		k = k+1;
		construct_candidates(a,k,input,c,&ncandidates);
		for (i=0; i<ncandidates; i++) 
		{
			a[k] = c[i];
			backtrack(a,k,input);
			if (finished) return; /* terminate early */
		}
	}
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int i,j; /* counters */
	bool legal_move; /* might the move be legal? */
	*ncandidates = 0;
	for (i=1; i<=n; i++)
	{
		legal_move = true;
		for (j=1; j<k; j++) 
		{
			if (abs(k-j) == abs(i-a[j])) /* diagonal threat */
			legal_move = false;
			if (i == a[j]) /* column threat */
			legal_move = false;
		}
		if (legal_move == true) 
		{
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}

void process_solution(int a[], int k)
{
//	int i; /* counter */
	solution_count ++;
	int value,i;
    
	

	   //cout << output++;
	   value = 0;
	   v.clear();
	   for( i = 1; i <= 8; i++)
	   {
	       value += input[a[i]-1][i-1];
		   v.push_back(input[a[i]-1][i-1]);
	   }

	   if( value > max1)
	   {
		   max1 = value;
		  
		   //cout << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << " " << a[6] <<" " << a[7] << " " << a[8] << endl;
		   /*for( it = v.begin(); it != v.end(); it++)
		   {
			   cout << *it << " ";
		   }
		   cout << endl;*/
	   }

	
}

bool is_a_solution(int a[], int k, int n)
{
	return (k == n);
}

void nqueens(int n)
{
	//int a[NMAX]; /* solution vector */
	solution_count = 0;
	backtrack(a,0,n);
	//printf("n=%d solution_count=%d\n",n,solution_count);
}

int main(void)
{
    
	int t,i,j;

	cin >> t;


	max1 = 0;

	while( t--)
	{
		for( i = 0; i < 8; i++)
		{
			for( j = 0; j < 8; j++)
			{
				cin >> input[i][j];
			}
		}

		
        max1 = 0;
		nqueens(8);

		//cout << max1 << endl;
		printf("%5d\n",max1);

		output = 1;
	}

	

	



	return 0;
}