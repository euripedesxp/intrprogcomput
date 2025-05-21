#include <stdio.h>
#include <string.h>

int main() {
    // Dados da carta 1
    char estado1[30], cidade1[30];
    int codigo1 = 0, populacao1 = 0, pontos1 = 0;
    float pib1 = 0, area1 = 0, densidade1 = 0, pib_per_capita1 = 0;

    // Dados da carta 2
    char estado2[30], cidade2[30];
    int codigo2 = 0, populacao2 = 0, pontos2 = 0;
    float pib2 = 0, area2 = 0, densidade2 = 0, pib_per_capita2 = 0;

    int opcao;

    do {
        printf("\n--- Menu Super Trunfo de Cidades ---\n");
        printf("1. Cadastrar Carta 1\n");
        printf("2. Cadastrar Carta 2\n");
        printf("3. Listar Cartas\n");
        printf("4. Comparar Cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCadastro da Carta 1:\n");
                printf("Estado: ");
                scanf(" %[^\n]", estado1);
                printf("Cidade: ");
                scanf(" %[^\n]", cidade1);
                printf("Código: ");
                scanf("%d", &codigo1);
                printf("População: ");
                scanf("%d", &populacao1);
                printf("PIB (em bilhões): ");
                scanf("%f", &pib1);
                printf("Área (km²): ");
                scanf("%f", &area1);
                printf("Pontos turísticos: ");
                scanf("%d", &pontos1);

                densidade1 = (area1 > 0) ? populacao1 / area1 : 0;
                pib_per_capita1 = (populacao1 > 0) ? (pib1 * 1000000000) / populacao1 : 0;
                break;

            case 2:
                printf("\nCadastro da Carta 2:\n");
                printf("Estado: ");
                scanf(" %[^\n]", estado2);
                printf("Cidade: ");
                scanf(" %[^\n]", cidade2);
                printf("Código: ");
                scanf("%d", &codigo2);
                printf("População: ");
                scanf("%d", &populacao2);
                printf("PIB (em bilhões): ");
                scanf("%f", &pib2);
                printf("Área (km²): ");
                scanf("%f", &area2);
                printf("Pontos turísticos: ");
                scanf("%d", &pontos2);

                densidade2 = (area2 > 0) ? populacao2 / area2 : 0;
                pib_per_capita2 = (populacao2 > 0) ? (pib2 * 1000000000) / populacao2 : 0;
                break;

            case 3:
                printf("\n--- Carta 1 ---\n");
                printf("Estado: %s\n", estado1);
                printf("Cidade: %s\n", cidade1);
                printf("Código: %d\n", codigo1);
                printf("População: %d\n", populacao1);
                printf("PIB: R$ %.2f bilhões\n", pib1);
                printf("Área: %.2f km²\n", area1);
                printf("Pontos turísticos: %d\n", pontos1);
                printf("Densidade: %.2f hab/km²\n", densidade1);
                printf("PIB per capita: R$ %.2f\n", pib_per_capita1);

                printf("\n--- Carta 2 ---\n");
                printf("Estado: %s\n", estado2);
                printf("Cidade: %s\n", cidade2);
                printf("Código: %d\n", codigo2);
                printf("População: %d\n", populacao2);
                printf("PIB: R$ %.2f bilhões\n", pib2);
                printf("Área: %.2f km²\n", area2);
                printf("Pontos turísticos: %d\n", pontos2);
                printf("Densidade: %.2f hab/km²\n", densidade2);
                printf("PIB per capita: R$ %.2f\n", pib_per_capita2);
                break;

            case 4:
                printf("\n--- Comparação entre Cartas ---\n");

                printf("População: %s\n", (populacao1 > populacao2) ? cidade1 : (populacao2 > populacao1) ? cidade2 : "Empate");
                printf("PIB: %s\n", (pib1 > pib2) ? cidade1 : (pib2 > pib1) ? cidade2 : "Empate");
                printf("PIB per capita: %s\n", (pib_per_capita1 > pib_per_capita2) ? cidade1 : (pib_per_capita2 > pib_per_capita1) ? cidade2 : "Empate");
                printf("Densidade: %s\n", (densidade1 > densidade2) ? cidade1 : (densidade2 > densidade1) ? cidade2 : "Empate");
                printf("Pontos turísticos: %s\n", (pontos1 > pontos2) ? cidade1 : (pontos2 > pontos1) ? cidade2 : "Empate");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
