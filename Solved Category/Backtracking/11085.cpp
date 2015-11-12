#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

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
int mn;

bool finished = false; /* found all solutions yet? */

int row_pos[10];

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
			if (finished) return; /* termnate early */
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
			if (abs((k-j)*1.0) == abs((i-a[j])*1.0)) /* diagonal threat */
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
	int cnt,i;
    
	cnt = 0;

	for(i = 1; i < 9;i++)
	{
		if(a[i] != row_pos[i])
			cnt++;
	}
	   
	if(cnt < mn)
		mn = cnt;
	
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
    
	int i;

	

    int ch = 1;
	

	while(cin >> row_pos[1])
	{
	     for(i = 2; i < 9; i++)
		 {
			 cin >> row_pos[i];
		 }

	
	    mn = 9999;

		nqueens(8);

	    cout << "Case " << ch++ << ": " << mn << endl;

		output = 1;
	}

	

	



	return 0;
}
