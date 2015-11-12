#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{
    int t,i;
    char in[11];
    cin >> t;
    getchar();
    
    while(t--)
    {
              
            gets(in);
             
            int l1 = strlen(in);
             
        	vector<char> l;
        	
        	for(  i = 0; i < l1; i++)
        	{
        	   l.push_back(in[i]);
            }
            
            sort(l.begin(),l.end());
   	
        	do 
        	{
        		vector<char>::iterator iter;
                 	
        		for (iter = l.begin(); iter != l.end(); iter++)
        		{			
        				cout << *iter;
        		}
        		cout << endl;
                		
        	}while(next_permutation(l.begin(), l.end()));
        	
        	cout << endl;
        	
        	l.clear();
     }
     
	return 0;
	


	
}

