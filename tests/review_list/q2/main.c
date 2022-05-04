#include <stdio.h>

void even(int i, int n) {
  if(2 * i < n) {
    printf("%d\n", 2 * i);
    even(i + 1, n);
  }
}

int main() {
  int n = 10;

  scanf("%d", &n);
  even(0, n);
}