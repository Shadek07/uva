#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 100005

struct dictionary
{
char foreign[12];
char eng[12];
}dict[size],*ptr;


int sort_f(const dictionary *a,const dictionary *b)
{
	return (strcmp(a->foreign,b->foreign));
}


int main()
{
long int total=0;
char line[1000],temp[200];

while(gets(line))
{
if(line[0]=='\0')
break;

sscanf(line,"%s %s",dict[total].eng,dict[total].foreign);
total++; //note the second code
}
qsort(dict,total,sizeof(dict[0]),(int (*)(const void *,const void *))sort_f);

while(gets(temp))
{

ptr=(dictionary *)bsearch(temp,dict,total,sizeof(dict[0]),(int (*)(const void *,const void *))sort_f);

if(ptr)
printf("%s\n",(*ptr).eng);
else
printf("eh\n");

}

return 0;
}
