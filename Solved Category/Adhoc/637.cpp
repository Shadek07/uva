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
#include<sstream>
#include<stack>
#include<list>
using namespace std;
#define FORL(i,a,b) for (int i = a; i < b; i++)
#define FORE(i,a,b) for (int i = a; i <= b; i++)

int main (void) {
  int n;

  while (cin >> n) 
  {
    if (!n)
      break;

    cout << "Printing order for " << n << " pages:" << endl;

    if (n == 1) {
      cout << "Sheet 1, front: Blank, 1" << endl;
      continue;
    }

    int sheets = ceil(n/4.0);
    int start = 1, end = 4 * sheets;
    for (int i = 0; i < sheets; i++) {
      cout << "Sheet " << i+1 << ", front: ";
      if (end > n)
        cout << "Blank";
      else
        cout << end;
      cout << ", " << start << endl;
      start++, end--;
      cout << "Sheet " << i+1 << ", back : " << start << ", ";
      if (end > n)
        cout << "Blank";
      else
        cout << end;
      cout << endl;
      start++, end--;
    }
  }

  return 0;
}
