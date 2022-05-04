#include <stdlib.h>
#include <stdio.h>

int main() {
  float summ = 0, sumf = 0;
  int nm = 0, nf = 0;
  FILE *file;

  file = fopen("grades.txt", "r");
  if(!file) {
    printf("error");
    return -1;
  }
  
  while(1) {
    char c = getc(file);
    if(feof(file)) break;
    if(c == 'M') {
      char grd[10];
      fseek(file, SEEK_CUR, sizeof(char));
      fgets(grd, 5 * sizeof(char), file);
      grd[strlen(grd) - 1] = '\0';
      summ += atof(grd);
      nm++;
    } 
    else if(c == 'F') {
      char grd[10];
      fseek(file, SEEK_CUR, sizeof(char));
      fgets(grd, 5 * sizeof(char), file);
      grd[strlen(grd) - 1] = '\0';
      sumf += atof(grd);
      nf++;
    }
  }
  
  if((summ / nm) > (sumf / nf)) 
    printf("M %.2f\n", (summ / nm));
  else 
    printf("F %.2f\n", (sumf / nf));

  fclose(file);

  return 0;
}