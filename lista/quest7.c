#include <stdio.h>

typedef struct {
  char nome[25];
  int matricula;
  float media;
  int situacao;
} aluno;

int verifica_media(aluno *vet, int N) {
  int abaixo_da_media = 0;
  for (int i = 0; i < N; i++) {
    if (vet[i].media >= 5) {
      vet[i].situacao = 1;
    } else {
      vet[i].situacao = 0;
      abaixo_da_media++;
    }
  }
  return abaixo_da_media;
}

void imprime_aluno(aluno aluno) {
  printf("Nome: %s\n", aluno.nome);
  printf("Matricula: %d\n", aluno.matricula);
  printf("Media: %.2f\n", aluno.media);
  if (aluno.situacao) {
    printf("Situacao: Aprovado\n");
  } else {
    printf("Situacao: Reprovado\n");
  }
}

void imprime_alunos(aluno *alunos, int N) {
  for (int i = 0; i < N; i++) {
    imprime_aluno(alunos[i]);
  }
}

void sumario(aluno *alunos, int N) {
  int abaixo = verifica_media(alunos, N);

  float media_turma = 0;
  for (int i = 0; i < N; i++) {
    media_turma += alunos[i].media;
  }
  media_turma /= N;

  if (abaixo == N) {
    printf("Todos os alunos estao reprovados\n");
  } else if (abaixo == 0){
    printf("Todos os alunos estao aprovados\n");
  } else {
    printf("%d alunos reprovados e %d alunos aprovados\n", abaixo, N - abaixo);
  }

  imprime_alunos(alunos, N);
}

int main(int argc, char const* argv[])
{
  int N;
  printf("Digite o numero de alunos: ");
  scanf("%d", &N);

  aluno alunos[N];

  for (int i = 0; i < N; i++) {
    printf("Digite o nome do aluno %d: ", i + 1);
    scanf("%s", alunos[i].nome);

    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &alunos[i].matricula);

    printf("Digite a media do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].media);
  }

  sumario(alunos, N);

  return 0;
}
