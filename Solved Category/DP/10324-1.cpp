#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int cal[1000004];

int main()
{
    
       char in[1000004];
       int t,i,m,n,a;
       int c = 1,q,len,diff;
       int check = 1;
	   while(gets(in))
	   {

		   cal[0] = 1;
		   len = strlen(in);
		   for(i = 1; i < len; i++)
		   {
			   if(in[i] == in[i-1])
			   {
				   cal[i] = cal[i-1] + 1;
			   }
			   else
			   {
				   cal[i] = 1;
			   }
		   }

		   cin >> q;

		   cout << "Case " << c++ << ":" << endl;

		   for(i = 0; i < q; i++)
		   {
			   cin >> m >> n;
			   if(m > n)
			   {
				   t = m;
				   m = n;
				   n = t;
			   }

			   diff = n - m;

			   if(cal[m] == 1)
			   {
				   if(cal[n] == diff +1)
					   cout << "Yes\n";
				   else
					   cout << "No\n";

			   }
			   else
			   {
				   a = cal[m];
				   if( a + diff == cal[n])
					     cout << "Yes\n";
				   else
					   cout << "No\n";
			   }
		   }

		   getchar();
	   }
      
 
       
      return 0;
}
