#include <iostream>
#include <map>
#include<string>
#include<cmath>

using namespace std;

const int LineMax = 15;

const int NULLCHAR = '\0';

typedef char LineType[LineMax];



class LineClass
   {
   private:
      LineType Info;
   public:
      LineClass(void);
      LineClass(LineType Str);
      void GetLine(LineType Line) const;
   };

class frequen
{
private:
	int cnt;
public:
	frequen(int a)
	{
		cnt = 1;
	}
	void inc()
	{
		cnt++;
	}
	int get()
	{
		return cnt;
	}
};



LineClass::LineClass(void)
   {
        Info[0] = NULLCHAR;
   }



LineClass::LineClass(LineType Str)
   {
		strcpy(Info, Str);
   }



void LineClass::GetLine(LineType Line) const
   {
		strcpy(Line, Info);
		
   }



bool operator<(LineClass LHS, LineClass RHS)
   {

	   LineType Left, Right;

	    LHS.GetLine(Left);
	    RHS.GetLine(Right);

	   if (strcmp(Left, Right) < 0)
		  return true;
	   else
		  return false;
   }


// Function prototypes:
void LoadData(map<LineClass,frequen> & Dictionary);
void Lookup(LineType Target, map<LineClass, frequen> & Dictionary);


int main ()
{
	map<LineClass, frequen> Dictionary;
    LineType Target;
	map<LineClass,frequen>::iterator it;
	pair<map<LineClass, frequen>::iterator,bool> ret;

	int ch = 0;

   int t;
   int i,j,k;

  string s2,s3;
 // char in[31];
  int count,m;

  char in[1000000];

  char sub[11];
  char result[11];

  while(cin >> t)
  {
	  count = 0;

	  cin >> in;

	  int len = strlen(in);

	  m = len - t + 1;

	  s2 = in;

	  i = 0;
	  LineType res;
	  int max;
	  max = 0;

	  while(m--)
	  {
		  
		      s3 = s2.substr(i,t);
			  count++;
			  //s2 = in;
			  strcpy(sub,s3.c_str());
			  //cout << sub << endl;
			  ret = Dictionary.insert(pair<LineClass,frequen>(LineClass(sub),
              frequen(0)));
			  if (ret.second==false)
			  {
				ret.first->second.inc();
				
				int a1 = ret.first->second.get();

				if( a1 > max)
				{
			        max = a1;
			        ret.first->first.GetLine(res);
				}
			  }

			  i++;
	  }

	  LineType Meaning;
	  

	  


	 /* for ( it=Dictionary.begin() ; it != Dictionary.end(); it++ )
	  {

           int a1 = it->second.get();
		   if( a1 > max)
		   {
			   max = a1;
			   it->first.GetLine(res);
		   }
		   
	  }*/

	  cout << res << endl;

	  it = Dictionary.begin();

	  Dictionary.erase ( it, Dictionary.end() );





  }
  

 

  

  return 0;
}