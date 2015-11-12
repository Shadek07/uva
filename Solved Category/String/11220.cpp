#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
        int T;
        int j,i;

		char in[1000];
   
		string s;
		
		cin >> T;
		getchar();
		getchar();
   
   for( i = 1; i <= T; i++)
   {   
      cout << "Case #" << i << ":" << endl;
      while(1)
      {
         
		  gets(in);
		  s = in;
         if(s.length() == 0)   
         {
			 if(i < T)
            cout << endl;
            break;
         }

		 else
		 {
			 istringstream sin(s);         
			 string w;
			 for( j = 0; sin >> w;)
				if(j < w.size())
				   cout << w[j++];
			 cout << endl;
		 }
      }
         
   }
   return 0;
}