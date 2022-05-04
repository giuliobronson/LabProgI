#include <stdio.h>

int main() {
  int seven = 0;
  int sodd = 0;
  FILE *file;

  file = fopen("number.txt", "r");
  if(!file) {
    printf("error");
    return -1;
  }
  
  while(1) {
    char c = getc(file);
    if(feof(file)) break;
    if(c != '\n') {
      int n = c - '0';
      if(n % 2) sodd += n;
      else seven += n;
    }
  }
  
  printf("%d\n%d\n", seven, sodd);

  fclose(file);

  return 0;
}