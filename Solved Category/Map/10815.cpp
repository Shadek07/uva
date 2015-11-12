#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<cctype>

using namespace std;

const int LineMax = 201;

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



int main(void)
{
	  map<LineClass,LineClass> mp;
	  multimap<LineClass,int> mymm;
      multimap<LineClass,int>::iterator it;
	  map<LineClass,LineClass>::iterator it1;
	  pair<multimap<LineClass,int>::iterator,multimap<LineClass,int>::iterator> ret;

	  char in[1000];

	  char c;

	  

	  
	  char *p;
	  int line_no = 1,i,j,k;
//" !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n"
	  while(gets(in))
	  {
		  p = strtok(in," !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n");

		  

		    
			while( p != NULL)
			{
				  for( i = 0; p[i] != '\0'; i++)
				  {
					  p[i] = tolower(p[i]);
				  }
				
				
					it = mymm.find(p);

					
					mymm.insert(pair<LineClass,int>(LineClass(p),line_no));
					mp.insert(pair<LineClass,LineClass>(LineClass(p),LineClass(p)));


				
				    p = strtok(NULL," !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n");
			}


			line_no++;

	  }
	  char in1[1000];

	  char prev[1000];

	  strcpy(prev,"--");

	  for ( it=mymm.begin() ; it != mymm.end(); it++ )
	  {
		    
			it->first.GetLine(in1);
		    
			
			
			if((strcmp(in1,prev)) != 0)
			{
			  cout << in1 << endl;
			  strcpy(prev,in1);
			}
			
			
		
	  }


	return 0;
}