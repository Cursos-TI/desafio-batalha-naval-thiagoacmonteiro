#include <stdio.h>



void popula_tabuleiro(int tabuleiro[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabuleiro[i][j] = 0;
    }
  }
}

void verifica_limites_do_tabuleiro(int posicao_inicial_navio_1, int posicao_inicial_navio_2) {
  if (posicao_inicial_navio_1 + 3 > 10) {
    printf("A posição do navio 1 estrapola os limites do tabuleiro");
    return 0;
  }

  if (posicao_inicial_navio_2 + 3 > 10) {
    printf("A posição do navio 2 estrapola os limites do tabuleiro");
    return 0;
  }
}

void posiciona_navio(
  int num_navio,
  char colunas[10],
  int tabuleiro[10][10],
  int navio_1[3],
  int navio_2[3],
  int indice_linha_navio_1,
  int posicao_inicial_navio_1,
  int indice_coluna_navio_2,
  int posicao_inicial_navio_2
) {
  switch (num_navio) {
    case 1:
      // Iterando sobre as linhas do tabuleiro
      for (int i = 0; i < 10; i++) {
        // Verifica se a linha atual é a linha do navio 1
        if (i == indice_linha_navio_1) {
          // Iterando sobre as colunas do tabuleiro
          for (int j = 0; j < 10; j++) {
            // Verifica se a coluna atual está dentro do intervalo do navio 1
            if (j >= posicao_inicial_navio_1 && j < posicao_inicial_navio_1 + 3) {
              // Verifica se já existe um navio na posição atual
              if (tabuleiro[i][j] != 0) {
                printf("A posição dos navios gerou conflito na seguinte posição:\n");
                printf("Coluna: %c\n", colunas[j]);
                printf("Linha: %d\n", i + 1);
                return 0;
              }
              
              // Atribui o valor do navio 1 à posição atual do tabuleiro
              tabuleiro[i][j] = navio_1[j - posicao_inicial_navio_1];
            }               
          }
        }
      }
      break;
    case 2:
      // Iterando sobre as linhas do tabuleiro
      for (int i = 0; i < 10; i++) {
        // Iterando sobre as colunas do tabuleiro
        for (int j = 0; j < 10; j++) {
          // Verifica se a coluna atual é a coluna do navio 2
          // e se a linha atual está dentro do intervalo do navio 2
          if (j == indice_coluna_navio_2 && i >= posicao_inicial_navio_2 && i < posicao_inicial_navio_2 + 3) {   
            // Verifica se já existe um navio na posição atual             
            if (tabuleiro[i][j] != 0) {
              printf("A posição dos navios gerou conflito na seguinte posição:\n");
              printf("Coluna: %c\n", colunas[j]);
              printf("Linha: %d\n", i + 1);
              return 0;
            }

            // Atribui o valor do navio 2 à posição atual do tabuleiro
            tabuleiro[i][j] = navio_2[i - posicao_inicial_navio_2];
          }
        }
      }
      break;
  }  
}

void imprime_tabuleiro(int tabuleiro[10][10]) {
  printf("   A B C D E F G H I J\n");
  for (int i = 0; i < 10; i++) {
    printf(i < 9 ? " %d " : "%d ", i + 1);
    for (int j = 0; j < 10; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro[10][10];
  int navio_1[3] = {3, 3, 3};
  int navio_2[3] = {3, 3, 3};
  int indice_linha_navio_1 = 3;
  int indice_coluna_navio_2 = 3;
  int posicao_inicial_navio_1 = 3;
  int posicao_inicial_navio_2 = 7;
  
  popula_tabuleiro(tabuleiro);

  verifica_limites_do_tabuleiro(posicao_inicial_navio_1, posicao_inicial_navio_2);
  
  posiciona_navio(
    1,
    colunas,
    tabuleiro,
    navio_1,
    navio_2,
    indice_linha_navio_1,
    posicao_inicial_navio_1,
    indice_coluna_navio_2,
    posicao_inicial_navio_2
  );

  posiciona_navio(
    2,
    colunas,
    tabuleiro,
    navio_1,
    navio_2,
    indice_linha_navio_1,
    posicao_inicial_navio_1,
    indice_coluna_navio_2,
    posicao_inicial_navio_2
  );
  
  imprime_tabuleiro(tabuleiro);  

  return 0;
}
