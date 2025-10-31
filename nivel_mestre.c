#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Carta {
    char estado;
    char codigo[8];
    char cidade[100];
    int populacao;
    double area;
    double pib;                 // em bilhões (conforme entrada)
    int pontos_turisticos;
    double densidade_populacional;
    double pib_per_capita;
};

/* retorna o valor do atributo selecionado como double */
double getValor(const struct Carta *c, int atributo) {
    switch (atributo) {
        case 1: return (double)c->populacao;
        case 2: return c->area;
        case 3: return c->pib;
        case 4: return (double)c->pontos_turisticos;
        case 5: return c->densidade_populacional;
        case 6: return c->pib_per_capita;
        default: return 0.0;
    }
}

/* nome legível do atributo */
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area (km²)";
        case 3: return "PIB (bilhoes)";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional (hab/km²)";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

/* lê uma linha e remove newline final */
void lerLinha(char *buf, int tam) {
    if (fgets(buf, tam, stdin)) {
        size_t ln = strlen(buf);
        if (ln > 0 && buf[ln-1] == '\n') buf[ln-1] = '\0';
    }
}

int main() {
    struct Carta carta1 = {0}, carta2 = {0};

    printf("===== Cadastro da Carta 1 =====\n");
    printf("Digite o estado da carta (A-H): ");
    scanf(" %c", &carta1.estado);
    carta1.estado = toupper(carta1.estado);

    printf("Digite o codigo da carta (Ex: A01): ");
    scanf("%7s", carta1.codigo);
    getchar(); // consome newline deixado pelo scanf

    printf("Digite o nome do pais/cidade: ");
    lerLinha(carta1.cidade, sizeof(carta1.cidade));

    printf("Digite a populacao (int): ");
    while (scanf("%d", &carta1.populacao) != 1) {
        printf("Entrada invalida. Digite um inteiro para populacao: ");
        while (getchar() != '\n');
    }

    printf("Digite a area (em km², float): ");
    while (scanf("%lf", &carta1.area) != 1) {
        printf("Entrada invalida. Digite um numero para area: ");
        while (getchar() != '\n');
    }

    printf("Digite o PIB (em bilhoes, float): ");
    while (scanf("%lf", &carta1.pib) != 1) {
        printf("Entrada invalida. Digite um numero para PIB: ");
        while (getchar() != '\n');
    }

    printf("Digite o numero de pontos turisticos (int): ");
    while (scanf("%d", &carta1.pontos_turisticos) != 1) {
        printf("Entrada invalida. Digite um inteiro para pontos turisticos: ");
        while (getchar() != '\n');
    }

    while (getchar() != '\n'); // limpa buffer antes de ler próxima linha completa

    printf("\n===== Cadastro da Carta 2 =====\n");
    printf("Digite o estado da carta (A-H): ");
    scanf(" %c", &carta2.estado);
    carta2.estado = toupper(carta2.estado);

    printf("Digite o codigo da carta (Ex: A01): ");
    scanf("%7s", carta2.codigo);
    getchar();

    printf("Digite o nome do pais/cidade: ");
    lerLinha(carta2.cidade, sizeof(carta2.cidade));

    printf("Digite a populacao (int): ");
    while (scanf("%d", &carta2.populacao) != 1) {
        printf("Entrada invalida. Digite um inteiro para populacao: ");
        while (getchar() != '\n');
    }

    printf("Digite a area (em km², float): ");
    while (scanf("%lf", &carta2.area) != 1) {
        printf("Entrada invalida. Digite um numero para area: ");
        while (getchar() != '\n');
    }

    printf("Digite o PIB (em bilhoes, float): ");
    while (scanf("%lf", &carta2.pib) != 1) {
        printf("Entrada invalida. Digite um numero para PIB: ");
        while (getchar() != '\n');
    }

    printf("Digite o numero de pontos turisticos (int): ");
    while (scanf("%d", &carta2.pontos_turisticos) != 1) {
        printf("Entrada invalida. Digite um inteiro para pontos turisticos: ");
        while (getchar() != '\n');
    }

    // Proteções: evitar divisão por zero
    if (carta1.area <= 0) carta1.densidade_populacional = 0.0;
    else carta1.densidade_populacional = (double)carta1.populacao / carta1.area;

    if (carta2.area <= 0) carta2.densidade_populacional = 0.0;
    else carta2.densidade_populacional = (double)carta2.populacao / carta2.area;

    if (carta1.populacao <= 0) carta1.pib_per_capita = 0.0;
    else carta1.pib_per_capita = carta1.pib * 1e9 / (double)carta1.populacao; // convertendo bilhoes->reais se quiser

    if (carta2.populacao <= 0) carta2.pib_per_capita = 0.0;
    else carta2.pib_per_capita = carta2.pib * 1e9 / (double)carta2.populacao;

    // Resumo rápido
    printf("\nCartas cadastradas:\n1) %s (%c)\n2) %s (%c)\n",
           carta1.cidade, carta1.estado, carta2.cidade, carta2.estado);

    // Menu e seleção de dois atributos diferentes
    int a1 = 0, a2 = 0;
    printf("\n===== MENU DE ATRIBUTOS =====\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");

    do {
        printf("Escolha o primeiro atributo (1-6): ");
        if (scanf("%d", &a1) != 1) { while (getchar() != '\n'); a1 = 0; }
        if (a1 < 1 || a1 > 6) printf("Opcao invalida. ");
    } while (a1 < 1 || a1 > 6);

    do {
        printf("Escolha o segundo atributo (1-6), diferente do primeiro: ");
        if (scanf("%d", &a2) != 1) { while (getchar() != '\n'); a2 = 0; }
        if (a2 < 1 || a2 > 6) printf("Opcao invalida. ");
        else if (a2 == a1) printf("Nao pode escolher o mesmo atributo. ");
    } while (a2 < 1 || a2 > 6 || a2 == a1);

    // Captura valores
    double v1a = getValor(&carta1, a1), v2a = getValor(&carta2, a1);
    double v1b = getValor(&carta1, a2), v2b = getValor(&carta2, a2);

    printf("\n==============================\n");
    printf("Atributo 1: %s\n", nomeAtributo(a1));
    printf("%s: %.2f | %s: %.2f\n\n", carta1.cidade, v1a, carta2.cidade, v2a);

    printf("Atributo 2: %s\n", nomeAtributo(a2));
    printf("%s: %.2f | %s: %.2f\n\n", carta1.cidade, v1b, carta2.cidade, v2b);

    // Regras: densidade (atributo 5) -> menor vence; else maior vence
    // Vamos somar os valores (conforme enunciado) e também computar pontos por atributo (opcional)
    double soma1 = v1a + v1b;
    double soma2 = v2a + v2b;

    printf("Soma dos atributos:\n%s: %.2f\n%s: %.2f\n\n", carta1.cidade, soma1, carta2.cidade, soma2);

    if (soma1 > soma2) printf("Resultado Final: Carta 1 (%s) venceu!\n", carta1.cidade);
    else if (soma2 > soma1) printf("Resultado Final: Carta 2 (%s) venceu!\n", carta2.cidade);
    else printf("Resultado Final: Empate!\n");

    printf("\n==============================\nFim da comparacao.\n==============================\n");
    return 0;
}
