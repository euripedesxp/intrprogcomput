//
// Created by euripedes on 20/05/25 on CLion
//
#include <stdio.h>

#define MAX 5

int main() {
    char estado[MAX][30], cidade[MAX][30];
    int codigo[MAX], populacao[MAX], pontos[MAX];
    float pib[MAX], area[MAX], densidade[MAX], pib_per_capita[MAX];
    int n, i;

    printf("Quantas cartas deseja cadastrar? (máx %d): ", MAX);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nCarta %d:\n", i + 1);

        printf("Estado: ");
        scanf(" %[^\n]", estado[i]);

        printf("Cidade: ");
        scanf(" %[^\n]", cidade[i]);

        printf("Código: ");
        scanf("%d", &codigo[i]);

        printf("População: ");
        scanf("%d", &populacao[i]);

        printf("PIB (em bilhões): ");
        scanf("%f", &pib[i]);

        printf("Área (km²): ");
        scanf("%f", &area[i]);

        printf("Pontos turísticos: ");
        scanf("%d", &pontos[i]);

        densidade[i] = populacao[i] / area[i];
        pib_per_capita[i] = (pib[i] * 1000000000) / populacao[i];
    }

    printf("\n--- Cartas Cadastradas ---\n");
    for (i = 0; i < n; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %s\n", estado[i]);
        printf("Cidade: %s\n", cidade[i]);
        printf("Código: %d\n", codigo[i]);
        printf("População: %d\n", populacao[i]);
        printf("PIB: R$ %.2f bilhões\n", pib[i]);
        printf("Área: %.2f km²\n", area[i]);
        printf("Pontos turísticos: %d\n", pontos[i]);
        printf("Densidade: %.2f hab/km²\n", densidade[i]);
        printf("PIB per capita: R$ %.2f\n", pib_per_capita[i]);
    }

    return 0;
}
