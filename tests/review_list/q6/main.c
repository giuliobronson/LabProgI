#include <stdio.h>

int main() {
  int n;
  int a = 1, b = 1;

  scanf("%d", &n);
  for(int i = 1; i < n - 1; i++) {
    int tmp = b;
    b = a + b; a = tmp;
  }
  printf("%d\n", b);

  return 0;
}