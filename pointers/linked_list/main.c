#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list {
  int num;
  struct linked_list *nxt;
} Tlist;

void insert(Tlist **list, int num) {
  Tlist *new = (Tlist*)malloc(sizeof(Tlist));
  new->num = num;
  new->nxt = *list;
}

void delete(Tlist **list, int num) {
  Tlist *aux = list, *prev = NULL;
  while(aux) {
    if(num == aux->num) break;
    prev = aux;
    aux = aux->nxt;
  }
  if(aux) {
    if(prev) prev->nxt = aux->nxt;
    else *list = aux->nxt;
    free(aux);
  }
}

int find(Tlist *list, int num) {
  while(list) {
    if(num == list->num) return 1;
    list = list->nxt;
  }
  return 0;
}

int main() {
  Tlist *list = NULL, *aux = list;

  list = (Tlist*)malloc(sizeof(Tlist));
  insert(&list, 10);
  insert(&list, 20);
  insert(&list, 30);
  printf("%d\n", find(list, 10));
  delete(&list, 10);
  printf("%d\n", find(list, 10));

  while(aux) {
    printf("%d\n", aux->num);
  }

  // Liberação de memória
  aux = list;
  while(aux) {
    Tlist *tmp = aux->nxt;
    free(aux);
    aux = tmp;
  }

  return 0;
}