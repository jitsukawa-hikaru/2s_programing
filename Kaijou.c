//Kaijou.c

#include <stdio.h>

int main(){
 int n,i;
 long result;
 
 result=1;
 scanf("%d", &n);
 for(i=1; i<=n; i++)
  result*=i;
 
 printf("%d!=%ld\n", n, result);
 return 0;
}

