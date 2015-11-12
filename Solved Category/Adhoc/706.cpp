#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

void horizontal(int s);
void vertical();
void horizontal_space(int s);

int main(void)
{
    int s,num,y;
    
    char in[15];
    
    int i,k,d,len;
    
    
    
    
    while(1)
    {
            cin >> s ;
            
            cin >> in;
            
    
            len = strlen(in);
            
            
            if((s == 0 )&& (len == 1 )&& (in[0] == '0')) break;
            
            i = 0;
           
           
            
            //first part
            
            for( i = 0; i < len; i++)
            {
                if( in[i] == '0' || in[i] == '3' || in[i] == '5' || in[i] == '6' || in[i] == '7' || in[i] == '8' || in[i] == '9' || in[i] == '2')
                {
                    cout << " ";
                    horizontal(s);
                    cout << " ";
                }
                if( in[i] == '1' )
                {
                    
                    for(k = 1; k <= s + 2; k++)
                    cout << " "; 
                                   
                }
                if( in[i] == '4')
                {
                    cout << " ";
                    
                    horizontal_space(s);
                    
                    cout << " ";
                }
                
                if( i < len -1)
                cout << ' ';
			
            }
            
            cout << endl;
            
            //second part
            
            
            for( k = 0; k < s; k++)
            {                              
                for( i = 0; i < len; i++)
                {
                     if( in[i] == '0' || in[i] == '4' || in[i] == '8' || in[i] == '9')
                     {
                         cout << '|';
                         horizontal_space(s);
                         cout << '|';
                                                 
                     }
                     if( in[i] == '1')
                     {
                         for(y = 1; y <= s+1;y++)
                         cout << " ";
                         cout << '|';
                         
                                                                         
                     }
                     if( in[i] == '2' || in[i] == '7' || in[i] == '3')
                     {
                         cout << " ";
                         horizontal_space(s);
                         cout << '|';
                                                
                     }
                     if( in[i] == '5' || in[i] == '6')
                     {
                         cout << '|';
                         
                         horizontal_space(s);
                         
                         cout << " ";
                         
                                                                         
                     }

					 if( i < len - 1)
                       cout << ' ';
                     
                     
                     
                }
                
                
				cout << endl;
				
            }
            
            //third part
            
            for( i = 0; i < len; i++)
            {
                if( in[i] == '0' || in[i] == '7' || in[i] == '1')
                {
                    cout << " ";
                    horizontal_space(s);
                    cout << " ";
                }
                if( in[i] == '2' || in[i] == '3' || in[i] == '4' ||  in[i] == '5' || in[i] == '6' || in[i] == '8' || in[i] == '9')
                {
                    cout << " ";
                    horizontal(s);
                    cout << " ";
                }
                
                if( i < len -1)
                cout << ' ';  
            }
            
            cout << endl;
            
            
            
            //fourth part
             for( k = 0; k < s; k++)
            {                              
                for( i = 0; i < len; i++)
                {
                     if( in[i] == '3' || in[i] == '4' || in[i] == '5' || in[i] == '7' || in[i] == '9')
                     {
                         cout << " ";
                         horizontal_space(s);
                         cout << '|';
                          
                                               
                     }
                     if( in[i] == '1')
                     {
                         for(y = 1; y <= s+1;y++)
                         cout << " ";
                         cout << '|';
                                                                       
                     }
                     if( in[i] == '2')
                     {
                         cout << '|';
                         horizontal_space(s);
                         cout << " ";
                                                                      
                     }
                     
                     if( in[i] == '6' || in[i] == '8' || in[i] == '0')
                     {
                         cout << '|';
                         horizontal_space(s);
                         cout << '|';
                                                
                     }
                     
                     
					 if( i < len -1)
                      cout << ' ';
                     
                }

				cout << endl;
                
                    
            }
            
            
            
            //fifth part
             for( i = 0; i < len; i++)
             {
                if( in[i] == '0' || in[i] == '3' || in[i] == '5' || in[i] == '6'  || in[i] == '8' || in[i] == '9' || in[i] == '2' )
                {
                    cout << " ";
                    horizontal(s);
                    cout << " ";
                }
                if( in[i] == '1')
                {
                    
                    for(k = 1; k <= s + 2; k++)
                    cout << " ";
                                     
                }
                if( in[i] == '4' || in[i] == '7' )
                {
                    cout << " ";
                    horizontal_space(s);
                    cout << " ";
                }                              
                if( i < len -1)
                cout << ' '; 
            }
            
            cout << endl;
            
            
            cout << endl;
            
    }
         
    return 0;
}

void horizontal(int s)
{
     int i;
     
     for(i = 0; i < s; i++)
     cout << '-';
     
     
}
void horizontal_space(int s)
{
     int i;
     
     for(i = 0; i < s; i++)
     cout << ' ';
     
}






