#include <iostream>
#include <string>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int best;
int result;
char board[4][4];

void print_board() {
	int i,j;
  for (i= 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

bool is_open_position(int a, int b) 
{
int	i,j;
  for (i = a - 1; i >= 0; i--) 
  {
    if (board[i][b] == 'X')
      break;
    if (board[i][b] == '*')
      return false;
  }

  for (i = a + 1; i < n; i++) 
  {
    if (board[i][b] == 'X')
      break;
    if (board[i][b] == '*')
      return false;
  }
  
  for (i = b - 1; i >= 0; i--)
  {
    if (board[a][i] == 'X')
      break;
    if (board[a][i] == '*')
      return false;
  }

  for (i = b + 1; i < n; i++)
  {
    if (board[a][i] == 'X')
      break;
    if (board[a][i] == '*')
      return false;
  }

  return true;
}
void solve(int row, int col) 
{
int	i,j;
  for ( i = 0; i < n; i++) 
  {
    for (j = 0; j < n; j++)
	{
      if (board[i][j] == '.' && is_open_position(i, j)) 
	  {
        board[i][j] = '*';
        //print_board();
        result++;
        if (result > best) 
		{
          best = result;
        }
        solve(i, j + 1);
        result--;
        board[i][j] = '.';
		j++;
      }
    }
  }
}

int main(void) {
  
  char in[6];
 int i,j;

  while (cin >> n) {
	  getchar();
    if (n == 0)
      break;

    for ( i = 0; i < n; i++) {
      gets(in);

      for ( j = 0; j < n; j++)
        board[i][j] = in[j];
    }

    best = 0;
    result = 0;
    solve(0, 0);

    cout << best << endl;
  }

  return 0;
}
