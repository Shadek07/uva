#include <stdio.h>
 
int main() 
{ 
	int p[607],i=3,j=1,k,ans[100000]={-1},n,m,x; 
	p[0]=2; 
	while(i<4482) 
	{ 
		for(k=0;p[k]*p[k]<i;k++) 
		if(i%p[k]==0) break; 
		if(p[k]*p[k]>i) 
		p[j++]=i; 
		i+=2; 
	} 

	j=2; 
	ans[0]=3; 
	ans[1]=5; 

	while((scanf("%d",&n)) == 1) 
	{ 
		if(n<j); 
		else 
		{ 
			i=j; 
			m=ans[j-1]+6; 
			x=m+2; 
			while(j<n) 
			{ 
				for(k=0;p[k]*p[k]<x;k++) 
				if(m%p[k]==0||x%p[k]==0) 
					break; 
				if(p[k]*p[k]>x) 
					ans[j++]=m; 
					m+=6; 
					x+=6; 
			} 
		} 

		printf("(%d, %d)\n",ans[n-1],ans[n-1]+2); 
	}
	
	return 0; 
}