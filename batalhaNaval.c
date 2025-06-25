#include <stdio.h>

void popula_tabuleiro(int tabuleiro[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabuleiro[i][j] = 0;
    }
  }
}

void verifica_sobreposicao(int tabuleiro[10][10], char colunas[10], int i, int j) {
  if (tabuleiro[i][j] != 0) {
    printf("\n\nOs navios se sobrepõem na seguinte posição:\n");
    printf("Coluna: %c\n", colunas[j]);
    printf("Linha: %d\n\n", i + 1);
  }
}

void posiciona_navio(
  int num_navio,
  char colunas[10],
  int tabuleiro[10][10],
  int posicao_inicial_navio_1[2],
  int posicao_inicial_navio_2[2],
  int posicao_inicial_navio_3[2],
  int posicao_inicial_navio_4[2]
) {
  int num_pecas_navio = 0;

  switch (num_navio) {
    case 1:
      // Iterando sobre as linhas do tabuleiro
      for (int i = 0; i < 10; i++) {
        // Verifica se a linha atual é a linha do navio 1
        if (i == posicao_inicial_navio_1[0]) {
          // Iterando sobre as colunas do tabuleiro
          for (int j = 0; j < 10; j++) {
            // Verifica se a coluna atual está dentro do intervalo do navio 1
            if (j >= posicao_inicial_navio_1[1] && j < posicao_inicial_navio_1[1] + 3) {
              // Verifica se já existe um navio na posição atual
              verifica_sobreposicao(tabuleiro, colunas, i, j);             
              // Atribui o valor do navio 1 à posição atual do tabuleiro
              tabuleiro[i][j] = 3;
              num_pecas_navio++;
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
          if (j == posicao_inicial_navio_2[1] && i >= posicao_inicial_navio_2[0] && i < posicao_inicial_navio_2[0] + 3) {   
            // Verifica se já existe um navio na posição atual             
            verifica_sobreposicao(tabuleiro, colunas, i, j); 
            // Atribui o valor do navio 2 à posição atual do tabuleiro
            tabuleiro[i][j] = 3;
            num_pecas_navio++;
          }
        }
      }
      break;
    case 3:
      // Iterando sobre as linhas do tabuleiro
      for (int i = 0; i < 10; i++) {
        // Iterando sobre as colunas do tabuleiro
        for (int j = 0; j < 10; j++) {
          // Verifica se a coluna atual é a coluna do navio 3
          // e se a linha atual está dentro do intervalo do navio 3
          // O navio 3 é diagonal, então verifica as posições diagonais
          if (
            (i == posicao_inicial_navio_3[0] && j == posicao_inicial_navio_3[1])
            || (i == posicao_inicial_navio_3[0] + 1 && j == posicao_inicial_navio_3[1] + 1)
            || (i == posicao_inicial_navio_3[0] + 2 && j == posicao_inicial_navio_3[1] + 2)
          ) {
            verifica_sobreposicao(tabuleiro, colunas, i, j); 
            tabuleiro[i][j] = 3;
            num_pecas_navio++;
          }
        }
      }
      break;
    case 4:
      // Iterando sobre as linhas do tabuleiro
      for (int i = 0; i < 10; i++) {
        // Iterando sobre as colunas do tabuleiro
        for (int j = 0; j < 10; j++) {
          // Verifica se a coluna atual é a coluna do navio 4
          // e se a linha atual está dentro do intervalo do navio 4
          // O navio 4 é diagonal, então verifica as posições diagonais
          if (
            (i == posicao_inicial_navio_4[0] && j == posicao_inicial_navio_4[1])
            || (i == posicao_inicial_navio_4[0] + 1 && j == posicao_inicial_navio_4[1] - 1)
            || (i == posicao_inicial_navio_4[0] + 2 && j == posicao_inicial_navio_4[1] - 2)
          ) {
            verifica_sobreposicao(tabuleiro, colunas, i, j); 
            tabuleiro[i][j] = 3;
            num_pecas_navio++;
          }
        }
      }
      break;
  }  

  // Verifica se o navio foi montado por inteiro
  // Se uma das peças não foi adicionada, significa que estrapolou o tabuleiro
  if (num_pecas_navio < 3) printf("\n\nO navio %d estrapolou os limites do tabuleiro!!\n\n", num_navio);
}

void imprime_tabuleiro(int tabuleiro[10][10]) {
  printf("\n\n   A B C D E F G H I J\n");
  for (int i = 0; i < 10; i++) {
    printf(i < 9 ? " %d " : "%d ", i + 1);
    for (int j = 0; j < 10; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  };

  printf("\n\n");
}

int main() {
  char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  int tabuleiro[10][10];
  int posicao_inicial_navio_1[2] = {2, 3};
  int posicao_inicial_navio_2[2] = {4, 4};
  int posicao_inicial_navio_3[2] = {7, 0};
  int posicao_inicial_navio_4[2] = {1, 1};
  
  popula_tabuleiro(tabuleiro);
  
  posiciona_navio(
    1,
    colunas,
    tabuleiro,
    posicao_inicial_navio_1,
    posicao_inicial_navio_2,
    posicao_inicial_navio_3,
    posicao_inicial_navio_4
  );

  posiciona_navio(
    2,
    colunas,
    tabuleiro,
    posicao_inicial_navio_1,
    posicao_inicial_navio_2,
    posicao_inicial_navio_3,
    posicao_inicial_navio_4
  );

  posiciona_navio(
    3,
    colunas,
    tabuleiro,
    posicao_inicial_navio_1,
    posicao_inicial_navio_2,
    posicao_inicial_navio_3,
    posicao_inicial_navio_4
  );

  posiciona_navio(
    4,
    colunas,
    tabuleiro,
    posicao_inicial_navio_1,
    posicao_inicial_navio_2,
    posicao_inicial_navio_3,
    posicao_inicial_navio_4
  );
  
  imprime_tabuleiro(tabuleiro);  

  return 0;
}
