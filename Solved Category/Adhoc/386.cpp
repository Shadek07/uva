
#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
using namespace std;

int main ()
{
	double A, B, C, D, PA, PB, PC, PD;
	

	for (A = 6; A <= 200; A++) {
		PA = pow (A, 3);
		for (D = 2; D < A; D++) {
			PD = pow (D, 3);
			for (C = D + 1; C < A; C++) {
				PC = pow (C, 3);
				for (B = C + 1; B < A; B++) {
					PB = pow (B, 3);
					if ( floor (PA) == (floor (PB) + floor (PC) + floor (PD)) )
						printf("Cube = %0.lf, Triple = (%0.lf,%0.lf,%0.lf)\n", A, D, C, B);
				}
			}
		}
	}
	
	return 0;
}
