#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000
/*******************************************************************/
int call_div(char *number,long div,char *result)
{
	int len=strlen(number);
	int now;
	long extra;
	char Res[MAX];
	for(now=0,extra=0;now<len;now++)
	{
		extra=extra*10 + (number[now]-'0');
		Res[now]=extra / div +'0';
		extra%=div;
	}

	Res[now]='\0';
	for(now=0;Res[now]=='0';now++);
	strcpy(result, &Res[now]);
	if(strlen(result)==0)
	strcpy(result, "0");
	return extra;
}
/*******************************************************************/
int main()
{
	char fir[MAX],res[MAX],sign[5];
	long sec,remainder,i;
	while(scanf("%s %s %ld",&fir,&sign,&sec)==3)
	{
		//if(sec==0) printf("Divide by 0 error\n");

		
		    remainder=call_div(fir,sec,res);

		    if( strcmp(sign,"%") == 0)
			{			    				
				printf("%ld",remainder);
			}
			else
			{
				int len=strlen(res);
				for(i=0;i<len;i++) printf("%c",res[i]);

			}
			printf("\n");
		
	}

	return 0;
}