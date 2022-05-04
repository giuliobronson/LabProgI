#include <stdio.h>

int fib(int a, int b, int n) {
  if(n - 1) return fib(b, a + b, n - 1);
  return b; 
}

int main() {
  int n;

  scanf("%d", &n);
  printf("%d \n", fib(0, 1, n));

  return 0;
}