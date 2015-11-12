#include<iostream>
#include<map>
#include<cstring>
#include<string>

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

	  c = getchar();

	  getchar();
	  char *p;
	  int line_no = 1;

	  while(gets(in))
	  {
		  p = strtok(in," ,.,!?&@#\"");
		    
			while( p != NULL)
			{
				
				if(p[0] == c)
				{
					it = mymm.find(p);

					
					mymm.insert(pair<LineClass,int>(LineClass(p),line_no));
					mp.insert(pair<LineClass,LineClass>(LineClass(p),LineClass(p)));


				}
				p = strtok(NULL," ,.,!?&@#\"");
			}


			line_no++;

	  }
	  char in1[1000];

	  for ( it1=mp.begin() ; it1 != mp.end(); it1++ )
	  {
		    //strcpy(in1,(*it)->first);
		    int prev;
			//it->first.GetLine(in1);
			//cout << in1;
			it1->first.GetLine(in1);
		    ret = mymm.equal_range(in1);
			it=ret.first;
			cout << in1;
			cout << " " << (*it).second;
			prev = (*it).second;
			for (; it!=ret.second; ++it)
			{
				if((*it).second != prev)
				{
			       cout << " " << (*it).second;
				   prev = (*it).second;
				}
			}
			cout << endl;
	  }


	return 0;
}
