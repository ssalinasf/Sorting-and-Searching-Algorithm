#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  FILE *inputfile;
  char c;
  int largo = 0;
  char *a = (char *)malloc(50000*sizeof(char *));;
  char *b = (char *)malloc(50000*sizeof(char *));;
  inputfile = fopen("archivo_1.tex", "r");

  if (inputfile == NULL) {
      fprintf(stderr, "Failed to open the file.\n");
      exit(1);
  }
  if (inputfile) {
      for ( int i=0; (c = getc(inputfile)) != EOF; i++){
          a[i] = c;
          //putchar(a[i]);
          largo++;
      }
      fclose(inputfile);
  }

  printf("El largo de la mierda es %i\n", largo);

  char key[4];
  int aux = 0;
  int freq = 0;
  int k;
  for (size_t i = 0; i < 1000; i++) {
      aux = i;
      key[3]= aux/10 <100 ? aux%10  + '0' : '0' ;
      aux/=10;
      key[2]= aux/10 <10 ? aux%10  + '0' : '0' ;
      aux/=10;
      key[1]= aux/10 <1 ? aux%10 + '0' : '0' ;
      key[0]= aux%10 + '0';
      // for (size_t j = 0; j < 4; j++) {
      //   printf("%c", key[j]);
      // }
      // printf("\n");
      for (size_t j = 0; j < largo-4; j++) {
        k =0;
        while(k <4 && a[j+k] == key[k])
          k=k+1;
        if(k == 4){
          //  for (size_t t = 0; t < 4; t++) {
          //    printf("%c", key[t]);
          //  }
          //  printf("\n" );
          freq++;
        }
      }
  }
  free(a);
  return 0;
}
