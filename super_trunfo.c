#include <stdio.h>

// Definição da estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[2];         // Estado (ex: "SP")
    char codigo[4];         // Código da carta (ex: "A01")
    char nomeCidade[50];    // Nome da cidade
    int populacao;          // População
    float area;             // Área em km²
    float pib;              // PIB em bilhões de reais
    int pontosTuristicos;   // Número de pontos turísticos
    float densidadePopulacional; // Calculado: População / Área
    float pibPerCapita;     // Calculado: PIB / População
};

int main() {
    // Declaração de duas variáveis do tipo Carta
    struct Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf("%s", carta1.estado);
    printf("Codigo da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculo da Densidade Populacional e PIB per capita para a Carta 1
    carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib * 1000000000 / carta1.populacao;

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf("%s", carta2.estado);
    printf("Codigo da carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculo da Densidade Populacional e PIB per capita para a Carta 2
    carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib * 1000000000 / carta2.populacao;

    // Escolha do atributo para comparação (definido diretamente no código)
    // Altere o valor abaixo para testar diferentes atributos:
    // 1 - População
    // 2 - Área
    // 3 - PIB
    // 4 - Densidade Populacional
    // 5 - PIB per capita
    int atributoEscolhido = 1; // Exemplo: Comparação por População

    // Variáveis para armazenar os valores das cartas para o atributo escolhido
    float valorCarta1 = 0, valorCarta2 = 0;

    // Determinar os valores com base no atributo escolhido
    if (atributoEscolhido == 1) { // População
        valorCarta1 = carta1.populacao;
        valorCarta2 = carta2.populacao;
    } else if (atributoEscolhido == 2) { // Área
        valorCarta1 = carta1.area;
        valorCarta2 = carta2.area;
    } else if (atributoEscolhido == 3) { // PIB
        valorCarta1 = carta1.pib;
        valorCarta2 = carta2.pib;
    } else if (atributoEscolhido == 4) { // Densidade Populacional
        valorCarta1 = carta1.densidadePopulacional;
        valorCarta2 = carta2.densidadePopulacional;
    } else if (atributoEscolhido == 5) { // PIB per capita
        valorCarta1 = carta1.pibPerCapita;
        valorCarta2 = carta2.pibPerCapita;
    }

    // Determinar o nome do atributo para exibição
    const char *nomeAtributo = "";
    if (atributoEscolhido == 1) {
        nomeAtributo = "Populacao";
    } else if (atributoEscolhido == 2) {
        nomeAtributo = "Area";
    } else if (atributoEscolhido == 3) {
        nomeAtributo = "PIB";
    } else if (atributoEscolhido == 4) {
        nomeAtributo = "Densidade Populacional";
    } else if (atributoEscolhido == 5) {
        nomeAtributo = "PIB per capita";
    }

    // Comparar os valores e determinar a carta vencedora
    int cartaVencedora = 0; // 1 para Carta 1, 2 para Carta 2
    if (atributoEscolhido == 4) { // Para Densidade Populacional, menor valor vence
        cartaVencedora = (valorCarta1 < valorCarta2) ? 1 : 2;
    } else { // Para todos os outros atributos, maior valor vence
        cartaVencedora = (valorCarta1 > valorCarta2) ? 1 : 2;
    }

    // Exibir o resultado da comparação
    printf("\n--- Comparacao de Cartas (%s) ---\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valorCarta2);
    printf("Resultado: Carta %d (%s) venceu!\n", cartaVencedora, cartaVencedora == 1 ? carta1.nomeCidade : carta2.nomeCidade);

    return 0;
}

