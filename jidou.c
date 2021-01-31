#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main(){
 double x[100], rst, a;
 int i = 1, z = 0;
 char str[10000], op, sw;
 x[0] = 0;
 
 for(;;){
  if(z != 0){
   scanf("%c", &sw);
   while(sw == '\n')
    scanf("%c", &sw);
   if(sw == 'q'){
    printf("END\n"); return 0;
   }
  }
  if(sw != 'b' && sw != 'r'){
   scanf("%s", str);
   if(str[0]>='0' && str[0]<='9')
    sscanf(str,"%lf", &rst);
   else{
    sscanf(str,"%c%lf", &op, &a);
    switch(op){
     case 's': rst = sin(a*PI/180); break;
     case 'c': rst = cos(a*PI/180); break;
     case 't': rst = tan(a*PI/180); break;
     case 'q': printf("END\n"); return 0;
    }
   }
  }
  if(z == 0)
   x[i] = x[0] + rst;
  else{
   switch(sw){
    case '+': x[i] = x[i-1] + rst; break;
    case '-': x[i] = x[i-1] - rst; break;
    case '*': x[i] = x[i-1] * rst; break;
    case '/': x[i] = x[i-1] / rst; break;
    case 'b': i -= 2; break;
    case 'r': x[i] = 0; break;
   }
   printf("    =%g\n", x[i]);
  }
  i += 1; z = 1;
 }
 return 0;
}
