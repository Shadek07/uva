#include <iostream>
#include <map>
#include<string>
#include<cmath>

using namespace std;

const int LineMax = 72;

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

  string s2,s3;
  char in[31];
  int count;

  cin >> t;

  getchar();
  getchar();

  while(t--)
  {
	  count = 0;

	  while(gets(in))
	  {
		  if(strlen(in) == 0)
		      break;
		  else
		  {
			  count++;
			  s2 = in;
			  ret = Dictionary.insert(pair<LineClass,frequen>(LineClass(in),
              frequen(0)));
			  if (ret.second==false)
			  {
				ret.first->second.inc();
			  }

			  

		  }
	  }

	  LineType Meaning;

	  if( ch == 0)
		  ch = 1;
	  else
		  cout << "\n";

	  for ( it=Dictionary.begin() ; it != Dictionary.end(); it++ )
	  {

           int a1 = it->second.get();
		   double d;
		   it->first.GetLine(Meaning);
		   cout << Meaning << " ";
		   d = it->second.get();
		   d *= 100.0;
		   d /= count;
		   printf("%.4f\n",d);
	  }

	  it = Dictionary.begin();

	  Dictionary.erase ( it, Dictionary.end() );





  }
    
  return 0;
}
