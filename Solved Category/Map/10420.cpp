#include <iostream>
#include <map>
#include<string>
#include<cmath>

using namespace std;

const int LineMax = 72;

const int NULLCHAR = '\0';

typedef char LineType[LineMax];


/* To keep the example short, we will set up LineClass right here.
   LineClass objects each contain a short C-style string.  The idea is
   that such an object contains a line of text.  The class basically
   provides object-oriented packaging for a C-style string.
*/
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


/* Given:  Nothing.
   Task:   This is the default constructor.  It creates a LineClass object
           containing the empty string.
   Return: Nothing directly, but the implicit object is created.
*/
LineClass::LineClass(void)
   {
        Info[0] = NULLCHAR;
   }


/* Given:  Nothing.
   Task:   This constructor creates a LineClass object containing the
           string Str.
   Return: Nothing directly, but the implicit object is created.
*/
LineClass::LineClass(LineType Str)
   {
		strcpy(Info, Str);
   }


/* Given:  Nothing.
   Task:   To get the string contained in the implicit LineClass object.
   Return: Line   A copy of the string contained in the implicit object.
*/
void LineClass::GetLine(LineType Line) const
   {
		strcpy(Line, Info);
		
   }


/* Given:  LHS   A LineClass object (the left side of the comparison).
           RHS   A LineClass object (the right side of the comparison).
   Task:   To compare the strings containe in LHS and RHS.
   Return: In the function name, it returns true if the LHS string is less
           than the RHS string, false otherwise.
*/
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

  string s2,s3,one,two;
  char in[31];
  int count;
  size_t found;


  cin >> t;

  getchar();
  

  while(t--)
  {
		  count = 0;

		  gets(in);

		  one = in;
		  
		  found=one.find_first_of(" ");  

		  two = one.substr (0,found);

		  strcpy(in,two.c_str());
			 
		  
			  count++;
			  s2 = in;
			  ret = Dictionary.insert(pair<LineClass,frequen>(LineClass(in),
              frequen(0)));
			  if (ret.second==false)
			  {
				ret.first->second.inc();
			  }

			  

  }	  
	  

	  LineType Meaning;

	  //if( ch == 0)
		 // ch = 1;
	  //else
		  //cout << "\n";

	  for ( it=Dictionary.begin() ; it != Dictionary.end(); it++ )
	  {

           int a1 = it->second.get();
		   double d;
		   it->first.GetLine(Meaning);
		   cout << Meaning << " ";
		   d = it->second.get();
		   //d *= 100.0;
		   //d /= count;
		   printf("%.0f\n",d);
	  }

	  it = Dictionary.begin();

	  Dictionary.erase ( it, Dictionary.end() );  

  return 0;
}