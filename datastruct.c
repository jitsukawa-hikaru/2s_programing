#include <stdio.h> 

struct complex{
  double  re;
  double  im;
};

void main(){
  struct complex a, b;
  int i;
  
  a.re = 1.0;
  a.im = 2.3;
  for(i = 0; i < 5; i ++){
    a.re = a.re + 1.0;
    a.im = a.im - 3.0;
    printf("a.re = %.1lf a.im = %.1lf \n", a.re, a.im);
  }
}
