#include <stdio.h>

#define MAX 100

int main() {
    char estado[MAX][30], cidade[MAX][30];
    int codigo[MAX], populacao[MAX], pontos[MAX];
    float pib[MAX], area[MAX], densidade[MAX], pib_per_capita[MAX];
    int total = 0;
    int opcao;
    int carta1, carta2;

menu:

    printf("\n--- Menu Super Trunfo ---\n");
    printf("1. Cadastrar carta\n");
    printf("2. Listar cartas\n");
    printf("3. Comparar cartas\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        if (total >= MAX) {
            printf("Limite de cartas atingido!\n");
            goto menu;
        }

        printf("\nCadastro da Carta %d:\n", total + 1);
        printf("Estado: ");
        scanf(" %[^\n]", estado[total]);
        printf("Cidade: ");
        scanf(" %[^\n]", cidade[total]);
        printf("Código: ");
        scanf("%d", &codigo[total]);
        printf("População: ");
        scanf("%d", &populacao[total]);
        printf("PIB (em bilhões): ");
        scanf("%f", &pib[total]);
        printf("Área (km²): ");
        scanf("%f", &area[total]);
        printf("Pontos turísticos: ");
        scanf("%d", &pontos[total]);

        densidade[total] = (area[total] > 0) ? populacao[total] / area[total] : 0;
        pib_per_capita[total] = (populacao[total] > 0) ? (pib[total] * 1000000000) / populacao[total] : 0;

        total++;
        goto menu;

    } else if (opcao == 2) {
        if (total == 0) {
            printf("Nenhuma carta cadastrada!\n");
            goto menu;
        }

        int i = 0;
mostrar:
        if (i >= total) goto menu;

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

        i++;
        goto mostrar;

    } else if (opcao == 3) {
        if (total < 2) {
            printf("Cadastre pelo menos duas cartas para comparar.\n");
            goto menu;
        }

        printf("Digite o número da primeira carta (1 a %d): ", total);
        scanf("%d", &carta1);
        printf("Digite o número da segunda carta (1 a %d): ", total);
        scanf("%d", &carta2);

        carta1--; carta2--;

        if (carta1 < 0 || carta1 >= total || carta2 < 0 || carta2 >= total) {
            printf("Cartas inválidas!\n");
            goto menu;
        }

        printf("\n--- Comparação ---\n");

        printf("População: %s\n", 
            (populacao[carta1] > populacao[carta2]) ? cidade[carta1] :
            (populacao[carta2] > populacao[carta1]) ? cidade[carta2] : "Empate");

        printf("PIB: %s\n", 
            (pib[carta1] > pib[carta2]) ? cidade[carta1] :
            (pib[carta2] > pib[carta1]) ? cidade[carta2] : "Empate");

        printf("PIB per capita: %s\n", 
            (pib_per_capita[carta1] > pib_per_capita[carta2]) ? cidade[carta1] :
            (pib_per_capita[carta2] > pib_per_capita[carta1]) ? cidade[carta2] : "Empate");

        printf("Densidade: %s\n", 
            (densidade[carta1] > densidade[carta2]) ? cidade[carta1] :
            (densidade[carta2] > densidade[carta1]) ? cidade[carta2] : "Empate");

        printf("Pontos turísticos: %s\n", 
            (pontos[carta1] > pontos[carta2]) ? cidade[carta1] :
            (pontos[carta2] > pontos[carta1]) ? cidade[carta2] : "Empate");

        goto menu;

    } else if (opcao == 0) {
        printf("Saindo...\n");
        return 0;
    } else {
        printf("Opção inválida!\n");
        goto menu;
    }

    return 0;
}
