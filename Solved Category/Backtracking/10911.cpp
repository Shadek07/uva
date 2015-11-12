#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


double square(double x)
{
     return x*x;
}



int n;

char in[20];

struct toa
{       
       int b;
       double dis;
};

vector<toa> v[20];

double all[20][20];

int point[20][2];

int order[20][20];

double mn;
double  temp;

int comp(toa a ,toa b)
{
    if(a.dis < b.dis)
    return 1;
    else
    return 0;
}

double d1(int i,int j)
{
       double c;
       double a,b;
       a = square((point[i][0]-point[j][0])*1.0);
       b = square((point[i][1]-point[j][1])*1.0);
       c = sqrt(a+b);
       return c;
}

void backtrack(int state[17],int cover)
{
     int i,j;
     double a,b;
     int c = 2*n;
     int ch[17];
     int fr;
     if(cover == n)
     {
                   
          if(temp < mn)
          {
               mn = temp;
               
          }
          
          return;  
     }
     
     for(i = 0;i<c;i++)
     {
           if(state[i] == -1)
           {
                fr = i;
                state[i] = 1;
                break;       
           }
     }
                  
                  for(j = 0;j<c;j++)
                  {
                        
                        if(state[j]== -1)
                        {
                             //state[i] = j;
                             //state[j] = i;
                             double c1 = d1(fr,j);
                             if(temp+c1 < mn)
                             {
                                 //cout << i  <<  " "<< j << " " << order[i][j]<< " " << state[order[i][j]]<<endl;
                                 temp += c1;
                                 state[j]=1;
                                 backtrack(state,cover+1);
                                 temp -= c1;
                                 state[j] = -1;                                                        
                             }
                             else
                             continue;
                        }
                  }
                  
       state[fr] = -1;                  
     
}

int main(void)
{
    int i,j,k;
    int c;
    int a,b;
    double f1,f2;
    struct toa t;
    int state[17];
    int ca = 1;
    while(cin >> n && n)
    {
         c = 2*n;
         for(i = 0; i < c;i++)
         {
             cin >> in >> a >> b;
             point[i][0] = a;
             point[i][1] = b;  
         }
         
         for(i = 0; i <c;i++)
         {
             for(j = i+1;j<c;j++)
             {
                  f1 = d1(i,j);
                  all[i][j] = f1;
                  all[j][i] = f1;
                  t.b = j;
                  t.dis = f1;
                  v[i].push_back(t);
                  
                  t.b = i;
                  t.dis = f1;
                  v[j].push_back(t);
             }
                          
             sort(v[i].begin(),v[i].end(),comp);
             k = 0;
             for(j = 0; j <= i-1;j++)
             {                   
                   order[i][j] = v[i][k++].b;
             }
             order[i][i] = 0;
             for(j = i+1; j < c;j++)
             {                  
                   order[i][j] = v[i][k++].b;
             }
             
         }
         
         mn = (1<<30)*1.0;
         //cout << mn << endl;
         memset(state,-1,sizeof(state));
         temp = 0.0;
         backtrack(state,0); 
         cout << "Case " << ca++ << ": "; 
         printf("%.2lf\n",mn);
         //cout << mn << endl;
    }
    return 0;
}
