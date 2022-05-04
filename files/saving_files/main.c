#include <string.h>
#include <stdio.h>

int main() {
  FILE *input;
  char sin[100];

  // Escrita no arquivo
  input = fopen("word.txt", "w");
  if(!input) {
    return -1;
  }

  printf("Insira uma palavra: ");
  fgets(sin, 99 * sizeof(char), stdin);
  fputs(sin, input);
  printf("%s", sin);

  fclose(input);

  // Leitura do arquivo
  FILE *output;
  char sout[100];

  output = fopen("word.txt", "r");
  if(!output) {
    return -1;
  }

  char *ptr = fgets(sout, 99 * sizeof(char), output);
  if(!ptr) {
    return -2;
  }
  printf("%s", sout);

  if(!strcmp(sin, sout)) printf("true\n");
  else printf("false\n");

  fclose(output);

  return 0;
}