#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
};

struct Produto produtos[20];
int quantidade[20];
float ValorFinal[20], desconto[20], total[20];
float totalGeral = 0;
int i = 0;

void calcularTotal() {
    total[i] = produtos[i].preco * quantidade[i];
}

void aplicarDesconto() {
    if (total[i] <= 100) {
        desconto[i] = 0;
    } else if (total[i] > 100 && total[i] <= 250) {
        desconto[i] = 0.05;
    } else if (total[i] > 250 && total[i] <= 500) {
        desconto[i] = 0.10;
    } else {
        desconto[i] = 0.15;
    }
    ValorFinal[i] = total[i] - (total[i] * desconto[i]);
    totalGeral += ValorFinal[i];
}

void adicionarProduto() {
    int opcao;
    do {
        if (i >= 20) {
            printf("Limite atingido!\n");
            break;
        }
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf("%s", produtos[i].nome);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &quantidade[i]);

        calcularTotal();
        aplicarDesconto();

        printf("Outro? (1-Sim / 0-Não): ");
        scanf("%d", &opcao);
        
        if (opcao == 1) i++;
        else { i++; break; }
        
    } while (i < 20);
}

void emitirNotaFiscal() {
    printf("\n------- Dados dos Produtos -------");
    for (int j = 0; j < i; j++) {
        printf("\nProduto: %s | Preço: %.2f | Qtd: %d", produtos[j].nome, produtos[j].preco, quantidade[j]);
        printf("\nBruto: %.2f | Desc: %.0f%% | Final: %.2f", total[j], desconto[j]*100, ValorFinal[j]);
        printf("\n----------------------------------");
    }
    printf("\nValor TOTAL da compra: %.2f \n", totalGeral);
}