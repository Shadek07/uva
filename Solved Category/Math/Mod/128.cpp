#include <iostream.h>
#include <stdio.h>
int main()
{
   char c;
   long  int crc,m=34943;
   for(;;)
   {
      c=getchar();
      if(c=='#') break;
      crc=0; 
      while(c!='\n') 
      { 
         crc<<=8; 
         crc+=c; 
         crc%=34943;
         c=getchar(); 
      } 
      crc=(crc<<16)%34943; 
      if(crc) crc=34943-crc; 
      printf("%02X %02X\n",crc/256,crc%256); 
   }
   return 0;
}

