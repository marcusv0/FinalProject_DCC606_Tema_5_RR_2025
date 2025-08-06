#include <stdio.h>
#include <stdlib.h>

#define MAX 1066 // ajuste de acordo com o tamanho real

int graph[MAX][MAX];
int n;

void ler_matriz(const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(fp, "%d", &n); // número de vértices

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &graph[i][j]);

    fclose(fp);
}
