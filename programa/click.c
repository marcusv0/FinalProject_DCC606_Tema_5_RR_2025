#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1066

int graph[MAX][MAX];
int n;

int total_cliques = 0;
int tamanho_max_clique = 0;
int histograma[MAX] = {0};

void ler_matriz(const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(fp, "%d", &n);
    if (n > MAX)
    {
        fprintf(stderr, "Número de vértices (%d) excede o máximo permitido (%d)\n", n, MAX);
        exit(1);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &graph[i][j]);

    fclose(fp);
}

bool is_clique(int clique[], int size, int v)
{
    for (int i = 0; i < size; i++)
        if (!graph[clique[i]][v])
            return false;
    return true;
}

void greedy_clique()
{
    int clique[MAX], size;
    bool used[MAX] = {0};

    for (int u = 0; u < n; u++)
    {
        if (used[u])
            continue;

        clique[0] = u;
        size = 1;
        used[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (u == v || used[v])
                continue;
            if (is_clique(clique, size, v))
            {
                clique[size++] = v;
                used[v] = true;
            }
        }

        printf("Clique encontrada (tam %d): ", size);
        for (int i = 0; i < size; i++)
            printf("%d ", clique[i]);
        printf("\n");

        total_cliques++;
        histograma[size]++;
        if (size > tamanho_max_clique)
            tamanho_max_clique = size;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Uso: %s <arquivo_matriz>\n", argv[0]);
        return 1;
    }

    ler_matriz(argv[1]);

    clock_t inicio = clock();
    greedy_clique();
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nResumo experimental:\n");
    printf("Total de cliques encontrados: %d\n", total_cliques);
    printf("Tamanho máximo de clique: %d\n", tamanho_max_clique);
    printf("Tempo de execução: %.3f segundos\n", tempo);

    printf("\nDistribuição dos tamanhos dos cliques:\n");
    for (int i = 1; i <= tamanho_max_clique; i++)
        if (histograma[i] > 0)
            printf("Tamanho %d: %d cliques\n", i, histograma[i]);

    return 0;
}
