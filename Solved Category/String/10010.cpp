#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
    int t,search;

	bool pr = false;
    
    char in[51][52],temp1[52],find[52];
    
    int i,j,k,m,n,len1;

	int one,two;
	int row1,col1;

	int check;
    
    int y;
    
    int ind;
    
    int row,col;
    
    cin >> t;
    
    getchar();
    getchar();
    
    while(t--)
    {
		 
		 
         cin >> m >> n;
         
         getchar();
		 
         
         for(i = 1; i <= m; i++)
         {
               gets(in[i]);
         }
         
         cin >> search;
         
         getchar();
         
         for( i = 0; i < search; i++)
         {
              gets(find);
                           
              len1 = strlen(find);
              
              for( y = 0; y < len1; y++)
              {
                   find[y] = toupper(find[y]);
              }
              
              check = 0;

              for( j = 1; j <= m; j++)
              {
                   for( k = 0; k < n; k++)
                   {
                        //horizontal left to right
                        ind = 0;
                        row = j;
                        col = k;
                        if(k+len1-1 <= n - 1)
                        {
                              while(col <= k + len1 -1)
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 col++;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
                            //cout << j << " " << k+1 << endl ;
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                                                
                        //horizontal right to left
                        
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if(k-len1+1 >= 0)
                        {
                              while(col >= k - len1 + 1)
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 col--;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							
                            //cout << j << " " << k+1 << endl ;
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        
                        
                        
                        //vertical up to down
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if(j+len1-1 <= m)
                        {
                              while(row <= j + len1 - 1)
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 row++;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							check = 1;
                            //cout << j << " " << k+1 << endl;
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        
                        
                        //vertical down to up
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if(j-len1+1 >= 1)
                        {
                              while(row >= j - len1 + 1)
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 row--;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							//check = 1;
                            //cout << j << " " << k+1 << endl;
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        
                        
                        //   \-up
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if((j-len1+1 >= 1) && (k-len1+1 >= 0))
                        {
                              while( (row >= j - len1 + 1) && (col >= k - len1 + 1) )
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 row--;
                                 col--;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							//check = 1;
                            //cout << j << " " << k+1 << endl;
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        //   \-down
                        
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if((j+len1-1 <= m) && (k+len1-1 <= n-1))
                        {
                              while( (row <= j + len1 - 1) && (col <= k + len1 - 1) )
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 row++;
                                 col++;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							//check = 1;
                            //cout << j << " " << k+1 << endl;
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        
                        //   /-up
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if((j-len1+1 >= 0) && (k+len1-1 <= n-1))
                        {
                              while( (row >= j - len1 + 1) && (col <= k + len1 - 1) )
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 row--;
                                 col++;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							//check = 1;
                            //cout << j << " " << k+1 << endl;
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        
                        //   /-down
                        
                        ind = 0;
                        row = j;
                        col = k;
                        if((j+len1-1 <= m) && (k-len1+1 >= 0))
                        {
                              while( (row <= j + len1 - 1) && (col >= k - len1 + 1) )
                              {                                        
                                 temp1[ind++] = toupper(in[row][col]);
                                 row++;
                                 col--;
                              }      
                        }
                        
                        temp1[ind] = '\0';
                        
                        if( strcmp(temp1,find) == 0)
                        {
							if( check == 0)
							{
								one = j;
								two = k+1;
								row1 = j;
								col1 = k;
							}
							else
							{
								if( j < row1)
								{
									row1 = j;
									col1 = k;
								}
								if( j == row1 && k < col1)
								{
									row1 = j;
									col1 = k;
								}
							}

							check = 1;
							//check = 1;
                            //cout << j << " " << k+1 << endl;
                            
                            //j = m+1;
                            
                            //break;
                            
                        }
                        
                        
                   }
              }

			  cout << row1 << " " << col1 + 1 << endl;

			  
         }
         
		 if(t)
		 {
		   cout << endl;
		   getchar();
		 }
    }
    
    return 0;
}
