#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int vet[4]) {
  if (vet[0] <= vet[4 - 1]) {
    printf("vetor_crescente: ");
    for (int i = 0; i < 4; i++) {
      printf("%d ", vet[i]);
    }
    printf("\n");
  } else {
    printf("vetor_decrescente: ");
    for (int i = 0; i < 4; i++) {
      printf("%d ", vet[i]);
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  int vetNums[4], vetCrescente[4], vetDecrescente[4];
  for (int i = 0; i < 4; i++) {
    scanf("%d", &vetNums[i]);
  }

  for (int i = 0; i < 4; i++) {
    vetCrescente[i] = vetNums[i];
    vetDecrescente[i] = vetNums[i];
  }

  int auxmax = vetNums[0];
  int auxmin = vetNums[0];
  for(int i = 0; i < 4 - 1; i++) {
    for(int k = 0; k < 4 - 1 - i; k++) {
        if(vetCrescente[k] > vetCrescente[k+1]) {
            auxmax = vetCrescente[k];
            vetCrescente[k] = vetCrescente[k+1];
            vetCrescente[k+1] = auxmax;
        }
        if(vetDecrescente[k] < vetDecrescente[k+1]) {
            auxmin = vetDecrescente[k];
            vetDecrescente[k] = vetDecrescente[k+1];
            vetDecrescente[k+1] = auxmin;
        }
    }
  }

  imprime_vetor(vetCrescente);
  imprime_vetor(vetDecrescente);
  return 0;
}
