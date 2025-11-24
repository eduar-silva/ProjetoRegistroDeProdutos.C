#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
};

int main() {
    struct Produto produtos[20];
    int quantidade[20];
    float total[20], desconto[20], ValorFinal[20];
    float totalGeral = 0;
    int i = 0, opcao;

    do {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco); 
        printf("Quantidade: ");
        scanf("%d", &quantidade[i]); 

        // Lógica direta na main
        total[i] = produtos[i].preco * quantidade[i];

        if (total[i] <= 100) desconto[i] = 0;
        else if (total[i] <= 250) desconto[i] = 0.05;
        else if (total[i] <= 500) desconto[i] = 0.10;
        else desconto[i] = 0.15;

        ValorFinal[i] = total[i] - (total[i] * desconto[i]);
        totalGeral += ValorFinal[i];

        printf("Continuar? (1-Sim / 0-Não): ");
        scanf("%d", &opcao);
        i++;
    } while (opcao == 1 && i < 20);

    printf("\n------- Nota Fiscal -------\n");
    for (int j = 0; j < i; j++) {
        printf("%s - Final: %.2f\n", produtos[j].nome, ValorFinal[j]);
    }
    printf("Total Geral: %.2f\n", totalGeral);

    return 0;
}