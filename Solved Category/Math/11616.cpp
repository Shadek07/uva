

#pragma comment(linker,"/STACK:16777216")
#pragma  warning ( disable: 4786)
#include <bits/stdc++.h>
using namespace std;

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

#define forl(i,a,b) for ( i = a; i < b; i++)
#define fore(i,a,b) for ( i = a; i <= b; i++)
#define forrev(i,a,b) for ( i = a; i >= b; i--)
#define MID(a, b) (a + ((b - a) >> 1))
#define pb push_back
typedef long long  LL;
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define ms(a,b) memset((a),(b),sizeof(a))

#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ull unsigned long long int
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

string to_string(long long x) { stringstream ss; ss << x; return ss.str(); }
long long to_int(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

#define MAX 100005
#define INF 9999999

map<char,int> RomanToDecimal;
map<int,char> DecimalToRoman;

int getPower(int base,int p){
    int i;
    if(p==0)
        return 1;
    forl(i,0,p-1){
        base *= 10;
    }
    return base;
}
bool isLess(char a,char b){
    if(a=='I' && b == 'V')
        return true;
    if(a=='I' && b == 'X')
        return true;
    if(a=='X' && b == 'L')
        return true;
    if(a == 'X' && b == 'C')
        return true;
    if(a=='C' && b == 'D')
        return true;
    if(a == 'C' && b == 'M')
        return true;
    return false;
}
string getValue(int value){
    string s="";
    if(DecimalToRoman[value]){
        s += DecimalToRoman[value];
        return s;
    }
    if(value == 2000)
        return "MM";
    if(value == 3000)
        return "MMM";
    if(value==2){
        return "II";
    }
    if(value==3){
        return "III";
    }if(value==4){
        return "IV";
    }if(value==6){
        return "VI";
    }if(value==7){
        return "VII";
    }if(value==8){
        return "VIII";
    }if(value==9){
        return "IX";
        
    }if(value==20){
        return "XX";
    }
    if(value==30){
        return "XXX";
    }if(value==40){
        return "XL";
    }if(value==60){
        return "LX";
    }if(value==70){
        return "LXX";
    }if(value==80){
        return "LXXX";
    }if(value==90){
        return "XC";
        
    }if(value==200){
        return "CC";
    }
    if(value==300){
        return "CCC";
    }if(value==400){
        return "CD";
    }if(value==600){
        return "DC";
    }if(value==700){
        return "DCC";
    }if(value==800){
        return "DCCC";
    }if(value==900){
        return "CM";
    }
    return "";
}
int main(void)
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    string s;
    int len,num,i,a,b;
    RomanToDecimal['I'] = 1;
    DecimalToRoman[1] = 'I';
    
    RomanToDecimal['V'] = 5;
    DecimalToRoman[5] = 'V';
    
    RomanToDecimal['X'] = 10;
    DecimalToRoman[10] = 'X';
    
    RomanToDecimal['L'] = 50;
    DecimalToRoman[50] = 'L';
    
    RomanToDecimal['C'] = 100;
    DecimalToRoman[100] = 'C';
    
    RomanToDecimal['D'] = 500;
    DecimalToRoman[500] = 'D';
    
    RomanToDecimal['M'] = 1000;
    DecimalToRoman[1000] = 'M';
    //cout << DecimalToRoman[1000] << endl;
    while(cin >> s){
        len = s.size();
        string ans = "";
        if(s[0] >= '0' && s[0] <= '9'){ //decimal to roman
            forl(i,0,len){
                a = (s[i]-'0');
                b = getPower(10,len-i-1);
                a *= b;
                ans = ans + getValue(a);
            }
            cout << ans << endl;
        }else{ //roman to decimal
            a = RomanToDecimal[s[0]];
            b = 0;
            forl(i,1,len){
                if(isLess(s[i-1],s[i])){
                    a = RomanToDecimal[s[i] ] - a;
                    b += a;
                    a = 0;
                }
                else if(s[i] == s[i-1]){
                    a += RomanToDecimal[s[i] ];
                }else{
                    b += a;
                    a = RomanToDecimal[s[i] ];
                }
            }
            if(a>0)
                b += a;
            cout << b << endl;
        }
    }
    return 0;
}
