#include<iostream>
using namespace std;

int main(void)
{
    int t,Term1 , Term2,  Final,  Attendance , Class_Test1 , Class_Test2,  Class_Test3,cas = 1;
    float sum = 0.0;
    float avg;
    int c ;
    
    cin >> t;
    
    while(t--)
    {
              cin >> Term1 >> Term2 >>  Final >>  Attendance >> Class_Test1 >> Class_Test2 >>  Class_Test3;
              
              sum += Term1 + Term2 + Final + Attendance ;
              
              if( Class_Test1 >= Class_Test2)
              {
                  
              
                 avg = Class_Test1;
                 c = 1;
              }
              else
              {
                  
                    avg = Class_Test2;
                    c = 2;
              }
              if( c == 1)
              {
                  
                  if( Class_Test3 >=  avg || Class_Test3 >= Class_Test2 )
                  
                  avg += Class_Test3;
                  else
                  avg += Class_Test2;
                  
              }
              else
              {
                  if( Class_Test3 >=  avg || Class_Test3 >= Class_Test1 )
                  
                  avg += Class_Test3;
                  else
                  avg += Class_Test1;
                  
              }
              avg /= 2;
              
              sum += avg;
              cout << "Case " << cas++  <<": ";
              if( sum >= 90.0)
              {
                  cout << "A";
              }
              else if( sum >= 80.0 && sum < 90.0)
              {
                   cout << "B";
              }
              else if( sum >= 70.0 && sum < 80.0)
              {
                   cout << "C";
              }
              else if( sum >= 60.0 && sum < 70.0)
              {
                   cout << "D";
              }
              else if( sum < 60.0)
              {
                   cout << "F";
              }
              cout << endl;
              
              
             sum = 0.0; 
    }
    
    
    
    return 0;
}
