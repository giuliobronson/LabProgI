#include <stdio.h>

int main() {
  int n = 10;

  scanf("%d", &n);
  for(int i = 0; 2 * i < n; i++) {
    printf("%d\n", 2 * i);
  }

  return 0;
}