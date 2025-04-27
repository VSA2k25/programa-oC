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

    // Menu Interativo
    int opcao;
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    // Variáveis auxiliares para comparação
    float valorCarta1 = 0, valorCarta2 = 0;
    const char *atributoEscolhido = "";

    // Lógica de comparação usando switch
    switch (opcao) {
        case 1: // População
            valorCarta1 = carta1.populacao;
            valorCarta2 = carta2.populacao;
            atributoEscolhido = "Populacao";
            break;
        case 2: // Área
            valorCarta1 = carta1.area;
            valorCarta2 = carta2.area;
            atributoEscolhido = "Area";
            break;
        case 3: // PIB
            valorCarta1 = carta1.pib;
            valorCarta2 = carta2.pib;
            atributoEscolhido = "PIB";
            break;
        case 4: // Número de Pontos Turísticos
            valorCarta1 = carta1.pontosTuristicos;
            valorCarta2 = carta2.pontosTuristicos;
            atributoEscolhido = "Numero de Pontos Turisticos";
            break;
        case 5: // Densidade Demográfica
            valorCarta1 = carta1.densidadeDemografica;
            valorCarta2 = carta2.densidadeDemografica;
            atributoEscolhido = "Densidade Demografica";
            break;
        default:
            printf("Opcao invalida!\n");
            return 1; // Encerra o programa com erro
    }

    // Comparação dos valores
    printf("\n--- RESULTADO DA COMPARACAO (%s) ---\n", atributoEscolhido);
    printf("Carta 1 - %s: %.2f\n", carta1.nomePais, valorCarta1);
    printf("Carta 2 - %s: %.2f\n", carta2.nomePais, valorCarta2);

    if (valorCarta1 == valorCarta2) {
        printf("Resultado: Empate!\n");
    } else {
        if (opcao == 5) { // Para Densidade Demográfica, menor valor vence
            if (valorCarta1 < valorCarta2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            }
        } else { // Para todos os outros atributos, maior valor vence
            if (valorCarta1 > valorCarta2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomePais);
            } else {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomePais);
            }
        }
    }

    return 0;
}
