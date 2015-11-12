#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>

using namespace std;

map<string,int> mp;
map<string,int> mp1;
map<char,int> keypad;

map<string,int>::iterator it;
char in[900];
int main(void)
{
    int t;
    string s1,s2;
    int i,j,k,n;
    bool ch,ch1;
    keypad['A'] = keypad['B'] = keypad['C'] = 2;
    keypad['D'] = keypad['E'] = keypad['F'] = 3;
    keypad['G'] = keypad['H'] = keypad['I'] = 4;
    keypad['J'] = keypad['K'] = keypad['L'] = 5;
    keypad['M'] = keypad['N'] = keypad['O'] = 6;
    keypad['P'] = keypad['R'] = keypad['S'] = 7;
    keypad['T'] = keypad['U'] = keypad['V'] = 8;
    keypad['W'] = keypad['X'] = keypad['Y'] = 9;
    ch = false;
    cin >> t;
    getchar();
    getchar();
    while(t--)
    {
       cin >> n;
       getchar();
       while(n--)
       {
           gets(in);
           s1 = "";
           i = strlen(in);
           int cnt = 0;
           int check = 0;
           for(j = 0; j < i;j++)
           {
                 if(in[j] >= 'A' && in[j] <= 'Z')
                 {
                          s1 += char(keypad[in[j]]+'0');
                          cnt++;
                 }
                 if(in[j] >= '0' && in[j] <= '9')
                 {
                          s1 += in[j];
                          cnt++;
                 }
                 if(cnt == 3 && check == 0)
                 {
                        s1 += '-';
                        check = 1;
                 }
           }
           if(mp[s1])
           {
                     mp[s1]++;
                     mp1[s1] = mp[s1];
           }
           else
           {
               mp[s1] = 1;
           }      
       }
       
       if(!ch)
       ch = true;
       else
       cout << endl;
       ch1 = false;
       for ( it=mp1.begin() ; it != mp1.end(); it++ )
       {
           s2 = (*it).first;
           cout << s2 << " ";
           cout << mp[s2] << endl;
           ch1 = true;   
       }
       
       if(ch1 == false)
       {
              cout << "No duplicates.\n";
       }
       
       mp.clear();
       mp1.clear(); 
    }
    return 0;
}
