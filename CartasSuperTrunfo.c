#include <stdio.h>
#include <string.h>

// Criado por: Pedro Rufino
// Aluno: 202503565627@alunos.unifavip.edu.br
// Descrição: Sistema criado e optimizado desde o nível novato ao nível mestre conforme as videoaulas e as solicitações evoluiram.
// Além disso, o sistema foi otimizado e modularizado para evitar repetições redundantes de código.

// Definição da estrutura para representar uma carta
typedef struct
{
    char estado;
    char codigo[4];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float super_poder;
} Carta;

// Protótipos das funções
void cadastrarCarta(Carta *carta, int numero);
void exibirCarta(Carta carta, int numero);
void calcularDensidadeESuperPoder(Carta *carta);
void compararAtributo(const char *nome, float valor1, float valor2, int maiorMelhor);

int main()
{
    Carta carta1, carta2;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibição dos dados
    printf("\nDados das Cartas Cadastradas\n");
    printf("============================\n");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Cálculos
    calcularDensidadeESuperPoder(&carta1);
    calcularDensidadeESuperPoder(&carta2);

    // Comparações
    printf("\nResultado das Comparações:\n");
    printf("=========================\n");

    // Passamos os valores com cast explícito para float quando necessário
    compararAtributo("População", (float)carta1.populacao, (float)carta2.populacao, 1);
    compararAtributo("Área", carta1.area, carta2.area, 1);
    compararAtributo("PIB", carta1.pib, carta2.pib, 1);
    compararAtributo("Pontos Turísticos", (float)carta1.pontos_turisticos, (float)carta2.pontos_turisticos, 1);
    compararAtributo("Densidade Populacional", carta1.densidade, carta2.densidade, 0);
    compararAtributo("Super Poder", carta1.super_poder, carta2.super_poder, 1);

    return 0;
}

// Função para cadastrar os dados de uma carta
void cadastrarCarta(Carta *carta, int numero)
{
    printf("\nCadastro da Carta %d\n", numero);
    printf("-------------------\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->cidade);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero)
{
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.cidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// Função para calcular densidade e super poder
void calcularDensidadeESuperPoder(Carta *carta)
{
    // Calcular densidade populacional
    carta->densidade = (carta->area == 0) ? 0 : (float)carta->populacao / carta->area;

    // Calcular super poder
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos;
    if (carta->densidade != 0)
    {
        carta->super_poder += 1 / carta->densidade;
    }
}

// Função para comparar atributos genéricos
void compararAtributo(const char *nome, float valor1, float valor2, int maiorMelhor)
{
    printf("\n%s:\n", nome);

    // Exibição formatada de acordo com o tipo de dado
    if (strcmp(nome, "População") == 0)
    {
        printf("Carta 1: %lu vs Carta 2: %lu\n", (unsigned long)valor1, (unsigned long)valor2);
    }
    else if (strcmp(nome, "Pontos Turísticos") == 0)
    {
        printf("Carta 1: %d vs Carta 2: %d\n", (int)valor1, (int)valor2);
    }
    else
    {
        printf("Carta 1: %.2f vs Carta 2: %.2f\n", valor1, valor2);
    }

    int vencedor;
    if (maiorMelhor)
    {
        vencedor = (valor1 > valor2) ? 1 : 0;
    }
    else
    {
        vencedor = (valor1 < valor2) ? 1 : 0;
    }

    printf("Vencedor: %s\n", (vencedor == 1) ? "Carta 1" : "Carta 2");
}