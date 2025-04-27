#include <stdio.h>

// Definição da estrutura para armazenar os dados de uma carta
struct Carta {
    char estado;
    char codigo[4]; // 3 caracteres + '\0'
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional; // Novo campo para armazenar a densidade populacional
    float pibPerCapita;          // Novo campo para armazenar o PIB per capita
};

int main() {
    // Declaração de duas variáveis do tipo Carta
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");

    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &carta1.estado);

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &carta1.populacao);

    printf("Digite a area da cidade (em km²): \n");
    scanf("%f", &carta1.area);
        getchar(); // consome a quebra de linha

    printf("Digite o PIB da cidade (em bilhões de reais): \n");
    scanf("%f", &carta1.pib);
        getchar();


    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calcula a densidade populacional e o PIB per capita para a Carta 1
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao; // Converte bilhões para unidades

    printf("\nCadastro da Carta 2:\n");

    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", carta2.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &carta2.populacao);

    printf("Digite a area da cidade (em km²): ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

     // Calcula a densidade populacional e o PIB per capita para a Carta 2
     carta2.densidadePopulacional = carta2.populacao / carta2.area;
     carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao; // Converte bilhões para unidades

    // Exibição dos dados cadastrados
    printf("\n\n--- Dados das Cartas Cadastradas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);

    return 0;
}


