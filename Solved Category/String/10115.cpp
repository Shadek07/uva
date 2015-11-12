#include<iostream>
#include<cctype>
#include<string>

using namespace std;

int main(void)
{
    
    int rule;
    string word[10];
    string rep[10];
   
    string orig,temp;
    int f;
    char c;
    int i,m,n,b;
    
    while(1)
    {
            cin >> rule;
            getchar();
            if( rule == 0) break;
            
            for( i = 0; i < rule; i++)
            {
                 getline(cin,word[i]);
                 getline(cin,rep[i]);
            }
            
            getline(cin,orig);
            
            for( i = 0 ; i < rule; i++)
            {
                 f = orig.find(word[i]);
                 while( f != -1)
                 {
                        orig.replace(f,word[i].size(),rep[i]);//replace with rep[i]
                        f = orig.find(word[i]);
                 }
            }
            
            cout << orig << endl;
            
            
            
    }
     
    
    return 0;
}
