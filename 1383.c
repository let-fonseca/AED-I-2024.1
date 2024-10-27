#include <stdio.h>

/* as 3 funções abaixo verificam se cada linha, coluna e submatriz de 3x3
da matriz do sudoku inserida contém números únicos de 1 a 9. se algum número
se repetir ou estiver fora desse intervalo, a função retorna 0 (falha), caso
contrário (todos os números são válidos e não repetidos) a função retorna 1
(sucesso). */

int linhas(int matriz[9][9]) {
    for (int i = 0; i < 9; i++) { // verificando cada linha
        int vistos[10] = {0}; // vetor p marcar números vistos, de 1 a 9
      
        for (int j = 0; j < 9; j++) { // percorrendo os elementos de cada linha
            int num = matriz[i][j];
          
            if (num < 1 || num > 9 || vistos[num]) return 0; // se num for inválido ou repetido retorna 0
            vistos[num] = 1; // marca o número percorrido como visto
        }
    }
    return 1;
}

int colunas(int matriz[9][9]) {
    for (int j = 0; j < 9; j++) { // verificando cada coluna
        int vistos[10] = {0}; // vetor p marcar números vistos, de 1 a 9
      
        for (int i = 0; i < 9; i++) { // percorrendo os elementos de cada coluna
            int num = matriz[i][j];
          
            if (num < 1 || num > 9 || vistos[num]) return 0; // se num for inválido ou repetido retorna 0
            vistos[num] = 1; // marca o número percorrido como visto
        }
    }
    return 1;
}

int submatrizes(int matriz[9][9]) { // submatrizes 3x3
    for (int linha = 0; linha < 9; linha += 3) { // cada linha inicial de cada 3x3
        for (int coluna = 0; coluna < 9; coluna += 3) { // cada coluna inicial de cada 3x3
            int vistos[10] = {0}; // vetor p marcar números vistos dentro de cada 3x3
          
            for (int i = linha; i < linha + 3; i++) { // percorrendo os elementos de cada linha
                for (int j = coluna; j < coluna + 3; j++) { // percorrendo os elementos de cada coluna
                    int num = matriz[i][j];
                  
                    if (num < 1 || num > 9 || vistos[num]) return 0; // se num for inválido ou repetido retorna 0
                    vistos[num] = 1; // marca o número percorrido como visto
                }
            }
        }
    }
    return 1;
}

int main() {
    int n; // qtd de matrizes a serem lidas
    int matriz[9][9]; // cada matriz 9x9
    scanf("%d", &n);
    char resultados[n][20]; // vetor de strings p guardar o resultado de cada matriz

    for (int k = 1; k <= n; k++) { // lendo cada matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // verificando se a matriz é válida (ou seja, linhas, colunas e submatrizes retornam 1):
        int valida = linhas(matriz) && colunas(matriz) && submatrizes(matriz);

        if (valida) { // se for válida, a instância atual é válida (SIM)
            sprintf(resultados[k - 1], "Instancia %d\nSIM\n", k);
        } else { // se for inválida, a instância atual é inválida (NAO)
            sprintf(resultados[k - 1], "Instancia %d\nNAO\n", k);
        }
    }

    for (int k = 0; k < n; k++) { // mostrando todos os resultados (bloco if-else) juntos no final
        printf("%s\n", resultados[k]);
    }

    return 0;
}
