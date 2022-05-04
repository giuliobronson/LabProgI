#include <stdio.h>
#include <stdlib.h>

float mean(float *v, int size) {
  float sum = 0;

  for(int i = 0; i < size; i++) {
    sum += v[i];
  }

  return sum / size;
}

int main() {
  float *v;
  int n;

  printf("Insira a quantidade de notas a serem inseridas:\n");
  scanf("%d", &n);

  v = (float*)malloc(n * sizeof(float));
  if(v == NULL) {
    printf("Erro de alocação\n");
    return -1;
  }

  printf("Insira as notas:\n");
  for(int i = 0; i < n; i++) {
    scanf("%f", &v[i]);
  }

  float res = mean(v, n);

  printf("%f\n", res);

  free(v);

  return 0;
}