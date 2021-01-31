#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main(){
 double a, b, x, y;
 char op, sw;
 
 printf("(+,-,*,/) sin:s cos:c tan:t reset:r finish:q\n");
 printf("Example* Input:30s  --> sin(30) = 0.5\n");
 printf("         Input:s    --> sin(0.5) = 0.00872654\n");
 printf("         Input:+30s --> 0.00872654 + sin(30) = 0.508727\n");
 printf("--Input------------------------------------------------\n");
 scanf("%lf", &a);
 for(;;){
  scanf("%c", &op);
  while(op == '\n')
   scanf("%c", &op);
  switch(op){
   case 's': x = sin(a*PI/180.0);
             printf("sin(%g) = %g\n", a, x);
             a = x;
             break;
   case 'c': x = cos(a*PI/180.0);
             printf("cos(%g) = %g\n", a, x);
             a = x;
             break;
   case 't': x = tan(a*PI/180.0);
             printf("tna(%g) = %g\n", a, x);
             a = x;
             break;
   case '+': scanf("%lf", &b);
             scanf("%c", &sw);
             if(sw == '\n'){
              x = a + b;
              printf("%g + %g = %g\n", a, b, x);
              a = x;
              break;
             }
             switch(sw){
              case 's': y = sin(b*PI/180.0);
                        x = a + y;
                        printf("%g + sin(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 'c': y = cos(b*PI/180.0);
                        x = a + y;
                        printf("%g + cos(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 't': y = tan(b*PI/180.0);
                        x = a + y;
                        printf("%g + tan(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              }
              break;
   case '-': scanf("%lf", &b);
             scanf("%c", &sw);
             if(sw == '\n'){
              x = a - b;
              printf("%g - %g = %g\n", a, b, x);
              a = x;
              break;
             }
             switch(sw){
              case 's': y = sin(b*PI/180.0);
                        x = a - y;
                        printf("%g - sin(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 'c': y = cos(b*PI/180.0);
                        x = a - y;
                        printf("%g - cos(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 't': y = tan(b*PI/180.0);
                        x = a - y;
                        printf("%g - tan(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              }
              break;
   case '*': scanf("%lf", &b);
             scanf("%c", &sw);
             if(sw == '\n'){
              x = a * b;
              printf("%g * %g = %g\n", a, b, x);
              a = x;
              break;
             }
             switch(sw){
              case 's': y = sin(b*PI/180.0);
                        x = a * y;
                        printf("%g * sin(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 'c': y = cos(b*PI/180.0);
                        x = a * y;
                        printf("%g * cos(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 't': y = tan(b*PI/180.0);
                        x = a * y;
                        printf("%g * tan(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              }
              break;
   case '/': scanf("%lf", &b);
             scanf("%c", &sw);
             if(sw == '\n'){
              x = a / b;
              printf("%g / %g = %g\n", a, b, x);
              a = x;
              break;
             }
             switch(sw){
              case 's': y = sin(b*PI/180.0);
                        x = a / y;
                        printf("%g / sin(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 'c': y = cos(b*PI/180.0);
                        x = a / y;
                        printf("%g / cos(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              case 't': y = tan(b*PI/180.0);
                        x = a / y;
                        printf("%g / tan(%g) = %g\n", a, b, x);
                        a = x;
                        break;
              }
              break;
   case 'r': printf("--Reset:Input again--\n");
             scanf("%lf", &a);
             break;
   case 'q': printf("--Finish calculation--\n"); return 0;
   default: printf("--Error:Input again--\n"); continue;
  }
 }
 return 0;
}
