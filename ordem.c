#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int vetor[5], c, a;
  printf("Ordenação\n");
  srand(time(NULL));

  for (int c = 0; c <= 4; c++) {
    vetor[c] = rand() % (100);
    printf("vetor inicial de n:%d ficou com o numero:%d\n", c, vetor[c]);
  }

  for (int i = 0; i <= 4; i++) {
    for (int c = 0; c <= 4; c++) {
      if (vetor[c] > vetor[c + 1]) {
        a = vetor[c];
        vetor[c] = vetor[c + 1];
        vetor[c + 1] = a;
      }
    }
  }
  printf("vetor final :\n");
  for (int c = 0; c <= 4; c++) {
    printf("ficou com o numero:%d\n", vetor[c]);
  }
}
