#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int m,n;

char in[1001][1001];
char sm[1001][1001];
int cnt[4];
char temp[1001];
char t2[1001][1001];
char t3[1001][1001];
char t4[1001][1001];

bool cal(int i,int j,char check[1001][1001])
{
     bool ch = 1;
     int a,b,a1,b1;
     for(a = i,a1 = 0; a < i+n;a++,a1++)
     {
           for(b = j,b1 = 0; b < j+n;b++,b1++)
           {
                 if(in[a][b] != check[a1][b1])
                 {
                             ch = 0;
                             return ch;
                 }
           }
     }
     
     return ch;
     
}
int main(void)
{
    int i,j,k;
    bool ch;
    while(1)
    {
            cin >> m >> n;
            getchar();
            if(!m && !n)
            break;
            for(i = 0; i < m;i++)
            gets(in[i]);
            for(i = 0; i <n;i++)
            gets(sm[i]);
            memset(cnt,0,sizeof(cnt));
            for(i = 0; i < n;i++)
            {
                  strcpy(temp,sm[i]);
                  
                  for(j = 0; j < n;j++)
                  {
                        t2[j][n-1-i] = temp[j];
                        t3[n-1-i][n-1-j] = temp[j];
                        t4[n-1-j][i] = temp[j];
                  }
            }
            
            for(i = 0; i<= m-n;i++)
            {
                  for(j = 0;j <= m-n;j++)
                  {
                       ch = cal(i,j,sm);
                       if(ch)
                       cnt[0]++;
                       ch = cal(i,j,t2);
                       if(ch)
                       cnt[1]++;
                       ch = cal(i,j,t3);
                       if(ch)
                       cnt[2]++;
                       ch = cal(i,j,t4);
                       if(ch)
                       cnt[3]++;
                        
                  }
            }
            
            cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3]<< endl;
              
    }
}
