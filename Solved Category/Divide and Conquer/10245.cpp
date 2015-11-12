#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

#define MAXS 10007
#define INF 10000

#define ABS(x) ((x)<0?(-(x)):(x))
#define SDIS(A,B) ((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))
#define DIS(A,B) (sqrt(SDIS(A,B)))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


using namespace std;

int N;
struct point
{
    double x,y;
};

point in[MAXS];

point s1[MAXS],s2[MAXS];

bool cmpx(point a,point b){return a.x<b.x;}
bool cmpy(point a,point b){return a.y<b.y;}

double back(int lo,int hi)
{
    double d,d1,d2;
    int i,j,mid;
    if(hi-lo+1<=3)
    {
        d=INF*INF;
        for(i=lo;i<=hi;i++)
        {
            for(j=i+1;j<=hi;j++)
            {
                d=MIN(SDIS(in[i],in[j]),d);
            }
        }
        return d;
    }

    mid=(hi+lo)/2;

    d1=back(lo,mid);
    d2=back(mid+1,hi);
    d=MIN(d1,d2);

    int ns1=0,ns2=0;

    for(i=mid;i>=lo;i--)
    {
        if((in[mid].x-in[i].x)*(in[mid].x-in[i].x)>d)break;
        s1[ns1++]=in[i];
    }

    for(i=mid+1;i<=hi;i++)
    {
        if((in[i].x-in[mid].x)*(in[i].x-in[mid].x)>d)break;
        s2[ns2++]=in[i];
    }

    sort(s1,s1+ns1,cmpy);
    sort(s2,s2+ns2,cmpy);

    for(i=0;i<ns1;i++)
    {
        for(j=0;j<ns2;j++)
        {
            if((s2[j].y-s1[i].y)>d)break;
            d=MIN(SDIS(s1[i],s2[j]),d);
        }
    }

    return d;
}

int main()
{
    int i;
    while(scanf("%d",&N)==1)
    {
        if(N==0)break;
        for(i=0;i<N;i++)
        {
            scanf("%lf%lf",&in[i].x,&in[i].y);
        }

        if(N==1)
        {
            printf("INFINITY\n");
            continue;
        }
        sort(in,in+N,cmpx);
        double ans=back(0,N-1);
        ans=sqrt(ans);
        if(ans<INF)printf("%.4lf\n",ans);
        else printf("INFINITY\n");

    }
    return 0;
}
