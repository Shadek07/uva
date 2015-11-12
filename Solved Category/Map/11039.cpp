#include <iostream>
#include <map>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
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
	  int val;
   public:
      LineClass(void);
	  LineClass(int);
      LineClass(LineType Str);
      void GetLine(LineType Line) const;
	  int val_ret();
	  void ret(int &a) const;
   };

class frequen
{
private:
	int cnt;
public:
	frequen(int a)
	{
		cnt = a;
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
LineClass::LineClass(int a)
   {
        val = a;
   }
int LineClass::val_ret()
{
	return val;
}

void LineClass:: ret(int &a) const
{
	a = val;
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

	   

	    int a = LHS.val_ret();
	    int b = RHS.val_ret();

	   if (a<b)
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



   int t,n,i,a,value;

  string s2,s3,one,two;
  char in[31];
  int co;
  size_t found;


  cin >> t;

  getchar();
  

  while(t--)
  {
			 co = 0;

			 cin >> n;
			 i = 0;

			 while(i < n)
			 {
                  cin >> a;
				  a>0?value = 1:value = 0;  //0 for negative and 1 for positive size
				  int bs = abs(a*1.0);
				  ret = Dictionary.insert(pair<LineClass,frequen>(LineClass(bs),
				  frequen(value)));

				  i++;
			 }

				  
		  LineType Meaning;

		 
		  it=Dictionary.begin();
		  int a2 = it->second.get();
		  int ch;
		  it->first.ret(ch);
		  co = 1;
		  

		  for (  ; it != Dictionary.end(); it++ )
		  {

			   int a1 = it->second.get();
			   it->first.ret(ch);
			   if(a1 == a2)
				   continue;
			   else
			   {
				   co++;
				   a2 = a1;
			   }
		  }

		  cout << co << endl;

		  it = Dictionary.begin();

		  Dictionary.erase ( it, Dictionary.end() );

			  

  }	  
	  
  
 

  return 0;
}