#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados de uma carta
struct Carta {
    char nomePais[50];          // Nome do país
    int populacao;              // População
    float area;                 // Área em km²
    float pib;                  // PIB em bilhões de reais
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadeDemografica; // Densidade demográfica (já calculada)
};

int main() {
    // Declaração de duas variáveis do tipo Carta
    struct Carta carta1, carta2;

    // Cadastro das Cartas
    printf("=== CADASTRO DE CARTAS ===\n");

    printf("\nCadastro da Carta 1:\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta1.nomePais);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;

    printf("\nCadastro da Carta 2:\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta2.nomePais);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    // Menu Interativo para escolha do primeiro atributo
    int opcao1 = 0, opcao2 = 0;
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao1);

    // Verifica se a opção é válida
    if (opcao1 < 1 || opcao1 > 5) {
        printf("Opcao invalida!\n");
        return 1;
    }

    // Menu Dinâmico para escolha do segundo atributo
    printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1:
                    printf("1 - Populacao\n");
                    break;
                case 2:
                    printf("2 - Area\n");
                    break;
                case 3:
                    printf("3 - PIB\n");
                    break;
                case 4:
                    printf("4 - Numero de Pontos Turisticos\n");
                    break;
                case 5:
                    printf("5 - Densidade Demografica\n");
                    break;
            }
        }
    }
    printf("Digite sua escolha: ");
    scanf("%d", &opcao2);

    // Verifica se a segunda opção é válida e diferente da primeira
    if (opcao2 < 1 || opcao2 > 5 || opcao2 == opcao1) {
        printf("Opcao invalida ou repetida!\n");
        return 1;
    }

    // Variáveis para armazenar os valores dos atributos
    float valorCarta1Atributo1 = 0, valorCarta2Atributo1 = 0;
    float valorCarta1Atributo2 = 0, valorCarta2Atributo2 = 0;
    const char *atributo1Nome = "", *atributo2Nome = "";

    // Determinar os valores e nomes dos atributos escolhidos
    switch (opcao1) {
        case 1:
            valorCarta1Atributo1 = carta1.populacao;
            valorCarta2Atributo1 = carta2.populacao;
            atributo1Nome = "Populacao";
            break;
        case 2:
            valorCarta1Atributo1 = carta1.area;
            valorCarta2Atributo1 = carta2.area;
            atributo1Nome = "Area";
            break;
        case 3:
            valorCarta1Atributo1 = carta1.pib;
            valorCarta2Atributo1 = carta2.pib;
            atributo1Nome = "PIB";
            break;
        case 4:
            valorCarta1Atributo1 = carta1.pontosTuristicos;
            valorCarta2Atributo1 = carta2.pontosTuristicos;
            atributo1Nome = "Numero de Pontos Turisticos";
            break;
        case 5:
            valorCarta1Atributo1 = carta1.densidadeDemografica;
            valorCarta2Atributo1 = carta2.densidadeDemografica;
            atributo1Nome = "Densidade Demografica";
            break;
    }

    switch (opcao2) {
        case 1:
            valorCarta1Atributo2 = carta1.populacao;
            valorCarta2Atributo2 = carta2.populacao;
            atributo2Nome = "Populacao";
            break;
        case 2:
            valorCarta1Atributo2 = carta1.area;
            valorCarta2Atributo2 = carta2.area;
            atributo2Nome = "Area";
            break;
        case 3:
            valorCarta1Atributo2 = carta1.pib;
            valorCarta2Atributo2 = carta2.pib;
            atributo2Nome = "PIB";
            break;
        case 4:
            valorCarta1Atributo2 = carta1.pontosTuristicos;
            valorCarta2Atributo2 = carta2.pontosTuristicos;
            atributo2Nome = "Numero de Pontos Turisticos";
            break;
        case 5:
            valorCarta1Atributo2 = carta1.densidadeDemografica;
            valorCarta2Atributo2 = carta2.densidadeDemografica;
            atributo2Nome = "Densidade Demografica";
            break;
    }

    // Comparação individual dos dois atributos
    printf("\n--- RESULTADO DA COMPARACAO ---\n");
    printf("Atributo 1: %s\n", atributo1Nome);
    printf("Carta 1 - %s: %.2f\n", carta1.nomePais, valorCarta1Atributo1);
    printf("Carta 2 - %s: %.2f\n", carta2.nomePais, valorCarta2Atributo1);
    if (opcao1 == 5) { // Para Densidade Demográfica, menor valor vence
        printf("Resultado: %s\n", valorCarta1Atributo1 < valorCarta2Atributo1 ? "Carta 1 venceu!" : "Carta 2 venceu!");
    } else { // Para outros atributos, maior valor vence
        printf("Resultado: %s\n", valorCarta1Atributo1 > valorCarta2Atributo1 ? "Carta 1 venceu!" : "Carta 2 venceu!");
    }

    printf("\nAtributo 2: %s\n", atributo2Nome);
    printf("Carta 1 - %s: %.2f\n", carta1.nomePais, valorCarta1Atributo2);
    printf("Carta 2 - %s: %.2f\n", carta2.nomePais, valorCarta2Atributo2);
    if (opcao2 == 5) { // Para Densidade Demográfica, menor valor vence
        printf("Resultado: %s\n", valorCarta1Atributo2 < valorCarta2Atributo2 ? "Carta 1 venceu!" : "Carta 2 venceu!");
    } else { // Para outros atributos, maior valor vence
        printf("Resultado: %s\n", valorCarta1Atributo2 > valorCarta2Atributo2 ? "Carta 1 venceu!" : "Carta 2 venceu!");
    }

    // Soma dos atributos para determinar o vencedor final
    float somaCarta1 = valorCarta1Atributo1 + valorCarta1Atributo2;
    float somaCarta2 = valorCarta2Atributo1 + valorCarta2Atributo2;

    printf("\n--- SOMA DOS ATRIBUTOS ---\n");
    printf("Carta 1 - %s: %.2f\n", carta1.nomePais, somaCarta1);
    printf("Carta 2 - %s: %.2f\n", carta2.nomePais, somaCarta2);

    if (somaCarta1 == somaCarta2) {
        printf("Resultado Final: Empate!\n");
    } else {
        printf("Resultado Final: %s\n", somaCarta1 > somaCarta2 ? "Carta 1 venceu!" : "Carta 2 venceu!");
    }

    return 0;
}