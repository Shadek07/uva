#include<stdio.h>
#include<string.h>
#define MAXD 35
#define INF 1000000000
char a[MAXD], b[MAXD], p[MAXD][MAXD];
long  int f[MAXD][MAXD];
void solve()
{
    int i, j, k, lena, lenb, len;
    gets(a + 1);
    gets(b + 1);
    lena = strlen(a + 1);
    lenb = strlen(b + 1);
    memset(f, 0, sizeof(f));
    for(i = 0; i <= lena; i ++)
        for(j = 0; j <= lenb; j ++)
            p[i][j] = INF;
    for(i = 0; i <= lenb; i ++)
    {
        f[0][i] = 1;
        p[0][i] = 0;
    }
    for(i = 0; i <= lena; i ++)
    {
        f[i][0] = 1;
        p[i][0] = 0;
    }
    for(i = 1; i <= lena; i ++)
        for(j = 1; j <= lenb; j ++)
        {
            if(a[i] == b[j])
            {
                p[i][j] = p[i - 1][j - 1] + 1;
                f[i][j] += f[i - 1][j - 1];
            }
            else
            {
                p[i][j] = p[i - 1][j] > p[i][j - 1] ? p[i - 1][j] : p[i][j - 1];
                if(p[i - 1][j] == p[i][j])
                    f[i][j] += f[i - 1][j];
                if(p[i][j - 1] == p[i][j])
                    f[i][j] += f[i][j - 1];
            }
        }
    printf("%d %lld\n", lena + lenb - p[lena][lenb], f[lena][lenb]);
}
int main()
{
    int t, tt;
    gets(b);
    sscanf(b, "%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        printf("Case #%d: ", tt + 1);
        solve();
    }
    return 0;
}