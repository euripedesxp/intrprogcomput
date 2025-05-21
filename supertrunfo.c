#include <stdio.h>

int main() {
    char estado[30], cidade[30];
    int codigo, populacao, pontos;
    float pib, area, densidade, pib_per_capita;

    // Entrada
    printf("Estado: ");
    scanf(" %[^\n]", estado);

    printf("Cidade: ");
    scanf(" %[^\n]", cidade);

    printf("Código: ");
    scanf("%d", &codigo);

    printf("População: ");
    scanf("%d", &populacao);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib);

    printf("Área (km²): ");
    scanf("%f", &area);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos);

    // Cálculos com verificação
    if (area > 0)
        densidade = populacao / area;
    else
        densidade = 0;

    if (populacao > 0)
        pib_per_capita = (pib * 1000000000) / populacao;
    else
        pib_per_capita = 0;

    // Saída
    printf("\n--- Carta Cadastrada ---\n");
    printf("Estado: %s\n", estado);
    printf("Cidade: %s\n", cidade);
    printf("Código: %d\n", codigo);
    printf("População: %d\n", populacao);
    printf("PIB: R$ %.2f bilhões\n", pib);
    printf("Área: %.2f km²\n", area);
    printf("Pontos turísticos: %d\n", pontos);
    printf("Densidade: %.2f hab/km²\n", densidade);
    printf("PIB per capita: R$ %.2f\n", pib_per_capita);

    return 0;
}
