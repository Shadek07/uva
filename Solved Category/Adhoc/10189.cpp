#include<iostream>

using namespace std;

int count(int row,int col);
int r,cl;
char in[105][105],c;

int out[105][105];

void refreash()
{
	int j,k;
	for(j=0;j<105;j++)
	{
		for(k=0;k<105;k++)
		{
			in[j][k]='0';
			out[j][k]=0;
		}
	}
}

int main(void)
{
    int row,col;
    int a,b,d;
    int t = 1;

	int check = 0;
    
    
    
     // output string
    
    
    while(1)
    {
            cin >> row >> col;

            r = row;
            cl = col;
            getchar();
            if(!row && !col)
				break;
            if(check && row && col)
			cout << endl;
            
            for(a = 0 ; a < row; a++)
            {
                  gets(in[a]);
            }
            
            for(a = 0; a < row; a++)
            {
                  for( b = 0; b < col;b++)
                  {
                       if( in[a][b] == '*')
                       out[a][b] = '*';
                       else
                       {
                           d = count(a,b); //function call
                           
                           out[a][b] = d;
                       }
                  }
            }
            
            cout << "Field #" << t++ << ":\n";
            for( a = 0 ; a < row; a++)
            {
                 for( b = 0; b < col; b++)
                 {
					 if( in[a][b] != '*')
                      cout << out[a][b];
					 else
						 cout << in[a][b];
                 }
                 cout << endl;
            }
            
            
            check = 1;
			refreash();
    }
      
    return 0;
}

int count(int row,int col)
{
    int c = 0;
    
    if( row-1 >= 0)
    {
       if( in[row-1][col] == '*')
       c++; 
    }
    if( row+1 <= r-1 )
    {
        if( in[row+1][col] == '*')
        c++;
    }
    if( col-1 >= 0)
    {
        if( in[row][col-1] == '*')
        c++;
        
    }
    if( col+1 <= cl-1 )
    {
        if( in[row][col+1] == '*')
        c++;
    }
    if( row-1 >= 0 && col-1 >= 0)
    {
        if( in[row-1][col-1] == '*')
        c++;
    }
    if( row-1 >= 0 && col + 1 <= cl-1)
    {
        if( in[row-1][col+1] == '*')
        c++;
    }
    if( row+1 <= r && col-1 >= 0)
    {
        if( in[row+1][col-1] == '*')
        c++;
    }
    if( row + 1 >= 0 && col + 1 <= cl-1)
    {
        if( in[row+1][col+1] == '*')
        c++;
    }
    
    return c;
    
    
}
