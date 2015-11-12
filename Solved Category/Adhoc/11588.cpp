#include<iostream>

using namespace std;

int main(void)
{
    
    int t;
    
    int R, C,M,N;
    int c = 1;
    
    int i,j,k;
    int sum = 0;
    
    char inf[20][21];
    
    int count[26] = {0};
    int max;
    int c1 = 0;
    
    cin >> t;
    
    while(t--)
    {
        
        cin >> R >> C >> M >> N;
        
        getchar();      
              
        for( i = 0 ; i < R; i++)
        {
             gets(inf[i]);
             
        }

		memset(count,0,sizeof(count));

		sum = 0;

		c1 = 0;
        
        for( i = 0 ; i< R;i++)
        {
             for( j = 0; j < C; j++)
             {
                 count[inf[i][j] - 'A']++; 
             }
        }
        
        max = count[0];
        
        for( i = 1 ; i <26;i++ )
        {
             if( count[i] > max)
             max = count[i];
        }
        
        for( i = 0 ; i < 26;i++)
        {
            if( count[i] == max )
            
            sum += count[i]*M;
            else
            c1 += count[i];
        }
        
        sum += c1*N;
        
        cout << "Case "<< c++ <<  ": " << sum << endl; 
        
          
          
       
               
    }
       
    
    return 0;
}
