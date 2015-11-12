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
      multimap<LineClass,int>::iterator it,it2,it3;
	 // map<LineClass,LineClass>::iterator it1;
	  pair<multimap<LineClass,int>::iterator,multimap<LineClass,int>::iterator> ret;

	  char in[1000];

	  char c;

	  string s1,s2,s3;

	  
	  char *p;
	  int line_no = 1,i,j,k;
      char word[1000],first[1000],second[1000];
	  while(gets(in))
	  {		
				
					//it = mymm.find(p);
					
					mymm.insert(pair<LineClass,int>(LineClass(in),line_no));
					//mp.insert(pair<LineClass,LineClass>(LineClass(p),LineClass(p)));

			        
	  }
	  char in1[1000];

	  

	  for ( it=mymm.begin() ; it != mymm.end(); it++ )
	  {
		    int len,i1;
		    
			it->first.GetLine(word);
			//it->first.GetLine(Meaning);
		    
			s1 = word;

			len = strlen(word);

			if(len > 1)
			{
				for( i1 = 1; i1 < len;i1++)
				{
					s2 = s1.substr(0,i1);
					s3 = s1.substr(i1,len-i1);
					strcpy(first,s2.c_str());
					strcpy(second,s3.c_str());
					it2 = mymm.find(first);
					it3 = mymm.find(second);
					if(it2 != mymm.end() && it3 != mymm.end())
					{
						cout << word << endl;
						break;
					}

				}
			}
			
			
			
			
		
	  }


	return 0;
}