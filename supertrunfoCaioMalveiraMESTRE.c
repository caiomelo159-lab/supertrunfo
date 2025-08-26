#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado;                
    char codigo[4];             
    char nomeCidade[50];        
    int populacao;              
    float area;                 
    double pib;                 // PIB em bilhões convertido para unidades
    int numPontosTuristicos;    
    float densidadePopulacional;
    double pibPerCapita;
    float superPoder;
};

// Funções de comparação
void compararPopulacao(struct Carta c1, struct Carta c2) {
    if (c1.populacao > c2.populacao)
        printf("\nNa categoria POPULACAO, %s vence!\n", c1.nomeCidade);
    else if (c2.populacao > c1.populacao)
        printf("\nNa categoria POPULACAO, %s vence!\n", c2.nomeCidade);
    else
        printf("\nNa categoria POPULACAO, houve empate!\n");
}

void compararArea(struct Carta c1, struct Carta c2) {
    if (c1.area > c2.area)
        printf("Na categoria AREA, %s vence!\n", c1.nomeCidade);
    else if (c2.area > c1.area)
        printf("Na categoria AREA, %s vence!\n", c2.nomeCidade);
    else
        printf("Na categoria AREA, houve empate!\n");
}

void compararPIB(struct Carta c1, struct Carta c2) {
    if (c1.pib > c2.pib)
        printf("Na categoria PIB, %s vence!\n", c1.nomeCidade);
    else if (c2.pib > c1.pib)
        printf("Na categoria PIB, %s vence!\n", c2.nomeCidade);
    else
        printf("Na categoria PIB, houve empate!\n");
}

void compararPontosTuristicos(struct Carta c1, struct Carta c2) {
    if (c1.numPontosTuristicos > c2.numPontosTuristicos)
        printf("Na categoria PONTOS TURISTICOS, %s vence!\n", c1.nomeCidade);
    else if (c2.numPontosTuristicos > c1.numPontosTuristicos)
        printf("Na categoria PONTOS TURISTICOS, %s vence!\n", c2.nomeCidade);
    else
        printf("Na categoria PONTOS TURISTICOS, houve empate!\n");
}

void CompararDensidadePopulacional(struct Carta c1, struct Carta c2) {
    if (c1.densidadePopulacional < c2.densidadePopulacional)
        printf("Na categoria Densidade Populacional, %s vence\n", c1.nomeCidade);
    else if (c2.densidadePopulacional < c1.densidadePopulacional)
        printf("Na categoria Densidade Populacional, %s vence\n", c2.nomeCidade);
    else
        printf("Na categoria Densidade Populacional, houve empate!\n");
}

void CompararPIBperCapita(struct Carta c1, struct Carta c2) {
    if (c1.pibPerCapita > c2.pibPerCapita)
        printf("Na categoria PIB per Capita, %s vence\n", c1.nomeCidade);
    else if (c2.pibPerCapita > c1.pibPerCapita)
        printf("Na categoria PIB per Capita, %s vence\n", c2.nomeCidade);
    else
        printf("Na categoria PIB per Capita, houve empate!\n");
}



void CompararSuperPoder(struct Carta c1, struct Carta c2) {
    if (c1.superPoder > c2.superPoder)
        printf("Na categoria Super Poder, %s vence!\n", c1.nomeCidade);
    else if (c2.superPoder > c1.superPoder)
        printf("Na categoria Super Poder, %s vence!\n", c2.nomeCidade);
    else
        printf("Na categoria Super Poder, houve empate!\n");
}

int main() {
    struct Carta carta1, carta2;

    printf("=== Cadastro de Cartas Super Trunfo (Cidades) ===\n");
    printf("===== ATENÇÃO: NÃO USAR CARACTERES ESPECIAIS OU ACENTOS =====\n");

    // Cadastro da primeira carta
    printf("\n--- Primeira Carta ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    getchar(); // limpa buffer
    printf("Nome da Cidade: ");
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = 0;

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &carta1.pib);  // usa %lf para double

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.numPontosTuristicos);

    // Calculando métricas da primeira carta
    carta1.pib = carta1.pib * 1000000000.0; // converte PIB de bilhões para unidades
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / (double)carta1.populacao;

    // Cadastro da segunda carta
    printf("\n--- Segunda Carta ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Código da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);

    getchar(); // limpa buffer
    printf("Nome da Cidade: ");
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = 0;

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.numPontosTuristicos);

    // Calculando métricas da segunda carta
    carta2.pib = carta2.pib * 1000000000.0; // converte PIB de bilhões para unidades
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / (double)carta2.populacao;

carta1.superPoder = carta1.populacao 
                      + carta1.area 
                      + carta1.pib 
                      + carta1.numPontosTuristicos 
                      + carta1.pibPerCapita 
                      + (1.0 / carta1.densidadePopulacional);

carta2.superPoder = carta2.populacao 
                      + carta2.area 
                      + carta2.pib 
                      + carta2.numPontosTuristicos 
                      + carta2.pibPerCapita 
                      + (1.0 / carta2.densidadePopulacional);


    // Exibindo cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");

    printf("\nCarta 1:\n Estado: %c\n Código: %s\n Cidade: %s\n População: %d\n Área: %.2f km²\n PIB: %.2lf\n Pontos Turísticos: %d\n Densidade Populacional: %.2f\n PIB per Capita: %.2lf\n SuperPoder: %.2lf\n",
           carta1.estado, carta1.codigo, carta1.nomeCidade, carta1.populacao, carta1.area, carta1.pib, carta1.numPontosTuristicos, carta1.densidadePopulacional, carta1.pibPerCapita, carta1.superPoder);

    printf("\nCarta 2:\n Estado: %c\n Código: %s\n Cidade: %s\n População: %d\n Área: %.2f km²\n PIB: %.2lf\n Pontos Turísticos: %d\n Densidade Populacional: %.2f\n PIB per Capita: %.2lf\n SuperPoder: %.2lf\n",
           carta2.estado, carta2.codigo, carta2.nomeCidade, carta2.populacao, carta2.area, carta2.pib, carta2.numPontosTuristicos, carta2.densidadePopulacional, carta2.pibPerCapita, carta2.superPoder);

    // Comparações
    printf("\n=== Resultados das Comparações ===\n");
    compararPopulacao(carta1, carta2);
    compararArea(carta1, carta2);
    compararPIB(carta1, carta2);
    compararPontosTuristicos(carta1, carta2);
    CompararDensidadePopulacional(carta1, carta2);
    CompararPIBperCapita(carta1, carta2);
    CompararSuperPoder(carta1, carta2);

    return 0;
    }
