#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main(){
 double x, rst, a;
 int z = 0;
 char str[10000], op, sw, mod = 'a';
 
 for(;;){
  while(mod == 'a'){
   if(z != 0){
    scanf("%c", &sw);
    while(sw == '\n')
     scanf("%c", &sw);
   }
   scanf("%s", str);
   if(str[0] == 'f'){
    mod = 'f'; z =0; break;
   }
   sscanf(str,"%lf", &a);
   if(z == 0)
    x = a;
   else{
    switch(sw){
     case '+': x += a; break;
     case '-': x -= a; break;
     case 'f': 
    }
    pritnf("   =%g\n", x);
   }
   z = 1;
  }
  while(mod == 
