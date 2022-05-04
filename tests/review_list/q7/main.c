#include <stdio.h>
#include <stdlib.h>

int main() {
  int *v, n;

  scanf("%d", &n); // Determina a quantidade de memória necessária
  v = (int*)malloc(n * sizeof(int)); // Solicita a alocação da memória

  // Utiliza a memória alocada
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n - 1; j++) {
      if(v[j] > v[j + 1]) {
        int tmp = v[j];
        v[j] = v[j + 1]; v[j + 1] = tmp;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf(i == n - 1 ? "%d\n": "%d ", v[i]);
  }

  free(v); // Libera a região de memória alocada após o uso

  return 0;
}