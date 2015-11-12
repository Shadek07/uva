#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;

#define min(a,b) a<b?a:b
int dist[200][200][200];
int ca,cb,cc,d;
int diff;
int mx;
int poured;

struct state
{
	int x;
	int y;
	int z;
	int sum;
};

queue<state> pq;

struct state s1,s2;
void calculate()
{
    int d1,s;
	int e1;
	int f;
	int t1,t2,t3;
	s1.x = 0;
	s1.y = 0;
	s1.z = cc;
	s1.sum = 0;
	dist[0][0][cc] = 0;
	pq.push(s1);

	while(!pq.empty())
	{
		s1 = pq.front();
		pq.pop();
		d1 = dist[s1.x][s1.y][s1.z];
		t1 = s1.x;
		t2 = s1.y;
		t3 = s1.z;
		s = s1.sum;
		if(t1 == d || t2 == d || t3 == d)
		{
			poured = s1.sum;
			mx = d;
			break;
		}
		else
		{
			e1 = min(abs((t1-d)*1.0),abs((t2-d)*1.0));
			e1 = min(e1,abs((t3-d)*1.0));
			if(e1 < diff)
			{
				diff = e1;
				mx = d-diff;
				poured = s1.sum;
			}
		}
		//pour from a to b
		if(t1 > 0 && t2 < cb)
		{
			f = cb - t2;//empty space in b
			if(f >= t1)
			{
				s2.x = 0;
				s2.y = t2+t1;
				s2.z = t3;
				s2.sum = s+t1;
				if(dist[0][t2+t1][t3] > d1+1)
				{
					dist[0][t2+t1][t3] = d1+1;
					pq.push(s2);
				}
			}
			else
			{
				s2.x = t1-f;
				s2.y = cb;
				s2.z = t3;
				s2.sum = s+f;
				if(dist[t1-f][cb][t3] > d1+1)
				{
					dist[t1-f][cb][t3] = d1+1;
					pq.push(s2);
				}
			}
		}
		//pour from a to c
		if(t1 > 0 && t3 < cc)
		{
			f = cc - t3;//empty space in c
			if(f >= t1)
			{
				s2.x = 0;
				s2.y = t2;
				s2.z = t3+t1;
				s2.sum = s+t1;
				if(dist[0][t2][t3+t1] > d1+1)
				{
					dist[0][t2][t3+t1] = d1+1;
					pq.push(s2);
				}
			}
			else
			{
				s2.x = t1-f;
				s2.y = t2;
				s2.z = cc;
				s2.sum = s+f;
				if(dist[t1-f][t2][cc] > d1+1)
				{
					dist[t1-f][t2][cc] = d1+1;
					pq.push(s2);
				}
			}
		}

		//pour from b to a
		if(t2 > 0 && t1 < ca)
		{
			f = ca - t1;
			if(f >= t2)
			{
				s2.x = t1+t2;
				s2.y = 0;
				s2.z = t3;
				s2.sum = s+t2;
				if(dist[t1+t2][0][t3] > d1+1)
				{
					dist[t1+t2][0][t3] = d1+1;
					pq.push(s2);
				}
			}
			else
			{
				s2.x = ca;
				s2.y = t2 - f;
				s2.z = t3;
				s2.sum = s+f;
				if(dist[ca][t2-f][t3] > d1+1)
				{
					dist[ca][t2-f][t3] = d1+1;
					pq.push(s2);
				}
			}
		}
		//pour from b to c
		if(t2 > 0 && t3 < cc)
		{
			f = cc - t3;
			if(f >= t2)
			{
				s2.x = t1;
				s2.y = 0;
				s2.z = t3+t2;
				s2.sum = s+t2;
				if(dist[t1][0][t3+t2] > d1+1)
				{
					dist[t1][0][t3+t2] = d1+1;
					pq.push(s2);
				}
			}
			else
			{
				s2.x = t1;
				s2.y = t2 - f;
				s2.z = cc;
				s2.sum = s+f;
				if(dist[ca][t2-f][cc] > d1+1)
				{
					dist[t1][t2-f][cc] = d1+1;
					pq.push(s2);
				}
			}
		}
		//pour from c to a
		if(t3 > 0 && t1 < ca)
		{
			f = ca - t1;
			if(f >= t3)
			{
				s2.x = t1+t3;
				s2.y = t2;
				s2.z = 0;
				s2.sum = s+t3;
				if(dist[t1+t3][t2][0] > d1+1)
				{
					dist[t1+t3][t2][0] = d1+1;
					pq.push(s2);
				}
			}
			else
			{
				s2.x = ca;
				s2.y = t2;
				s2.z = t3-f;
				s2.sum = s+f;
				if(dist[ca][t2][t3-f] > d1+1)
				{
					dist[ca][t2][t3-f] = d1+1;
					pq.push(s2);
				}
			}
		}
		//pour from c to b
		if(t3 > 0 && t2 < cb)
		{
			f = cb - t2;
			if(f >= t3)
			{
				s2.x = t1;
				s2.y = t2+t3;
				s2.z = 0;
				s2.sum = s+t3;
				if(dist[t1][t2+t3][0] > d1+1)
				{
					dist[t1][t2+t3][0] = d1+1;
					pq.push(s2);
				}
			}
			else
			{
				s2.x = t1;
				s2.y = cb;
				s2.z = t3-f;
				s2.sum = s+f;
				if(dist[t1][cb][t3-f] > d1+1)
				{
					dist[t1][cb][t3-f] = d1+1;
					pq.push(s2);
				}
			}
		}
	}

	while(!pq.empty())
		pq.pop();


}

int main(void)
{
	int t;

	cin >> t;

	while(t--)
	{
		cin >> ca >> cb >> cc >> d;
		diff = d;
		mx = 0;
		memset(dist,999999,sizeof(dist));
		calculate();
		cout << poured << " " << mx << endl;
	}

	return 0;

}