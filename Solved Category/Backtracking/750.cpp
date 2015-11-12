#include<iostream>

using namespace std;
void backtrack(int a[], int k, int input);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
bool is_a_solution(int a[], int k, int n);
void nqueens(int n);
#define NMAX 100
#define MAXCANDIDATES 100

int solution_count;

int a[NMAX];

int output = 1;

int x,y;

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
    
	if( a[y] == x)
	{

		
		
		printf("%2d",output++);
		cout<<"    ";
	   
	   cout  <<" " <<  a[1] << " " << a[2] << " " << a[3]<< " " <<  a[4]<< " " << a[5]<< " " << a[6]<< " " << a[7] << " " << a[8] << endl;
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
    
	int t;

	cin >> t;

    int ch = 0;
	

	while( t--)
	{
		cin >> x >> y;

	
	  if( ch == 0)
	  ch = 1;
	  else
	  cout << endl;
		  cout<<"SOLN       COLUMN"<<endl;
         cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;

		nqueens(8);

	

		output = 1;
	}

	

	



	return 0;
}
