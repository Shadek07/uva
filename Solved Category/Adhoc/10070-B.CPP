#include <iostream> 
#include <string> 
using namespace std; 
int main(){ 
string str; 
int n; 
int p; 
int l; 
int lasttwo; 
int beforetwo; 
int odd; 
int even; 
int sum; 
int last; 
int i; 
int check = 0;


while (cin>>str){ 
n=0; 
p=0; 
sum=0; 
lasttwo=0; 
beforetwo=0; 
last=0; 
odd=0; 
even=0; 
l=str.length(); 
lasttwo= (str[l-1]-'0')+(str[l-2]-'0')*10; 
beforetwo=(str[l-3]-'0')+(str[l-4]-'0')*10; 
last=str[l-1]-'0'; 
for(i=0;i<l;i++){ 
sum+=str[i]-'0'; 
if (i%2==1){ 
odd+=str[i]-'0'; 
} 
if (i%2==0){ 
even+=str[i]-'0'; 
} 
} 

if(check == 1)
{
  cout<<endl; 
}
else
check = 1;
if ( lasttwo!=0 && lasttwo%4==0){ 
cout<<"This is leap year."<<endl; 
n++; 
} 
if (lasttwo==0 && beforetwo%4==0){ 
cout<<"This is leap year."<<endl; 
n++;} 

if ((last==0 || last==5) && sum%3==0){ 
cout<<"This is huluculu festival year."<<endl; 
p++; 
} 

if (n>0 && (last==0 || last==5) && (odd-even)%11==0){ 
cout<<"This is bulukulu festival year."<<endl;} 

if (n==0 && p==0){ 
cout<<"This is an ordinary year."<<endl;} 

//cout<<endl; 
} 

return 0; 
}